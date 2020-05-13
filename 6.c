#include<stdio.h>
#include<stdlib.h>
#define MAX 5
char CQ[MAX],f=-1,r=-1;
int CQempty();
int CQfull();
void CQinsert(char elem)
{
  if(CQfull())
    printf("\nOverflow");
  else
  {
    if(f==-1)
      f=0;
    r=(r+1)%MAX;
    CQ[r]=elem;
  }
}
char CQdelete()
{
  char elem;
  if(CQempty())
  {
    printf("\nUnderflow");
    return(-1);
  }
  else
  {
    elem=CQ[f];
    if(f==r)
    {
      f=-1;
      r=-1;
    }
    else
      f=(f+1)%MAX;
    return elem;
  }
}
int CQfull()
{
  if((f==r+1)||(f==0 && r==MAX-1))
    return 1;
  return 0;
}
int CQempty()
{
  if(f==-1)
    return 1;
  return 0;
}
void display()
{
  int i;
  if(CQempty())
    printf("Empty queue\n");
  else
  {
    printf("Front->[%d]",f);
    for(i=f;i!=r;i++)
      printf("%c",CQ[i]);
    printf("%c",CQ[i]);
    printf("<-[%d]Rear",r);
  }
}
int main()
{
  int opn;
  char elem;
  while(1)
  {
    printf("\nEnter your choice\n1:Insert\n2:Delete\n3:Display\n4:Exit\n");
    scanf("%d",&opn);
    switch(opn)
    {
      case 1:printf("Enter element to be inserted\n");
             scanf("%s",&elem);
             CQinsert(elem);
             break;
      case 2:elem=CQdelete();
             if(elem!=-1)
              printf("\nDeleted element is %c\n",elem);
             break;
      case 3:printf("\nThe circular queue is\n");
             display();
             break;
      case 4:exit(0);
             break;
    }
  }
  return 0;
}
