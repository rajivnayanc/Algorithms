#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

void trees( int *R, int i, int j, int n, char str[]){
	if(i<j){
		int k = *((R+i*n)+j);
		printf("%c ", str[k]);
		trees(R,i,k,n,str);
		trees(R,k+1,j,n,str);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Number of identifiers: ");
	scanf("%d",&n);

	char str[n];
	int i,j,k,L;char c;
	for(c = 'A', L=0;L<n;c++,L++)
		str[L]=c;


	str[L] = '\0';
	printf("%s\n",str);



	float p[n+1];
	float q[n+1];

	float w[n+1][n+1];
	float cost[n+1][n+1];
	int R[n+1][n+1];

	printf("Enter successful search probabilities: \n");
	

	for(i=1;i<=n;i++)
		scanf("%f",&p[i]);

	printf("Enter unsuccessful search probabilities: \n"); 
	for(i=0;i<=n;i++){
		scanf("%f",&q[i]);
		w[i][i] = q[i];
		cost[i][i] = 0;
		R[i][i] = 0;
	}




	for(i=0;i<=n;i++){
		for(j=i+1;j<=n;j++)
			w[i][j] = p[j] + q[j] + w[i][j-1];
	}

	printf("\n\nPre-Order Traversal of Optimal Tree : \n");

	


	for(i=1;i<=n;i++){

		for(j=0;j<=n-i;j++){

			k = j+i;
			cost[j][k] = INT_MAX;
			int mins;

			for(mins = j;mins<k;mins++){
				float temp = cost[j][mins] + cost[mins+1][k] + w[j][k];
				if(temp<cost[j][k]){
					cost[j][k] = temp;
					R[j][k] = mins;
				}
			}

		}
	}

	/*for(i=0;i<n+1;i++){
		for(j=i;j<n+1;j++){
			printf("%f->%f->%d\t\t", w[i][j],cost[i][j],R[i][j]+1);
		}
		printf("\n");
	}*/

	trees((int *)R,0,n,n+1,str);
	printf("\n\nOptimal Cost: %f\n",cost[0][n]);

	return 0;
}

/*

Number of identifiers: 4
ABCD
Enter successful search probabilities: 
3 3 1 1
Enter unsuccessful search probabilities: 
2 3 1 1 1


Pre-Order Traversal of Optimal Tree : 
B A C D 

Optimal Cost: 32.000000


*/

/*

Number of identifiers: 5
ABCDE
Enter successful search probabilities: 
.15 .1 .05 .1 .2
Enter unsuccessful search probabilities: 
.05 .1 .05 .05 .05 .1


Pre-Order Traversal of Optimal Tree : 
D B A C E 

Optimal Cost: 2.350000


*/