#include<stdio.h>

int main(){
    int k,n,i,temp,j,gap;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter the elements\n");
    for (k = 0; k < n; k++)
    {
        scanf("%d",&a[k]);
    }
	
	for(gap=n/2;gap>0;gap /= 2){
		for(i=gap;i<n;i += 1){
			temp=a[i];
			for(j=i;j>=gap && a[j-gap] > temp;j -= gap)
				a[j] = a[j-gap];
			a[j]=temp;
 			
		}
	}

	printf("Sorted array: \n");
	for (k = 0; k < n; k++)
	{
        printf("%d ",a[k]);
	}
	printf("\n");
	return 0;

}
