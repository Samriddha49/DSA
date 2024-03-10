#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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
char peek(node* top)
{
    if(top==NULL)
    {
    printf("Nothing to show, stack is empty\n");  
    return;
    }
    else
    {
    //printf("%d\n",top->info);
    return top->info;
    }
}
int isempty(node *top)
{
    if(top==NULL)
    return 1;
    else
    return 0;
}
//will work for single digit integers only...if 153/2 would read 1 5 3 not 15 and 3
void main()
{
    char* exp=(char*)malloc(1*sizeof(char));
    //gets(exp);
    exp="153/2*5+7-";
    int i=0;
    node* stack=NULL;
    //push(&stack,exp[i]);
    while(exp[i]!='\0')
    {
        //printf("character %c\n",exp[i]);
        if(isdigit(exp[i]))
        {
         push(&stack,exp[i]);
        }
        else
        {
            int op1=pop(&stack)->info-'0';
            int op2=pop(&stack)->info-'0';
            printf("%d %c %d\n",op1,exp[i],op2);
            char ch=exp[i];
            //int r=0;
            switch(ch)
            {
                case '+':push(&stack,op1+op2+48);
                          break;
                case '-': push(&stack,op2-op1+48);
                          break;
                case '*': push(&stack,(op2*op1)+48);
                          break;
                case '/': push(&stack,(op2/op1)+48);
                          break;
            }
        }
        i++;
    }
    printf("%d\n",(pop(&stack)->info)-'0');
}