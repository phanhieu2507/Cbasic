/*Define an array of integers, load from 1
to 100 in order to the array.
• Read a number from the standard input,
perform the binary search for an array.
Output "Not Found" if the array does not
have it.
• When you perform the binary search,
output the array index compared to the
standard output. Also, display the number
of comparisons achieved until the target
number is found. */

#include<stdio.h>
int b=0;
void binarysearch(int A[],int key, int lo, int hi)
{
    int mid;
    
    
        mid=(lo+hi)/2;
        if(A[mid]==key) {printf("%d %d ",A[mid],key);}
        else if (A[mid]<key) {printf("%d %d \n",A[mid],key);lo=mid+1;binarysearch(A,key,lo,hi);}
        else {printf("%d %d \n",A[mid],key);hi=mid-1;binarysearch(A,key,lo,hi);}
    b++;
}

void main(){
    int A[100],a;
    for(int i=0;i<100;i++) A[i]=i+1;
    scanf("%d",&a);
     binarysearch(A,a,0,99);
     printf("\nNumber of comparisons: %d ",b);
     
}