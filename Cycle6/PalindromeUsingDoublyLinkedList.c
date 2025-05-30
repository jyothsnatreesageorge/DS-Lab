#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    struct node* llink;
    struct node* rlink;
    char data;
};
struct node* header;
struct node* ptr;
struct node* temp;
struct node* fptr;
struct node* bptr;
void display();
void create(int n,char a[50]);
void palindrome();
int main()
{
    int i,len;
    char str[50];
    printf("Enter the string:");
    scanf("%s",&str);
    len=strlen(str);
    header=(struct node*)malloc(sizeof(struct node));
    header->llink=NULL;
    header->rlink=NULL;
    header->data=0;
    ptr=header;
    create(len,str);
    printf("The entered string is:%s\n",str);
    palindrome();
}
void display()
{
    ptr=header->rlink;
    if(header->rlink==NULL)
    {
        printf("Linked List is empty!");
        return;
    }
    while(ptr!=NULL)
    {
        printf("%c",ptr->data);
        ptr=ptr->rlink;
    }
    printf("\n");
}
void create(int n,char a[50])
{
    for(int i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        if(temp==NULL)
        {
            printf("Error in allocating memory!\n");
            return;
        }
        else
        {
            temp->data=a[i];
            ptr->rlink=temp;
            temp->llink=ptr;
            temp->rlink=NULL;
            ptr=ptr->rlink;
        }
    }
}
void palindrome()
{
    int flag=0;
    fptr=header->rlink;
    ptr=header->rlink;
    if(header->rlink==NULL||ptr->rlink==NULL)
    {
        printf("It is a palindrome\n");
        return;
    }
    while(ptr->rlink!=NULL)
    {
        ptr=ptr->rlink;
    }
    bptr=ptr;
    {
        while(fptr<=bptr)
        {
            if(fptr->data!=bptr->data)
            {
                printf("It is not a palindrome!\n");
                flag=1;
                break;
            }
            fptr=fptr->rlink;
            bptr=bptr->llink;
        }
        if(flag==0)
        {
            printf("It is a palindrome!\n");
        }
    }
}
