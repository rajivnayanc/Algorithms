#include <stdio.h>


int main()
{
    int k,n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter the elements\n");
    for (k = 0; k < n; k++)
    {
        scanf("%d",&a[k]);
    }
   int i, key, j;
   for (i = 1; i < n;i++)
   {
       key = a[i];
       j = i-1;
 
      
       while (j >= 0 && a[j] > key)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = key;
   }
   printf("Sorted array: \n");
   for (k = 0; k < n; k++)
   {
        printf("%d ",a[k]);
   }
   printf("\n");
   return 0;

}
