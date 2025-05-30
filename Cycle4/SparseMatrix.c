# include<stdio.h>
# include<stdlib.h>
struct matrix
{
	int row;
	int col;
	int val;
}term[50],term1[50],term2[50],term3[50],term4[50],term5[50];
int row1,row2,col1,col2,i,j,k,q,n,k1,k2,k3,k4,k5,sum,mat1[10][10],mat2[10][10];
void input(int a[10][10],int rows,int cols);
void tuple(int a[10][10],int rows,int cols,struct matrix term[],int *k);
void tuple_display(int k,struct matrix term[]);
void transpose(struct matrix term1[],struct matrix term2[]);
void add(struct matrix term1[],struct matrix term2[],struct matrix term3[]);
int main()
{
	printf("Enter the number of rows of matrix 1:");
	scanf("%d",&row1);
	printf("Enter the number of columns of matrix 1:");
	scanf("%d",&col1);
	input(mat1,row1,col1);
	tuple(mat1,row1,col1,term1,&k1);
	printf("Printing tuple form of matrix 1\n");
	tuple_display(k1,term1);
	transpose(term1,term3);
	printf("Printing the transpose of matrix 1\n");
	tuple_display(k1,term3);
	printf("Enter the number of rows of matrix 2:");
	scanf("%d",&row2);
	printf("Enter the number of columns of matrix 2:");
	scanf("%d",&col2);
	input(mat2,row2,col2);
	tuple(mat2,row2,col2,term2,&k2);
	printf("Printing tuple form of matrix 2\n");
	tuple_display(k2,term2);
	transpose(term2,term4);
	printf("Printing the transpose of matrix 2\n");
	tuple_display(k2,term4);
	add(term1,term2,term5);
	return 0;
}
void input(int a[10][10],int rows,int cols)
{
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			printf("Enter element [%d][%d]:",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
}
void tuple(int a[10][10],int rows,int cols,struct matrix term[],int *k)
{
	*k=1;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			if(a[i][j]!=0)
			{
				term[*k].row=i;
				term[*k].col=j;
				term[*k].val=a[i][j];
				(*k)++;
			}
		}
	}
	term[0].row=rows;
	term[0].col=cols;
	term[0].val=(*k)-1;
}
void tuple_display(int k,struct matrix term[])
{
	printf("ROW\tCOLUMN\tVALUE\n");
	for(i=0;i<k;i++)
	{
		printf("%d\t%d\t%d\n",term[i].row,term[i].col,term[i].val);
	}
}
void transpose(struct matrix term1[],struct matrix term2[])
{
	n=term1[0].val;
	term2[0].row=term1[0].col;
	term2[0].col=term1[0].row;
	term2[0].val=n;
	if(n>0)
	{
		q=1;
		for(i=0;i<term1[0].col;i++)
		{
			for(j=0;j<=n;j++)
			{
				if(term1[j].col==i)
				{
					term2[q].row=term1[j].col;
					term2[q].col=term1[j].row;
					term2[q].val=term1[j].val;
					q++;
				}
			}
		}
	}
}
void add(struct matrix term1[],struct matrix term2[],struct matrix term3[])
{
	if(term1[0].row!=term2[0].row||term1[0].col!=term2[0].col)
	{
		printf("Cannot add matrices\n");
		return;
	}
	else
	{
		term3[0].row=term1[0].row;
		term3[0].col=term2[0].col;
		i=j=k=1;
		while(i<=term1[0].val&&j<=term2[0].val)
		{
			if(term1[i].row<term2[j].row)
			{
				term3[k].row=term1[i].row;
				term3[k].col=term1[i].col;
				term3[k].val=term1[i].val;
				i++;
				k++;
			}
			else if(term1[i].row>term2[j].row)
			{
				term3[k].row=term2[j].row;
				term3[k].col=term2[j].col;
				term3[k].val=term2[j].val;
				j++;
				k++;
			}
			else
			{
				if(term1[i].col<term2[j].col)
				{
					term3[k].row=term1[i].row;
					term3[k].col=term1[i].col;
					term3[k].val=term1[i].val;
					i++;
					k++;
				}
				else if(term1[i].col>term2[j].col)
				{
					term3[k].row=term2[j].row;
					term3[k].col=term2[j].col;
					term3[k].val=term2[j].val;
					j++;
					k++;
				}
				else
				{
					sum=term1[i].val+term2[j].val;
					if(sum!=0)
					{
						term3[k].row=term1[i].row;
						term3[k].col=term1[i].col;
						term3[k].val=sum;
						i++;
						j++;
						k++;
					}
				}
			}
			while(i<=term1[0].val)
			{
				term3[k].row=term1[i].row;
				term3[k].col=term1[i].col;
				term3[k].val=term1[i].val;
				i++;
				k++;
			}
			while(j<=term2[0].val)
			{
				term3[k].row=term2[j].row;
				term3[k].col=term2[j].col;
				term3[k].val=term2[j].val;
				j++;
				k++;
			}
		}
	term3[0].val=k-1;
        printf("The resultant of addition of two matrices\n");
	tuple_display(k,term3);
	}
}
