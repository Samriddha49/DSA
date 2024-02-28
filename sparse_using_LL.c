#include<stdio.h>
#include<stdlib.h>
struct node{
    int ele;
    int i;
    int j;
    struct node* next;
};
typedef struct node node;
node* append(node** head,int ele,int row,int col)
{
    node* new=(node*)malloc(sizeof(node));
    new->ele=ele;
    new->i=row;
    new->j=col;
    new->next=NULL;
    if(*head==NULL)
    {
    *head=new;
    }
    else
    {
        node* current=*head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=new;
    }
}
node* add(node* head1,node* head2)
{
    node* add=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->i == head2->i && head1->j==head2->j)
        {
            append(&add,head1->ele+head2->ele,head1->i,head1->j);
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->i==head2->i)
        {
            if(head1->j<head2->j)
            {
            append(&add,head1->ele,head1->i,head1->j);
            head1=head1->next;
            }
            else
            {
                append(&add,head2->ele,head2->i,head2->j);
                head2=head2->next;
            }
        }
        else if(head1->j==head2->j)
        {
            if(head1->i<head2->i)
            {
                append(&add,head1->ele,head1->i,head1->j);
                head1=head1->next;
            }
            else{
                append(&add,head2->ele,head2->i,head2->j);
                head2=head2->next;
            }
        }
    }
    while(head1!=NULL)
    {
        append(&add,head1->ele,head1->i,head1->j);
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        append(&add,head2->ele,head2->i,head2->j);
        head2=head2->next;
    }
    return add;
}
void display(node* head)
{
    node* tmp=head;
    while(tmp!=NULL)
    {
        printf("%d %d %d\n",tmp->ele, tmp->i, tmp->j);
        tmp=tmp->next;
    }
}
void main()
{
    int M1[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        scanf("%d",&M1[i][j]);
    }
    int M2[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        scanf("%d",&M2[i][j]);
    }
    node* sp1=NULL;
    node* sp2=NULL;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
        if(M1[i][j]!=0)
        append(&sp1,M1[i][j],i,j);
        if(M2[i][j]!=0)
        append(&sp2,M2[i][j],i,j);
        }
    }
    printf("Printing 1st sparse matrix in coordinate form\n");
    display(sp1);
    printf("Printing 2nd sparse matrix in coordinate form\n");
    display(sp2);
    node* added=add(sp1,sp2);
    printf("Printing Added matrix\n");
    display(added);
}