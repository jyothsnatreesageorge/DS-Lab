# include<stdio.h>
# include<stdlib.h>
int main()
{
	int size,i,key;
        printf("Enter the size of the array:");
        scanf("%d",&size);
	int *p=(int *)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
	{
		printf("Enter the element %d:",i+1);
		scanf("%d",&p[i]);
	}
	int low=0;
	int high=size-1;
	printf("Enter the key to be searched:");
	scanf("%d",&key);
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(p[mid]==key)
		{
			printf("Element found at position %d\n",mid+1);
			break;
		}
		else if(key<p[mid])
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	if(low>high)
	{
		printf("Element is not found\n");
	}
	return 0;
}
