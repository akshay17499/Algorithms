#include<stdio.h>

void count_sort(int *arr,int size)
{
  int max=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
     int count[max];
     
      for(int i=0;i<size;i++)
        count[i]=0;
     
      for(int i=0;i<size;i++)
          ++count[arr[i]];
          
      int arrb[size];
      for(int i=1;i<=max;i++)
          count[i]+=count[i-1];
      
      for(int i=size-1;i>=0;i--)
          arrb[--count[arr[i]]]=arr[i];
          
      
      for(int i=0;i<size;i++)
      arr[i]=arrb[i];
}
int main()
{
    int size;
    printf("enter array size");
    scanf("%d",&size);
    int arr[size];
    printf("enter array elements");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    count_sort(arr,size);
     for(int i=0;i<size;i++)
     {
        printf("%d ",arr[i]);
    }
}