#include "atchannel.h"

static inline bool certain_command_response(const std::string data, 
                        const char *cmp1, const char *cmp2, const char *cmp3)
{
    bool result;

    if (cmp1) {
        result = (data.find(cmp1) != std::string::npos) ? true : false;
        goto Result;
    }

    if (cmp2) {
        result = (data.find(cmp2) != std::string::npos) ? true : false;
        goto Result;
    }

    if (cmp3) {
        result = (data.find(cmp3) != std::string::npos) ? true : false;
        goto Result;
    }

Result:
    return result;
}

void atchannel::command_handle(const std::string data)
{
    if (nullptr == sim7500)
        return;

    if (certain_command_response(data, SIM7500_CMD_SIGNAL_RESPONSE, nullptr, nullptr)) {
        sim7500::Sim7500SignalDecode(data, &sim7500->signal);
        sim7500::Sim7500SignalDebug(sim7500->signal);
    }

    else if (certain_command_response(data, SIM7500_CMD_INDENTIFICATION_RESPONSE, nullptr, nullptr)) {
        sim7500::Sim7500IndentificationDecode(data, &sim7500->indentification);
        sim7500::Sim7500IndentificationDebug(sim7500->indentification);
    }

    // else if (certain_command_response(data, EC20_CMD_SIM_INSERTION_STATUS_RESPONSE, nullptr, nullptr)) {
    //     ec20_sim_insertion_status_decode(data, ec20->sim_insertion_status);
    //     ec20_sim_insertion_status_debug(ec20->sim_insertion_status);
    // }

    else if (certain_command_response(data, SIM7500_CMD_CPIN_REQUIRED_RESPONSE, nullptr, nullptr)) {
        sim7500::Sim7500CpinRequiredDecode(data, &sim7500->cpin);
        sim7500::Sim7500CpinRequiredDebug(sim7500->cpin);
    }

    // else if (certain_command_response(data, EC20_CMD_PHONE_FUNCTIONAL_RESPONSE, nullptr, nullptr)) {
    //     ec20_phone_functional_decode(data, ec20->phone_functional);
    //     ec20_phone_functional_debug(ec20->phone_functional);
    // }

    // else if (certain_command_response(data, EC20_CMD_PS_ATTACHMENT_RESPONSE, nullptr, nullptr)) {
    //     ec20_ps_attachment_decode(data, ec20->ps_attachment);
    //     ec20_ps_attachment_debug(ec20->ps_attachment);
    // }

    else if (certain_command_response(data, SIM7500_CMD_4G_NETWORK_STATUS_RESPONSE, nullptr, nullptr)) {
        sim7500::Sim75004GNetworkStatusDecode(data, &sim7500->network_status_4G);
        sim7500::Sim75004GNetworkStatusDebug(sim7500->network_status_4G);
    }
}
