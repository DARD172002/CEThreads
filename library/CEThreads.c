
#define _GNU_SOURCE
#include "CEThreads.h"
#include <stdlib.h>
#include <stdio.h>
#include <sched.h> //contained the clone function
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>


int CEThread_create(CEThread *thread, void * (*start_routine)(void *) ,void *arg){
    void *stack=malloc(PTHREAD_STACK_SIZE);
    if(!stack){
        perror("Failed to allocate stack");
        return -1;
    }
    thread->stack=stack;
    thread->state=RUNNING;
    //created a new thread using clone();
    int flags = CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND;// this parameter is necesary to create the thread

    
    thread->id= clone((int(*)(void *))start_routine,stack+PTHREAD_STACK_SIZE,flags,arg);
    if(thread->id<0){
        perror("clone file");
        free(stack);
        return -1;
    }
    return 0;

}


// this function free space of stack memory
void CEThread_end(void *retval){
    free(retval); //free stack memory
    _exit(0); // code to terminate thread
}



int CEThread_join(CEThread thread){
        int status;
        waitpid(thread.id,&status,0); //wait for thread is finish
        free(thread.stack);// when the thread is in status FINISH free stack
        return status;

}




void CEmutex_init(CEmutex *mutext){
    mutext->locked=0;
}

void CEmutex_destroy(CEmutex *mutext){
    free(mutext);
};

void CEmutex_unlock(CEmutex *mutext){
    atomic_store(&mutext->locked,0);
}





