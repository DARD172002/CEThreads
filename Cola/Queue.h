#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node Node;
typedef struct {
    char name[10];
    int id;
} Barco;
struct Node {
    Node *next;
    void *data;
};

typedef struct {
    Node *head;
}Queue;


void agregar( void *data, Queue *queue);
void imprimir(Queue *queue);
Node *get_firt_node(Queue *queue);

#endif 