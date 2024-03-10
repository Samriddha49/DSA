#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct {
    Node *top;
} Stack;


typedef struct {
    Node *front, *rear;
} Queue;


void initStack(Stack *s);
int isEmptyStack(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);


void initQueue(Queue *q);
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);

int main()
{
    Stack token;
    Stack order;
    Queue customer_q;

    initStack(&token);
    initStack(&order);
    initQueue(&customer_q);
    /*Method 1
    printf("Press 0 to quit\n");
    int t_n;
    int c=0;
    while(1)
    {
      scanf("%d",&t_n);
      if(t_n==0)
      break;
      else
      {
      enqueue(&customer_q,t_n);
      c++;
      }
    }
    int i=0;
    while(i++<c)
    {
        push(&token,dequeue(&customer_q));
    }
    i=0;
    while(i++<c)
    {
        push(&order,pop(&token));
    } 
    while(c--)
    printf("Order %d is ready\n",pop(&order));
    */
    //Method 2 Dyanmic approach
    printf("Press 0 to quit\n");
    int t_n;
    int c=0;
    while(1)
    {
      printf("Enter number: ");
      scanf("%d",&t_n);
      if(t_n==0)
      break;
      else
      {
      enqueue(&customer_q,t_n);
      push(&order,dequeue(&customer_q));
      push(&token,pop(&order));
      c++;
      }
    }
    int i=0;
    while(i++<c)
    {
        push(&order,pop(&token));
    }
    
    while(c--)
    {
        printf("Preparing food...\n");
        sleep(3);
        printf("Order %d is ready\n",pop(&order));
    }
    printf("Thankyou! Visit Again!!\n");
    return 0;
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


int dequeue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("Queue underflow\n");
        return -1; 
    }

    
    int data = q->front->data;

    
    Node *temp = q->front;
    q->front = q->front->next;

    
    if (q->front == NULL) {
        q->rear = NULL;
    }

    
    free(temp);

    return data;
}

void initStack(Stack *s) {
    s->top = NULL;
}


int isEmptyStack(Stack *s) {
    return s->top == NULL;
}


void push(Stack *s, int data) {
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;

    
    s->top = newNode;
}


int pop(Stack *s) {
    if (isEmptyStack(s)) {
        printf("Stack underflow\n");
        return -1; 
    }

    
    int data = s->top->data;

    
    Node *temp = s->top;
    s->top = s->top->next;

    
    free(temp);

    return data;
}