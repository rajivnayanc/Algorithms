/*
Given a sorted array of non-repeated integers A[1...n]; n > 1 then check whether there is an
index i for which A[i] = i. Give an algorithm that runs in O(logn) time.
*/


#include<stdio.h>

int BinarySearch(int a[],int n){
	int l=0;
	int r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==mid)
			return mid;
		else if(a[mid]<mid)
			l=mid+1;
		else
			r=mid-1;	
	}
	
	return -1;	
}
int main(){
	
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int a[n];
	int i;
	printf("Enter your array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	int index=BinarySearch(a,n);
	
	if(index==-1)
		printf("Such Number not found!");
	else
		printf("Such Number present at index %d and value is %d",index,a[index]);
	return 0;		
	
}
