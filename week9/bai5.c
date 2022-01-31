/*Write to a program WordCount which reads a text file, then
analyzes the word frequencies. The result is stored in a file.
When user provide a word, program should return the
number of occurrences of this word in the file.*/
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define max 100
typedef struct nodetype{
    char word[100];
    int frequency;
    struct nodetype *left,*right;
} nodetype;
void Free(nodetype* root)
{
    if(root==NULL) return ;
    Free(root->left);
    Free(root->right);
    Free(root);
}

nodetype* insert(char word[],nodetype* root)
{   
    if(root==NULL)
    {
        nodetype* node=(nodetype*)malloc(sizeof(nodetype));
        node->left=NULL;
        node->right=NULL;
        strcpy(node->word,word);
        node->frequency=1;
        return node;
    } 
    
       int c=strcmp(word,root->word);
        if(c==0)
        {
            root->frequency++;
        }
      else  if(c<0)
    {
        root->left=insert(word,root->left);
    }
       else if(c>0)
    {
        root->right=insert(word,root->right);
    }
    return root;
}
nodetype* input(nodetype* root)
{     FILE* f=fopen("input2.txt","r");
          if (f==NULL) printf("Can't open file");
      char word[max];
      while(fscanf(f,"%s ",word)!=EOF)
      {
          root=insert(word,root);
      }
       return root;
   fclose(f);
}
void inorder(nodetype* root)
{   if(root!=NULL)
    {inorder(root->left);
     printf("%s - %d \n",root->word,root->frequency);
     inorder(root->right);
}}
void main()
{   nodetype *root=NULL;
   root=input(root);
      inorder(root);                             
 Free(root);
}