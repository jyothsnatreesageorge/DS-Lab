#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
};
struct node* root;
int choice,data;
void insert(int data,struct node** root);
void delete(int data,struct node** root);
void inorder(struct node* root);
void preorder(struct node* root);
void postorder(struct node* root);
int main()
{
    printf("Displaying the menu:\n");
    printf("1.Insert\n2.Delete3.Inorder\n4.Preorder\n5.Postorder\n6.Exit\n");
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
                insert(data,&root);
                break;
            }
            case 2:
            {
                if(root==NULL)
                {
                    printf("Tree empty!\n");
                }
                else
                {
                    printf("Enter the data:");
                    scanf("%d",&data);
                    delete(data,&root);
                    break;
                }
            }
            case 3:
            {
                if(root==NULL)
                {
                    printf("Tree is empty!\n");
                }
                else
                {
                    inorder(root);
                    printf("\n");
                }
                break;
            }
            case 4:
            {
                if(root==NULL)
                {
                    printf("Tree is empty!\n");
                }
                else
                {
                    preorder(root);
                    printf("\n");
                }
                break;
            }
            case 5:
            {
                if(root==NULL)
                {
                    printf("Tree is empty!\n");
                }
                else
                {
                    postorder(root);
                    printf("\n");
                }
                break;
            }
            case 6:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("Invalid choice!");
                break;
            }
        }
    }
}
void insert(int data,struct node** root)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->lchild=NULL;
    newnode->rchild=NULL;
    if(*root==NULL)
    {
        *root=newnode;
    }
    else
    {
        if(data<(*root)->data)
        {
            insert(data,&(*root)->lchild);
        }
        else if(data>(*root)->data)
        {
            insert(data,&(*root)->rchild);
        }
    }
}
void delete(int data,struct node** root)
{
    if(*root==NULL)
    {
        return;
    }
    if(*root->data>data)
    {
        delete(data,&(*root));
    }
    else if(*root->data<data)
    {
        delete(data,&(*root));
    }
    else
    {
        
    }
}
void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->lchild);
    printf("%d\t",root->data);
    inorder(root->rchild);
}
void preorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d\t",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
void postorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d\t",root->data);
}
