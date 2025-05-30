# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<math.h>
# include<ctype.h>
char s1[50];
int s2[50];
char item;
int num;
int res;
int a;
int b;
int result;
void pushchar(char item,char s[50],int *top);
void pushint(int item,int s[50],int *top);
char popchar(char s[50],int *top);
int popint(int s[50],int *top);
int top1=-1;
int top2=-1;
int icp(char item);
int isp(char item);
char eval[50];
int main()
{
    char expr[50];
    char x,y,z;
    printf("Enter the expression:");
    scanf("%s",expr);
    strcat(expr,"#");
    int i=0,j=0;
    while(expr[i]!='#')
    {
        x=expr[i];
        if(x=='(')
        {
            pushchar(x,s1,&top1);
        }
        else if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
        {
            while(top1>-1&&icp(x)<=isp(s1[top1]))
            {
                y=popchar(s1,&top1);
                eval[j++]=y;
            }
            pushchar(x,s1,&top1);
        }
        else if(x>='a'&&x<='z'||x>='A'&&x<='Z'||x>='0'&&x<='9')
        {
            eval[j++]=x;
        }
        else if(x==')')
        {
            while((y=popchar(s1,&top1))!='(')
            eval[j++]=y; 
        }
        i++;
    }
    while(top1>-1)
    {
        y=popchar(s1,&top1);
        eval[j++]=y;
    }
    eval[j]='\0';
    printf("Postfix expression is %s\n",eval);
    strcat(eval,"#");
    i=0;
    while(eval[i]!='#')
    {
        z=eval[i];
        if(isdigit(z))
        {
            pushint(z-'0',s2,&top2);
        }
        else if(z=='+'||z=='-'||z=='*'||z=='/'||z=='^')
        {
            a=popint(s2,&top2);
            b=popint(s2,&top2);
            switch(z)
            {
                case '+':
                res=b+a;
                break;
                case '-':
                res=b-a;
                break;
                case '*':
                res=b*a;
                break;
                case '/':
                res=b/a;
                break;
                case '^':
                res=pow(b,a);
                break;
                default:
                printf("Undefined operator\n");
                break;
            }
            pushint(res,s2,&top2);
        }
        i++;
    }
    result=popint(s2,&top2);
    printf("The result of evaluation of the postfix expression %d\n",result);
    return 0;
}
void pushchar(char item,char s[50],int *top)
{
    *top=*top+1;
    s[*top]=item;
}
void pushint(int item,int s[50],int *top)
{
    *top=*top+1;
    s[*top]=item;
}
char popchar(char s[50],int *top)
{
    item=s[*top];
    *top=*top-1;
    return item; 
}
int popint(int s[50],int *top)
{
    num=s[*top];
    *top=*top-1;
    return num; 
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
