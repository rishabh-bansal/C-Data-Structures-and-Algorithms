// LinkedList implementation of queue
#include<stdio.h>
#include<stdlib.h>
// A LinkedList node to store queue entry
typedef struct Node{
    int key;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *front;
    Node *rear;
} Queue;

// Function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to create new node with key k
Node *newNode(int k){
    Node *n = (Node*) malloc(sizeof(Node));
    n->key = k;
    return n;
}

// Function to add key k to the q
void enqueue(Queue *q,int k){
    Node *node = newNode(k);
    // if q is empty then node is front and read both
    if(q->rear == NULL){
        q->front = q->rear = node;
        return ;
    }
    // add node to end of the q
    q->rear->next = node;
    // update q rear pointer
    q->rear = node;
}

Node *dequeue(Queue *q){
    // If queue is emoty return NULL
    if(q->front == NULL) return NULL;
    // Store the node at front & update the front pointer to next node
    Node *temp = q->front;
    q->front = q->front->next;
    // if front is NULL the q is empty so update rear pointer to NULL
    if(q->front == NULL){
        q->rear = NULL;
    }
    return temp;
}

// Main function 
int main(){
    
    Queue *q = createQueue(); 
    enqueue(q,10); // rear -> 10 <- front
    enqueue(q,20); // rear -> 20 10 <- front
    enqueue(q,30); // rear -> 30 20 10 <- front
    dequeue(q); // rear -> 30 20 10 <- front
    printf("%d\n",q->front->key); // prints 20
    dequeue(q); // rear -> 30 <- front
    printf("%d\n",q->front->key); // prints 30
    
    return 0;
}