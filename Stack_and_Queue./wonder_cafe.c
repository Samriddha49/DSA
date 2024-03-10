#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100 // Define the maximum size

//int stk[MAX_SIZE];
int q[MAX_SIZE];
int top = -1; // Stack top pointer

int front = -1, rear = -1; // Queue front and rear pointers

// Function prototypes for stack operations
int isEmptyStack(int*);
int isFullStack(int*);
void push(int*,int data);
int pop(int*);

// Function prototypes for queue operations
int isEmptyQueue();
int isFullQueue();
void enqueue(int data);
int dequeue();

int main() {
    printf("Press 0 to stop\n");
    int token_no;
    //scanf("%d",&token_no);
    int c=0;
    while(1)
    {
      scanf("%d",&token_no);
      if(token_no==0)
      break;
      else
      enqueue(token_no);
      c++;
    }
    int* token_stack=(int*)malloc(c*sizeof(int));
    int* order_stack=(int*)malloc(c*sizeof(int));
    int i=0;
    
    while(i++<c)
    {
      push(token_stack,dequeue());
    }
    //printf("%d value of c\n",c);
    // push(order_stack,1);
    // push(order_stack,2);
    // push(order_stack,3);
    // printf("%d\n",pop(order_stack));
    // printf("%d\n",pop(order_stack));
    // printf("%d\n",pop(order_stack));
    // printf("%d\n",pop(order_stack));
    // printf("%d\n",pop(order_stack));
    for(int j=0;j<c;j++)
    {
      //printf("%d ",pop(token_stack));
      order_stack[j]=pop(token_stack);
    }
    //top=0;
    i=c-1;
    while(i>=0)
    {
      printf("Order number %d is ready\n",order_stack[i--]);
    }
    return 0;
}

// Stack functions
int isEmptyStack(int* stk) {
    return top == -1;
}

int isFullStack(int* stk) {
    return top == MAX_SIZE - 1;
}

void push(int* stk,int data) {
    if (isFullStack(stk)) {
        printf("Stack overflow\n");
        return;
    }
    stk[++top] = data;
}

int pop(int *stk) {
    if (isEmptyStack(stk)) {
        printf("Stack underflow\n");
        return -1;
    }
    return stk[top--];
}

// Queue functions
int isEmptyQueue() {
    return front == -1 || front > rear; // Handle empty and full queue conditions
}

int isFullQueue() {
    return (rear + 1) % MAX_SIZE == front; // Circular queue logic
}

void enqueue(int data) {
    if (isFullQueue()) {
        printf("Queue overflow\n");
        return;
    }
    if (isEmptyQueue()) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    q[rear] = data;
}

int dequeue() {
    if (isEmptyQueue()) {
        printf("Queue underflow\n");
        return -1;
    }
    int data = q[front];
    if (front == rear) {
        front = rear = -1; // Reset queue if only one element
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return data;
}
