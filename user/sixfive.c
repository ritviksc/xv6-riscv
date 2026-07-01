#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


char buf[512];


void
sixfive(char *file)
{
	int fd = open(file,0); // read file - no need to modify
	
	int IN_NUMBER = 0;
	int IN_WORD = 0;
	int number = 0;	
	int res;

	while ((res = read(fd,buf,sizeof(buf))) > 0)
	{
		for (int i = 0; i < res; i++)
		{
			// seperator checks
			if (   buf[i] == ' '
		            || buf[i] == '-'	
			    || buf[i] == '\r' 
		            || buf[i] == '\t' 
			    || buf[i] == '\n'
			    || buf[i] == '.'
			    || buf[i] == '/'
			    || buf[i] == ',' 
			    )
			{
				if (IN_NUMBER == 1) // number check
				{
					if (number % 5 == 0 || number % 6 == 0)
					{
						fprintf(1,"%d\n", number);
						number = 0;
					
					}
				}

				IN_WORD = 0;
				IN_NUMBER = 0;
							
			} else if ((buf[i] >= '0' && buf[i] <= '9') && IN_WORD == 0)
			{
				IN_NUMBER = 1;
				number = number * 10 + (buf[i] - '0');
				
			} else // in non-digit 'word'
			{
				IN_WORD = 1;
			}

		}

	}

	// flush 	
	if (IN_NUMBER == 1)
	{
		if (number % 5 == 0 || number % 6 == 0)
                {
                        fprintf(1,"%d\n", number);
                                
                }
	}

}

int 
main(int argc,char *argv[])
{

	if (argc <= 1)
	{
		fprintf(2,"USAGE: %s <file> [file] ...\n", argv[0]);
		exit(1);
	}

	for (int i = 1; i < argc; i++)
	{
		sixfive(argv[i]);
	}

	exit(0);
	
}
