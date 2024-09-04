#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/shm.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#include "DataCenter.h"

DataCenter mdataCenter;

int main()
{
	int ret = 0;

    printf("============== datalink start version: V1.0.12 20231103 ===============\n");
    printf("============== datalink add 4G function ===============\n");

    mdataCenter.Start();

	while(1){
		sleep(5);
	}
	
    return 0;   
}
