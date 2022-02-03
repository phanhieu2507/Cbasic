/*Make a random string that has about 2000
characters consisting of a set of characters.
• set of characters: abcdef
• string:
abcadacaeeeffaadbfacddedcedfbeccae…
• Write the program that search the pattern,
for example “aadbf”, from the string.
• Note: use Boyer-Moore Algorithm*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define as 256
int Max(int a, int b)
{
    return(a>b?a:b);
}
void preprocess(char text[], int sz, int pre[])
{         for(int i=0;i<as;i++)
              {    pre[i]=-1;

              }
              for (int j=0;j<sz;j++)
              {
                  pre[(int)text[j]]=j;
              }
}
void moore(char text[],char par[])
{
    int t=strlen(text);
    int p=strlen(par);
    int s=0;
    int pre[as];
    preprocess(par,p,pre);
    while(s+p<=t)
    {
         int j=p-1;
         while(j>=0&&text[s+j]==par[j])
         {
             j--;
         }
         if(j<0)
         {
             printf("Pattern find at: %d",s);
             s+=(s+p<t)?(1+p-pre[text[s+p]]):1;
         }
         else s+=Max(1,j-pre[text[s+j]]);
    }
}
typedef struct book
{
    char name[100];
} book;
book a[100];
void get()
{
    FILE* p=fopen("input.txt","r");
    int i=0;
    while(fscanf(p,"%s",a[i].name)!=EOF)
    i++;
    fclose(p);
}

void main()
{
    get();
     moore(a[0].name,a[1].name);
}
