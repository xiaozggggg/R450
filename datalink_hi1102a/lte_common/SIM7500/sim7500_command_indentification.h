#ifndef SIM7500_COMMAND_INDENTIFICATION_H_
#define SIM7500_COMMAND_INDENTIFICATION_H_

#include "sim7500_basic.h"
#include <strings.h>

namespace sim7500 {

#define SIM7500_CMD_INDENTIFICATION              "ATI"
#define SIM7500_CMD_INDENTIFICATION_RESPONSE     "Manufacturer:"
#define SIM7500_INDENTIFICATION_IDS              "SIMCOM"

#define SIM7500_MANUFACTURER_KEY                 SIM7500_CMD_INDENTIFICATION_RESPONSE
#define SIM7500_MODEL_KEY                        "Model:"
#define SIM7500_REVISION_KEY                     "Revision:"
#define SIM7500_IMEI_KEY                         "IMEI:"
#define SIM7500_GCAP_KEY                         "+GCAP:"

typedef struct Sim7500Indentification {
    char manufacturer[128];
    char model[32];
    char revision[32];
    uint64_t imei;
    char gcap[64];

    Sim7500Indentification() {
        bzero(manufacturer, sizeof(manufacturer));
        bzero(model, sizeof(model));
        bzero(revision, sizeof(revision));
        imei = 0;
        bzero(gcap, sizeof(gcap));
    }
} Sim7500Indentification_t;

SIM7500_HELPER void Sim7500IndentificationDecode(const std::string &data, Sim7500Indentification_t *indec)
{
    int i;
    ssize_t pos;
    std::string tmp;
    std::istringstream ss;
    std::string element;

    if (data.empty())
        return;

    if (indec == nullptr)
        return;

    pos = data.find(SIM7500_CMD_INDENTIFICATION_RESPONSE);

    if (pos != std::string::npos) {
        tmp = data.substr(pos);
        ss.str(tmp);
    } else {
        return;
    }

    i = 1;
    while (std::getline(ss, element, '\n')) {

        size_t r = element.find_last_of('\r');
        if (r != 0)
            element.erase(r);

        std::cout << element.length() << " " << element << std::endl;

        switch (i) 
        {
        case 1:
            pos = element.find(SIM7500_MANUFACTURER_KEY);
            if (pos == std::string::npos)
                break;
            tmp = element.substr(pos + sizeof(SIM7500_MANUFACTURER_KEY));
            memmove(indec->manufacturer, element.data(), element.length());
            break;

        case 2:
            pos = element.find(SIM7500_MODEL_KEY);
            if (pos == std::string::npos)
                break;
            tmp = element.substr(pos + sizeof(SIM7500_MODEL_KEY));
            memmove(indec->model, tmp.c_str(), tmp.length());
            break;

        case 3:
            pos = element.find(SIM7500_REVISION_KEY);
            if (pos == std::string::npos)
                break;
            tmp = element.substr(pos + sizeof(SIM7500_REVISION_KEY));
            memmove(indec->revision, tmp.c_str(), tmp.length());
            break;

        case 4:
            pos = element.find(SIM7500_IMEI_KEY);
            if (pos == std::string::npos)
                break;
            tmp = element.substr(pos + sizeof(SIM7500_IMEI_KEY));
            indec->imei = atoll(tmp.c_str());
            break;

        case 5:
            pos = element.find(SIM7500_GCAP_KEY);
            if (pos == std::string::npos)
                break;
            tmp = element.substr(pos + sizeof(SIM7500_GCAP_KEY));
            memmove(indec->gcap, tmp.c_str(), tmp.length());
            return;

        default:
            break;
        }

        ++i;
    }
}

SIM7500_HELPER void Sim7500IndentificationEncode(std::string *command)
{
    std::string tmp;

    if (command == nullptr)
        return;

    tmp = SIM7500_CMD_INDENTIFICATION;
    tmp.append("\r\n");

    command->assign(tmp);
}

SIM7500_HELPER void Sim7500IndentificationDebug(const Sim7500Indentification_t &indec)
{
    SIM7500_DEBUG_PRINTF(("\n\n%s\n", SIM7500_CMD_INDENTIFICATION));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n"));
    SIM7500_DEBUG_PRINTF(("Manufacturer:\t%s\n", indec.manufacturer));
    SIM7500_DEBUG_PRINTF(("Model:\t\t%s\n", indec.model));
    SIM7500_DEBUG_PRINTF(("Revision:\t%s\n", indec.revision));
    SIM7500_DEBUG_PRINTF(("IMEI:\t\t %llu\n", indec->imei));
    SIM7500_DEBUG_PRINTF(("GCAP:\t\t%s\n", indec->gcap));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n\n"));
}

}

#endif /* SIM7500_COMMAND_INDENTIFICATION_H_ */
