#include "atchannel.h"

int atchannel::command_indentification()
{
    std::string command;

    sim7500::Sim7500IndentificationEncode(&command);

    return sendto(command);
}

int atchannel::command_signal()
{
    std::string command;

    sim7500::Sim7500SignalEncode(&command);

    return sendto(command);
}

int atchannel::command_sim_insertion_status()
{
    std::string command;

    // ec20_sim_insertion_status_encode(command);

    // return sendto(command);
    return -1;
}

int atchannel::command_cpin_required()
{
    std::string command;

    sim7500::Sim7500CpinRequiredEncode(&command);

    return sendto(command);
}

int atchannel::command_phone_functional_set(int func)
{
    std::string command;

    return -1;
}

int atchannel::command_phone_functional_get()
{
    std::string command;

    return -1;
}

int atchannel::command_ps_attachment_set(int state)
{
    std::string command;

    return -1;
}

int atchannel::command_ps_attachment_get()
{
    return -1;
}

int atchannel::command_network_status()
{
    std::string command;

    sim7500::Sim75004GNetworkStatusEncode(&command);

    return sendto(command);
}

int atchannel::command_set_dialmode()
{
    std::string command;
    std::string tmp;

    tmp = "AT$QCRMCALL=1,1";
    tmp.append("\r\n");

    command.assign(tmp);

    return sendto(command);
}

int atchannel::command_set_disconnect()
{
    std::string command;
    std::string tmp;

    tmp = "AT$QCRMCALL=0,1";
    tmp.append("\r\n");

    command.assign(tmp);

    return sendto(command);
}
