#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node Node;
struct Node {
    Node *next;
    int data;
};

typedef struct {
    Node *head;
}Queue;


void agregar(int data, Queue *queue);
void imprimir(Queue *queue);

#endif 