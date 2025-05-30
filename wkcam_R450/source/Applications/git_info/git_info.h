#ifndef __CONF_GIT_INFO_H__
#define __CONF_GIT_INFO_H__

#include <stdio.h>

#define WK_MODEL_NAME "R450"
#define WK_CPU_NAME "3519"
#define WK_SOFT_GIT_COMMIT_ID "29626477"
#define WK_SOFT_GIT_COMMIT_TIME "2024-12-28 16:28"
#define WK_SOFT_COMPILING_TIME "2025-05-23 13:48"

static inline void wk_git_info_print()
{
	printf("\033[1;35mBuild Data %s Time %s \r\n",__DATE__,__TIME__);
	printf("\n");
	printf("\033[1;35m########################\n");
	printf("\033[1;35m######           #######\n");
	printf("\033[1;35m#    %s\033[0;39m\n",WK_MODEL_NAME);
	printf("\033[1;35m#\t%s\033[0;39m\n",WK_CPU_NAME);
	printf("\033[1;35m#\t%s\033[0;39m\n",WK_SOFT_GIT_COMMIT_ID);
	printf("\033[1;35m#    %s\033[0;39m\n",WK_SOFT_GIT_COMMIT_TIME);
	printf("\033[1;35m#    %s\033[0;39m\n",WK_SOFT_COMPILING_TIME);
	printf("\033[1;35m######           #######\n");
	printf("\033[1;35m########################\033[m\n");
	
	return;
}

#endif
