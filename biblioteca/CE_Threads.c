#include <stdlib.h>
#include <stdio.h>
#include "CE_Threads.h"
int contador=0;

void CE_Thread_start_wrapper(CE_Thread *thread) {
    thread->func(thread->arg);
    thread->state = TERMINATED;
    return ;
    // Maybe yield to scheduler here
}

int CE_Thread_create(CE_Thread *thread,void (*func)(void *), void *arg){
    contador++;
    thread->id=contador;
    thread->state=READY;
    thread->func=func;
    thread->arg=arg;
    thread->stack=malloc(STACK_SIZE);
    if(!thread->stack) return -1;
    if (getcontext(&thread->context) == -1) return -1;
    thread->context.uc_stack.ss_sp = thread->stack;
    thread->context.uc_stack.ss_size = STACK_SIZE;
    thread->context.uc_stack.ss_flags = 0;
    thread->context.uc_link = NULL; 
    makecontext(&thread->context,(void(*)())CE_Thread_start_wrapper,1,thread);
    return thread->id;
} 


void CE_Thread_join(CE_Thread thread){
    while(thread.state!=TERMINATED){
        
    }
}






