#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<stdbool.h>

int main(int argc, char const *argv[])
{
	printf("Enter number of nodes in graph: ");
	int n;
	scanf("%d",&n);
	int key[n];
	int weight[n][n];

	int i, j, k;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&weight[i][j]);
		}
	}


	bool MST[n];
	for(i=0;i<n;i++){
		MST[i]=false;
		key[i]=true;
	}


	int min_i=0,min_j=0;
	int min =INT_MAX;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if( min>weight[i][j] && weight[i][j]!=0 ){
				min_i = i; min_j = j;
				min = weight[i][j];
			}
		}
	}
	

	MST[min_i]=true;
	MST[min_j]=true;
	key[min_i]=false;
	key[min_j]=false;
	
	printf("%d - %d   -> %d\n", min_i+1,min_j+1,min);
	
	weight[min_i][min_j]=0;
	

	for(i=0;i<n-2;i++){
		
		int l,r;
		min=INT_MAX;
		
		for(l=0;l<n;l++){
			for(r=0;r<n;r++){
				if(MST[l]==false && MST[r]==true && weight[l][r]!=0){
					if(min>weight[l][r]){
						min=weight[l][r];
						min_i=l;
						min_j=r;
					}
				}
			}
		}
		
		MST[min_i]=true;
		key[min_i]=false;
		printf("%d - %d   -> %d\n", min_j+1,min_i+1,min);		
		
	}
	

	return 0;
}


/*

Test Cases:


0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0


0 2 5 1
2 0 3 6
5 3 0 4
1 6 4 0

0 1 13 18 0
1 0 20 19 10
13 20 0 12 25
18 19 12 0 15
0 10 25 15 0


*/
