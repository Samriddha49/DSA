#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<stdbool.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

Queue Q1,Q2;
void initQueue(Queue *q);
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);


void push(int);
int pop();
int check(Queue* q)
{
    if(q->front!=NULL && q->rear!=NULL && q->front==q->rear)
    return 1;
    else 
    return 0;
}
void push(int ch)
{
   enqueue(&Q1,ch);
}
int pop()
{
   if(isEmptyQueue(&Q1)==0)
   initQueue(&Q2);
   while(!isEmptyQueue(&Q1))
   {
    if(check(&Q1))
    {
        return dequeue(&Q1);
    }
    else
    {
        //printf("Enqueueing\n");
    enqueue(&Q2,dequeue(&Q1));
    }
   }
   //printf("Yay!\n");
   //printf("%d\n",isEmptyQueue(&Q2));
   if(isEmptyQueue(&Q2)==0)
   initQueue(&Q1);
   while(!isEmptyQueue(&Q2))
   {
    if(check(&Q2))
    {
        return dequeue(&Q2);
    }
    else
    enqueue(&Q1,dequeue(&Q2));
   }
   //printf("Yayy!\n");
}
void main()
{
    int x;
    int c=0;
    initQueue(&Q1);
    printf("Pushing\n");
    while(true)
    {
        scanf("%d",&x);
        if(x==0)
        break;
        push(x);
        //printf("Pushed x\n");
        c++;
    }
    printf("Popping\n");
    while(c-->0)
    {
        printf("%d\n",pop());
        //printf("%d\n",isEmptyQueue(&Q2));
    }
    // printf("popped %d\n",pop());
    // printf("Q1 empty or not %d\n",isEmptyQueue(&Q1));
    // printf("Q2 empty or not %d\n",isEmptyQueue(&Q2));
    // printf("Popped %d\n",pop());
}
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}


int isEmptyQueue(Queue *q) {
    return q->front == NULL;
}


void enqueue(Queue *q, int data) {
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmptyQueue(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}


int dequeue(Queue *q) 
{
    if (isEmptyQueue(q))
    {
        printf("Queue underflow\n");
        return -1; 
    }
   int data = q->front->data;
   Node *temp = q->front;
   q->front = q->front->next;
   if (q->front == NULL)
    {
        q->rear = NULL;
    }
   free(temp);
   return data;
}
