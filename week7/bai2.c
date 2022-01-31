/* We assume that you make a mobile
phone’s address book.
• Declare the structure which can store at
least "name", "telephone number", "e-mail
address.". And declare an array of the
structure that can handle about 100
address data.
• Read this array data of about 10 from an
input file, and write a name which is equal
to a specified name and whose array index
is the smallest to an output file. Use the
binary search for this exercise */
#include<stdio.h>
#include<string.h>
typedef struct phonebook 
{      char name[100];
       char phone[100];
       char mail[100];
} phonebook;
phonebook A[100];
void input()
{
    FILE *p;
    p=fopen("input.txt","r");
    if (p==0) printf("Can't open file");
    char name[100],phone[100],mail[100];
    int i=0;
    while(fscanf(p,"%s %s %s/n",name,phone,mail)!=EOF)
    {
       strcpy(A[i].name,name);
       strcpy(A[i].phone,phone);
       strcpy(A[i].mail,mail);
       i++;

    }
    fclose(p);
}
int binarysearch(phonebook C[],char name[],int low, int high)
{
      int mid=(low+high)/2;
      if(strcmp(C[mid].name,name)==0) return mid;
      else if(strcmp(C[mid].name,name)<0) 
          binarysearch(C,name,mid+1,high);
        else  binarysearch(C,name,low,mid-1); 
}
void main()
{    char name[100];
    input();
    printf("Nhap ten can tim thong tin: ");
    scanf("%s",name);
    int c=binarysearch(A,name,0,5);
    printf("%s %s %s",A[c].name,A[c].phone,A[c].mail);
}