#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<stdbool.h>
#include<string.h>
typedef struct Node {
    char* data;
    struct Node *next;
} Node;

typedef struct {
    Node *front, *rear;
} Queue;

void initQueue(Queue *q);
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, char* data);
char* dequeue(Queue *q);

// Follow the given steps to solve the problem:

// Create an empty queue of strings 
// Enqueue the first binary number “1” to the queue. 
// Now run a loop for generating and printing n binary numbers. 
// Dequeue and Print the front of queue. 
// Append “0” at the end of front item and enqueue it. 
// Append “1” at the end of front item and enqueue it.
void main()
{
    Queue Q;
    initQueue(&Q);
    char* item="1";
    enqueue(&Q,item);
    printf("Enqueuing first item\n");
    //printf("%s",dequeue(&Q));
    int n;
    scanf("%d",&n);
    int i=1;
    //char* tmp=malloc(i*sizeof(char));
    while(n--)
    {
       char* tmp=dequeue(&Q);
       char* tmp_=tmp;
       //printf("%s\n",tmp);
    //    int j=0;
    //    while(tmp[j]!='\0')
    //    printf("%c",tmp[j++]);
    //    printf("\n");
       puts(tmp);
    //    tmp=realloc(tmp,(i++)*(sizeof(char)));
    //    tmp[i-1]='0';
       strcat(tmp,"0");
       enqueue(&Q,tmp);
       printf("0 enqueued\n");
       strcat(tmp_,"1");
       //tmp[i-1]='1';
       enqueue(&Q,tmp_);
       printf("1 enqueued\n");
    }
}
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmptyQueue(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, char* data) {
    
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


char* dequeue(Queue *q) 
{
    if (isEmptyQueue(q))
    {
        printf("Queue underflow\n");
        return; 
    }
   char* data = q->front->data;
   Node *temp = q->front;
   q->front = q->front->next;
   if (q->front == NULL)
    {
        q->rear = NULL;
    }
   free(temp);
   return data;
}