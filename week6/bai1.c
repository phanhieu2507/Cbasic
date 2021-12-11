/*Read 11 integers from the standard input and assign first
ten integers to the array.
Then if the 11th integer is in the array, output the position
of the element (1 – 10). If not, output 0. */
#include<stdio.h>
void main()
{
    int a[11];
    for (int i = 0; i < 11; i++)
    {
        scanf("%d",&a[i]);
    }
    int k=0;
    for (int i = 0; i < 10; i++)
    {
        if(a[i]==a[10]) {printf("%d ",i+1);k++;}
        
    }
    if (k==0) printf("0");
}