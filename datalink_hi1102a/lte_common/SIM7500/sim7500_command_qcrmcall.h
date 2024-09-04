#ifndef SIM7500_COMMAND_QCRMCALL_H_
#define SIM7500_COMMAND_QCRMCALL_H_

#include "sim7500_basic.h"

namespace sim7500 {

#define SIM7500_CMD_QCRMCALL            "AT$QCRMCALL="

SIM7500_HELPER void Sim7500SignalEncode(std::string *command, const bool &enable)
{
    std::string tmp;

    if (command == nullptr)
        return;

    tmp = SIM7500_CMD_QCRMCALL;
    if (enable)
        tmp.append("1,1");
    else
        tmp.append("0,1");
    tmp.append("\r\n");

    command->assign(tmp);
}

}

#endif /* SIM7500_COMMAND_SIGNAL_H_ */
