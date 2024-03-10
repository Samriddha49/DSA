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
void main()
{
    printf("Enter expression ");
    char* exp=(char*)malloc(sizeof(char));
    //gets(exp);
    int c=0;
    while((exp[c++]=getchar())!='\n')
    {
        exp=realloc(exp,c*sizeof(char));
    }
    
    //exp="6/3*2+5-7";
    printf("Expression provided %s\n",exp);
    char* postfix=(char*)malloc((strlen(exp)+1)*sizeof(char));
    int i=0,j=0;
    node* stack=NULL;
    
    while(exp[i]!='\0')
    {
        if(!isdigit(exp[i]))
        {
            if(isempty(stack))
            {
                push(&stack,exp[i]);
            }
            else if((peek(stack)=='/' && exp[i]=='*') || (peek(stack)=='*' && exp[i]=='/') || 
            (peek(stack)=='+' && exp[i]=='-') || (peek(stack)=='-' && exp[i]=='+') )
            {
              postfix[j++]=pop(&stack)->info;
              push(&stack,exp[i]);
            }
            else if((peek(stack)=='*' || peek(stack)=='/') && (exp[i]=='+'||exp[i]=='-'))
            {
                while(!isempty(stack))
                {
                    postfix[j++]=pop(&stack)->info;
                }
                push(&stack,exp[i]);
            }
            else
            {
                push(&stack,exp[i]);
            }
        }
        else
        {
         postfix[j++]=exp[i];
        }
        i++;
    }
    
    while(!isempty(stack))
    {
      postfix[j++]=pop(&stack)->info;
    }
   
    puts(postfix);
}
/*
char* arr=(char*)malloc(i*sizeof(char));
              int k=0,tmp=j;
              while(!isempty(stack))
               {
                 arr[k++]=pop(&stack)->info;
                 j++;
               }               
               int t=0;
               int c=j-1;
               while(c>=tmp)
               {
                postfix[c]=arr[t];
                c--;t++;
               }
               */