#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
	if (argc <= 1 || argc > 2)
	{
		fprintf(2,"USAGE: %s <ticks>\n",argv[0]);
		exit(1);
	}

	// Validate input
	for(int i = 0; argv[1][i] != '\0'; i++)
	{
    		if(argv[1][i] < '0' || argv[1][i] > '9')
		{
        		fprintf(2,"ERROR: invalid number\n");
        		exit(1);
    		}
	}

	int ticks = atoi(argv[1]);
	if (ticks < 0)
	{
    		fprintf(2, "ERROR: ticks must be a positive number\n");
    		exit(1);
	}
	// End of validation checks

	int res = pause(ticks);
	if (res < 0) // syscall failed
	{
		fprintf(2,"ERROR sleeping\n");
		exit(1);
	}

	exit(0);


}
