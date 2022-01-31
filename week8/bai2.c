/*We assume that you make a mobile phone’s address book.
• Declare a structure which can store at least "name", "telephone
number", "e-mail address.”.
• Declare a structure for a binary tree which can stores the
structure of an address book inside. Read data of about 10 from
an input file to this binary tree as the following rules.
– An address data which is smaller in the dictionary order for the e-mail
address is stored to the left side of a node.
– An address data which is larger in the dictionary order for the e-mail
address is stored to the right side of a node.
• (1) Confirm the address data is organized in the binary tree
structure with some methods (printing, debugger, etc).
• (2) Find a specified e-mail address in the binary tree and output it
to a file if found.
• (3) Output all the data stored in the binary tree in ascending
order for the e-mail address. (Reserve it for the next week)*/
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
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
    free(root);
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
    else if(leftof(mail,root))
    {
        root->left=insert(name,phone,mail,root->left);
    }
       else if(rightof(mail,root))
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
void preorder(nodetype* root)
{   if(root!=NULL)
    {printf("%s %s %s \n",root->name,root->phone,root->mail);
    preorder(root->left);
    preorder(root->right);
}}
void inorder(nodetype* root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%s %s %s \n",root->name,root->phone,root->mail);
    inorder(root->right);
}
}

void main()
{   nodetype *root=NULL;
   root=input(root);
      inorder(root);  
                       
 Free(root);
}