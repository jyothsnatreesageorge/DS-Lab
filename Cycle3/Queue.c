# include<stdio.h>
# include<stdlib.h>
# define max_size 50
void input();
void dequeue();
void display();
int front=-1;
int rear=-1;
int user;
int queue[max_size];
int main()
{
	int choice;
	char res;
	printf("Enter size of the queue:");
	scanf("%d",&user);
	int queue[user];
    printf("Displaying the menu:\n");
	printf("1:Insert elements into the queue\n2:Delete elements from the queue\n3:Display the contents of the queue\n4:Exit\n");
	while(1)
	{
		
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				input();
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
				printf("Invalid choice!");
				break;
			}
		}
	}
	return 0;
}

void input()
{
	int item;
	if(rear==user-1)
	{
		printf("Queue Overflow!\n");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		printf("Enter the element to be inserted:");
		scanf("%d",&item);
		rear=rear+1;
		queue[rear]=item;
	}
}

void dequeue()
{
	if(front>rear||front==-1)
	{
		printf("Queue underflow!\n");
	}
	else
	{
		printf("Element deleted from the queue is %d\n",queue[front]);
		front=front+1;
		if(front>rear)
		front=rear=-1;
	}
}

void display()
{
	if(front==-1)
	{
		printf("The queue is empty\n");
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
		printf("\n");
	}
}
