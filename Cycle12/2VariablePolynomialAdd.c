#include<stdio.h>
#include<stdlib.h>
struct poly
{
    float coeff;
    int exp1;
    int exp2;
    struct poly* link;
};
struct poly* header=NULL;
struct poly* header1=NULL;
struct poly* header2=NULL;
struct poly* header3=NULL;
struct poly* newnode=NULL;
struct poly* ptr=NULL;
struct poly* ptr1=NULL;
struct poly* ptr2=NULL;
struct poly* ptr3=NULL;
int n1,n2,i;
void insert(int term,struct poly** header);
void display(struct poly* header);
void add(struct poly** header1,struct poly** header2,struct poly** header3);
int main()
{
    printf("Enter the number of terms of polynomial 1:");
    scanf("%d",&n1);
    insert(n1,&header1);
    printf("First polynomial:");
    display(header1);
    printf("Enter the number of terms of polynomial 2:");
    scanf("%d",&n2);
    insert(n2,&header2);
    printf("Second polynomial:");
    display(header2);
    add(&header1,&header2,&header3);
    return 0;
}
void insert(int term,struct poly** header)
{
    for(i=0;i<term;i++)
    {
        newnode=(struct poly*)malloc(sizeof(struct poly));
        if(newnode==NULL)
        {
            printf("Error in allocating memory\n");
            return;
        }
        printf("Enter the exponent of x:");
        scanf("%d",&newnode->exp1);
        printf("Enter the exponent of y:");
        scanf("%d",&newnode->exp2);
        printf("Enter the coefficient of term:");
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
void display(struct poly* header)
{
    ptr=header;
    while(ptr!=NULL)
    {
        printf("%.2f x^%d y^%d",ptr->coeff,ptr->exp1,ptr->exp2);
        ptr=ptr->link;
        if(ptr!=NULL)
        {
            printf("+");
        }
    }
    printf("\n");
}
void add(struct poly** header1,struct poly** header2,struct poly** header3)
{
    ptr1=*header1;
    ptr2=*header2;
    while(ptr1!=NULL||ptr2!=NULL)
    {
        struct poly* newnode=(struct poly*)malloc(sizeof(struct poly));
        if(newnode==NULL)
        {
            printf("Error in allocating memory!\n");
            return;
        }
            if(ptr1==NULL)
            {
                newnode->exp1=ptr2->exp1;
                newnode->exp2=ptr2->exp2;
                newnode->coeff=ptr2->coeff;
                ptr2=ptr2->link;
            }
            else if(ptr2==NULL)
            {
                newnode->exp1=ptr1->exp1;
                newnode->exp2=ptr1->exp2;
                newnode->coeff=ptr1->coeff;
                ptr1=ptr1->link;
            }
            else if(ptr1->exp1<ptr2->exp1||ptr1->exp1==ptr2->exp1&&ptr1->exp2<ptr2->exp2)
            {
                newnode->exp1=ptr1->exp1;
                newnode->exp2=ptr1->exp2;
                newnode->coeff=ptr1->coeff;
                ptr1=ptr1->link;
            }
            else if(ptr2->exp1<ptr1->exp1||ptr1->exp1==ptr2->exp1&&ptr2->exp2<ptr1->exp2)
            {
                newnode->exp1=ptr2->exp1;
                newnode->exp2=ptr2->exp2;
                newnode->coeff=ptr2->coeff;
                ptr2=ptr2->link;
            }
            else
            {
                newnode->exp1=ptr1->exp1;
                newnode->exp2=ptr2->exp2;
                newnode->coeff=ptr1->coeff+ptr2->coeff;
                ptr1=ptr1->link;
                ptr2=ptr2->link;
            }
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
        
    }
    printf("Resultant polynomial:");
    display(*header3);
}
