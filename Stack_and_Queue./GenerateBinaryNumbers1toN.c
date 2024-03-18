#include <stdio.h>
#include <string.h>
#define MAX 10005
char queue[MAX][20], temp[20];
int front = -1, rear = -1;
void enqueue(char *ptr)
   {
if(rear == MAX-1)
{
    return;
}
if(front == -1 && rear == -1)
    front = rear = 0;
else
    rear = rear + 1;
strcpy(queue[rear],ptr);
}
char* dequeue()
{
if(front == -1)
    printf("\nEmpty Queue");
else
{
    strcpy(temp,queue[front]);
    if(front == rear)
        front = rear = -1;
    else
        front = front + 1;
    return temp;
}
}
 void binary_numbers_using_queue()
{
char temp2[MAX];
strcpy(temp,dequeue());
printf("%s ",temp);
strcpy(temp2,temp);
strcat(temp,"0");
enqueue(temp);
strcat(temp2,"1");
enqueue(temp2);
}
 int main()
{
int t;
scanf("%d",&t);
while(t--)
{
    int n;scanf("%d",&n);
char temp[2] = "1";
enqueue(temp);
for(int i = 1; i <= n; i++)
    binary_numbers_using_queue();
    printf("\n");
    front = -1, rear = -1;
    for(int i=0;i<10005;i++)
    for(int j=0;j<20;j++)
    queue[i][j]='\0';
}
return 0;
}
