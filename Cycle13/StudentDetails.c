#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct std
{
    int num;
    char name[50];
    float total;
    struct std* link;
};
struct std* header=NULL;
struct std* ptr=NULL;
struct std* ptr1=NULL;
struct std* temp=NULL;
void insert();
void delete();
void searchnum();
void searchname();
void sort();
void display();
int main()
{
    int choice,search;
    printf("Displaying the menu:\n");
    printf("1.Insert Details\n2.Delete Details\n3.Search Details\n4.Display Details\n5.Sort Details\n6.Exit\n");
    while(1)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                insert();
                break;
            }
            case 2:
            {
                delete();
                break;
            }
            case 3:
            {
                printf("Do you want to searh using name or number?:\n");
                printf("Enter 1 for search using number and 2 for search using name:");
                scanf("%d",&search);
                if(search==1)
                {
                    searchnum();
                }
                else if(search==2)
                {
                    searchname();
                }
                else
                {
                    printf("Invalid choice!\n");
                }
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 5:
            {
                sort();
                break;
            }
            case 6:
            {
                ptr=header;
                while(ptr->link!=NULL)
                {
                    temp=ptr->link;
                    free(ptr);
                    ptr=temp;
                }
                exit(1);
                break;
            }
        }
    }
    return 0;
}
void insert()
{
    struct std* newnode=(struct std*)malloc(sizeof(struct std));
    if(newnode==NULL)
    {
        printf("Error in allocating memory!\n");
        return;
    }
    else
    {
                printf("Enter the number:");
                scanf("%d",&newnode->num);
                printf("Enter the name:");
                scanf(" %[^\n]",newnode->name);
                printf("Enter the mark:");
                scanf("%f",&newnode->total);
        newnode->link=header; 
        header=newnode;  
    }
}
void display()
{
    ptr=header;
    if(ptr==NULL)
    {
        printf("No Student Details to show!\n");
        return;
    }
    else
    {
        printf("NUMBER\tNAME\tMARKS\n");
        while(ptr!=NULL)
        {
            printf("%d\t%s\t%.2f\n",ptr->num,ptr->name,ptr->total);
            ptr=ptr->link;
        }
    }
}
void delete()
{
    if(header==NULL)
    {
        printf("No Student Details to delete!\n");
        return;
    }
    else
    {
        temp=NULL;
        ptr=header;
        int data;
        printf("Enter the number of the student which is to be deleted:");
        scanf("%d",&data);
        while(ptr!=NULL&&ptr->num!=data)
        {
            temp=ptr;
            ptr=ptr->link;
        }
        if(ptr==NULL)
        {
            printf("Cannot find the student with the specified number\n");
            return;
        }
        if(ptr->num==data)
        {
            if(ptr==header)
            {
                header=header->link;
                free(ptr);
            }
            else
            {
                temp->link=ptr->link;
                free(ptr);
            }
        }
    }
}
void searchnum()
{
    if(header==NULL)
    {
        printf("No Student Details to search!\n");
        return;
    }
    else
    {
        int num;
        printf("Enter the number of the student to be searched:");
        scanf("%d",&num);
        ptr=header;
        while(ptr!=NULL&&ptr->num!=num)
        {
            ptr=ptr->link;
        }
        if(ptr==NULL)
        {
            printf("Couldnt find the student with the specified number\n");
            return;
        }
        else if(ptr->num==num)
        {
            printf("The details of the student is:\n");
            printf("NUMBER\tNAME\tMARKS\n");
            printf("%d\t%s\t%.2f\n",ptr->num,ptr->name,ptr->total);
        }
    }
}
void searchname()
{
    if(header==NULL)
    {
        printf("No Student Details to search!\n");
        return;
    }
    else
    {
        char name[50];
        int i,flag=0;
        printf("Enter the name of the student to be searched:");
        scanf("%s",&name);
        ptr=header;
        while(ptr!=NULL)
        {
            i=0;
            while(ptr->name[i]!='\0'&&name[i]!='\0')
            {
                if(ptr->name[i]!=name[i])
                {
                    break;
                }
                i++; 
            }
            if(ptr->name[i]=='\0'&&name[i]=='\0'&&flag==0)
            {
                flag=1;
                printf("The details of the student is:\n");
                printf("NUMBER\tNAME\tMARKS\n");
                printf("%d\t%s\t%.2f\n",ptr->num,ptr->name,ptr->total);
                return;
            }
            ptr=ptr->link;
        }
        if(flag==0)
        {
            printf("Couldnt find the student with specified name\n");
            return;
        }
    }
}
void sort()
{
    if(header==NULL)
    {
        printf("No student records to sort!\n");
        return;
    }
    else
    {
        int tempnum;
        char tempname[50];
        float temptotal;
        int swapped;
        do
        {
            swapped=0;
            ptr=header;
            while(ptr->link!=NULL)
            {
                ptr1=ptr->link;
                if(ptr->num>ptr1->num)
                {
                    tempnum=ptr->num;
                    ptr->num=ptr1->num;
                    ptr1->num=tempnum;
                    temptotal=ptr->total;
                    ptr->total=ptr1->total;
                    ptr1->total=temptotal;
                    int i;
                    i=0;
                    while(ptr->name[i]!='\0')
                    {
                        tempname[i]=ptr->name[i];
                        i++;
                    }
                    tempname[i]='\0';
                    i=0;
                    while(ptr1->name[i]!='\0')
                    {
                        ptr->name[i]=ptr1->name[i];
                        i++;
                    }
                    ptr->name[i]='\0';
                    i=0;
                    while(tempname[i]!='\0')
                    {
                        ptr1->name[i]=tempname[i];
                        i++;
                    }
                    ptr1->name[i]='\0';
                    swapped=1;
                }
                ptr=ptr->link;
            }
        } while (swapped);
        printf("The sorted List is:\n");
        display();
    }
}
