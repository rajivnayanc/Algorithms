#include<stdio.h>

void display(int a[], int n){
	int i;
	printf("\nArray is: ");
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");	
}

void arrayInput(int a[], int n){
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void swap(int *a, int *b){
	int *c=a;
	a=b;
	b=c;
}


int partition(int a[], int l, int r){
	int pivot=a[l];
	int i=l;
	int j=r+1;
	while(i<=j){
		do{
			i++;
		}while(pivot>a[i]);
		
		do{
			j--;
		}while(pivot<a[j]);
		
		if(i<j)
			{
				int c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
	}
	
	int c=a[l];
	a[l]=a[j];
    a[j]=c;
	return j;
			
}


void QuickSorts(int a[], int l, int r){
	if(l<r){
		int k=partition(a,l,r);
		QuickSorts(a,l,k-1);
		QuickSorts(a,k+1,r);
	}
}

void QuickSort(int a[], int l, int r){
	a[r+1]=10000000;
	QuickSorts(a,l,r);	
}


int main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int a[n+1];
	fflush(stdin);
	printf("Enter Array: ");
	arrayInput(a,n);
	QuickSort(a,0,n-1);
	display(a,n);
	return 1;	
}

