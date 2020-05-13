#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct node
{
  int coeff;
  int exp[3];
  struct node *next;
};
typedef struct node* Node;
Node addterm(Node p,int coeff,int i,int j,int k)
{
  Node temp=(Node)malloc(sizeof(struct node));
  Node temp1=p;
  temp->coeff=coeff;
  temp->exp[0]=i;
  temp->exp[1]=j;
  temp->exp[2]=k;
  while(temp1->next!=p)
    temp1=temp1->next;
  temp1->next=temp;
  temp->next=p;
  return p;
}
Node mkheader()
{
  Node p=(Node)malloc(sizeof(struct node));
  p->coeff=-1;
  p->exp[0]=-1;
  p->exp[1]=-1;
  p->exp[2]=-1;
  p->next=p;
  return p;
}
double evaluate(Node p,int i,int j,int k)
{
  Node p0=p->next;
  double sum=0;
  while(p0!=p)
  {
    sum+=p0->coeff*pow(i,p0->exp[0])*pow(j,p0->exp[1])*pow(k,p0->exp[2]);
    p0=p0->next;
  }
  return sum;
}
void print_poly(Node p)
{
  Node p0=p->next;
  while(p0!=p)
  {
    printf("%dx^%dy^%dz^%d",p0->coeff,p0->exp[0],p0->exp[1],p0->exp[2]);
    if(p0->next!=p)
      printf("+");
    p0=p0->next;
  }
  printf("\n");
}
void read(Node t1,int n)
{
  int i;
  Node temp=(Node)malloc(sizeof(struct node));
  for(i=1;i<=n;i++)
  {
    printf("Enter the value of coefficient and powers of x,y and z");
    scanf("%d %d %d %d",&temp->coeff,&temp->exp[0],&temp->exp[1],&temp->exp[2]);
    t1=addterm(t1,temp->coeff,temp->exp[0],temp->exp[1],temp->exp[2]);
  }
  print_poly(t1);
}
Node add(Node p1,Node p2)
{
  Node temp=mkheader();
  Node t1=p1->next,t3=p1->next;
  Node t2=p2->next,t4=p2->next;
  int i,flag;
  while(t1!=p1)
  {
    t2=p2->next;
    while(t2!=p2)
    {
      flag=0;
      for(i=0;i<3;i++)
        if(t1->exp[i]!=t2->exp[i])
        {
          flag=1;
          break;
        }
      if(flag==0)
      {
        temp=addterm(temp,t1->coeff+ t2->coeff,t1->exp[0],t1->exp[1],t2->exp[2]);
        break;
      }
      t2=t2->next;
    }
    if(flag==1)
      temp=addterm(temp,t1->coeff,t1->exp[0],t1->exp[1],t1->exp[2]);
    t1=t1->next;
  }
  while(t4!=p2)
  {
    t3=p1->next;
    while(t3!=p1)
    {
      flag=0;
      for(i=0;i<3;i++)
        if(t3->exp[i]!=t4->exp[i])
        {
          flag=1;
          break;
        }
      if(flag==0)
        break;
      t3=t3->next;
    }
    if(flag==1)
      temp=addterm(temp,t4->coeff,t4->exp[0],t4->exp[1],t4->exp[2]);
    t4=t4->next;
  }
  return temp;
}
int main()
{
  int x,y,z,n,ch,i,coeff;
  Node polysum;
  Node p=mkheader();
  Node poly2=mkheader();
  while(1)
  {
    printf("1:Evaluate polynomial\n2:Add\n3:Exit\nEnter your choice:\t");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter the terms in the polynomial");
             scanf("%d",&n);
             read(p,n);
             printf("Enter the values of x,y,z");
             scanf("%d %d %d",&x,&y,&z);
             printf("the sum is %f",evaluate(p,x,y,z));
             break;
      case 2:printf("Enter the terms in the polynomial2");
             scanf("%d",&n);
             read(poly2,n);
             polysum=add(p,poly2);
             print_poly(polysum);
             break;
      case 3:exit(0);
    }
  }
  return 0;
}
