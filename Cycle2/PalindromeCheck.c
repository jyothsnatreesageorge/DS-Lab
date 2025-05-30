# include<stdio.h>
# include<string.h>
int top1=-1;
int top2=-1;
int top3=-1;
int flag=0;
int main()
{
    char s1[50],s2[50],s3[50],str[50];
    int i,item,len;
    printf("Enter the string:");
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        top1=top1+1;
        s1[top1]=str[i];
    }
    for(i=0;i<len;i++)
    {
        top3=top3+1;
        s3[top3]=str[i];
    }
    while(top1>-1)
    {
        item=s1[top1];
        top2=top2+1;
        s2[top2]=item;
        top1=top1-1;
    }
    for(i=0;i<len;i++)
    {
        if(s3[i]!=s2[i])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("The given string is a palindrome\n");
    }
    if(flag==1)
    {
        printf("The given string is not a palindrome\n");
    }
    return 0;
}
