#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct term
{
    int row;
    int col;
    int value;
};
struct term a[MAX],b[MAX];
void Create();//declaration of functions
void Transpose();
void display(int n,struct term m[]);
int main()
{
    int choice;
    while(1)
    {
        printf("\n Menu:\n");
        printf("1.Create sparse matrix \n");
        printf("2.Transpose of sparse matrix \n");
        //printf("display sparse matrix \n");
        printf("3.Exit \n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            Create();
            break;
            case 2:
            Transpose();
            break;
            case 3:
            exit(0);
        }
    }
    return 0;
}
void Create()
{
    //int matrix [10] [10];
    int i,rows,cols,n;//starting index from 1 since 0 is used for matrix
    printf("\n enter number of rows,columns and number of values:");
    scanf("%d%d%d",&rows,&cols,&n);
    a[0].row=rows;//first term conditions no of rows,cols and values
    a[0].col=cols;
    a[0].value=n;
    for(i=1;i<=n;i++)
    {
        printf("enter row,col and value:");
        scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
    }
    display(n,a);
}
void Transpose()
{
    int i,j,k=1,n;
    n=a[0].value;
    b[0].row=a[0].col;
    b[0].col=a[0].row;
    b[0].value=n;
    for(i=1;i<=a[0].col;i++)
    {
        for(j=1;j<=n;j++)
        {
            //find the element from the current col
            if(a[j].col==i)//based on col we need to transpose
            {
                //element in current col, add it
                b[k].row=a[j].col;
                b[k].col=a[j].row;
                b[k].value=a[j].value;
                k++;
            }
        }
    }
    display(n,b);
}
void display(int value,struct term m[])
{
    int i;
    printf("\n row \t col \t value \t \n");
    for(i=0;i<=value;i++)
    {
        printf("%d \t %d \t %d \t \n",m[i].row,m[i].col,m[i].value);
    }
}