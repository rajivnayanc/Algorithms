#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <limits.h>
#include <stdbool.h>

int parent(int a[], int n){
	if(a[n]==n){
		return n;
	}
	else{
		parent(a,a[n]);
	}
}
void makeSet(int a[], int n){
	int i;
	for (i = 0; i < n; ++i){
		a[i] = i;
	}
}

int findSet(int a[], int k){
	return parent(a,k);
}

void Union(int a[], int n1,int n2, int n){

	int i;
	int a1 = findSet(a, n1);
	int b1 = findSet(a, n2);
	for (i = 0; i < n; ++i){
		if(a[i]==b1 || a[i] == a1)
			a[i]=a1;
	}
}

void display(int a[], int n){
	int i;
	for (i = 0; i < n; ++i){
		printf("%d ", a[i]);
	}
	printf("\n");
}


int main(){

	int N;
	printf("Enter Number of vertices: ");
	scanf("%d", &N);
	int weight[N][N];
	int sets[N];
	bool S[N];

	int i, j, k;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&weight[i][j]);
		}
	}

	for(i=0;i<N;i++){
		S[i]=false;	
	}

	makeSet(sets,N);


	for(i = 0;i<N-1;i++){

		int min = INT_MAX;
		int min_i, min_j;

		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				if(min>weight[j][k] && weight[j][k]!=0){
					if(findSet(sets, j)!=findSet(sets, k)){
						min = weight[j][k];
						min_i = j;
						min_j = k;
					}
					
				}
			}
		}
		S[min_j] = true;
		S[min_i] = true;

		Union(sets, min_i, min_j, N);

		printf("%d -> %d :   %d\n",min_i, min_j, weight[min_i][min_j]);

	}



	return 0;
} 