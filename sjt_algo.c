#include<stdio.h>

void print(int *permu,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",permu[i]);
    }
    printf("\n");
}

int largest_mobile_index(int*permu,int*dir,int n)
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

void swap(int *temp1,int *temp2)
{
    int temp=*temp1;
    *temp1=*temp2;
    *temp2=temp;
}

void sjt_algo(int n)
{
    int permu[n];
    int dir[n];

    for(int i=0;i<n;i++)
    {
        permu[i]=i+1;
        dir[i]=0;
    }

    int largestindex;
    print(permu,n);

    while(1)
    {
        largestindex=largest_mobile_index(permu,dir,n);

        if(largestindex==-1)
        break;

        if(dir[largestindex]==0&&permu[largestindex]>permu[largestindex-1])
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
    }
}

int main()
{
    int num;
    printf("Enter number to find permutation from 1 to that num : ");
    scanf("%d",&num);
    sjt_algo(num);
}