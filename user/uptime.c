#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int
main(int argc,char *argv[])
{
	int time = uptime();
	if (time < 0)
	{
		fprintf(2,"ERROR getting uptime\n");
		exit(1);
	
	}

	fprintf(1,"Uptime: %d ticks\n",time);
	exit(0);

}
