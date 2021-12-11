/*Modify a list that you have created in
previous exercises which support the
capacity of self-organizing using
"move to front" strategy.
• Infact, develop the function search
an element in a list*/
#include<stdio.h>
void sol(int r[],int key)
{
    int i,j;
int tempr;
for ( i=0; i<10 && r[i] != key; i++ );
if ( key == r[i] )
{ if ( i>0 ) {
tempr = r[i];
while(i!=0){
r[i] = r[i-1];
i--;
}
r[0] = tempr;
for(int i=0;i<10;i++) printf("%d ",r[i]);
} else printf("0");
}}
void main()
{
    int a[11];
    for (int i = 0; i < 11; i++)
    {
        scanf("%d",&a[i]);
    }
    sol(a,3);
}