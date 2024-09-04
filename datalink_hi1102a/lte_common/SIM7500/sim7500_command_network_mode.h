#ifndef SIM7500_COMMAND_NETWORK_MODE_H
#define SIM7500_COMMAND_NETWORK_MODE_H

#include "sim7500_basic.h"

namespace sim7500 {

#define SIM7500_CMD_NETWORK_MODE           "AT+CNSMOD"
#define SIM7500_CMD_NETWORK_MODE_RESPONSE  "+CNSMOD:"

typedef enum Sim7500NetworkModeAutoReport {
    SIM7500_NETWORK_MODE_AUTOREPORT_DISABLE = 0,
    SIM7500_NETWORK_MODE_AUTOREPORT_ENABLE  = 1
} Sim7500NetworkModeAutoReport_t;

typedef enum Sim7500NetworkModeStat {
    SIM7500_NETWORK_MODE_STAT_NOSERVICE     = 0, /* no service */
    SIM7500_NETWORK_MODE_STAT_GSM           = 1,
    SIM7500_NETWORK_MODE_STAT_GPRS          = 2,
    SIM7500_NETWORK_MODE_STAT_EGPRS         = 3,
    SIM7500_NETWORK_MODE_STAT_WCDMA         = 4,
    SIM7500_NETWORK_MODE_STAT_HSDPA         = 5,
    SIM7500_NETWORK_MODE_STAT_HSUPA         = 6,
    SIM7500_NETWORK_MODE_STAT_HSPA          = 7,
    SIM7500_NETWORK_MODE_STAT_LTE           = 8,
    SIM7500_NETWORK_MODE_STAT_TDS_CDMA      = 9,
    SIM7500_NETWORK_MODE_STAT_TDS_HSDPA     = 10,
    SIM7500_NETWORK_MODE_STAT_TDS_HSUPA     = 11,
    SIM7500_NETWORK_MODE_STAT_TDS_HSPA      = 12,
    SIM7500_NETWORK_MODE_STAT_CDMA          = 13,
    SIM7500_NETWORK_MODE_STAT_EVDO          = 14,
    SIM7500_NETWORK_MODE_STAT_HYBRID_CEV    = 15,
    SIM7500_NETWORK_MODE_STAT_1XLTE         = 16,
    SIM7500_NETWORK_MODE_STAT_EHRPD         = 17,
    SIM7500_NETWORK_MODE_STAT_HYBRID_CEH    = 18
} Sim7500NetworkModeStat_t;

typedef struct Sim7500NetworkMode {
    uint8_t n;
    uint8_t stat;

    Sim7500NetworkMode() {
        n = SIM7500_NETWORK_MODE_AUTOREPORT_DISABLE;
        stat = SIM7500_NETWORK_MODE_STAT_NOSERVICE;
    }
} Sim7500NetworkMode_t;

SIM7500_HELPER void Sim7500NetworkModeDecode(const std::string &data, Sim7500NetworkMode_t *mode)
{
    if (data.empty())
        return;

    if (mode == nullptr)
        return;

    ssize_t pos;
    std::string tmp;

    pos = data.find(SIM7500_CMD_NETWORK_MODE_RESPONSE);

    if (pos != std::string::npos) {
        tmp = data.substr(pos + sizeof(SIM7500_CMD_NETWORK_MODE_RESPONSE));
    } else {
        return;
    }

    int n;
    int stat;

    sscanf(tmp.c_str(), "%d,%d", &n, &stat);

    mode->n = static_cast<uint8_t>(n);
    mode->stat = static_cast<uint8_t>(stat);
}

SIM7500_HELPER void Sim7500NetworkModeEncode(std::string *command, 
                                             Sim7500CmdMotions_t motion, 
                                             Sim7500NetworkModeAutoReport_t n = SIM7500_NETWORK_MODE_AUTOREPORT_DISABLE,
                                             Sim7500NetworkModeStat_t stat = SIM7500_NETWORK_MODE_STAT_LTE)
{
    std::string tmp;

    if (command == nullptr)
        return;

    switch (motion) {
    case SIM7500_CMD_MOTION_SETUP:
        tmp = SIM7500_CMD_NETWORK_MODE;
        tmp.append("=");
        tmp.append(std::to_string(n));
        tmp.append(",");
        tmp.append(std::to_string(stat));
        tmp.append("\r\n");
        break;

    case SIM7500_CMD_MOTION_INQUIRE:
        tmp = SIM7500_CMD_NETWORK_MODE;
        tmp.append("?\r\n");
        break;
    }

    command->assign(tmp);
}

SIM7500_HELPER void Sim7500NetworkModeDebug(const Sim7500NetworkMode_t &mode)
{
    SIM7500_DEBUG_PRINTF(("\n\n%s\n", SIM7500_CMD_NETWORK_MODE));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n"));
    SIM7500_DEBUG_PRINTF(("n    :\t\t%d\n", mode.n));
    SIM7500_DEBUG_PRINTF(("stat :\t\t%d\n", mode.stat));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n\n"));
}

}

#endif /* SIM7500_COMMAND_NETWORK_MODE_H */
