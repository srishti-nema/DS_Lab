#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top=-1;
int overflow()
{
  if(top==MAX-1)
    return 1;
  else
    return 0;
}
int underflow()
{
  if(top==-1)
    return 1;
  else
    return 0;
}
void push(int *s,int ele)
{
  if(!overflow())
    s[++top]=ele;
  else
    printf("Stack overflow\n");
}
int pop(int *s)
{
  if(!underflow())
    return s[top--];
  else
    printf("Stack underflow\n");
  return 0;
}
void display(int *s)
{
  int i;
  if(underflow())
  {
    printf("Stack underflow\n");
    return;
  }
  printf("The stack contents are:\n");
  for(i=0;i<=top;i++)
    printf("%d\t",s[i]);
}
int palin(char *pal,int *s)
{
  int i;
  top=-1;
  for(i=0;pal[i]!='\0';i++)
    push(s,pal[i]-'0');
  for(i=0;pal[i]!='\0';i++)
    if(pal[i]!=(pop(s)+'0'))
      return 0;
  return 1;
}
int main()
{
  int stack[MAX],ch,i,j,ele,p;
  char str[10];
  while(1)
  {
    printf("\nEnter choice:\n1:push\n2:pop\n3:check palindrome\n4:display\n5:exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter element to be pushed:\n");
             scanf("%d",&ele);
             push(stack,ele);
             break;
      case 2:ele=pop(stack);
             if(ele!=0)
              printf("\nThe deleted element is %d\n",ele);
             break;
      case 3:printf("\nEnter the string");
             fflush(stdin);
             scanf("%s",str);
             p=palin(str,stack);
             if(p)
              printf("String is a palindrome");
            else
              printf("Not a palindrome");
            break;
      case 4:display(stack);
              break;
      default:exit(0);
    }
  }
  return 0;
}
