#include<stdio.h>
#include<stdlib.h>
struct node{
int value;
struct node *next;
};
typedef struct node *node;
node head=NULL;
int isempty()
{
    if(head==NULL) return 1; else return 0;
}
node makenode(int a)
{ node p;
 p=(node)malloc(sizeof(node));
 p->value=a;
 return p;

}
void enqueue(int a)
{    node p=makenode(a); 
    if(head==NULL){head=p;p->next=NULL;}
    else {p->next=head;head=p;}
    
}
int dequeue()
{
    node p=head;
   
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    printf("%d ",p->next->value);
    free(p->next);
    p->next=NULL;
    
   
}
void main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    while(isempty()!=1)
       dequeue();
    
    
}