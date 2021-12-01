#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    int id;
    char name[12];
    int grade;
    struct student *next;

} ;
typedef struct student *student;
student head = NULL;
student addstudent(int id, char name[],int grade )
{  student node;
   node=(student)malloc(sizeof(struct student));
   node->grade=grade;
   node->id=id;
   strcpy(node->name,name);
   if(head== NULL)
   {
       head=node;node->next=NULL;
   } else {node->next=head; head= node;}
   return head; 
}
void readfile()
{    FILE *f;
    f=fopen("infor.txt","r");
    if(f==NULL) printf("Can't open file");
     int id;
    char name[12];
    int grade;
    char c;
  while(fscanf(f,"%d %s %d",&id,name,&grade)!=EOF)
    {
         
       addstudent(id,name,grade);
    }
    fclose(f);
}
void printinfor()
{    student p=head;
 while(p!=NULL)
 {
     printf("%d %s %d \n",p->id,p->name,p->grade);
     p=p->next;
 }

}
void searching(int a)
{
    student p =head;
    while(p!=NULL)
    {
        if(p->id==a) {printf("%d %s %d \n",p->id,p->name,p->grade);break;} p=p->next;
    }
    if(p==NULL) printf("Student does not exist !");
}
void delete(int a)
{
    student p =head;
    while(p!=NULL)
    {
        if(p->next->id==a) {p->next=p->next->next;break;} p=p->next;
    }
    if(p==NULL) printf("Student does not exist !");

}
void changegrade(int a,int b)
{
    student p =head;
    while(p!=NULL)
    {
        if(p->id==a) {p->grade=b;break;} p=p->next;
    }
    if(p==NULL) printf("Student does not exist !");
}
void out()
{
    student p;
    p=head;
    while(p != NULL) {head= head->next;free(p);p = head;}
    printf("See you again!!");
}
void main()
{       int a=0,id,grade;
while(a!=6)
{  printf("MENU \n1: readfile \n2: printinfor \n3: searching \n4: delete \n5: changegrade \n6 free \n");
      scanf("%d",&a);
      switch (a)
      {
      case 1: readfile();
          break;
      case 2: printinfor();
          break;
      case 3: scanf("%d",&id);searching(id);
          break;
      case 4: scanf("%d",&id);delete(id);
          break;
      case 5: scanf("%d %d",&id,&grade);changegrade(id,grade);
          break;
      case 6: out();
          break;
      }
} 

}

