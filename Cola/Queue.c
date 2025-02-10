#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

void agregar(int data, Queue *queue){
//create a new node
 Node *newNode= malloc(sizeof(Node));
 //data fulling the data node
 newNode->data=data;
 if(queue->head==NULL){
   
    queue->head=newNode;
    newNode->next=NULL;    
 }
 else{
    Node *aux=queue->head;
   
    while(aux!=NULL){
    if(aux->next==NULL){
      
       aux->next=newNode;
       break;
    }
    else{
        aux=aux->next;
    }
    
 }
}}


void imprimir(Queue *queue){
    Node *aux=queue->head;
    while(aux!=NULL){
        printf(" \n valor %d", aux->data);
        aux=aux->next;
    }
}

int main(){
    
    Queue queue;
    queue.head=NULL;
    agregar(5,&queue);
    agregar(7,&queue);
    agregar(9,&queue);
    imprimir(&queue);

    return 0;
}


