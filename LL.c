#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* next;
};
typedef struct node node;
node* create(int n)
{
    int i=1;
    node* head=(node*)malloc(sizeof(node));
    node* tmp1=head;
    while(n--)
    {
        //printf("Enter value: ");
        //scanf("%d",&tmp1->info);
        tmp1->info=i++;
        node* tmp2=malloc(sizeof(node));
        if(n!=0)
        tmp1->next=tmp2;
        else
        tmp1->next=NULL;
        tmp1=tmp2;
    }
    return head;
}
node* insert(node* head,int ind,int val)
{
    node* new=(node*)malloc(sizeof(node));
    new->info=val;
    if(head==NULL)
    {
        head=new;
        return head;
    }
    if(ind==1)
    {
    new->next=head;
    return new;
    }
    else
    {
        node* current=head;
        int i=1;
        while(current!=NULL)
        {
            i++;
            if(i==ind)
            break;
            current=current->next;
        }
        new->next=current->next;
        current->next=new;
        return head;
    }
}
node* insert_in_sorted(node* head,int ele)
{
    //printf("Inside function\n");
    node* tmp=head;
    while(1)
    {
      //printf("Node status %d\n",tmp->info);
      if(ele>(tmp->next)->info)
      {
      tmp=tmp->next;
      }
      else
      break;
    }
    node* new=(node*)malloc(sizeof(node));
    new->info=ele;
    node* t=tmp->next;
    tmp->next=new;
    new->next=t;
    return head;
}
node* delete(node* head,int ind)
{
   int i=1;
   node* front;
   if(head->next!=NULL)
   front=head->next;
   else
   return NULL;
   node* back=head;
   while(i!=ind && front->next!=NULL)
   {
    front=front->next;
    back=back->next;
    i++;
   }
   if(i==ind)
   {
    back->info=front->info;
    back->next=front->next;
   }
   else
   back->next=NULL;
   return head;
}
node* reverse(node* head)
{
    node* prev=NULL;
    node* next=NULL;
    node* current=head;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}
node* rotate(node* head,int ind)
{
  node* tmp=head;
  node* t=head;
  int i=1;
  while(i++!=ind && tmp!=NULL)
  {
    tmp=tmp->next;
  }
  node* tmp2=malloc(sizeof(node));
  if(tmp->next!=NULL)
  tmp2=tmp->next;
  else
  return head;
  tmp->next=NULL;
  head=tmp2;
  while(tmp2->next!=NULL)
  tmp2=tmp2->next;
  tmp2->next=t;
  return head;
}
void middle(node* head)
{
    node* slow;
    node* fast;
    slow=fast=head;
    if(head!=NULL)
    {
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        printf("Middle %d\n",slow->info);
    }
}
void print(node* head)
{
    if(head==NULL)
    printf("No node\n");
    while(head!=NULL)
    {
        printf("%d ",head->info);
        head=head->next;
    }
    printf("\n");
}
void main()
{
    /*printf("How many nodes?");
    int n;
    scanf("%d",&n);
    node* p=create(6);
    print(p);
    node* p1=insert(p,1,100);
    print(p1);
    node* p2=insert(p,6,100);
    print(p2);
    
    p=delete(p2,1);
    print(p);
    p=reverse(p);
    print(p);
    p=rotate(p,3);
    print(p);
    middle(p);*/
    node* n=NULL;
    node* p=insert(n,1,1);
    print(p);
    p=insert(p,2,2);
    print(p);
    p=insert(p,3,3);
    print(p);
    p=insert(p,4,5);
    print(p);
    //printf("%d\n",p->info);
    p=insert_in_sorted(p,4);
    print(p);
}