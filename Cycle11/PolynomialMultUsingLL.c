#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int exp;
    float coeff;
    struct poly* link;
};
struct poly* header1=NULL;
struct poly* header2=NULL;
struct poly* header3=NULL;
struct poly* newnode;
struct poly* ptr;
struct poly* ptr1;
struct poly* ptr2;
struct poly* ptr3;
struct poly* temp=NULL;
int n1,n2,i,j;
void insert(int term,struct poly** header);
void display(struct poly* header);
void multiply(struct poly** header1,struct poly**header2,struct poly**header3);
void sort(struct poly* header1);
int main()
{
    printf("Enter the number of terms of polynomial 1:");
    scanf("%d",&n1);
    insert(n1,&header1);
    printf("Polynomial 1:");
    display(header1);
    printf("Enter the number of terms of polynomial 2:");
    scanf("%d",&n2);
    insert(n2,&header2);
    printf("Polynomial 2:");
    display(header2);
    multiply(&header1,&header2,&header3);
    return 0;
}
void insert(int term,struct poly** header)
{
    for(i=0;i<term;i++)
    {
        newnode=(struct poly*)malloc(sizeof(struct poly));
        if(newnode==NULL)
        {
            printf("Error in allocating memory!");
            return;
        }
        else
        {
            printf("Enter the exponent:");
            scanf("%d",&newnode->exp);
            printf("Enter the coefficient:");
            scanf("%f",&newnode->coeff);
            newnode->link=NULL;
            if(*header==NULL)
            {
                *header=newnode;
            }
            else
            {
                ptr=*header;
                while(ptr->link!=NULL)
                {
                    ptr=ptr->link;
                }
                ptr->link=newnode;
            }
            
        }
    }
}
void display(struct poly* header)
{
    ptr=header;
    while(ptr!=NULL)
    {
        printf("%.2fx^%d",ptr->coeff,ptr->exp);
        ptr=ptr->link;
        if(ptr!=NULL)
        {
            printf("+");
        }
    }
    printf("\n");
}
void multiply(struct poly** header1,struct poly**header2,struct poly**header3)
{
    ptr1=*header1;
    ptr2=*header2;
    ptr3=*header3;
    while(ptr1!=NULL)
    {
        ptr2=*header2;
        while(ptr2!=NULL)
        {
            newnode=(struct poly*)malloc(sizeof(struct poly));
            if(newnode==NULL)
            {
                printf("Error in allocating memory!\n");
                return;
            }
            newnode->exp=ptr1->exp+ptr2->exp;
            newnode->coeff=ptr1->coeff*ptr2->coeff;
            newnode->link=NULL;
            if(*header3==NULL)
            {
                *header3=newnode;
                ptr3=newnode;
            }
            else
            {
                ptr3->link=newnode;
                ptr3=ptr3->link;
            }
            /*ptr3->link=newnode;
            ptr3=newnode;
            ptr3->link=NULL;*/
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
    sort(*header3);
    printf("Resultant polynomial:");
    display(*header3);
}
void sort(struct poly* header1)
{
    if(header1==NULL)
    {
        return;
    }
    ptr1=header1;
    while(ptr1!=NULL&&ptr1->link!=NULL)
    {
        ptr2=ptr1;
        while(ptr2->link!=NULL)
        {
            if(ptr1->exp==ptr2->link->exp)
            {
                ptr1->coeff=ptr1->coeff+ptr2->link->coeff;
                ptr=ptr2->link;
                ptr2->link=ptr2->link->link;
                free(ptr);
            }
            else
            {
                ptr2=ptr2->link;
            }
        }
        ptr1=ptr1->link;
    }
}
