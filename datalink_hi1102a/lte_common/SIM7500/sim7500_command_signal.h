#ifndef SIM7500_COMMAND_SIGNAL_H_EC20
#define SIM7500_COMMAND_SIGNAL_H_

#include "sim7500_basic.h"

namespace sim7500 {

#define SIM7500_CMD_SIGNAL                "AT+CSQ"
#define SIM7500_CMD_SIGNAL_RESPONSE       "+CSQ:"

typedef struct Sim7500Signal {
    uint8_t rssi;
    uint8_t ber;

    Sim7500Signal() {
        rssi = 0;
        ber = 0;
    }
} Sim7500Signal_t;

SIM7500_HELPER void Sim7500SignalDecode(const std::string &data, Sim7500Signal_t *signal)
{
    if (data.empty())
        return;

    ssize_t pos;
    std::string tmp;

    pos = data.find(SIM7500_CMD_SIGNAL_RESPONSE);

    if (pos != std::string::npos) {
        tmp = data.substr(pos);
    } else {
        return;
    }

    int rssi = 0;
    int ber = 0;

    sscanf(tmp.c_str(), "+CSQ: %d,%d", &rssi, &ber);

    signal->rssi = static_cast<uint8_t>(rssi);
    signal->ber = static_cast<uint8_t>(ber);
}

SIM7500_HELPER void Sim7500SignalEncode(std::string *command)
{
    std::string tmp;

    if (command == nullptr)
        return;

    tmp = SIM7500_CMD_SIGNAL;
    tmp.append("\r\n");

    command->assign(tmp);
}

SIM7500_HELPER void Sim7500SignalDebug(const Sim7500Signal_t &signal)
{
    SIM7500_DEBUG_PRINTF(("\n\n%s\n", SIM7500_CMD_SIGNAL));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n"));
    SIM7500_DEBUG_PRINTF(("rssi:\t\t%u\n", signal.rssi));
    SIM7500_DEBUG_PRINTF(("ber :\t\t%u\n", signal.ber));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n\n"));
}

}

#endif /* SIM7500_COMMAND_SIGNAL_H_ */
