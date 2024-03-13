#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<stdbool.h>
typedef struct Node {
    int data;
    struct Node *next;
} Node;


typedef struct {
    Node *top;
} Stack;

Stack stk1,stk2;

void initStack(Stack *s);
int isEmptyStack(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s);

void enqueue(int item)
{
   push(&stk1,item);
}
int dequeue()
{
    while(!isEmptyStack(&stk1))
    push(&stk2,pop(&stk1));
    return pop(&stk2);
}
void main()
{
    int ch;
    printf("Enter 0 to exit\n");
    initStack(&stk1);
    int c=0;
    while(true)
    {
        scanf("%d",&ch);
        if(ch==0)
        break;
        else
        {
            enqueue(ch);
            c++;
        }
    }
    initStack(&stk2);
    while(c--)
    {
        printf("dequeued %d\n",dequeue());
    }
}
void initStack(Stack *s)
{
    s->top = NULL;
}
int isEmptyStack(Stack *s)
{
    return s->top == NULL;
}
void push(Stack *s, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}
int pop(Stack *s)
{
    if (isEmptyStack(s))
    {
        printf("Stack underflow\n");
        return -1; 
    }
    int data = s->top->data;
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}