#include<stdio.h>
int arr[50];
int z=0;
void  print(int*permu,int n)
{
    int num=0;
    for(int i=0;i<n;i++)
    {
       int digit=permu[i];
       num=num*10+digit;
        
    }
    arr[z++]=num;
   // printf("%d",num);
    //printf("\n");
}
int largest_mobile(int*permu,int *dir,int n)
{
    int largestindex=-1;
    for(int i=0;i<n;i++)
    {
        if(dir[i]==0&&i>0&&permu[i]>permu[i-1])
        {
            if(largestindex==-1||permu[i]>permu[largestindex])
            largestindex=i;
        }
        else if(dir[i]==1&&i<n-1&&permu[i]>permu[i+1])
        {
            if(largestindex==-1||permu[i]>permu[largestindex])
            largestindex=i;
        }
    }
    return largestindex;
}

void swap(int*temp1,int*temp2)
{
    int temp=*temp1;
    *temp1=*temp2;
    *temp2=temp;
}

void sjt_algo(int*permu,int n)
{
    int dir[n];
    for(int i=0;i<n;i++)
    {
        dir[i]=0;
    }
    int count=0;
    int largestindex;
    print(permu,n);
    count++;
    while(1)
    {
        largestindex=largest_mobile(permu,dir,n);
        
        if(largestindex==-1)
        break;
        
        if(dir[largestindex]==0)
        {
            swap(&permu[largestindex],&permu[largestindex-1]);
             swap(&dir[largestindex],&dir[largestindex-1]);
             largestindex--;
        }
        else
        {
          swap(&permu[largestindex],&permu[largestindex+1]);
          swap(&dir[largestindex],&dir[largestindex+1]);
          largestindex++; 
        }
        
        for(int i=0;i<n;i++)
        {
            if(permu[i]>permu[largestindex])
            {
                dir[i]=1-dir[i];
            }
        }
        
        print(permu,n);
        count++;
    }
   printf("Total no of permutation possible on given n.o are : %d\n",count); 
}

void bubble(int*permu,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(permu[j]>permu[j+1])
            swap(&permu[j],&permu[j+1]);
        }
    }
}
int main()
{
    int n;
    printf("enter size of array : ");
    scanf("%d",&n);
    int permu[n];
    printf("enter array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&permu[i]);
    }
    bubble(permu,n);
    sjt_algo(permu,n);
    bubble(arr,z);
   for(int i=0;i<z;i++)
    {
        printf("%d\n",arr[i]);
    } 
}