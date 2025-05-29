# include<stdio.h>
int main()
{
    int a[10],n,i,smallest;
    int *p;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element:");
        scanf("%d",&a[i]);
    }
    p=a;
    smallest=*p;
    for(i=0;i<n;i++)
    {
        if(*p<smallest)
        {
            smallest=*p;
        }
        *p++;
    }
    printf("The smallest element in the given set of integers is %d\n",smallest);
    return 0;
}
