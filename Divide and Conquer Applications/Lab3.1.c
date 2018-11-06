/*

Given an array of n elements. Find whether there are two elements in the array such that
their sum is equal to given element K or not?

Input should be in non-decreasing order.


*/

#include<stdio.h>

int BinarySearch(int a[],int n, int key,int skip){
	int l=0;
	int r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(mid==skip)
		{
			if(a[mid]<key)
				l=mid+1;
			else
				r=mid-1;
		}
	   else {		
		if(a[mid]==key)
			return 1;
		else if(a[mid]<key)
			l=mid+1;
		else
			r=mid-1;
		}
	}
	
	return 0;	
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
	
	printf("Enter the sum value : ");
	int key;
	int flag=0;
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{   int K=key-a[i];
		int index=BinarySearch(a,n,K,i);
		if(index==1)
			flag=1;
	}
	if(flag==1)
		printf("Such pair is present!");
	else
		printf("Such pair is not present!");
		
}
