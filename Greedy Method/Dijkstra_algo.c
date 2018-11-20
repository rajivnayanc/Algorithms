#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>

void paths(long long int path[], long long int j){

	if(path[j]==-1){
		return;
	}
	paths(path,path[j]);

	printf("%lld->", j);

}

int main(){
	int N;
	printf("Enter Number of vertices: \n");
	scanf("%d",&N);
	long long int weight[N][N];
	long long int D[N];
	long long int path[N];

	bool S[N]={false}; //visited vertex
	bool NS[N]={true}; //Non-visited Vertex
	int CS;
	int i,j;
	

	printf("Enter weight adjacency matrix: \n");
	for (i = 0; i < N; ++i){	
		for (j = 0; j < N; ++j){
			int in;
			scanf("%d",&in);
			if(in==0)
				weight[i][j]=INT_MAX;
			else
				weight[i][j]=in;
		}
	}


	int source;
	printf("Enter Souce vertex: ");
	scanf("%d",&source);
	path[source] = -1;
	for(i=0;i<N;i++){
		S[i] = false;
		NS[i] = true;
		D[i] = INT_MAX;
	}

	D[source] = 0;
	CS = source;
	for(i=0;i<N-1;i++){
		int mins = INT_MAX, min_j;
		for(j=0;j<N;j++){
			if(S[j]==false && D[j]<=mins){
				mins = D[j]; min_j = j;
			}
		}

		S[min_j] = true;
		NS[min_j] = false;
		CS = min_j;

		for (j = 0; j < N ; ++j){
			if(S[j]==false && NS[j] == true){
				long long int a = D[CS]+weight[CS][j];
				D[j] = std::min(D[j],D[CS]+weight[CS][j]);
				if(D[j]==a)
					path[j]=CS;
			}
		}


	}

	printf("\n\nPairs\t\tDistance\t\tPaths\n");
	for(i=0;i<N;i++){
		printf("%d->%d",source,i);
		printf("\t\t%lld", D[i] );
		printf("\t\t\t%d->",source);
		paths(path,i);
		printf("\b\b  \n");

	}

	printf("\n");

	return 0;
}


/*

Example 1:


Enter Number of vertices: 
9
Enter weight adjacency matrix: 
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0  9 0 10 0 0 0    
0 0 4 14 10 0 2 0 0  
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
Enter Souce vertex: 0


Pairs		Distance		Paths
0->0		0			0  
0->1		4			0->1  
0->2		12			0->1->2  
0->3		19			0->1->2->3  
0->4		21			0->7->6->5->4  
0->5		11			0->7->6->5  
0->6		9			0->7->6  
0->7		8			0->7  
0->8		14			0->1->2->8 

*/



/*

Example 2: 


Enter Number of vertices: 
5
Enter weight adjacency matrix: 
0 2 3 0 0
5 0 0 7 4
7 1 0 6 0
0 0 1 0 5
0 0 0 3 0
Enter Souce vertex: 0


Pairs		Distance		Paths
0->0		0			0  
0->1		2			0->1  
0->2		3			0->2  
0->3		9			0->1->4->3  
0->4		6			0->1->4 

*/



/*
Example 3:


Enter Number of vertices: 
4
Enter weight adjacency matrix: 
0 1 2 3
1 0 0 0
2 0 0 0
3 0 0 
0
Enter Souce vertex: 0


Pairs		Distance		Paths
0->0		0			0  
0->1		1			0->1  
0->2		2			0->2  
0->3		3			0->3  
*/
