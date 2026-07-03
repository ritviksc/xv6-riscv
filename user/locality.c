#include "kernel/types.h"
#include "user/user.h"

int main(){
    for(int i = 0; i < 5; i++){
        fork();
    }
    // lots of processes competing for harts
    for(;;)
        ;  // busy loop
    exit(0);
}
