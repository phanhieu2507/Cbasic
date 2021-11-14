//test the "stack" type that you've defined in a program that read from user a string, then reverse it.
#include<stdio.h>
char stack[100] ;
char a[100],b[100];
int be=0;
int top=-1;
int empty()
{
    if (top ==-1)
    return 1;
    else return 0;
}
int full()
{
    if (top ==999)
    return 1;
    else return 0;
}
void push(char x)
{   top++;
    stack[top]=x;
    
}
char pop()
{    top=top-1;
     return stack[top+1];
  
}

void get()
{
    char c;
    int i=0;
    scanf("%s",a);
}


void main()
{
    get();
    int i=0;
    while(a[i]!='\0')
    {
        push(a[i]);
        i++;
    }
   
 int c=0;
   while(c==0)
   {
       printf("%c",pop());
       c=empty();
   }
    
}