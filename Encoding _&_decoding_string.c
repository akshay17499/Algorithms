#include <stdio.h>
#include <string.h>
int main() 
{
    
    int sum=3;
    printf("Enter your name : ");
    char str[50];
    scanf("%[^\n]",str);
   
    int len =strlen(str);
    short int arr[8*len];
    for(int i=0;i<8*len;i++)
    {
        arr[i]=sum;
        sum++;
    } printf("%d\n",arr[8]);
    int i=0;
    for(int j=0;j<len;j++)
    {
       char ch =str[j];
       int n=7;
       int m=8;
      while(m)
      {
        m--;
       int mask=1<<(n) ;
       mask=mask&ch;
       mask=mask>>n;
       arr[i]=arr[i]&((1<<8)-2);
       arr[i]=arr[i]|mask;
       n--;
       i++;
      }

    }
    
   char c;
    int temp=0;
    int last=0;
   // int i;
    for(int j=0;j<len;j++)
    { 
        temp=0;
      for(i=last;i<last+8;i++)
      {
        c=arr[i]&1;
        temp=temp|c<<(7-i%8);
      
      }
     last=i;
     printf("%c",temp);
    }
}
    
