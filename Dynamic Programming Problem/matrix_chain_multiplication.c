#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Matrix{
	int cost;
	int j;
}Mat;

void parenthesize(char str[], int i, int j, Mat *M, int n){

	if(j==i){
		printf("%c",str[i]);
		return;
	}

	Mat k = *((M + i*n)+j);
	printf("(");

	parenthesize(str,i,k.j,M,n);
	parenthesize(str,k.j+1,j,M,n);
	
	printf(")");

}

int main(int argc, char const *argv[])
{
	printf("Enter number of matrices: ");
	int n;
	scanf("%d",&n);

	char str[n];
	int L; char c;
	for(c = 'A', L=0;L<n;c++,L++)
		str[L]=c;


	str[L] = '\0';
	printf("%s\n",str);

	int dim[n+1];

	Mat M[n][n];

	printf("Enter Dimensions of each matrix: ");

	int i, j;
	for(i=0;i< 2*n;i++){
		int index = (i+1)/2;
		scanf("%d",&dim[index]);
	}


	for(i=0;i<n;i++){
		M[i][i].cost = 0;
		M[i][i].j = 0;
	}
	int k;

	for(i=1;i<n;i++){

		for(j=0;j<n-i;j++){

			k = j+i;
			M[j][k].cost = INT_MAX;
			int mins;

			for(mins = j;mins<k;mins++){
				int temp = M[j][mins].cost + M[mins+1][k].cost + dim[j]*dim[mins+1]*dim[k+1];
				if(temp<M[j][k].cost){
					M[j][k].cost = temp;
					M[j][k].j = mins;;
				}
			}

		}
	}

	printf("\n\nMatrix Multiplication Order: \n");
	parenthesize(str, 0 , n-1, (Mat *)M,n);
	printf("\n\nCost: %d\n\n\n",M[0][n-1].cost);

	return 0;

}

/*
Enter number of matrices: 4
ABCD
Enter Dimensions of each matrix: 5 4 4 6 6 2 2 7


Matrix Multiplication Order:
((A(BC))D)

Cost: 158

*/

/*

Enter number of matrices: 4
ABCD
Enter Dimensions of each matrix: 10 20 20 30 30 40 40 50


Matrix Multiplication Order:
(((AB)C)D)

Cost: 38000

*/

