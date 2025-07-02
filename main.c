#include <stdlib.h>
#include <stdio.h>




int sum(int a, int b){
    int result=a+b;
    return result;
}
int main(){
    int a=4;
    int b=5;
    printf("el resultado es  %d now", sum(a,b));
    return 0;
}