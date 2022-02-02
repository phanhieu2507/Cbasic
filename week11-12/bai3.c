/*When a program sorts a little number of the data,
a program using insertion sort is faster than a
program using quick sort and so on. So, a
program sorts efficiently, if a program changes
sorting algorithms by the number of data.
• You write a function that selects sorting
algorithms – If number of the data is more than x
numbers, the function selects quick sort. If not
so, it selects insertion sort.
• Note: get the number “x” as the program
argument.
• Read the text file that has more than 100
characters, sort the first 100 characters, and
show the result by standard output.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char A[1000];
int dem=0;
void Swap(int a,int b)
{   char c=A[a];
     A[a]=A[b];
     A[b]=c;
}
void get()
{ 
     FILE *f;
    f=fopen("input2.txt","r");
    if(f==NULL) printf("Can't open file");
     
    char name[1000];
  
  fscanf(f,"%s\n",A);
    
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
char pivot=A[indexPivot];

Swap(indexPivot,R);
int storeIndex = L;
for(int i = L; i <= R-1; i++){
if(A[i]<pivot){
Swap(storeIndex,i);
storeIndex++;
}
}
Swap(storeIndex,R);
return storeIndex;
}

void insertionsort(char a[],int N)
{       for(int i=0;i<N;i++)
            {
                int j=i;
                char c=a[i];
                while(j>0&&a[j-1]>c)
                {
                    a[j]=a[j-1];
                    j--;
                }
                a[j]=c;
            }

}
void main(int argc, char *argv[])
{
    get();
    int n;
    printf("Nhap so x : \n");
    scanf("%d",&n);
    if(n<30)
    insertionsort(A,100);
    else quickSort(0,99);
    printf("%s",A);
}