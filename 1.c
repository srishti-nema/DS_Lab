#include<stdio.h>
#include<stdlib.h>
int n;
void read(int a[10])
{
  int i;
  printf("\nEnter the elements\n");
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
}
void print(int a[10])
{
  int i;
  printf("The elements are\n");
  for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}
void insert(int a[10],int ele,int pos)
{
  int i;
  for(i=n-1;i>=pos-1;i--)
    a[i+1]=a[i];
  a[pos-1]=ele;
  n++;
}
int delete(int a[10],int pos)
{
  int i,ele;
  ele=a[pos-1];
  for(i=pos-1;i<n;i++)
    a[i]=a[i+1];
  n--;
  return ele;
}
int main()
{
  int a[10],ch,ele,pos;
  while(1)
  {
    printf("\nEnter your choice:\n1:Read\n2:Print\n3:Insert\n4:Delete\n5:Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("\nEnter the number of elements");
             scanf("%d",&n);
             read(a);
             break;
      case 2:print(a);
             break;
      case 3:printf("Enter the element to be inserted");
             scanf("%d",&ele);
             printf("Enter the position of the element");
             scanf("%d",&pos);
             insert(a,ele,pos);
             break;
      case 4:printf("\nEnter the position of the element to be deleted\t");
             scanf("%d",&pos);
             ele=delete(a,pos);
             printf("deleted element:%d\t",ele);
             break;
      case 5:exit(0);
    }
  }
  return 0;
}
