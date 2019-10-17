#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int lar = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  

    if (l < n && a[l] > a[lar])
        lar = l;
 

    if (r < n && a[r] > a[lar])
        lar = r;
 

    if (lar != i)
    {
        int temp = a[i];
   		a[i] = a[lar];
    	a[lar] = temp;
 
        heapify(a, n, lar);
    }
}
 

void heapSort(int a[], int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
	
    for (i=n-1; i>=0; i--)
    {

        int temp = a[0];
   		a[0] = a[i];
    	a[i] = temp;
 
        heapify(a, i, 0);
    }
}
 

int main()
{
    int n;
	printf("Enter the number of elements:");
    scanf("%d",&n);

    int a[n+1],i;
    printf("Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
 
    heapSort(a, n);

	printf("Sorted array: \n");
 	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	printf("\n");
	return 0;

}


/*
eg.
4 17 3 5 1


*/
