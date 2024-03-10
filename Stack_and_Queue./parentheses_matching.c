#include<stdio.h>
#include<stdlib.h>
#define max_len 500
struct node{
    char info;
    struct node* next;
};
typedef struct node node;
void push(node** top,char ch)
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
    new->info=ch;
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
    printf("%c\n",top->info);
}
void parentheses_matching(char *s)
{
    char *check=s;
    int l=0;
    while(*(check+(l++))!='\0');
    node* stack=NULL;
    char ch;
    int i=0;
    int flag=0;
    while((ch=*(s+i++))!='\0')
    {
     if(ch=='['||ch=='{'||ch=='(')
     push(&stack,ch);
     else if(ch==')')
     {
        if(pop(&stack)->info=='(')
        flag++;
     }
     else if(ch=='}')
     {
        if(pop(&stack)->info=='{')
        flag++;
     }
     else if(ch==']')
     {
        if(pop(&stack)->info=='[')
        flag++;
     }
    }
    if(flag==l/2)
    printf("Balanced\n");
    else
    printf("Not matched\n");
}
void main()
{
    /*node* stack1=NULL;
    push(&stack1,'a');
    push(&stack1,'e');
    push(&stack1,'o');
    node* t=pop(&stack1);
    printf("%c\n",t->info);
    peek(stack1);
    pop(&stack1);
    peek(stack1);
    pop(&stack1);*/
    char* s=(char*)malloc(11*sizeof(char));
    s="[{()}]{}()";
    parentheses_matching(s);
}