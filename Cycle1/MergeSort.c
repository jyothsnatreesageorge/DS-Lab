# include<stdio.h>
int main()
{
    int arr1[20],arr2[20],arr3[40],i,j,k,m,n;
    printf("Enter the elements of the array:");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("Enter the element:");
        scanf("%d",&arr1[i]);
    }
    printf("Enter the elements of the array:");
    scanf("%d",&n);
    for(j=0;j<n;j++)
    {
        printf("Enter the element:");
        scanf("%d",&arr2[j]);
    }
    i=0,j=0,k=0;
    while(i<m&&j<n)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k]=arr1[i];
            i++;
            k++;
        }
        else if(arr2[j]<arr1[i])
        {
            arr3[k]=arr2[j];
            j++;
            k++;
        }
    }
    if(i<m)
    {
        while(i<m)
        {
            arr3[k]=arr1[i];
            i++;
            k++;
        }
    }
    else if(j<n)
    {
        while(j<n)
        {
            arr3[k]=arr2[j];
            j++;
            k++;
        }
    }
    printf("Printing the sorted array:");
    for(i=0;i<(m+n);i++)
    {
        printf("%d\t",arr3[i]);
    }
    return 0;
}
