/*Write a program that sorts strings
with quick sort by alphabetical order
based on the following instructions.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct book
{
           char name[100];
        
}  book;
book A[100];
int dem=0;
void get()
{ 
     FILE *f;
    f=fopen("input3.txt","r");
    if(f==NULL) printf("Can't open file");
    
  while(fscanf(f,"%s",A[dem].name)!=EOF)
  {
      dem++;
  } 
    fclose(f);

}
void quickSort(int L,int R) {
if(L < R){
int index = (L + R)/2;
index = partition(L,R,index);
if(L < index)
quickSort(L,index-1);
if(index < R)
quickSort( index+1,R);
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
void Swap(int a,int b)
{    char name1[100];  
    strcpy(name1,A[a].name);
    strcpy(A[a].name,A[b].name);
    strcpy(A[b].name,name1);
}
void main()
{
    get();
   quickSort(0,dem);
   for(int i=0;i<dem;i++)
   {
       printf("%s \n",A[i].name);
   }
    
}
