#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int num_vertices;
struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
typedef struct queue que;

typedef struct node{
    int info;
    bool mark;
    struct node* next;
}node;
int isFull(que *ptr){
    int n=ptr->size;
    if(ptr->r==n-1){
        //printf("Queue is full\n");
        return 1;
    }
    else return 0;
}
int isEmpty(que *ptr){
    int f=ptr->f;
    int r=ptr->r;
    if((r==-1 && f==-1) || f==r+1){
        //printf("Queue is Empty\n");
        return 1;
    }
    else return 0;
}
void enqueue(que *ptr,int value){
    if(isFull(ptr)) {
        printf("Can't enqueue queue is full\n");
        return;
    }
    if(isEmpty(ptr)){
        ptr->r++;
        ptr->arr[ptr->r]=value;
        ptr->f=ptr->r;
        return;
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]=value;
        return;
    }
}
int dequeue(que *ptr){
    if(isEmpty(ptr)){
        printf("Can't dequeue queue is empty\n");
        return 0;
    }
    else{
        int elem;
        elem=ptr->arr[ptr->f];
        ptr->f++;
        return elem;
    }
}
void create(node* adj_list[])
{
    node* newnode;
for(int i=0;i<num_vertices;i++)
    {
        int k;
        printf("%d has how many neighbours?: ",adj_list[i]->info);
        scanf("%d",&k);
        node* tmp=adj_list[i];
        for(int j=0;j<k;j++)
        {
            newnode=malloc(sizeof(node));
            printf("Enter the value of neightbour node: ");
            scanf("%d",&(newnode->info));
            tmp->next=newnode;
            newnode->next=NULL;
            newnode->mark=false;
            tmp=newnode;
        }
    }
}
void print(node* adj_list[])
{
for(int i=0;i<num_vertices;i++)
    {
        node* tmp=adj_list[i];
        while(tmp!=NULL)
        {
        printf("%d ",tmp->info);
        tmp=tmp->next;
        }
        printf("\n");
    }
}


