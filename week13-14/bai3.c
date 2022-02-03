/*Repeat the exercise 13.2 using the
KMP algorithm.
• Calculate the number of
comparisons.*/
#include<string.h>
#include<stdio.h>
int lps[100]={0,1,0,1};
void KMPSearch( char* txt,char* pat)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i = 0; 
    int j = 0; 
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            printf("Tim thay tai vi tri: %d ", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
           
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
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
    KMPSearch(a[0].name,a[1].name);
  }