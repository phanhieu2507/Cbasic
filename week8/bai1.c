/*Create an binary search tree with 10
nodes. Each node contains an
random integer.
• Ask user to input an number and
search for it.
• Print the content of the trees.*/
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
typedef struct nodetype{
    int value;
    struct nodetype *left,*right;
} nodetype;
void Free(nodetype* root)
{
    if(root==NULL) return ;
    Free(root->left);
    Free(root->right);
    Free(root);
}
int leftof(const int value, const nodetype *root)
{
    return value< root->value;
}
int rightof(const int value, const nodetype *root)
{
    return value > root ->value;
}
nodetype* insert( nodetype*root,const int value)
{
    if(root==NULL)
    {
        nodetype* node=(nodetype*)malloc(sizeof(nodetype));
        node->left=NULL;
        node->right=NULL;
        node->value=value;
        return node;
    }
    else if(leftof(value,root))
    {
        root->left=insert(root->left,value);
    }
    else if(rightof(value,root))
    {
        root->right=insert(root->right,value);
    }
    return root;
}
void preorder(nodetype* root)
{   if(root!=NULL)
    {printf("%d ",root->value);
    preorder(root->left);
    preorder(root->right);
}}
void main()
{   nodetype *root=NULL;
    srand(time(0));
    for(int i=0;i<10;i++)
    {
       root=insert(root,rand());
    }
    preorder(root);                                                  
 Free(root);
}