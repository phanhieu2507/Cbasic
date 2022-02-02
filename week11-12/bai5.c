/*Write a recursive function void recurTriangle (
int n, char ch ) which prints out an upsidedown triangle. The parameter ch is the
character to be used for drawing the triangle,
and n is the number of characters on the first
row. For example, if n is 7 and ch is ’+’, then
the output of the function should be:
+++++++
++++++
+++++
++++
+++
++
+*/
void recurtriangle(int n,char ch)
{
    if(n>0)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%c",ch);
        }
        printf("\n");
        recurtriangle(n-1,ch);
    }
}
void main()
{
    recurtriangle(7,'+');
    
}