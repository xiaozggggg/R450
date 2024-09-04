#ifndef _4GMODULE_PARAS_H_
#define _4GMODULE_PARAS_H_

#include "SIM7500/common.h"

typedef struct shm_4Gmodule {
    sim7500::Sim7500Indentification_t indentification;
    sim7500::Sim75004GNetworkStatus_t network_status_4G;
    sim7500::Sim7500NetworkStatus_t network_status;
    sim7500::Sim7500NetworkMode_t network_mode;
    sim7500::Sim7500CpinRequired_t cpin;
    sim7500::Sim7500PsAttachment_t ps_attachment;
    sim7500::Sim7500Signal_t signal;
} shm_4Gmodule_t;

shm_4Gmodule_t *get_shm_4Gmodule(void);
void release_shm_4Gmodule(shm_4Gmodule_t *shm);

typedef enum sim7500_para_id {
    SIM7500_ID_INDENTIFICATION = 0,
    SIM7500_ID_NETWORK_STATUS_4G,
    SIM7500_ID_NETWORK_STATUS,
    SIM7500_ID_NETWORK_MODE,
    SIM7500_ID_CPIN,
    SIM7500_ID_ATTACHMENT,
    SIM7500_ID_SIGNAL
} sim7500_para_id_t;

#endif
