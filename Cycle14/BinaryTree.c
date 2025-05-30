#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
};
int data;
int choice;
void insert(struct node** root,int data);
void delete();
void inorder();
void preorder();
void postorder();
struct node* root=NULL;
struct node* newnode=NULL;
struct node* temp=NULL;
struct node* ptr=NULL;
int main()
{
    printf("Displaying the menu:\n");
    printf("1.Insert a new node\n2.Delete a node\n3.Inorder Traversal\n4.Preorder Traversal\n5.Postorder Travresal\n6.Exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the data:");
                scanf("%d",&data);
                insert(&root,data);
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                inorder(root);
                break;
            }
            case 4:
            {
                preorder(root);
                break;
            }
            case 5:
            {
                postorder(root);
                break;
            }
            case 6:
            {
                /*ptr=root;
                while(ptr->link!=NULL)
                {
                    temp=ptr->link;
                    free(ptr);
                    ptr=temp;
                }*/
                exit(1);
                break;
            }
        }
    }

}
void insert(struct node** root,int data)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    if(*root==NULL)
    {
        *root=newnode;
        return;
    }
    struct node* queue[100];
    int f=0,r=0;
    queue[r++]=(*root);
    while(f<r)
    {
        struct node* temp=queue[f++];
        if(temp->lchild==NULL)
        {
            temp->lchild=newnode;
            return;
        }
        else
        {
            queue[r++]=temp->lchild;
        }
        if(temp->rchild==NULL)
        {
            temp->rchild=newnode;
            return;
        }
        else
        {
            queue[r++]=temp->rchild;
        }
    }

}
void inorder(struct node* root) 
{
    struct node* ptr=root;
    if (ptr==NULL) 
    {
        return;
    }
    inorder(ptr->lchild);
    printf("%d\n",ptr->data);
    inorder(ptr->rchild);
}
void preorder(struct node* root) 
{
    struct node* ptr=root;
    if (ptr==NULL) 
    {
        return;
    }
    printf("%d\n",ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}
void postorder(struct node* root) 
{
    struct node* ptr=root;
    if (ptr==NULL) 
    {
        return;
    }
    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d\n",ptr->data);
}
