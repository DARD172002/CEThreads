#ifndef  CE_Thread_H
#define  CE_Thread_H
#include <setjmp.h>  // to store execution context
#include <ucontext.h>
#define STACK_SIZE 8192


typedef enum {
    READY,
    RUNNING,
    BLOCKED,
    TERMINATED
} State;

typedef struct  {
   int id;
   ucontext_t context;
   State state;    
   void *stack;
   void (*func)(void *); 
   void *arg;

} CE_Thread;

int CE_Thread_create(CE_Thread *thread,void (*func)(void *), void *arg);
void CE_Thread_start_wrapper(CE_Thread *thread);

#endif