#include<stdio.h>
void read(char *s)
{
  gets(s);
}
void strcopy(char *s1,char *s2)
{
  int i;
  for(i=0;s2[i]!='\0';i++)
    s1[i]=s2[i];
  s1[i]='\0';
}
int matchnreplace(char *str,char *pat,char *rep)
{
  char ans[100];
  int i=0,m=0,c=0,flag=0,j=0,k;
  while(str[c]!='\0')
  {
    if(str[m]==pat[i])
    {
      i++;
      m++;
      if(pat[i]=='\0')
      {
        flag=1;
        for(k=0;rep[k]!='\0';k++,j++)
          ans[j]=rep[k];
        i=0;
        c=m;
      }
    }
    else
    {
      ans[j]=str[c];
      j++;c++;m=c;i=0;
    }
  }
  ans[j]='\0';
  strcopy(str,ans);
  return flag;
}
int main()
{
  char str[100],pat[50],rep[50];
  int flag=0;
  printf("Enter the string\t");
  read(str);
  printf("\nEnter the pattern\t");
  read(pat);
  printf("\nEnter the string by which we should replace\n");
  read(rep);
  flag=matchnreplace(str,pat,rep);
  if(flag==1)
    printf("The string is found %s",str);
  else
  printf("The string is not found");
  return 0;
}
