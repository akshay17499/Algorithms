#include<stdio.h>
#include <string.h>

void print(char**permu,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%s ",*(permu+i));
    }
    
    printf("\n");
}

int largest_mobile_index(char**permu,char*dir,int n)
{
    int largestindex=-1;
    for(int i=0;i<n;i++)
    {
        if(dir[i]=='0'&&i>0&&(strcmp(*(permu+i),*(permu+i-1))>0))
        {
            if(largestindex==-1||(strcmp(*(permu+i),*(permu+largestindex))>0))
            largestindex=i;
        }
        else if(dir[i]=='1'&&i<n-1&&(strcmp(permu[i],permu[i+1])>0))
        {
            if(largestindex==-1||(strcmp(permu[i],permu[largestindex])>0))
            largestindex=i;
        }
    }
    return largestindex;
}

void swap(char*temp1,char*temp2)
{
    char temp[50];
    strcpy(temp,temp1);
    strcpy(temp1,temp2);
    strcpy(temp2,temp);
}

void sjt_algo(char**permu,int n)
{
    char dir[n];
    for(int i=0;i<n;i++)
    {
        dir[i]='0';
    }
    int largestindex;
    print(permu,n);
    int m=1;
    while(1)
    {
        largestindex=largest_mobile_index(permu,dir,n);
        
        if(largestindex==-1)
        break;
        
       if(dir[largestindex]=='0')
        {
            swap(permu[largestindex],permu[largestindex-1]);
            swap(&dir[largestindex],&dir[largestindex-1]);
            largestindex--;
        }
        else
        {
            swap(permu[largestindex],permu[largestindex+1]);
            swap(&dir[largestindex],&dir[largestindex+1]);
            largestindex++; 
        }
        
        for(int i=0;i<n;i++)
        {
            
            if(strcmp(permu[i],permu[largestindex])>0)
            {
                if(dir[i]=='0')
                dir[i]='1';
                else
                dir[i]='0';
            }
            
        }
        print(permu,n);
    }
}
int main()
{
    printf("Enter size of string : ");
    int n;
    scanf("%d",&n);
    printf("Enter string 1 : ");
    char temp1[n];
    scanf("%s",temp1);
     printf("Enter string 2 : ");
    char temp2[n];
    scanf("%s",temp2);
     printf("Enter string 3 : ");
    char temp3[n];
    scanf("%s",temp3);
    char *permu[3]={temp1,temp2,temp3};
     printf("The Permutations of entered strings : \n");
    sjt_algo(permu,3);
}