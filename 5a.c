#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int stack[20],top=-1;
void push(int ele)
{
  stack[++top]=ele;
}
int pop()
{
  return (stack[top--]);
}
void eval(char post[20])
{
  char ch;
  int i,b,a;
  for(i=0;post[i]!='\0';i++)
  {
    ch=post[i];
    if(isdigit(ch))
      push(ch-'0');
    else
    {
      b=pop();
      a=pop();
      switch(ch)
      {
        case '+':push(a+b);
                 break;
        case '-':push(a-b);
                 break;
        case '*':push(a*b);
                 break;
        case '/':if(b==0)
                 {
                   printf("Divide by zero error\n");
                   exit(0);
                 }
                 push(a/b);
                 break;
        case '^':push(pow(a,b));
                 break;
        case '%':push(a%b);
                 break;
        default :printf("\nInvalid option");
      }
    }
  }
}
int main()
{
  char post[20];
  printf("\nEnter the postfix expression\n");
  scanf("%s",post);
  eval(post);
  printf("\nThe evaluated answer is %d",pop());
  return 0;
}
