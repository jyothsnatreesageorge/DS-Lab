# include<stdio.h>
struct poly
{
    float coeff;
    int exp;

}p[10],q[10],r[10];
int main()
{
    int n1,n2,i,j,k,exp;
    float coeff;
    printf("Enter the number of terms(<10) of polynomial 1:");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Enter the exponent of term %d:",i+1);
        scanf("%d",&p[i].exp);
        printf("Enter the coefficient of term %d:",i+1);
        scanf("%f",&p[i].coeff);
    }
    printf("Enter the number of terms(<10) of polynomial 2:");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("Enter the exponent of term %d:",i+1);
        scanf("%d",&q[i].exp);
        printf("Enter the coefficient of term %d:",i+1);
        scanf("%f",&q[i].coeff);
    }
    i=0,j=0,k=0;
    while(i<n1&&j<n2)
    {
        if(p[i].exp==q[j].exp)
        {
            r[k].exp=p[i].exp;
            r[k].coeff=p[i].coeff+q[j].coeff;
            i++;
            j++;
            k++;
        }
        else if(p[i].exp>q[j].exp)
        {
            r[k].exp=p[i].exp;
            r[k].coeff=p[i].coeff;
            i++;
            k++;
        }
        else
        {
            r[k].exp=q[j].exp;
            r[k].coeff=q[j].coeff;
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        r[k].exp=p[i].exp;
        r[k].coeff=p[i].coeff;
        i++;
        k++;
    }
    while(j<n2)
    {
        r[k].exp=q[j].exp;
        r[k].coeff=q[j].coeff;
        j++;
        k++;
    }
    int total=k;
    printf("\nPolynomial 1:\t");
    for(i=0;i<n1;i++)
    {
        printf("%.1fx^%d",p[i].coeff,p[i].exp);
        if(i<n1-1)
        printf("+");
    }
    printf("\nPolynomial 2:\t");
    for(j=0;j<n2;j++)
    {
        printf("%.1fx^%d",q[j].coeff,q[j].exp);
        if(j<n2-1)
        printf("+");
    }
    printf("\nResultant Polynomial:\t");
    for(k=0;k<total;k++)
    {
        printf("%.1fx^%d",r[k].coeff,r[k].exp);
        if(k<total-1)
        printf("+");
    }
    return 0;
}
