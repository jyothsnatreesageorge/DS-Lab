# include<stdio.h>
# include<stdlib.h>
void enqueue();
void dequeue();
void display();
int front[10];
int rear[10];
int maxpriority;
int item;
int size;
int choice;
int priority;
int queue[10][10];
int main()
{
    printf("Enter the maximum priority levels in the queue:");
    scanf("%d",&maxpriority);
    printf("Enter the size of the queue:");
    scanf("%d",&size);
    
    for(int i=0;i<maxpriority;i++)
    {
        front[i]=-1;
        rear[i]=-1;
    }
    printf("Displaying the menu\n");
    printf("1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                enqueue();
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(1);
                break;
            }
            default:
            {
                printf("Invalid choice\n");
                break;
            }
        }
    }
}
void enqueue()
{
    printf("Enter the priority level:");
    scanf("%d",&priority);
    if(priority<1||priority>maxpriority)
    {
        printf("Invalid priority\n");
    }
    else
    {
        if(rear[priority-1]==size-1)
        {
            printf("Queue is full at priority level %d\n",priority);
        }
        else
        {
            printf("Enter the item to be inserted:");
            scanf("%d",&item);
            rear[priority-1]=rear[priority-1]+1;
            queue[priority-1][rear[priority-1]]=item;
            if(front[priority-1]==-1)
            {
                front[priority-1]=0;
            }
            display();
        }
    }
}
void dequeue()
{
    int i=0;
    while(front[i]==-1&&i<maxpriority)
    {
        i++;
    }
    if(i==maxpriority)
    {
        printf("Queue is empty at all priority levels\n");
    }
    else
    {
        item=queue[i][front[i]];
        front[i]=front[i]+1;
        if(front[i]>rear[i])
        {
            front[i]=rear[i]=-1;
        }
        printf("The deleted item is %d\n",item);
    }
}
void display()
{
    int i=0;
    while(front[i]==-1&&i<maxpriority)
    {
        i++;
    }
    if(i==maxpriority)
    {
        printf("Queue is empty at all priority levels\n");
    }
    else
    {
        int i,j=0;
        for(i=0;i<maxpriority;i++)
        {
            printf("Priority level:%d\t",i+1);
            for(j=front[i];j<=rear[i];j++)
            {
                printf("%d\t",queue[i][j]);
            }
            printf("\n");
        }
    }
}
