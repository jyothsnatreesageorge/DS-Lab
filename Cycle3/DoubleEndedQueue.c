# include<stdio.h>
# include<stdlib.h>
void frontenqueue();
void frontdequeue();
void rearenqueue();
void reardequeue();
void display();
int item;
int choice;
int front=-1;
int rear=-1;
int size;
int queue[50];
int main()
{
    printf("Enter the size of the queue:");
    scanf("%d",&size);
    int queue[size];
    printf("Displaying the menu\n");
    printf("1:Front enqueue\n2:Rear enqueue\n3:Front Dequeue\n4:Rear dequeue\n5:Display\n6:Exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                frontenqueue();
                break;
            }
            case 2:
            {
                rearenqueue();
                break;
            }
            case 3:
            {
                frontdequeue();
                break;
            }
            case 4:
            {
                reardequeue();
                break;
            }
            case 5:
            {
                display();
                break;
            }
            case 6:
            {
                exit(1);
                break;
            }
            default:
            {
                printf("Invalid Choice!");
                break;
            }
        }
    }
}
void frontenqueue()
{
    if(front==0&&rear==size-1||front==rear+1)
    {
        printf("Queue Full\n");
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        printf("Enter the item to be inserted:");
        scanf("%d",&item);
        queue[front]=item;
    }
    else if(front==0)
    {
        front=size-1;
        printf("Enter the item to be inserted:");
        scanf("%d",&item);
        queue[front]=item;
    }
    else
    {
        front=front-1;
        printf("Enter the item to be inserted:");
        scanf("%d",&item);
        queue[front]=item;
    }
    display();
}
void rearenqueue()
{
    if(front==0&&rear==size-1||front==rear+1)
    {
        printf("Queue Full\n");
    }
    else if(front==-1&&rear==-1)
    {
        front=rear=0;
        printf("Enter the item to be inserted:");
        scanf("%d",&item);
        queue[rear]=item;
    }
    else if(rear==size-1)
    {
        rear=0;
        printf("Enter the item to be inserted:");
        scanf("%d",&item);
        queue[rear]=item;
    }
    else
    {
        rear=rear+1;
        printf("Enter the item to be inserted:");
        scanf("%d",&item);
        queue[rear]=item;
    }
    display();
}
void frontdequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("The queue is empty!\n");
    }
    else if(front==rear)
    {
        printf("The deleted element is %d\n",queue[front]);
        front=rear=-1;
    }
    else if(front==size-1)
    {
        printf("The deleted element is %d\n",queue[front]);
        front=0;
    }
    else
    {
        printf("The deleted element is %d\n",queue[front]);
        front++;
    }
    display();
}
void reardequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("The queue is empty!\n");
    }
    else if(front==rear)
    {
        printf("The deleted element is %d\n",queue[front]);
        front=rear=-1;
    }
    else if(rear==0)
    {
        printf("The deleted element is %d\n",queue[rear]);
        rear=size-1;
    }
    else
    {
        printf("The deleted element is %d\n",queue[rear]);
        rear--;
    }
    display();
}
void display()
{
    int i=front;
    while(i!=rear)
    {
        printf("%d\t",queue[i]);
        i=(i+1)%size;
    }
    printf("%d",queue[rear]);
    printf("\n");
}
