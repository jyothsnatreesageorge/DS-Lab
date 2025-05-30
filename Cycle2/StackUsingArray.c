#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void peek();
int top=-1;
int item;
int size;
int choice;
int s[50];
int main()
{
	printf("Enter the size of the stack:");
	scanf("%d",&size);
	printf("Displaying the menu\n");
	printf("1:Push elements into the stack\n2:Pop elements from the stack\n3:Peek the top most element\n4:Exit\n");
	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				push();
				break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
			{
				peek();
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
			}
		}
	}
}
void push()
{
        if(top>=size-1)
        {
                printf("The stack is full\n");
        }
	else
	{
		printf("Enter the element to be pushed on to the stack:");
		scanf("%d",&item);
		top=top+1;
		s[top]=item;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("The stack is empty\n");
	}
	else
	{
		printf("The element deleted from the stack is %d\n",s[top]);
		top=top-1;
	}
}
void peek()
{
	printf("The current topmost element of the stack is %d\n",s[top]);
}
void display()
{
	while(top>-1)
	{
		printf("%d\t",s[top]);
		top=top-1;
	}
	printf("\n");
}
