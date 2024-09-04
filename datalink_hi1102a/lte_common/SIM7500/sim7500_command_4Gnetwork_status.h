#ifndef SIM7500_COMMAND_4GNETWORK_STATUS_H
#define SIM7500_COMMAND_4GNETWORK_STATUS_H

#include "sim7500_basic.h"

namespace sim7500 {

#define SIM7500_CMD_4G_NETWORK_STATUS             "AT+CEREG?"
#define SIM7500_CMD_4G_NETWORK_STATUS_RESPONSE    "+CEREG:"

enum Sim75004GNetworkStat {
    SIM7500_4GNETWORK_STAT_NOTREG_NOTSEARCH  = 0,
    SIM7500_4GNETWORK_STAT_REGISTED_LOCALNET = 1,
    SIM7500_4GNETWORK_STAT_NOTREG_INSEARCH   = 2,
    SIM7500_4GNETWORK_STAT_REGDENIED_DENIED  = 3,
    SIM7500_4GNETWORK_STAT_UNKNOW            = 4,
    SIM7500_4GNETWORK_STAT_REGISTED_ROAMNET  = 5,
    SIM7500_4GNETWORK_STAT_REGISTED_SMS_HOME = 6,
    SIM7500_4GNETWORK_STAT_REGISTED_SMS_ROAM = 7,
    SIM7500_4GNETWORK_STAT_EMERGENCY_BEARER  = 8,
};

typedef struct Sim75004GNetworkStatus {
    uint8_t n;
    uint8_t stat;

    Sim75004GNetworkStatus() {
        n = 0;
        stat = SIM7500_4GNETWORK_STAT_NOTREG_NOTSEARCH;
    }
} Sim75004GNetworkStatus_t;

SIM7500_HELPER void Sim75004GNetworkStatusDecode(const std::string &data, Sim75004GNetworkStatus_t *status)
{
    ssize_t pos;
    std::string tmp;

    if (data.empty())
        return;

    if (status == nullptr)
        return;

    pos = data.find(SIM7500_CMD_4G_NETWORK_STATUS_RESPONSE);

    if (pos != std::string::npos) {
        tmp = data.substr(pos + sizeof(SIM7500_CMD_4G_NETWORK_STATUS_RESPONSE));
    } else {
        return;
    }

    int n = 0;
    int stat = SIM7500_4GNETWORK_STAT_NOTREG_NOTSEARCH;

    sscanf(tmp.c_str(), "%d,%d", &n, &stat);

    status->n = static_cast<uint8_t>(n);
    status->stat = static_cast<uint8_t>(stat);
}

SIM7500_HELPER void Sim75004GNetworkStatusEncode(std::string *command)
{
    std::string tmp;

    if (command == nullptr)
        return;

    tmp = SIM7500_CMD_4G_NETWORK_STATUS;
    tmp.append("\r\n");

    command->assign(tmp);
}

SIM7500_HELPER void Sim75004GNetworkStatusDebug(const Sim75004GNetworkStatus_t &status)
{
    SIM7500_DEBUG_PRINTF(("\n\n%s\n", SIM7500_CMD_4G_NETWORK_STATUS));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n"));
    SIM7500_DEBUG_PRINTF(("n       :\t\t%u\n", status.n));
    SIM7500_DEBUG_PRINTF(("stat    :\t\t%u\n", status.stat));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n\n"));
}

}

#endif
