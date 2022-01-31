/*Write a program to build a
tournament: a binary tree where
the item in every internal node is a
copy of the larger of the items in its
two children. So the root is a copy
of largest item in the tournament.
The items in the leaves constitute
the data of interest.
• The input items are stored in an
array.
• Hint: Uses a divide and conquer
strategy */
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{   
       int value;
       struct node *left,*right;
} node;
node* create(int a,node*left,node *right )
{        node *x =(node*)malloc(sizeof(node));
         x->value=a;
         x->left=left;
         x->right=right;
        return x;
}
node* maketree(int a[],int l,int r)
{
    int m=(l+r)/2;
    node *x= create(a[m],NULL,NULL);
    if(l==r) return x;
    x->left=maketree(a,l,m);
    x->right=maketree(a,m+1,r);
    int u=x->left->value,v=x->right->value;
    if(u>v) x->value=u;else x->value =v;
    return x;
}
void main()
{
    int a[10]={1,2,4,6,4,7,3,8,11,10};
    node *root=NULL;
    root=maketree(a,0,9);
    printf("%d",root->value);

}