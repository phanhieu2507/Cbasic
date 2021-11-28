//Write a program that reads any postfix expression involving multiplication and addition of interger.
#include<stdio.h>
int stack[100] ;
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
int pop()
{    top=top-1;
     return stack[top+1];
  
}

void get()
{
    char c;
    int i=0;
    scanf("%s",a);
}
 

void result(char x)
{    int a,b,c;
    if('0'<=x&&x<='9')
    push(x-48);
    else if(x=='+')
    {
        a=pop();
        b=pop();
        c=a+b;
        push(c);
        
    }
     else if(x=='*')
    {
        a=pop();
        b=pop();
        c=a*b;
        push(c);
        
    }
}

void main()
{
    get();
    int i=0;
    while(a[i]!='\0')
    {
        result(a[i]);
        i++;
    }
printf("%d",pop());
    
    
    
}