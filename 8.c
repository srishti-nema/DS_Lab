#include<stdio.h>
#include<stdlib.h>
struct node
{
  char SSN[3];
  char Name[10];
  char dept[5];
  char des[5];
  char sal[10];
  char phone[10];
  struct node *rlink;
  struct node *llink;
};
typedef struct node* Node;
Node head=NULL;
Node createnode()
{
  Node temp;
  temp=(Node)malloc(sizeof(struct node));
  printf("\nEnter the SSN");
  fflush(stdin);
  gets(temp->SSN);
  printf("\nEnter the name");
  gets(temp->Name);
  printf("\nEnter the department");
  gets(temp->dept);
  printf("\nEnter the designation");
  gets(temp->des);
  printf("Enter the salary");
  gets(temp->sal);
  printf("\nEnter the phone number");
  gets(temp->phone);
  temp->rlink=NULL;
  temp->llink=NULL;
  return temp;
}
void InsertFront()
{
  Node DLL=NULL;
  DLL=createnode();
  if(head!=NULL)
  {
    DLL->rlink=head;
    head->llink=DLL;
  }
  head=DLL;
}
void DeleteFront()
{
  Node DLL=head;
  printf("The deleted node is:\n");
  printf("SSN=%s\n",DLL->SSN);
  printf("Name=%s\n",DLL->Name);
  printf("Department=%s\n",DLL->dept);
  printf("Designation=%s\n",DLL->des);
  printf("Salary=%s\n",DLL->sal);
  printf("Phone number=%s\n",DLL->phone);
  head=DLL->rlink;
  head->llink=NULL;
  free(DLL);
}
void InsertEnd()
{
  Node DLL,temp=head;
  DLL=createnode();
  if(head==NULL)
    head=DLL;
  else
  {
    while(temp->rlink!=NULL)
      temp=temp->rlink;
    temp->rlink=DLL;
    DLL->llink=temp;
  }
}
void DeleteEnd()
{
  Node temp=head,t;
  if(head==NULL)
    printf("The list is empty\n");
  else
  {
    while(temp->rlink!=NULL)
    {
      t=temp;
      temp=temp->rlink;
    }
    printf("The deleted node is\n");
    printf("SSN=%s\n",temp->SSN);
    printf("Name=%s\n",temp->Name);
    printf("Department=%s\n",temp->dept);
    printf("Designation=%s",temp->des);
    printf("Salary=%s",temp->sal);
    printf("Phone number=%s",temp->phone);
    free(t->rlink);
    t->rlink=NULL;
  }
}
void create()
{
  int n,i;
  printf("Enter the number of employees\n");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    InsertEnd();
}
void display()
{
  int c=0;
  Node temp=head;
  while(temp!=head)
  {
    fflush(stdout);
    printf("\n%s\t",temp->SSN);
    printf("%s\t",temp->Name);
    printf("%s\t",temp->dept);
    printf("%s\t",temp->des);
    printf("%s\t",temp->sal);
    printf("%s\t",temp->phone);
    temp=temp->rlink;
    c=c+1;
  }
  printf("The number of nodes are %d",c);
}
void dequeue()
{
  int choice;
  printf("\n1:Insert at front\n2:Insert at end\n3:Delete from front\n4:Delete from rear\nEnter your choice\t");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:printf("\nEnter details to be inserted\n");
           InsertFront();
           break;
    case 2:printf("\nEnter details to be inserted\n");
           InsertEnd();
           break;
    case 3:DeleteFront();
           break;
    case 4:DeleteEnd();
           break;
  }
}
int main()
{
  int ch1,ch2,ch3;
  while(1)
  {
    printf("\nEnter your choice\n1:Create\n2:Display and count\n3:Insert and delete at end\n4:Insert and delete at front\n5:DLL as dequeue\n6:Exit");
    scanf("%d",&ch1);
    switch(ch1)
    {
      case 1:create();
             break;
      case 2:display();
             break;
      case 3:printf("\nEnter your choice:1:Insert\t2:Delete\n");
             scanf("%d",&ch2);
             if(ch2==1)
              InsertEnd();
             else
              DeleteEnd();
            break;
      case 4:printf("\nEnter your choice:1:Insert\t2:Delete\t");
             scanf("%d",&ch3);
             if(ch3==1)
              InsertFront();
            else
              DeleteFront();
            break;
      case 5:dequeue();
             break;
      case 6:exit(0);
    }
  }
  return 0;
}
