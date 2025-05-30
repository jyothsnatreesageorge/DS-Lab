#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};
int choice;
int data;
int node;
char pos;
struct node* header;
struct node* temp;
struct node* ptr;
void display();
void insertbeg(int data);
void insertend(int data);
void insertaft(int data);
void insertbef(int data);
void deletebeg();
void deleteend();
void deleteaft();
void deletebef();
void deletespecific();
void count(struct node* header);
int main()
{
    printf("Displaying the menu........\n");
    printf("1.Display the linked list\n2.Insert at beginning\n3.Insert at end\n4.Insert at specified position\n");
    printf("5.Delete from beginning\n6.Delete from end\n7.Delete from specified position\n8.Exit\n");
    header=(struct node*)malloc(sizeof(struct node));
    header->data=0;
    header->link=NULL;
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                display();
                break;
            }
            case 2:
            {
                printf("Enter the data to be inserted:");
                scanf("%d",&data);
                insertbeg(data);
                break;
            }
            case 3:
            {
                printf("Enter the data to be inserted:");
                scanf("%d",&data);
                insertend(data);
                break;
            }
            case 4:
            {
                printf("Where do you want to insert the new node?\nType 'a' for after and 'b' for before:");
                scanf(" %c",&pos);
                printf("Enter the data to be inserted:");
                scanf("%d",&data);
                if(pos=='a')
                insertaft(data);
                if(pos=='b')
                insertbef(data);
                break;
            }
            case 5:
            {
                deletebeg();
                break;
            }
            case 6:
            {
                deleteend();
                break;
            }
           case 7:
           {
            deletespecific();
            break;
           }
           case 9:
           {
            count(header);
            break;
           }
            case 8:
            {
                exit(-1);
                break;
            }
        }
    }
    return 0;
}
void count(struct node* header)
{
    ptr=header->link;
    int count=0;
    if(header->link==NULL)
    {
        count=0;
    }
    while(ptr!=NULL)
    {
        ptr=ptr->link;
        count++;
    }
    printf("%d\t",count);
}
void display()
{
    if(header->link==NULL)
    {
        printf("Linked List is empty!\n");
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
void insertbeg(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Error in allocating memory!\n");
    }
    else
    {
        newnode->data=data;
        newnode->link=header->link;
        header->link=newnode;
    }
}
void insertend(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Error in allocating memory!\n");
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
void insertaft(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Error in allocating memory!\n");
    }
    newnode->data=data;
    printf("Enter the data of the node after which new node is to be inserted:");
    scanf("%d",&node);
    ptr=header->link;
    while(ptr!=NULL&&ptr->data!=node)
    {
        ptr=ptr->link;
    }
    if(ptr==NULL)
    {
        printf("Couldnt find the specified position!\n");
        free(newnode);
    }
    else
    {
        newnode->link=ptr->link;
        ptr->link=newnode;
    }
}
void insertbef(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Error in allocating memory!\n");
    }
    newnode->data=data;
    printf("Enter the data of the node before which the node is to be inserted:");
    scanf("%d",&node);
    ptr=header->link;
    temp=header;
    while(ptr!=NULL&&ptr->data!=node)
    {
        temp=ptr;
        ptr=ptr->link;
    }
    if(ptr==NULL)
    {
        printf("Couldnt find the specified position!\n");
        free(newnode);
    }
    else
    {
        newnode->link=temp->link;
        temp->link=newnode;
    }
}
void deletebeg()
{
    if(header->link==NULL)
    {
        printf("Linked List is empty!\n");
    }
    ptr=header->link;
    temp=ptr->link;
    header->link=temp;
    free(ptr);
}
void deleteend()
{
    if(header->link==NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    ptr=header->link;
    if(ptr->link==NULL)//condition for only one node
    {
        header->link=NULL;
        free(ptr);
        return;
    }
    while(ptr->link!=NULL)
    {
        temp=ptr;
        ptr=ptr->link;
    }
    temp->link=NULL;
    free(ptr);
}
void deletespecific()
{
    if(header->link==NULL)
    {
        printf("Linked List is empty!\n");
        return;
    }
    else
    {
        printf("Enter the data of the node to be deleted:");
        scanf("%d",&node);
        ptr=header->link;
        temp=NULL;
        if(ptr!=NULL&&ptr->data==node)
        {
            header->link=ptr->link;
            free(ptr);
            return;
        }
        while(ptr!=NULL&&ptr->data!=node)
        {
            temp=ptr;
            ptr=ptr->link;
        }
        if(ptr==NULL)
        {
            printf("Couldnot find the specific node!\n");
            return;
        }
        if(ptr->data==node)
        {
            temp->link=ptr->link;
            free(ptr);
        }
    }
}
