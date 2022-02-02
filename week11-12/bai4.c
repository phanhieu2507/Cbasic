/*We assume that you make a mobile phone’s
address book.
• At the very least, you should declare the
structure that can store “name”, “phone number”
and “e-mail address”. And, you should declare
the singly-linked list that can store about 100
data that have this structure.
• You write a program that reads about 10 data
from an input file to the list and writes the data
to an output file after sorting in ascending order
for name.
• You must use Merge sort for sorting.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct book
{
           char name[100];
           char phonenumber[100];
           char mail[100];
        
}  book;
book A[100];
int dem=0;
void addpeople(char name[], char a[], char mail[])
{    strcpy(A[dem].name,name);
     strcpy(A[dem].phonenumber,a);
     strcpy(A[dem].mail,mail);
    dem++;
}
void get()
{ 
     FILE *f;
    f=fopen("input.txt","r");
    if(f==NULL) printf("Can't open file");
     
    char name[100];
    char phonenumber[100];
    char mail[100];
    
  for(int i=0;i<10;i++)
  fscanf(f,"%s %s %s\n",A[i].name,A[i].phonenumber,A[i].mail);
    
    fclose(f);

}
void mergesort(book a[],int l,int r)
{
       if(l<r)
       {
          int m=(l+r)/2;
           mergesort(a,l,m);
           mergesort(a,m+1,r);
           merge(a,l,m,r);
       }
}
void cop(book a[],book b[],int i, int j)
{
    strcpy(a[i].name,b[j].name);
    strcpy(a[i].phonenumber,b[j].phonenumber);
    strcpy(a[i].mail,b[j].mail);

}
void merge(book a[],int l,int m,int r)
{
    int i=l,j=m+1;
    book b[100];
    for(int k=l;k<=r;k++)
    {
        if(i>m) {cop(b,a,k,j);j++;}
        else if (j>r){cop(b,a,k,i);i++;}
        else 
        {
               if(strcmp(a[i].name,a[j].name)>0)
               {
                   cop(b,a,k,j);j++;
               }
               else{
                   cop(b,a,k,i);i++;
               }

        }
    } 
    for(int k=l;k<=r;k++)
    cop(a,b,k,k);

}

void main()
{     int a=0;
    get();
    mergesort(A,0,5);
    while(a<6)
{  printf("%s %s %s\n",A[a].name,A[a].phonenumber,A[a].mail);
a++;
}  
}