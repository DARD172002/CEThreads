#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include "../library/CEThreads.h"
//FUNCTION TO EXECUTE
void *test_function(void *arg){
    int *num=(int *) arg;
    *num+= 1;
    return NULL;
}


void test_thread_created(){
    CEThread thread;
    int value=0;
    int result=CEThread_create(&thread,test_function,&value);
    assert(result==0);
    printf("✅ CEThread_create test passed!\n");
}


int main() {
    test_thread_created();
    //test_thread_join();
    //test_mutex();
    
    printf("🎉 All tests passed successfully!\n");
    return 0;
}