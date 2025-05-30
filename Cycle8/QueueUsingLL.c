#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* header;
struct node* front=NULL;
struct node* rear=NULL;
int choice;
int data;
void enqueue(int data);
void dequeue();
void display();
int main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->data=0;
    header->link=NULL;
    printf("Displaying the menu.........\n");
    printf("1.Enqueue elements\n2.Dequeue elements\n3.Display\n4.Exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the data to be enqueued into the queue:");
                scanf("%d",&data);
                enqueue(data);
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
                exit(-1);
                break;
            } 
        }
    }
}
void display()
{
    if(front==NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    struct node* temp=front;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
}
void enqueue(int data)
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
        newnode->link=NULL;
        if(front==NULL)
        {
            rear=front=newnode;
        }
        else
        {
            rear->link=newnode;
            rear=newnode; 
        }
    }
}
void dequeue()
{
    if(front==NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    struct node* temp=front;
    front=front->link;
    if(front==NULL)
    {
        rear=NULL;
    }
    printf("The element deleted from the queue is %d\n",temp->data);
    free(temp);
}
