/*

Given an array of n elements. Find whether there are three elements in the array such
that their sum is equal to given element K or not?

Input should be in non-decreasing order.

*/

#include<stdio.h>

int threesum(int a[], int n, int key){
	int i;
	for(i=0;i<n-1;i++){
		int l=0, r=n-1;
		while(l<r){
			if(a[i]+a[l]+a[r]==key)
				return 1;
			else if(a[i]+a[l]+a[r]>key)
				r--;
			else
				l++;
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
	
	printf("Enter the sum value: ");
	int key;
	scanf("%d",&key);
	int index=threesum(a,n,key);
	if(index==0)
		printf("Sum not found!");
	else
		printf("Such sum is possible");
	return 0;		
	
}