bool check_visited(node* adj_list[],int i)
{
    node* tmp=adj_list[i];
    while(tmp!=NULL)
    {
    if(tmp->mark==false)
    return true;
    tmp=tmp->next;
    }
    return false;
}
void bfs(node* adj_list[],int start)
{
    que *visited=malloc(sizeof(que));
    visited->size=num_vertices;
    visited->arr=malloc(sizeof(int)*visited->size);
    visited->r=visited->f=-1;
    node* ptr=malloc(sizeof(node));
    node* p=malloc(sizeof(node));
    //int visited[num_vertices];
    int i=start;
    int x=-2;
    while(true)
    {
        ptr=adj_list[i];
        while(ptr!=NULL)
        {
            if(ptr->mark==false)
            {
              x=ptr->info;
              //printf("ENQUEUING %d\n",x);
              enqueue(visited,x);
              ptr->mark=true;
              for(int k=i+1;k<num_vertices;k++)
                  {
                     //printf("inside %d k loop\n",k);
                     p=adj_list[k];
                  while(p!=NULL)
                  {
                   //printf("inside second while\n");
                   if(p->info==x)
                   {
                    //printf("inside if\n");
                    p->mark=true;
                    break;
                   }
                  p=p->next;
                  }
                  }
            }
        ptr=ptr->next;
       } 
   
    //printf("%d=peeking queue\n",visited[front]);
    start=dequeue(visited);
    printf("DEQUEUING %d ",start);
    //while(true)
    //{
        for(int j=0;j<num_vertices;j++)
        {
            if(adj_list[j]->info==start && check_visited(adj_list,j)==true)
            {
                i=j;
                break;
            }
        }
       
    if(isEmpty(visited))
    break;
}
// while(!isEmpty(visited))
// printf("%d ",dequeue(visited));
}
void main()
{
    printf("Enter total number of vertices: ");
    scanf("%d",&num_vertices);
    node* adj_list[num_vertices];
    node* newnode;
    for(int i=0;i<num_vertices;i++)
    {
        printf("Enter the value of %dth node: ",i+1);
        newnode=malloc(sizeof(node));
        scanf("%d",&(newnode->info));
        newnode->next=NULL;
        adj_list[i]=newnode;
    }
    // for(int i=0;i<num_vertices;i++)
    // {
    //     printf("%d ",adj_list[i]->info);
    // }
    create(adj_list);
    print(adj_list);
    bfs(adj_list,0);
    // for(int i=0;i<num_vertices;i++)
    // printf("%d ",visited[i]);
}
// void bfs(node* adj_list[])
// {
//     int visited[num_vertices];
//     node* ptr=malloc(sizeof(node));
//     node* p=malloc(sizeof(node));
//     for(int i=0;i<num_vertices;i++)
//     {
//         printf("%dth iteration outer loop running\n",i);
//         ptr=adj_list[i];
//         while(ptr!=NULL)
//         {
//             printf("inside while\n");
//           if(ptr->mark==false)
//           {
//             printf("Inside if\n");
//             int x=ptr->info;
//           enqueue(visited,x);
//           ptr->mark=true;
//           for(int k=i+1;k<num_vertices;k++)
//           {printf("inside %d k loop\n",k);
//             p=adj_list[k];
//             while(p!=NULL)
//             {
//                 printf("inside second while\n");
//                 if(p->info==x)
//                 {
//                     printf("inside if\n");
//                 p->mark=true;
//                 break;
//                 }
//                 p=p->next;
//             }
//           }
//           }
//         // if(isEmpty(visited))
//         // enqueue(visited,ptr->info);
//         // else
//         // while(!isEmpty(visited))
//         // {
//         //     int x=dequeue(visited);
//         //     if(f)
//         // }
//           ptr=ptr->next;
//           printf("ptr just got incremented\n");
//         }
//     }
//     //while(!isEmpty(visited))
//     for(int i=0;i<num_vertices;i++)
//     {
//         printf("%d ",dequeue(visited));
//     }
//     //return visited;
// }
// void bfs(node* adj_list[],int start)
// {
//     int x=-2;
//     int visited[num_vertices];
//     node* ptr=malloc(sizeof(node));
//     node* p=malloc(sizeof(node));
//       int i=start;
//         while(true)
//         {
//         ptr=adj_list[i];
//         while(ptr!=NULL)
//         {
//             printf("inside while\n");
//           if(ptr->mark==false)
//           {
//             printf("Inside if\n");
//             x=ptr->info;
//           enqueue(visited,x);
//           ptr->mark=true;
//           for(int k=i+1;k<num_vertices;k++)
//           {
//             printf("inside %d k loop\n",k);
//             p=adj_list[k];
//             while(p!=NULL)
//             {
//                 printf("inside second while\n");
//                 if(p->info==x)
//                 {
//                     printf("inside if\n");
//                 p->mark=true;
//                 break;
//                 }
//                 p=p->next;
//             }
//           }
         
//           }
//            ptr=ptr->next;
//           printf("ptr just got incremented\n");
          
//         }
//         if(x==-2)
//           {
//             x=dequeue(visited);
//             if(isEmpty(visited))
//             break;
//             printf("%d ",x);
//           }
//         for(int z=0;z<num_vertices;z++)
//         if(adj_list[z]->info==x)
//         i=z;
//     }
  
// }


 // if(i==prev_start)
        // start=dequeue(visited);
        // else
        // break;
    //}
    // int c=0;
    // while(true)
    // {
    //     int flag=0;
    // for(int j=0;j<num_vertices;j++)
    // {
    //     printf("%dth iteration!\n",j);
    // if(adj_list[j]->info==start && check_visited(adj_list,j)==true)
    // {
    //     c++;
    //  i=j;
    //  printf("i became %d\n",i);
    //  flag=1;
    //  break;
    // }
    // }
    // if(flag)
    // break;
    // else
    // start=dequeue(visited);
    // printf("dequeuing %d ",start);
    // }
    // // if(i==prev_start)
    // // break;
    // if(c==0)
    // break;
    // int c=0;
    // int j=i;
    // while(true)
    // {printf("Inside while\n");
    //     c++;
    //     start=dequeue(visited);
    //     //start=visited[front++];
    //     printf("dequeuing %d ",start);
    //     for(j=0;j<num_vertices;j++)
    //     {
    //     if(adj_list[j]->info==start && j!=prev_start)
    //     i=j;
    //     }
    //     if(check_visited(adj_list,i)==true)
    //     break;
    // }
    // printf("\n");
    // if(c==1)
    // break;