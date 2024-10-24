#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p,n,ele,ch,i,pos;//p is pointer
    printf("enter number of elements to create an array:\t");
    scanf("%d",&n);
    p=malloc(n* sizeof(int));//use malloc to create dynamic array
    printf("dynamic array created \n");
    printf("enter %d elements \n",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    while(1)
    {
        printf("\n 1.insert \n 2.delete \n 3.display \n 4.exit \n enter your choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\n enter element and pos(0 to %d)to insert :\t",n-1);
            scanf("%d%d",&ele,&pos);
            realloc(p,(n+1)* sizeof(int));//increase the size
            n=n+1;
            for(i=n-1;i>pos;i--)//start moving all elements to next position
            {
                p[i]=p[i-1];
            }
            p[pos]=ele;//insert the new element at specified position
            break;
            case 2:
            printf("enter position (0 to %d)to delete :\t",n-1);
            scanf("%d",&pos);
            for(i=pos+i;i<n;i++)
            {
                p[i-1]=p[i];
            }
            n=n-1;//update the count total element
            break;
            case 3:
            printf("\n array elements are:\n");
            for(i=0;i<n;i++)
            {
                printf("%d \t",p[i]);
            }
            break;
            case 4:
            exit(0);
        }
    }
    free(p);
    return 0;
}