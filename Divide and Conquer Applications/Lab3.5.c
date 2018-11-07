/*

Given an array of n elements, give an algorithm for finding the element which appears
maximum number of times in the array.

*/

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


void merge(int a[], int l,int m, int r){
	int c[r-l+1];
	int i=l;
	int j=m+1;
	int k=0;
	while((i<=m)&&(j<=r)){
		if(a[i]<=a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];				
	}
	while(i<=m)
		c[k++]=a[i++];
	while(j<=r)
		c[k++]=a[j++];
	int z=0;
	for(z=0;z<k;z++)
		a[l+z]=c[z];		
}


void MergeSort(int a[], int l, int r){
	if(l<r){
		int m=(l+r)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int MaxNumElements(int a[], int n){
	int currentElement=a[0];
	int maxCountElement=a[0];
	int maxCount=0;
	int count=0;
	MergeSort(a, 0, n-1);
	int i;
	for(i=1;i<n;i++){
		if(a[i]==currentElement)
			count++;
		else{
			if(count>maxCount){
				maxCount=count;
				maxCountElement=currentElement;
			}
			currentElement=a[i];
			count=1;
		}	
	}
	
	return maxCountElement;		
}


int main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int a[n];
	fflush(stdin);
	printf("Enter Array: ");
	arrayInput(a,n);
	int res=MaxNumElements(a,n);
	printf("\nElement with maximum frequency is %d\n",res);
	display(a,n);	
}
