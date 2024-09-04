#ifndef SIM7500_BASIC_H_
#define SIM7500_BASIC_H_

#include <iostream>
#include <sstream>
#include <string>

extern "C"{
    #include <stdio.h>
    #include <string.h>
};

namespace sim7500 {

#define SIM7500_HELPER static inline

#define SIM7500_Debug_message 0

#if SIM7500_Debug_message
    #define SIM7500_DEBUG_PRINTF(x)  printf x
#else
    #define SIM7500_DEBUG_PRINTF(x) 
#endif

typedef enum Sim7500CmdMotions {
    SIM7500_CMD_MOTION_SETUP = 0,
    SIM7500_CMD_MOTION_INQUIRE = 1,
} Sim7500CmdMotions_t;

}

#endif /* SIM7500_BASIC_H_ */
