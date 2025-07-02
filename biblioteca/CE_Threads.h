#ifndef  CE_Thread_H
#define  CE_Thread_H
#include <setjmp.h>  // to store execution context
#define STACK_SIZE 8192


typedef enum {
    READY,
    RUNNING,
    BLOCKED,
    TERMINATED
} State;

typedef struct  {
   int id;
   jmp_buf context;
   State state;    
   void *stack;
   void (*func)(void *); 
   void *arg;

} CE_Thread;

#endif