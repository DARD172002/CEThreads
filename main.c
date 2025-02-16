#include <stdlib.h>
#include <stdio.h>
#include "library/CEThreads.h"


void *thread_fuction(void *number){
    printf("the number is %d \n", *(int *)number);
    return NULL;
}
int main(){
    CEThread thread;
    int number=9;
    CEThread_create(&thread,&thread_fuction,NULL);
    printf("todo bien de verdad");
    return 0;
}