#include<stdio.h>
void move(int n,char source,char temp,char dest)
{
  if(n==1)
    printf("Move from %c to %c\n",source,dest);
  else
  {
    move(n-1,source,dest,temp);
    move(1,source,temp,dest);
    move(n-1,temp,source,dest);
  }
}
int main()
{
  int n;
  printf("\nEnter the number of rings\n");
  scanf("%d",&n);
  move(n,'A','B','C');
  return 0;
}
