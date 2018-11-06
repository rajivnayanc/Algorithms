/*

Let A and B be two arrays of n elements. Given a number K, draw and algorithm 
for determining whether there exists a belongs to A, b belongs to B such that a+b = K or not?.

Input should be in non-decreasing order.

*/


#include<stdio.h>

int sum(int a[], int b[],int n1,int n2, int key){
	int i;
	for( i=0;i<n1;i++){
		int l=0, r=n2-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(b[mid]==key-a[i])
				return 1;
			else if(b[mid]<key-a[i])
				l=mid+1;
			else
				r=mid-1;
		}
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
	
	int n2;
	printf("Enter size of 2nd array: ");
	scanf("%d",&n2);
	int b[n2];
	printf("Enter your 2nd array: ");
	for(i=0;i<n2;i++)
		scanf("%d",&b[i]);
	
			
	
	printf("Enter the sum value: ");
	int key;
	scanf("%d",&key);
	int index=sum(a,b,n1,n2,key);
	if(index==0)
		printf("Sum not found!");
	else
		printf("Such sum is possible");
	return 0;		
	
}
