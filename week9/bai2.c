/*Output all the data stored in the
binary tree in ascending dictionnary
order for the name in the Phone
Book Tree:
–to screen.*/
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define max 100
typedef struct nodetype{
    char name[100],phone[100],mail[100];
    struct nodetype *left,*right;
} nodetype;
void Free(nodetype* root)
{
    if(root==NULL) return ;
    Free(root->left);
    Free(root->right);
    Free(root);
}
int leftof(char mail[], nodetype *root)
{ if(strcmp(root->mail,mail)==1)
    return 1; else return 0;
}
int rightof(char mail[], nodetype *root)
{   if( strcmp(mail,root->mail)==1)

    return 1; else return 0;
}
nodetype* insert(char name[],char phone[],char mail[],nodetype* root)
{
    if(root==NULL)
    {
        nodetype* node=(nodetype*)malloc(sizeof(nodetype));
        node->left=NULL;
        node->right=NULL;
        strcpy(node->name,name);
        strcpy(node->phone,phone);
        strcpy(node->mail,mail);
        return node;
    }
    else if(leftof(name,root))
    {
        root->left=insert(name,phone,mail,root->left);
    }
       else if(rightof(name,root))
    {
        root->right=insert(name,phone,mail,root->right);
    }
    return root;
}
nodetype* input(nodetype* root)
{     FILE* f=fopen("input.txt","r");
          if (f==NULL) printf("Can't open file");
      char name[max],phone[max],mail[max];
      while(fscanf(f,"%s %s %s",name,phone,mail)!=EOF)
      {
          root=insert(name,phone,mail,root);
      }
       return root;
   fclose(f);
}
void inorder(nodetype* root)
{   if(root!=NULL)
    {inorder(root->left);
     printf("%s %s %s \n",root->name,root->phone,root->mail);
     inorder(root->right);
}}
void main()
{   nodetype *root=NULL;
   root=input(root);
      inorder(root);                             
 Free(root);
}