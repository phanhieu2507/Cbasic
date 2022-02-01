/*You can write a program that processes in
the following order.
– 1. Declare char data[10].
– 2. Read every 1 word from the standard input
by fgetc( ) function and load it on the array
“data”.
– 3. Do the insertion sort to the array “data”
– 4. Output every 1 word of the value of the
sorted array ”sort” by fputc( ) function.*/
#include<stdio.h>
#include<string.h>
#define max 100
                                              
char a[100];
void input()
{
    int i=0;
    for(int i=0;i<10;i++)
    {  
        scanf("%c",&a[i]);
        
    }
}

void insertionsort(char a[],int k)
{        for(int i=0;i<k;i++)
           {
               char c;
               
             c=a[i];
               int j=i;
               while(j>0&& c<a[j-1])
               {
                    a[j]=a[j-1];
        
                    j--;
                  
               }
                a[j]=c;
             
           }
}
void main()
{
    input();
  insertionsort(a,10);
    for(int i=0;i<10;i++)
    {
        printf("%c\n",a[i]);
    }
    
}      