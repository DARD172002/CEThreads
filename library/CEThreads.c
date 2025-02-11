
#define _GNU_SOURCE
#include "CEThreads.h"
#include <stdlib.h>
#include <stdio.h>
#include <sched.h> //contained the clone function

int CEThread_create(CEThread *thread, void * (*start_routine)(void *) ,void *arg){
    void *stack=malloc(PTHREAD_STACK_SIZE);
    if(!stack){
        perror("Failed to allocate stack");
        return -1;
    }
    thread->stack=stack;
    thread->state=RUNNING;
    //created a new thread using clone();
    int flags = CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND;
    
    thread->id= clone((int*)start_routine,stack+PTHREAD_STACK_SIZE,flags,arg);
    if(thread->id<0){
        perror("clone file");
        return -1;
    }
    return thread->id;
}


