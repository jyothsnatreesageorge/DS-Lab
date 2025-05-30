#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
};
int data;
void insert(struct node** root)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&data);
    newnode->data=data;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    if(*root==NULL)
    {
        *root=newnode;
    }
    else
    {
        struct node* queue[100];
        int front=0;
        int rear=0;
        queue[rear++]=*root;
        while(front<rear)
        {
            struct node* current=queue[front++];
            if(current->lchild==NULL)
            {
                current->lchild=newnode;
                break;
            }
            else
            {
                queue[rear++]=current->lchild;
            }
            if(current->rchild==NULL)
            {
                current->rchild=newnode;
                break;
            }
            else
            {
                queue[rear++]=current->rchild;    
            }
        }
    }
}
void inorder(struct node* root)
{
    if(root==NULL) return;
    struct node* ptr=root;
    inorder(ptr->lchild);
    printf("%d\t",ptr->data);
    inorder(ptr->rchild);
}
void preorder(struct node* root)
{
    if(root==NULL) return;
    struct node* ptr=root;
    printf("%d\t",ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void postorder(struct node* root)
{
    if(root==NULL)return;
    struct node* ptr=root;
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d\t",ptr->data);
}
void delete(struct node** root,int key)
{
    if(*root==NULL)return;
    else
    {
        struct node* lastnode=NULL;
        struct node* keyvalue=NULL;
        struct node* parent=NULL;
        struct node* queue[100];
        int front=0;
        int rear=0;
        queue[rear++]=*root;
        while(front<rear)
        {
            struct node* current=queue[front++];
            lastnode=current;
            if (current->data==key)
            {
                keyvalue=current;
            }
            if(current->lchild)
            {
                parent=current;
                queue[rear++]=current->lchild;
            }
            if(current->rchild)
            {
                parent=current;
                queue[rear++]=current->rchild;
            }
        }
            if(keyvalue)
            {
                keyvalue->data=lastnode->data;
                if(parent->lchild==lastnode)
                {
                    parent->lchild=NULL;
                }
                else if(parent->rchild==lastnode)
                {
                    parent->rchild=NULL;
                }
                else
                {
                    *root=NULL;
                }
                free(lastnode);
            }
            else
            {
                printf("Item is not found!\n");
            }
    }
}
int main()
{
    int choice;
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root=NULL;
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert(&root);
            break;
            case 2:
            {
                int key;
                printf("Enter the key to be deleted:");
                scanf("%d",&key);
                delete(&root,key);
                break;
            }
            case 3:
            inorder(root);
            break;
            case 4:
            preorder(root);
            break;
            case 5:
            postorder(root);
            break;
            case 6:
            exit(0);
        }
    }
}
