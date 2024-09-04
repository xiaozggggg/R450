#include "mobilecc.h"

mobilecc::mobilecc()
{
    mobile_setup = MOBILECC_STEUP_IDLE;
    run_state = false;
    _isexist = false;
}

mobilecc::~mobilecc()
{
}

void mobilecc::start()
{
    atchn.start();

    mobile_setup = MOBILECC_STEUP_ATCHANNEL_CHECK;
    run_state = true;
    _isexist = true;
    mobilethread = std::thread(&mobilecc::setpup_handler, this);
    mobilethread.detach();
}

void mobilecc::stop()
{
    run_state = false;
    while (_isexist) { usleep(1000); }

    atchn.stop();
}

bool mobilecc::online()
{
    return atchn.isready();
}

shm_4Gmodule_t *mobilecc::get_4Gmobide_status()
{
    return atchn.get_shm_4Gmodule();
}

#define MOBILECC_STEUP_JUMPTO(s) do{ mobile_setup = s; } while (0)

void mobilecc::setpup_handler()
{
    int dail_timeout_count;
    shm_4Gmodule_t *m;
    uint8_t signal;

    while (run_state) {
        switch (mobile_setup)
        {
        /** 
         * NIC ATChannel configuration status detection
         * 
         * @note Check the current state of ATChannel, if the ATChannel module 
         *      is not started, start the module.
         ------------------------------------------------------------------------------- */
        case MOBILECC_STEUP_ATCHANNEL_CHECK:
            if (atchn.isrunning()) {
                if (atchn.isready()) {
                    // printf("=========== MOBILECC_STEUP_ATCHANNEL_CHECK atchready\n");
                    dail_timeout_count = 0;
                    MOBILECC_STEUP_JUMPTO(MOBILECC_STEUP_DIALPROCS_HOLDON);
                }
            }
            break;

        case MOBILECC_STEUP_DIALPROCS_HOLDON:
            m = get_4Gmobide_status();

            signal = abs(mobilecc_convert_signal(m->signal));
            fprintf(stderr, "mobile signal: %d dBm\n", signal);
            break;

        case MOBILECC_STEUP_IDLE:
        default:
            break;
        }

        sleep(1);
    }

    _isexist = false;
}