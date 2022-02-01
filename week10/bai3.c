/*Input 10 words from the standard
input, and load them to a character
type array.
• Sort the array by insertion sort, and
output the sorted array into the
standard output*/
#include<stdio.h>
#include<string.h>
#define max 100
typedef struct book
{
    char name[100];

}book;                                               
book a[100];
void input()
{
    int i=0;
    for(int i=0;i<10;i++)
    {  fflush(stdin);
        scanf("%s",a[i].name);
        
    }
}

void insertionsort(book a[],int k)
{        for(int i=0;i<k;i++)
           {
               char name[max];
               strcpy(name,a[i].name);
             
               int j=i;
               while(j>0&&strcmp(name,a[j-1].name)<0)
               {
                    strcpy(a[j].name,a[j-1].name);
        
                    j--;
                  
               }
                strcpy(a[j].name,name);
             
           }
}
void main()
{
    input();
  insertionsort(a,10);
    for(int i=0;i<10;i++)
    {
        printf("%s\n",a[i].name);
    }
    
}      