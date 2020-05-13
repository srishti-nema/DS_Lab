#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
  char usn[3];
  char name[10];
  char branch[4];
  char sem[3];
  char phone[10];
  struct node *link;
};
typedef struct node* Node;
Node head=NULL;
Node createnode()
{
  Node temp;
  temp=(Node)malloc(sizeof(struct node));
  fflush(stdin);
  printf("Enter the usn:");
  gets(temp->usn);
  printf("\nEnter the name:");
  gets(temp->name);
  printf("\nEnter branch");
  gets(temp->branch);
  printf("\nEnter sem");
  gets(temp->sem);
  printf("\nEnter phone number");
  gets(temp->phone);
  temp->link=NULL;
  return temp;
}
void InsertFront()
{
  Node SLL=NULL;
  SLL=createnode();
  if(head!=NULL)
    SLL->link=head;
  head=SLL;
}
void DelFront()
{
  Node SLL=head;
  printf("The deleted node is \n");
  printf("USN=%s\n",SLL->usn);
  printf("Name=%s\n",SLL->name);
  printf("Sem=%s\n",SLL->sem);
  printf("Phone=%s\n",SLL->phone);
  head=SLL->link;
  free(SLL);
}
void InsertEnd()
{
  Node SLL,temp=head;
  SLL=createnode();
  if(head==NULL)
    head=SLL;
  else
  {
    while(temp->link!=NULL)
      temp=temp->link;
    temp->link=SLL;
  }
}
void deleteEnd()
{
  Node temp=head;
  Node t;
  if(head==NULL)
  {
    printf("Link list is empty");
  }
  else
  {
    while(temp->link!=NULL)
    {
      t=temp;
      temp=temp->link;
    }
    printf("The deleted node is \n");
    printf("USN=%s",temp->usn);
    printf("Name=%s",temp->name);
    printf("Sem=%s",temp->sem);
    printf("Phone=%s",temp->phone);
    free(t->link);
    t->link=NULL;
  }
}
void create()
{
  int n,i;
  printf("\nEnter the number of students");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    InsertFront();
  }
}
void display()
{
  int c=0;
  Node temp=head;
  while(temp!=NULL)
  {
    fflush(stdout);
    printf("\n%s\t",temp->usn);
    printf("%s\t",temp->name);
    printf("%s\t",temp->branch);
    printf("%s\t",temp->sem);
    printf("%s\t",temp->phone);
    temp=temp->link;
    c=c+1;
  }
  printf("\nThe number of nodes:%d",c);
}
void stack()
{
  int choice;
  printf("\n1:PUSH\n2:POP\n3:DISPLAY\nEnter your choice:");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:printf("Enter the details to be pushed on to the stack\n");
           InsertFront();
           break;
    case 2:printf("The popped node is:\n");
           DelFront();
           break;
    case 3:printf("The stack is:\n");
           display();
   }
}
int main()
{
  int ch1,ch2,ch3;
  while(1)
  {
    printf("\nEnter your choice\n1:Create\n2:Display and count\n3:Insert and delete at end\n4:Insert and delete from front\n5:SLL as stack\n6:Exit");
    scanf("%d",&ch1);
    switch(ch1)
    {
      case 1:create();
             break;
      case 2:display();
             break;
      case 3:printf("Enter your choice:1:Insert\t2:Delete\t");
             scanf("%d",&ch1);
             if(ch2==1)
              InsertEnd();
             else
              deleteEnd();
             break;
      case 4:printf("Enter your choice:1:Insert\t2:Delete\t");
             scanf("%d",&ch3);
             if(ch3==1)
              InsertFront();
             else
               DelFront();
             break;
      case 5:stack();
             break;
      case 6:exit(0);
     }
  }
}
