# include<stdio.h>
# include<stdlib.h>
int size;
int front=-1;
int rear=-1;
int item;
int queue[50];
void display();
void enqueue();
void dequeue();
int main()
{
    int choice;
    char res;
    printf("Enter the size of the queue:");
    scanf("%d",&size);
    printf("Displaying the menu\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");
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
    return 0;
}
void enqueue()
{
    if(front==0&&rear==size-1||front==(rear+1)%size)
    {
        printf("Queue full!\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        printf("Enter the element to be inserted in the queue:");
        scanf("%d",&item);
        rear=(rear+1)%size;
        queue[rear]=item;
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("Queue empty!\n");
    }
    else
    {
        printf("Element deleted from the queue is %d\n",queue[front]);
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
    }
}
void display()
{
    if(front==-1)
    {
        printf("Queue empty!\n");
    }
    else
    {
        int i=front;
        while(i!=rear)
        {
            printf("%d\t",queue[i]);
            i=(i+1)%size;
        }
        printf("%d\n",queue[rear]);
    }
}
