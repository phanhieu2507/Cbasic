
/* Initiate an array of n random
integers. n is entered by user.
• Sort the array with the insertion sort
• And using quicksort
• Compare the execution time of two
algorithms.
• Run the program with various values
of n to view the effect.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int A[100];
float start,end;
void insertsort(int A[], int n)
{
    int i, j, last;
    for(i = 1; i < n; i++)
    {
        last = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > last)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = last;
    }
    printf("Mang duoc sap xep theo thu tu tang dan la:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int A[], int L, int R, int indexpivot)
{
    int pivot = A[indexpivot];
    swap(&A[indexpivot], &A[R]);
    int storeIndex = L;
    int i;
    for(i = L; i <= R-1; i++)
    {
        if(A[i] < pivot)
        {
            swap(&A[storeIndex], &A[i]);
            storeIndex ++;
        }
    }
    swap(&A[storeIndex], &A[R]);
    return storeIndex;
}

void quicksort(int A[], int L, int R)
{
    if(L < R)
    {
        int index = (L+R)/2;
        index = partition(A, L, R, index);
        if(L < index)
        {
            quicksort(A, L, index - 1);
        }
        if(index < R)
        {
            quicksort(A, index+1, R);
        }
    }
}

void main()
{   srand((int)time(0));
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
   clock_t start,end;
    for(int i = 0; i < n; i++) A[i]=rand();
   int k=0;
    
    while(k!=3){
        printf(" \n Nhan 1 de dung sap sep chen,nhan 2 de dung sap sep nhanh, nhan 3 de thoat ");
        scanf("%d",&k);
        switch (k)
        {
        case 1: start=clock(); insertsort(A,n); end=clock(); printf("Thoi gian chay la: %lf",(double)((end-start)/CLOCKS_PER_SEC));
            
            break;
             case 2: start=clock(); quicksort(A,0,n-1); printf("Mang duoc sap xep theo thu tu tang dan la:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);end=clock(); printf("Thoi gian chay la: %f",(end-start)/CLOCKS_PER_SEC);
            
            break;
        
        
        }
    }
}