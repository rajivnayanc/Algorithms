#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

int val(int * a, int i,int j, int n){
	return *((a+i*n)+j);
}

void paths(int * path, int i, int j, int n){
	if(val(path,i,j,n)==-1){
		if(i==j)
			printf("%d",i+1);
		else
			printf("%d->%d",i+1,j+1);
		return;
	}
	else{
		printf("%d->",i+1);
		paths(path,val(path,i,j,n),j,n);
	}
}

int main(int argc, char const *argv[])
{
	printf("Enter Number of Vertices: ");
	int n; scanf("%d",&n);
	int A[n][n];
	int path[n][n];
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
			if(i!=j && A[i][j]==0)
				A[i][j]=INT_MAX;
			path[i][j] = -1;
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				if(j==k){
					A[j][k]=0;
				}
				else{

					int a = A[j][k];
					int b = A[j][i];
					int c = A[i][k];
					int temp = 0;
					if(b==INT_MAX || c==INT_MAX)
						continue;
					else {
						b= b+c;
						temp = (a<=b)?0:1;
					}
					if(temp==1){
						A[j][k] = b;
						path[j][k] = i;
					}
				}
			}
		}
	}

	printf("\n\nWeight Matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%4d ", A[i][j]);
		}
		printf("\n");
	}

	printf("\n\nPath Matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%4d ", path[i][j]);
		}
		printf("\n");
	}

	
	printf("\n\n");
	printf("S->D\tDistance\tPath\n\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d->%d\t%d\t\t",i+1,j+1,A[i][j]);
			paths((int *)path, i,j,n);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}



/*

Enter Number of Vertices: 4
0 3 0 0
0 0 12 5
4 0 0 -1
2 -4 0 0


Weight Matrix:
   0    3   15    8
   7    0   12    5
   1   -5    0   -1
   2   -4    8    0


Path Matrix:
  -1   -1    1    1
   3   -1   -1   -1
   3    3   -1   -1
  -1   -1    1   -1


S->D    Distance        Path

1->1    0               1
1->2    3               1->2
1->3    15              1->2->3
1->4    8               1->2->4

2->1    7               2->4->1
2->2    0               2
2->3    12              2->3
2->4    5               2->4

3->1    1               3->4->1
3->2    -5              3->4->2
3->3    0               3
3->4    -1              3->4

4->1    2               4->1
4->2    -4              4->2
4->3    8               4->2->3
4->4    0               4

*/




/*

Enter Number of Vertices: 4
0 5 0 10
0 0 3 0
0 0 0 1
0 0 0 0


Weight Matrix:
   0    5    8    9
2147483647    0    3    4
2147483647 2147483647    0    1
2147483647 2147483647 2147483647    0


Path Matrix:
  -1   -1    1    2
  -1   -1   -1    2
  -1   -1   -1   -1
  -1   -1   -1   -1


S->D    Distance        Path

1->1    0               1
1->2    5               1->2
1->3    8               1->2->3
1->4    9               1->3->4

2->1    2147483647              2->1
2->2    0               2
2->3    3               2->3
2->4    4               2->3->4

3->1    2147483647              3->1
3->2    2147483647              3->2
3->3    0               3
3->4    1               3->4

4->1    2147483647              4->1
4->2    2147483647              4->2
4->3    2147483647              4->3
4->4    0               4

*/


/*

Enter Number of Vertices: 3
0 4 11
6 0 2
3 0 0


Weight Matrix:
   0    4    6
   5    0    2
   3    7    0


Path Matrix:
  -1   -1    1
   2   -1   -1
  -1    0   -1


S->D    Distance        Path

1->1    0               1
1->2    4               1->2
1->3    6               1->2->3

2->1    5               2->3->1
2->2    0               2
2->3    2               2->3

3->1    3               3->1
3->2    7               3->1->2
3->3    0               3

*/