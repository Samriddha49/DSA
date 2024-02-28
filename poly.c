#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coef;
    int expo;
    struct node* next;
};
typedef struct node node;
void insert(node** poly,int coef,int expo)
{
    node* tmp=(node*)malloc(sizeof(node));
    tmp->coef=coef;
    tmp->expo=expo;
    tmp->next=NULL;
    if(*poly==NULL)
    {
        *poly=tmp;
        return;
    }
    
    node* current=*poly;
    while(current->next!=NULL)
    current=current->next;
    current->next=tmp;
    
}
void display(node* poly)
{
    if(poly==NULL)
    {
    printf("Empty!\n");
    return;
    }
    node* tmp=poly;
    while(tmp!=NULL)
    {
        if(tmp->next!=NULL)
        printf("%dx%d+",tmp->coef,tmp->expo);
        else
        printf("%dx%d",tmp->coef,tmp->expo);
        tmp=tmp->next;
    }
    printf("\n");
}
node* add(node* poly1,node* poly2)
{
    node* result=NULL;
    if(poly1==NULL && poly2==NULL)
    return NULL;
    else if(poly1==NULL)
    return poly2;
    else if(poly2==NULL)
    return poly1;
    while(poly1!=NULL && poly2!=NULL)
    {
        if(poly1->expo==poly2->expo)
        {
            insert(&result,poly1->coef+poly2->coef,poly1->expo);
            poly1=poly1->next;
            poly2=poly2->next;
        }
        else if(poly1->expo<poly2->expo)
        {
            insert(&result,poly1->coef,poly1->expo);
            poly1=poly1->next;
        }
        else if(poly2->expo<poly1->expo)
        {
            insert(&result,poly2->coef,poly2->expo);
            poly2=poly2->next;
        }
    }
    while(poly1!=NULL)
    {
        insert(&result,poly1->coef,poly1->expo);
        poly1=poly1->next;
    }
    while(poly2!=NULL)
    {
        insert(&result,poly2->coef,poly2->expo);
        poly2=poly2->next;
    }
    return result;
}
node* multiply(node* poly1,node* poly2)
{
    node* a=NULL;
    node* tmp=poly2;
    int c=0;
    while(tmp!=NULL)
    {
      c++;
      tmp=tmp->next;
    }
    node* t1=poly1;
    while(t1!=NULL)
      {
        node* t2=poly2;
        node* t=(node*)malloc(sizeof(node));
        int count=c;
        while(count--)
        {
        insert(&t,t1->coef*t2->coef,t1->expo+t2->expo);
        t2=t2->next;
        }
      a=add(a,t);
      a=a->next;
      t1=t1->next;
    }
   return a;
}
void main()
{
    node* p1=NULL;
    insert(&p1,2,2);
    insert(&p1,3,3);
    insert(&p1,4,4);
    insert(&p1,8,8);
    display(p1);
    node* p2=NULL;
    insert(&p2,3,3);
    insert(&p2,8,4);
    insert(&p2,7,7);
    display(p2);
    node* res=add(p1,p2);
    display(res);
    node* r=multiply(p1,p2);
    display(r);
}