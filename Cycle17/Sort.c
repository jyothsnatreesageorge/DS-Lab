#include<stdio.h>
#include<stdlib.h>
int i,j,size,choice;
int *a,*copy;
void duip(int a[],int b[])
{
    for(i=0;i<size;i++)
    {
        b[i]=a[i];
    }
}
void display(int a[],int size)
{
    printf("Printing the array:");
    for(i=0;i<size;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void bubblesort(int a[],int size)
{
    for(i=0;i<size;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int minpos(int a[],int i,int size)
{
    int j;
    int least=i;
    for(j=i+1;j<size;j++)
    {
        if(a[j]<a[least])
        {
            least=j;
        }
    }
    return least;
}
void selectionsort(int a[],int size)
{
    for(i=0;i<size-1;i++)
    {
        int min=minpos(a,i,size);
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}
void insertionsort(int a[],int size)
{
    int i,j;
    for(i=1;i<size;i++)
    {
        int key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
void merge(int a[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=0;
    int temp[size];
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            temp[k++]=a[i++];
        }
        else /*if(a[j]>=a[i])*/
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=high)
    {
        temp[k++]=a[j++];
    }
    for(i=low,k=0;i<=high;i++,k++)
    {
        a[i]=temp[k];
    }
}
void mergesort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void quicksort(int a[],int low,int high)
{
    if(low<high){
    int i=low;
    int j=high+1;
    int pivot=a[low];
    while(i<j)
    {
        if(i<high&&a[i]<=pivot)
        {
            i++;
        }
        if(j>low&&a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    a[low]=a[j];
    a[j]=pivot;
    quicksort(a,low,j-1);
    quicksort(a,j+1,high);
    }
}
void heapify(int a[],int size,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size&&a[left]>a[largest])
    {
        largest=left;
    }
    if(right<size&&a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,size,largest);
    }
}
void heapsort(int a[],int size)
{
    for(i=(size/2)-1;i>=0;i--)
    {
        heapify(a,size,i);
    }
    for(i=size-1;i>=0;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}
int main()
{
    printf("Enter the size of the array:");
    scanf("%d",&size);
    a=(int*)malloc(size*(sizeof(int)));
    for(i=0;i<size;i++)
    {
        printf("Enter the element:");
        scanf("%d",&a[i]);
    }
    copy=(int*)malloc(size*sizeof(int));
    printf("1.Bubble\n2.Insertion\n3.Selection\n4.Merge\n5.Quick\n6.Heap\n7.Exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                duip(a,copy);
                display(copy,size);
                bubblesort(copy,size);
                display(copy,size);
                break;
            }
            case 2:
            {
                duip(a,copy);
                display(copy,size);
                selectionsort(copy,size);
                display(copy,size);
                break;
            }
            case 3:
            {
                duip(a,copy);
                display(copy,size);
                insertionsort(copy,size);
                display(copy,size);
                break;
            }
            case 4:
            {
                duip(a,copy);
                display(copy,size);
                mergesort(copy,0,size-1);
                display(copy,size);
                break;
            }
            case 5:
            {
                duip(a,copy);
                display(copy,size);
                quicksort(copy,0,size-1);
                display(copy,size);
                break;
            }
            case 6:
            {
                duip(a,copy);
                display(copy,size);
                heapsort(copy,size);
                display(copy,size);
                break;
            }
            case 7:
            {
                exit(0);
            }
        }
    }
    return 0;
}
