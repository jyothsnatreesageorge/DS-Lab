#include<stdio.h>
#include<string.h>
int main()
{
    char str[20],longest[20];
    int i,j,k,l=0,start=0,currlen=0;
    printf("Enter the string:");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
        int flag=0;
        for(j=start;j<i;j++)
        {
            if(str[j]==str[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            start=j+1;
        }
        currlen=i-start+1;
        if(currlen>l)
        {
            l=currlen;
            for(k=0;k<currlen;k++)
            {
                longest[k]=str[start+k];
            }
            longest[k]='\0';
        }
    }
    printf("The longest substring is:%s\n",longest);
    printf("The length of the longest substring is %d\n",strlen(longest));
    return 0;
}

