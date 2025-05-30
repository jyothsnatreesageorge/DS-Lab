# include<stdio.h>
# include<stdlib.h>
int main()
{
	int a[50],i,j,key,size;
	int *p;
        printf("Enter the size of the array:");
        scanf("%d",&size);
	p=(int *)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
	{
		printf("Enter the %d element:",i+1);
		scanf("%d",&p[i]);
	}
	printf("Enter the element to be searched:");
	scanf("%d",&key);
	for(i=0;i<size;i++)
	{
		if(key==p[i])
		{
			printf("Element found at position %d\n",i+1);
			break;
		}
	}
	if(i==size)
	{
		printf("Element is not present in the array\n");
	}
	free(p);
	return 0;
}
