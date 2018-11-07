/*

Given an array of n elements, give an algorithm for checking whether there are any
duplicate elements in the array or not?

Input should be in non-decreasing order.

*/


#include<stdio.h>

int sum(int a[], int n1){
	int i;
	for( i=0;i<n1-1;i++){
		if(a[i]==a[i+1])
			return 1;
		}
	return 0;
}


int main(){
	
	int n1;
	printf("Enter size of 1st array: ");
	scanf("%d",&n1);
	
	int a[n1];
	
	int i;
	printf("Enter your 1st array: ");
	
	for(i=0;i<n1;i++)
		scanf("%d",&a[i]);

	int index=sum(a,n1);
	
	if(index==0)
		printf("Duplicate elements not found");
	else
		printf("Duplicate elements found.!");
	return 0;		
	
}
