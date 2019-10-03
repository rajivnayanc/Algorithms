// C program to print largest contiguous array sum 
// Kadane's Algo
//TC = O(n)
#include<stdio.h>
#include<stdlib.h> 
#include<limits.h>
int maxSubArraySum(int a[], int size) 
{ 
    int ans = INT_MIN;  // Current ans is minimum number possible 
    int prev = 0; // The sum till previous element
  
    for (int i = 0; i < size; i++) 
    { 
        prev = prev + a[i]; // The sum till the ith element
        if (ans < prev) 
            ans = prev; //Updating the ans if new sum obtained is greater than earlier
  
        if (prev < 0) 
            prev = 0; 
    } 
    return ans; 
} 

//driver function to run the program
void main(){
    int n,i ;
    printf("Enter the size of input array: ");
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    int ans = maxSubArraySum(a, n);
    printf("The max subarray sum is %d\n", ans);
}