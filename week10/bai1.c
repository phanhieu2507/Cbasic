/*We assume that you make a mobile phone’s address book.
• At least, we want to write a program that can store about
100 structure data with name and phone number and email address.
• Read about 10 data from an input file to this structure, and
write the data that is sorted in ascending order into an
output file.
• Use the insertion sort and selection sort
• (1) Write a program that uses array of structure */
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
int count=0;
void insertionsort(book a[],int k)
{        for(int i=0;i<k;i++)
           {
               char name[max],phone[max],mail[max];
               strcpy(name,a[i].name);
               strcpy(phone,a[i].phone);
               strcpy(mail,a[i].mail);
               int j=i;
               while(j>0&&strcmp(name,a[j-1].name)<0)
               {
                    strcpy(a[j].name,a[j-1].name);
                    strcpy(a[j].phone,a[j-1].phone);
                    strcpy(a[j].mail,a[j-1].mail);
                    j--;
                    count++;
               }
                strcpy(a[j].name,name);
               strcpy(a[j].phone,phone);
               strcpy(a[j].mail,mail);
           }
}
void main()
{
    input();
    insertionsort(a,6);
    for(int i=0;i<6;i++)
    {
        printf("%s %s %s \n",a[i].name,a[i].phone,a[i].mail);
    }
    printf("Number of comparsion: %d",count);
}      