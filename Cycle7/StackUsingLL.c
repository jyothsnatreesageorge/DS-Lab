#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* header;
struct node* top=NULL;
int choice;
int data;
void push(int data);
void pop();
void display();
int main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->data=0;
    header->link=NULL;
    printf("Displaying the menu.........\n");
    printf("1.Push elements into the stack\n2.Pop elements from the stack\n3.Display the contents of the stack\n4.Exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the data to be pushed into the stack:");
                scanf("%d",&data);
                push(data);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                exit(-1);
                break;
            } 
        }
    }
}
void push(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Error in allocating memory!\n");
        return;
    }
    else
    {
        newnode->data=data;
        newnode->link=top;
        top=newnode;
    }
}
void pop()
{
    if(top==NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    struct node* temp=top;
    top=top->link;
    printf("The element deleted from the stack is %d\n",temp->data);
    free(temp);
}
void display()
{
    if(top==NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    else
    {
        struct node* temp=top;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}
