
#include<stdio.h>
 
int main()
{
    int i,j,n,loc,temp,min;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter the elements\n");
 
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
 
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }
        }
 
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
 
    printf("Sorted list: \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
