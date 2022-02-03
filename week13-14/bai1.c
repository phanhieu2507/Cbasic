/*Make a random string that has about 2000
characters consisting of a set of
characters..
• For example:
– set of characters: abcdef
– string: abcadacaeeeffaadbfacddedcedfbeccae…
• Write the program that searches the
pattern, for example “aadbf”, from the
string.
• Note: use Simple searching string
Algorithm*/
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
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
int bruteforce(char t[],char p[])
{    
        int m=strlen(p)-1;
        int k=strlen(t);
       
        for(int i=0;i<k;i++)
    {
         int j=0;
        while (j<m &&t[i+j]==p[j])
          {j++;}
        if(j==m) return i;
        
    }
    
    return -1;
}
void main()
{
    get();
    printf("pattern find at: %d",bruteforce(a[0].name,a[1].name));
}