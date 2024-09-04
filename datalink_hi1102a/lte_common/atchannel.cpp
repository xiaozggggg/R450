#include "atchannel.h"

atchannel::atchannel(std::string _device_name, int _baudrate, int _bitnum, int _stopbits, int _parity) : 
    uartbase(_device_name, _baudrate, _bitnum, _stopbits, _parity)
{
#if MOUDLE_PARAS_USE_SHM
    ec20 = get_shm_4Gmodule();
#else
    sim7500 = new shm_4Gmodule_t;
#endif

    run_state = false;
    _isexist = false;
}

atchannel::~atchannel()
{
#if MOUDLE_PARAS_USE_SHM
    release_shm_4Gmodule(ec20);
#else
    delete sim7500;
#endif
}

void atchannel::start()
{
    int ret;

#if MOUDLE_PARAS_USE_SHM
    if (nullptr == ec20)
        ec20 = get_shm_4Gmodule();
#else
    if (nullptr == sim7500)
        sim7500 = new shm_4Gmodule_t;
#endif

    uartbase::start();

    ret = isenable();
    if(ret == 0){
        printf("======= [simcom] open device failed ======= \n");
        run_state = false;
        return;
    }

    run_state = true;
    _isexist = true;
    setupstep = SETUPSTEP_IDENTIFICATION;
    setupthread = std::thread(&atchannel::setup_handler, this);
    setupthread.detach();
}

void atchannel::stop()
{
    setupstep = SETUPSTEP_IDENTIFICATION;
    run_state = false;

    while (_isexist) { usleep(1000); }

    uartbase::stop();
}

bool atchannel::isrunning()
{
    return run_state;
}

bool atchannel::isready()
{
    return (setupstep == SETUPSTEP_READY);
}

shm_4Gmodule_t *atchannel::get_shm_4Gmodule()
{
    return sim7500;
}

int atchannel::sendto(std::string command)
{
    return send(command.c_str(), command.length());
}

void atchannel::onreceive(int nread, const char *buf)
{
    std::string data = buf;

    // fprintf(stderr, "onreceive nread:%d\n", nread);
    // fprintf(stderr, "%s\n", buf);

    command_handle(data);
}

static inline bool judge_4Gmodule_para(shm_4Gmodule_t *sim7500, sim7500_para_id_t id)
{
    bool judge = false;

    if (!sim7500)
        return false;

#if 1
    switch (id)
    {
    case SIM7500_ID_INDENTIFICATION:
        judge = ((strstr(sim7500->indentification.manufacturer, SIM7500_INDENTIFICATION_IDS)) != nullptr) ? true : false;
        break;

    case SIM7500_ID_CPIN:
        judge = ((strstr(sim7500->cpin.code, SIM7500_CPIN_CODE_READY)) != nullptr) ? true : false;
        break;

    case SIM7500_ID_NETWORK_STATUS_4G:
        if ((sim7500->network_status_4G.stat == sim7500::SIM7500_4GNETWORK_STAT_REGISTED_LOCALNET) || \
            (sim7500->network_status_4G.stat == sim7500::SIM7500_4GNETWORK_STAT_REGISTED_ROAMNET))
        {
            judge = true;
        } else {
            judge = false;
        }
        break;

    default:
        break;
    }
#endif

    return judge;
}

#define SETUPSTEP_JUMPTO(s) do{ setupstep = s; } while (0)

void atchannel::setup_handler()
{
#define TIMER_INTERVAL 500

    unsigned int timecount = 0;
    bool gatt_long_wait = false;
    unsigned int gatt_time_count = 0;

    while (run_state) {
        switch (setupstep)
        {
        case SETUPSTEP_IDENTIFICATION:
            if (judge_4Gmodule_para(sim7500, SIM7500_ID_INDENTIFICATION) == false) {
                command_indentification();
            } else {
                SETUPSTEP_JUMPTO(SETUPSTEP_CPIN_CHECK);
            }
            break;

        case SETUPSTEP_CPIN_CHECK:
            if (judge_4Gmodule_para(sim7500, SIM7500_ID_CPIN) == false) {
                command_cpin_required();
            } else {
                SETUPSTEP_JUMPTO(SETUPSTEP_CREG_CHECK);
            }
            break;

        case SETUPSTEP_CREG_CHECK:
            if (judge_4Gmodule_para(sim7500, SIM7500_ID_NETWORK_STATUS_4G) == false) {
                command_network_status();
            } else {
                fprintf(stderr, "Network Normal\n");
                command_set_disconnect();
                usleep(500*1000);

                SETUPSTEP_JUMPTO(SETUPSTEP_DIALMODE);
            }
            break;

        case SETUPSTEP_DIALMODE:
            fprintf(stderr, "start connect to server\n");

            command_set_dialmode();
            sleep(1);
            system("ifconfig wwan0 up");
            usleep(200*1000);
            system("udhcpc -i wwan0");
            usleep(200*1000);

            fprintf(stderr, "connect server ok\n");
            SETUPSTEP_JUMPTO(SETUPSTEP_READY);
            break;

        case SETUPSTEP_READY:
            if (!(timecount%2)) {
                command_signal();
            }
            break;

        default:
            break;
        }

        timecount++;

        usleep(500*1000);
    }

    _isexist = false;
}
