#include<stdio.h>
#include<stdlib.h>
#define max_len 500
struct node{
    void* info;
    struct node* next;
};
typedef struct node node;
void push(node** top,int n)
{
    node* tmp=*top;
    int c=0;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        c++;
    }
    if(c==max_len)
    {
        printf("Overflow\n");
        return;
    }
    node* new=(node*)malloc(sizeof(node));
    new->info=n;
    if(*top==NULL)
    {
        *top=new;
        (*top)->next=NULL;
    }
    else
    {
        new->next=*top;
        *top=new;
    }
}
node* pop(node** top)
{
    if(*top==NULL)
    {
        printf("Underflow\n");
        return NULL;
    }
    else
    {
    //printf("%d\n",(*top)->info);
    node* tmp=*top;
    *top=(*top)->next;
    return tmp;
    }
}
void peek(node* top)
{
    if(top==NULL)
    printf("Nothing to show, stack is empty\n");  
    else
    printf("%d\n",top->info);
}

void main()
{
    node* stack1=NULL;
    push(&stack1,3);
    push(&stack1,4);
    push(&stack1,5);
    node* t=pop(&stack1);
    printf("%d\n",t->info);
    peek(stack1);
    pop(&stack1);
    peek(stack1);
    pop(&stack1);
}