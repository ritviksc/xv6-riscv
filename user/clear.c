#include "kernel/types.h"
#include "user/user.h"

int 
main()
{
    printf("\033[2J\033[H");  // clear screen, move cursor to top
    exit(0);
}
