#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
//int 
void sort(int* a,int start,int size)
{
    int min=a[start];
    int flag=0;
    for(int i=start+1;i<size;i++)
    {
    if(a[i]<min)
    {
    min=a[i];
    flag=i;
    }
    }
    
    if(min==a[start])
    return;
    else
    {
        swap(&a[start],&a[flag]);
        sort(a,start+1,size);
    }
    //return min;
}
void main()
{
    // int size;
    // scanf("%d",&size);
    int* a=malloc(sizeof(int)*1000);
    int c=1000;
    for(int i=0;i<1000;i++)
    //scanf("%d",&a[i]);
    a[i]=c--;
    double start=clock();
    sort(a,0,1000);
    double end=clock();
    for(int i=0;i<1000;i++)
    printf("%d ",a[i]);
    printf("\n%f\n",((end - start) / CLOCKS_PER_SEC)*(1000));
}