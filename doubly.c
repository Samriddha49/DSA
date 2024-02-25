#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int info;
    struct node* next;
};
typedef struct node node;
node* create(int n)
{
    int i=1;
    node* head=(node*)malloc(sizeof(node));
    node* tmp1=head;
    tmp1->prev=NULL;
    while(n--)
    {
      tmp1->info=i++;
      node* tmp2=malloc(sizeof(node));
      if(n!=0)
      tmp1->next=tmp2;
      else
      tmp1->next=NULL;
      tmp2->prev=tmp1;
      tmp1=tmp2;
    }
    return head;
}
node* insert(node* head,int ind,int val)
{
    node* new=malloc(sizeof(node));
    new->info=val;
    if(ind==1)
    {
        new->next=head;
        new->prev=NULL;
        return new;
    }
    else
    {
        node* tmp=head;
        int i=2;
        while(i!=ind && tmp!=NULL)
        {
           i++;
           tmp=tmp->next;
        }
        if(tmp->next!=NULL)
        new->next=tmp->next;
        else
        new->next=NULL;
        tmp->next=new;
    }
    return head;
}
node* delete(node* head,int ind)
{
    if(ind==1)
    {
        if(head->next==NULL)
        return NULL;
        else
        return head->next;
    }
    else
    {
        int i=2;
        node* tmp=head;
        while(i++!=ind && tmp!=NULL)
        {
           tmp=tmp->next;
        }
        if(tmp->next!=NULL)
        {
        tmp->next=tmp->next->next;
        }
        else
        tmp=NULL;
    return head;
    }
}
void reverse(node* head)
{
    //printf("reversing");
    node* tmp=head;
    while(tmp->next!=NULL)
    {
      tmp=tmp->next;
    }
    while(tmp!=NULL)
    {
    printf("%d ",tmp->info);
    tmp=tmp->prev;
    }
}
void print(node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->info);
        head=head->next;
    }
    printf("\n");
}
void main()
{
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    node* t=create(n);
    print(t);
    t=insert(t,6,100);
    print(t);
    t=delete(t,6);
    print(t);
    reverse(t);
}