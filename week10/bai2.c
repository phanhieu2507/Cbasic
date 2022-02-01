/*We assume that you make a mobile
phone’s address book.
• At least, we want to write a program that
can store the declared about 100 structure
data with name and phone number and email address.
• Read the about 10 data from an input file
to this structure, and write the data that is
sorted in ascending order into an output
file.
• Use the heap sort. Print out the number of
comparisons*/
#include<stdio.h>
#include<string.h>
#define max 100
typedef struct book
{
    char name[100],phone[max],mail[max];

} book;                                               
book a[100];
void input()
{
    int i=0;
    FILE *p=fopen("input.txt","r");
    if(p==NULL) printf("Can't open file");
    char name[100],phone[max],mail[max];
    while(fscanf(p,"%s %s %s",name,phone,mail)!=EOF)
    {    strcpy(a[i].name,name);
         strcpy(a[i].phone,phone);
         strcpy(a[i].mail,mail);
        i++;
    }
    fclose(p);
}
void swap(book a[],int i,int j)
{     char name[max],phone[max],mail[max];
        strcpy(name,a[i].name);
        strcpy(phone,a[i].phone);
        strcpy(mail,a[i].mail);
                    strcpy(a[i].name,a[j].name);
                    strcpy(a[i].phone,a[j].phone);
                    strcpy(a[i].mail,a[j].mail);
               strcpy(a[j].name,name);
               strcpy(a[j].phone,phone);
               strcpy(a[j].mail,mail);
}
void heapify(book a[],int i,int N)
{
    int left=2*i+1;
    int right=2*i+2;
    int m=i;
     if(left<N&&strcmp(a[left].name,a[i].name)>0)
     m=left;
     if(right<N&&strcmp(a[right].name,a[m].name)>0)
     m=right;
     if(m!=i)
     {
         swap(a,i,m);
         heapify(a,m,N);
     }

}
void buildheap(book a[],int N)
{   for(int i=N/2;i>=0;i--)
      {
          heapify(a,i,N);
      }
}
void heapsort(book a[],int N)
{
    buildheap(a,N);
    for(int i=N-1;i>1;i--)
    {   swap(a,0,i);
        heapify(a,0,i-1);
    }
}
void main()
{
    input();
    heapsort(a,6);
     for(int i=0;i<6;i++)
    {
        printf("%s %s %s \n",a[i].name,a[i].phone,a[i].mail);
    }
}