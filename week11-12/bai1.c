/*We assume that you make a mobile
phone’s address book.
• At the very least, you should declare the
structure that can store “name”, “phone
number” and “e-mail address”. And, you
should declare the array that can store
about 100 data that have this structure.
• You write a program that reads about 10
data from an input file to the array and
writes the data to an output file after
sorting in ascending order for name.
• You must use Quick sort for sorting.*/
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
void quickSort( int L, int R) {
if(L < R){
int index = (L + R)/2;
index = partition( L, R, index);
if(L < index)
quickSort( L, index-1);
if(index < R)
quickSort( index+1, R);
}
}
int partition( int L, int R, int
indexPivot) {
char pivot[100];
strcpy(pivot,A[indexPivot].name);
Swap(indexPivot, R);
int storeIndex = L;
for(int i = L; i <= R-1; i++){
if(strcmp(A[i].name,pivot)<0){
Swap(storeIndex, i);
storeIndex++;
}
}
Swap(storeIndex,R);
return storeIndex;
}
void Swap(int a, int b)
{    char name1[100];
    char phonenumber1[100];
    char mail1[100];     
    strcpy(name1,A[a].name);
    strcpy(phonenumber1,A[a].phonenumber);
    strcpy(mail1,A[a].mail);
    strcpy(A[a].name,A[b].name);
    strcpy(A[a].phonenumber,A[b].phonenumber);
    strcpy(A[a].mail,A[b].mail);
    strcpy(A[b].name,name1);
    strcpy(A[b].phonenumber,phonenumber1);
    strcpy(A[b].mail,mail1);
}
void print()
{    int a=0;
   FILE *f;
     f=fopen("output.txt","w");
   while(a<6)
{  fprintf(f,"%s %s %s\n",A[a].name,A[a].phonenumber,A[a].mail);
a++;
}  
     fclose(f);
}
void main()
{
    get();
    quickSort(0,5);
    print();
    
}

