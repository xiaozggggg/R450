#ifndef SIM7500_COMMAND_CPIN_REQUIRED_H
#define SIM7500_COMMAND_CPIN_REQUIRED_H

#include "sim7500_basic.h"

namespace sim7500 {

#define SIM7500_CMD_CPIN_REQUIRED              "AT+CPIN?"
#define SIM7500_CMD_CPIN_REQUIRED_RESPONSE     "+CPIN:"

#define SIM7500_CPIN_CODE_READY        "READY"
#define SIM7500_CPIN_CODE_SIMPIN       "SIM PIN"
#define SIM7500_CPIN_CODE_SIMPUK       "SIM PUK"
#define SIM7500_CPIN_CODE_SIMPIN2      "SIM PIN2"
#define SIM7500_CPIN_CODE_SIMPUK2      "SIM PUK2"
#define SIM7500_CPIN_CODE_PH_NET_PIN   "PH-NET PIN"
#define SIM7500_CPIN_CODE_PH_SIM_PIN   "PH-SIM PIN"

typedef struct Sim7500CpinRequired {
    char code[12];

    Sim7500CpinRequired() {
        bzero(code, sizeof(code));
    }
} Sim7500CpinRequired_t;

SIM7500_HELPER void Sim7500CpinRequiredDecode(const std::string &data, Sim7500CpinRequired_t *required)
{
    int i;
    ssize_t pos;
    std::string tmp;
    std::istringstream ss;

    if (data.empty())
        return;

    if (required == nullptr)
        return;

    pos = data.find(SIM7500_CMD_CPIN_REQUIRED_RESPONSE);

    if (pos != std::string::npos) {
        tmp = data.substr(pos + sizeof(SIM7500_CMD_CPIN_REQUIRED_RESPONSE));
        ss.str(tmp);
    } else {
        return;
    }

    std::string code;
    std::getline(ss, code, '\n');

    memmove(required->code, code.c_str(), code.length());
}

SIM7500_HELPER void Sim7500CpinRequiredEncode(std::string *command)
{
    std::string tmp;

    if (command == nullptr)
        return;

    tmp = SIM7500_CMD_CPIN_REQUIRED;
    tmp.append("\r\n");

    command->append(tmp);
}

SIM7500_HELPER void Sim7500CpinRequiredDebug(const Sim7500CpinRequired_t &required)
{
    SIM7500_DEBUG_PRINTF(("\n\n%s\n", SIM7500_CMD_CPIN_REQUIRED));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n"));
    SIM7500_DEBUG_PRINTF(("code :\t\t%s\n", required.code));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n\n"));
}

}

#endif
