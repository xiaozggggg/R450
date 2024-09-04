#ifndef SIM7500_COMMAND_PS_ATTACHMENT_H
#define SIM7500_COMMAND_PS_ATTACHMENT_H

#include "sim7500_basic.h"

namespace sim7500 {

#define SIM7500_CMD_PS_ATTACHMENT          "AT+CGATT"
#define SIM7500_CMD_PS_ATTACHMENT_RESPONSE "+CGATT:"

typedef enum Sim7500PsAttachmentStates {
    SIM7500_PS_ATTACHMENT_DETACHED = 0,
    SIM7500_PS_ATTACHMENT_ATTACHED = 1,
} Sim7500PsAttachmentStates_t;

typedef struct Sim7500PsAttachment {
    uint8_t state;

    Sim7500PsAttachment() {
        state = SIM7500_PS_ATTACHMENT_DETACHED;
    }
} Sim7500PsAttachment_t;

SIM7500_HELPER void Sim7500PsAttachmentDecode(const std::string &data, Sim7500PsAttachment_t *attachment)
{
    if (data.empty())
        return;

    if (attachment == nullptr)
        return;

    ssize_t pos;
    std::string tmp;

    pos = data.find(SIM7500_CMD_PS_ATTACHMENT_RESPONSE);

    if (pos != std::string::npos) {
        tmp = data.substr(pos + sizeof(SIM7500_CMD_PS_ATTACHMENT_RESPONSE));
    } else {
        return;
    }

    int state;

    sscanf(tmp.c_str(), "%d", &state);

    attachment->state = static_cast<uint8_t>(state);
}

SIM7500_HELPER void Sim7500PsAttachmentEncode(std::string *command,
                                              Sim7500CmdMotions_t motion,
                                              Sim7500PsAttachmentStates_t state = SIM7500_PS_ATTACHMENT_DETACHED)
{
    std::string tmp;

    if (command == nullptr)
        return;

    switch (motion) {
    case SIM7500_CMD_MOTION_SETUP:
        tmp = SIM7500_CMD_PS_ATTACHMENT;
        tmp.append("=");
        tmp.append(std::to_string(state));
        tmp.append("\r\n");
        break;

    case SIM7500_CMD_MOTION_INQUIRE:
        tmp = SIM7500_CMD_PS_ATTACHMENT;
        tmp.append("?\r\n");
        break;
    }

    command->assign(tmp);
}

SIM7500_HELPER void Sim7500PsAttachmentDebug(const Sim7500PsAttachment_t &attachment)
{
    SIM7500_DEBUG_PRINTF(("\n\n%s\n", SIM7500_CMD_PS_ATTACHMENT));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n"));
    SIM7500_DEBUG_PRINTF(("state :\t\t%d\n", attachment.state));
    SIM7500_DEBUG_PRINTF(("**********************************************************\n\n"));
}

}

#endif /* SIM7500_COMMAND_PS_ATTACHMENT_H */
