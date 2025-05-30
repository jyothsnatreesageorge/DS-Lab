#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
struct node* header=NULL;
struct node* temp;
struct node* ptr;
struct node* header2=NULL;
struct node* temp2;
struct node* ptr2;
int choice;
int data;
int size;
int ret;
void push(int data);
int pop();
void enqueue(int data);
int dequeue();
void display();
void reverse(struct node* header);
int main()
{
    header=(struct node*)malloc(sizeof(struct node));
    header->link=NULL;
    header2=(struct node*)malloc(sizeof(struct node));
    header2->link=NULL;
    printf("Displaying the menu.......\n");
    printf("1.Enqueue\n2.Dequeue\n3.Display before reverse\n4.Display after reverse\n5.Exit\n");
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
                reverse(header);
                break;
            }
            case 5:
            {
                ptr=header->link;
                while(ptr!=NULL)
                {
                        temp=ptr->link;
                        header->link=temp;
                        free(ptr);
                        ptr=temp;
                }

                exit(0);
                break;
            }
        }
    }
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
        if(header->link==NULL)
        {
            header->link=newnode;
        }
        else
        {
            ptr=header->link;
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=newnode;  
        }
    }
}
int dequeue()
{
    if(header->link==NULL)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    ptr=header->link;
    temp=ptr->link;
    header->link=temp;
    //printf("The element deleted from the queue is %d\n",ptr->data);
    int ret=ptr->data;
    free(ptr);
    return ret;
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
        newnode->link=header2->link;
        header2->link=newnode;
    }
}
int pop()
{
    if(header2->link==NULL)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    ptr=header2->link;
    temp=ptr->link;
    header2->link=temp;
    ret=ptr->data;
    free(ptr);
    return ret;
}
void display()
{
    if(header->link==NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    else
    {
        ptr=header->link;
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}
void reverse(struct node* header)
{
    while(header->link!=NULL)
    {
        int element=dequeue();
        push(element);
    }
    while(header2->link!=NULL)
    {
        int element=pop();
        enqueue(element);
    }
    display();
}
