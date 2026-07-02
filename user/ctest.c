// simple test program
#include "kernel/types.h"
#include "user/user.h"
int main(){
    char c;
    while(read(0, &c, 1) > 0){
        printf("got: %d\n", (int)c);
    }
    exit(0);
}
