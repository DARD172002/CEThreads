#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

void agregar(void *data,Queue *queue){
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

Node *get_firt_node(Queue *queue){
    return  queue->head;
}
void imprimir(Queue *queue){
    Node *aux=queue->head;
    while(aux!=NULL){
        printf(" \n valor %p",aux->data);
        aux=aux->next;
    }
}

/*int main(){
    
    Queue queue;
    queue.head=NULL;
    Barco barco1;
    Barco barco2;
    Barco barco3;
    barco1.id=1;
    barco2.id=2;
    barco3.id=3;
    agregar((void *)&barco1,&queue);
    agregar((void*)&barco2,&queue);
    agregar((void *)&barco3,&queue);
    //imprimir(&queue);
    Node *aux=get_firt_node(&queue);

    //(Barco *)aux->data;
    printf("this the id %d",((Barco *)aux->data)->id);


    return 0;
}*/


