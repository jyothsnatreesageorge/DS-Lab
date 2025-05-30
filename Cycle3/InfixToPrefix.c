# include<stdio.h>
# include<string.h>
char expr[50];
char rev[50];
char s[50];
char s1[50];
char s2[50];
char fin[50];
char reverse1[50];
char reverse2[50];
int top=-1;
int top1=-1;
int top2=-1;
int i;
char x,y,item;
void push(char s[50],char item,int *top);
char pop(char s[50],int *top);
int icp(char item);
int isp(char item);
void strreverse(char s1[50],char s2[50]);
int main()
{
    printf("Enter the exprssion:");
    scanf("%s",expr);
    strreverse(expr,reverse1);
    strcpy(rev,reverse1);
    for(i=0;rev[i]!='\0';i++)
    {
        if(rev[i]==')')
        rev[i]='(';
        else if(rev[i]=='(')
        rev[i]=')';
    }
    strcat(rev,"#");
    i=0;
    while(rev[i]!='#')
    {
        x=rev[i];
        if(x=='(')
        {
            push(s1,x,&top1);
        }
        else if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
        {
            while(top1>-1&&icp(x)<=isp(s1[top1]))
            {
                y=pop(s1,&top1);
                s2[++top2]=y;
            }
            push(s1,x,&top1);
        }
        else if(x==')')
        {
            while((y=pop(s1,&top1))!='(')
            s2[++top2]=y; 
        }
        else if(x>='a'&&x<='z'||x>='A'&&x<='Z'||x>='0'&&x<='9')
        {
            s2[++top2]=x;
        }
        i++;
    }
    while(top1>-1)
    {
        y=pop(s1,&top1);
        s2[++top2]=y;
    }
    s2[++top2]='\0';
    strreverse(s2,reverse2);
    strcpy(fin,reverse2);
    printf("The prefix expression is %s\n",fin);
    return 0;
}
void push(char s[50],char item,int *top)
{
    *top=*top+1;
    s[*top]=item;
}
char pop(char s[50],int *top)
{
    item=s[*top];
    *top=*top-1;
    return item; 
}
void strreverse(char s1[50],char s2[50])
{
    int len=strlen(s1);
    for(i=0;i<len;i++)
    {
        s2[i]=s1[len-i-1];
    }
}
int icp(char item)
{
    if(item=='+'||item=='-')
    return 1;
    else if(item=='*'||item=='/')
    return 3;
    else if(item=='^')
    return 6;
    else if(item=='(')
    return 7;
    else if(item==')')
    return 0;
}
int isp(char item)
{
    if(item=='+'||item=='-')
    return 2;
    else if(item=='*'||item=='/')
    return 4;
    else if(item=='^')
    return 5;
    else if(item=='(')
    return 0;
}
