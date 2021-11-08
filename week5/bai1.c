#include<stdio.h>
#include<stdbool.h>
int queue[20];
int front=0,rear=-1;
bool empty()
{   if(rear<front) return true;
else return false;

}
bool full()
{
    if(rear-front>=10) return true;
    else return false;
}
void dequeue()
{
    if(empty()==true) printf("Queue is empty");
    else {
        queue[front]=0;front++;
    }
}
void enqueue(int x)
{
    rear++;queue[rear]=x;
}
void result()
{
    for(int k=front;k<=rear;k++)
    {
        printf("%d ",queue[k]);
    }
}
void main()
{
    int a;
  for(int i=0;i<11;i++)
    {
        scanf("%d",&a);
        enqueue(a);
   }
    
  while(full()==true)
    {
        dequeue();
    }
    result();
}