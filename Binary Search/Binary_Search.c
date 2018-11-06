#include<stdio.h>

int BinarySearch(int a[],int n, int key){
	int l=0;
	int r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==key)
			return mid;
		else if(a[mid]<key)
			l=mid+1;
		else
			r=mid-1;	
	}
	
	return -1;	
}
int main(){
	
	int n;
	printf("Enter size of array: "); // In non-decreasing order
	scanf("%d",&n);
	int a[n];

	int i;
	printf("Enter your array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	printf("Enter the value to be searched for: ");
	int key;
	scanf("%d",&key);
	int index=BinarySearch(a,n,key);
	
	if(index==-1)
		printf("Number not found!");
	else
		printf("Number present at index %d",index);
	return 0;		
	
}

