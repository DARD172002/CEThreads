
#ifndef CETHREAD_H
#define CETHREAD_H

#include <ucontext.h>
#include <stdatomic.h>

//Prototype



#define PTHREAD_STACK_SIZE 500

typedef struct{
   atomic_int locked; 
}CEmutex;



typedef enum{
    RUNNING,
    FINISHED,
    DETACHED,

} state_thread;


typedef struct{
    int stack_size;
    int * stack_add;
}CEThread_att_t;

typedef struct {

    int id; // id of thread
    state_thread state; //state of thread
    void *stack; //stack memory of this thread
    ucontext_t context; //context of thread

} CEThread;


int CEThread_create(CEThread *thread, void * (*start_routine)(void *) ,void *arg);


void  CEThread_end(void *retval);


int CEThread_join(CEThread thread);



void CEmutex_init(CEmutex *mutext);

void CEmutex_destroy();

void CEmutex_unlock(CEmutex *mutext);

#endif