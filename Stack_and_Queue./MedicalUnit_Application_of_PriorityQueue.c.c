#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
    int data;
    int priority;
    struct node* next;
}node;
void push(node** head,int info,int p)
{
    node* new=(node*)malloc(sizeof(node));
    new->data=info;
    new->priority=p;
    
    node* tmp=*head;
    if (*head==NULL)
    {
        *head=new;
        (*head)->next=NULL;
        //printf("First node created\n");
    }
    else if(tmp->next==NULL)
    {
        if(tmp->priority>p)
        {
        tmp->next=new;
        new->next=NULL;
        }
        else
        {
        new->next=*head;
        *head=new;
        }
    }
    else if(tmp->priority<=p)
    {
        //printf("Executed\n");
        new->next=tmp;
        *(head)=new;
    }
    else
    {
        int flag=0;
        while(tmp->next->priority>=p && tmp->next!=NULL )
        {
            // i++;
            // if(i==1)
            // continue;
            // else
            if(tmp->next->next==NULL)
            {
                flag=1;
                break;
            }
            tmp=tmp->next;
            //printf("Executing\n");
        }
        if(!flag)
        {
        node* t=tmp->next;
        tmp->next=new;
        new->next=t;
        }
        else
        {
            node* t=tmp->next;
            t->next=new;
            new->next=NULL;
        }
        //new->next=tmp;
        // node* t=tmp;
        // tmp=new;
        // new->next=t;
        // //tmp->next=new;
        // //new->next=t;
    }
}
int pop(node** head)
{
    
    if((*head)!=NULL)
    {
        int x=(*head)->data;
    *head=(*head)->next;
    return x;
    }
    else
    return -1;
}
void main()
{
    node* n1=NULL;
    printf("press 0 to quit\n");

    int n,p;
    while(true)
    {
        printf("Enter patient number and severity index\n");
        scanf("%d",&n);
        if(n==0)
        break;
        scanf("%d",&p);
        push(&n1,n,p);
     
    }
    
    while(true)
    {
      int x=pop(&n1);
      if(x!=-1)
      printf("Attend patient number %d first\n",x);
      else
      {
      //printf("Underflow\n");
      break;
      }
    }
    // for(int i=0;i<5;i++)
    // printf("%d ",pop(&n1));
    // printf("%d\n",pop(&n1));
    // printf("%d\n",pop(&n1));
}
// push(&n1,40,4);
    // //printf("(((((((((())))))))))\n");
    // push(&n1,30,3);
    // //printf("(((())))\n");
    // push(&n1,100,5);
    // //printf("*((((()))))\n");
    // push(&n1,10000,100);
    // //printf("*****\n");
    // push(&n1,10,1);
    //printf("**(&)\n");
    //printf("%d\n",n1->data);