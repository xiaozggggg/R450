#ifndef _MOBILECC_H_
#define _MOBILECC_H_

#include "atchannel.h"
#include "mobilecc_toochain.h"

class mobilecc
{
private:
    atchannel atchn;
    std::thread mobilethread;
    bool run_state;
    bool _isexist;

    enum {
        MOBILECC_STEUP_IDLE = 0,
        MOBILECC_STEUP_ATCHANNEL_CHECK,
        MOBILECC_STEUP_DIALPROCS_CHECK,
        MOBILECC_STEUP_DIALPROCS_HOLDON
    } mobile_setup;

    void setpup_handler();

public:
    mobilecc(/* args */);
    ~mobilecc();

    void start();
    void stop();
    bool online();
    shm_4Gmodule_t *get_4Gmobide_status();
};

#endif
