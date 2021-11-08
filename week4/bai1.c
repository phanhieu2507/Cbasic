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
 
int check1(char y)
    {
        if(y=='+'||y=='-')
        return 1; else return 0;
    }
int check2(char z)
    {
        
        if(z=='*'||z=='/')
        return 1; else return 0;
    }
 void change()
{   int c=0;
    while (c==0)
    {
        b[be]=pop();
        be++;
        c=empty();
    }
    
}   
void result(char x)
{   
    if('0'<=x&&x<='9')
    { b[be]=x;be++;}
    else if(check1(x)==1&&check2(stack[top])==1) {change();push(x);}
    else push(x);
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
    change();

    for(int k=0 ;k<=10;k++)
    {
        printf("%c",b[k]);
    }
    
    
}