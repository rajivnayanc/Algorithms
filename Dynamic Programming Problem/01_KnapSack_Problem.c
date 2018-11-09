#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

typedef struct Ordered{
	int P;
	int W;
}O_P;

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter number of items: ");
	scanf("%d",&n);
	int W[n];
	int P[n];
	O_P o[n];
	int x[n];
	int i,j,k,l;

	printf("\nEnter Weights: ");
	for(i=0;i<n;i++)
		scanf("%d",&W[i]);
	
	printf("\nEnter Profits: ");
	for(i=0;i<n;i++)
		scanf("%d",&P[i]);
	int w;
	printf("\nEnter Maximum Capacity: " );
	scanf("%d",&w);

	for(i=0;i<n;i++){
		o[i].P = P[i];
		o[i].W = W[i];
	}

	O_P S[n+1][w];

	for(i=0;i<=n;i++)
		for(j=0;j<w;j++){
			S[i][j].P = -1;
			S[i][j].W = -1;
		}


	S[0][0].W = 0;
	S[0][0].P = 0;

	int L = 1;

	for(i=1;i<=n;i++){
		O_P Si[L];
		for(j=0;j<L;j++){
			Si[j].P = S[i-1][j].P + o[i-1].P;
			Si[j].W = S[i-1][j].W + o[i-1].W;
		}

		/*for(j=0;j<L;j++)
			printf("%d->%d  ",Si[j].P,Si[j].W);

		printf("\n");*/


		O_P Si2[2*L];
		k =0; l=0;

		j=0;

		while(k<L && l<L){
			if(S[i-1][k].P<=Si[l].P){
				Si2[j].P = S[i-1][k].P;
				Si2[j].W = S[i-1][k].W;
				j++;
				k++;
			}
			else{
				Si2[j].P = Si[l].P;
				Si2[j].W = Si[l].W;
				j++;
				l++;
			}
		}
		while(k<L){
			Si2[j].P = S[i-1][k].P;
			Si2[j].W = S[i-1][k].W;
			j++;
			k++;
		}
		while(l<L){
			Si2[j].P = Si[l].P;
			Si2[j].W = Si[l].W;
			j++;
			l++;
		}

		/*printf("~%d~\n",j);
		for(k=0;k<j;k++)
			printf("%d->%d  ",Si2[k].P,Si2[k].W);

		printf("\n\n");*/

		L = 2*L;
		k=0;
		l = 0; 

		while(l!=L){
			if((l!=L-1) && (Si2[l].W<=w) && !(Si2[l].P<=Si2[l+1].P && Si2[l].W>=Si2[l+1].W)){
				S[i][k].W = Si2[l].W;
				S[i][k].P = Si2[l].P;
				k++;
			}
			else if(l==L-1 && Si2[l].W<=w){
				S[i][k].W = Si2[l].W;
				S[i][k].P = Si2[l].P;
				k++;
		    }
		    l++;
		}

		L=k;
	}

	/*
	for(i=0;i<=n;i++){
		for(j=0;j<w;j++){
			printf("%d->", S[i][j].P);
			printf("%d ", S[i][j].W);
		}
		printf("\n");
	}
	*/
	O_P curr;
	curr.P = S[n][L-1].P;
	curr.W = S[n][L-1].W;

	for(j=n;j>0;j--){
		int flag1 = 0;
		int flag2 = 0;
		// printf("~%d->%d~\n",curr.P,curr.W);
		for(k=0;k<w;k++){
			if(S[j][k].P == curr.P && S[j][k].W ==curr.W){
				flag1 =1;
				break;
			}
		}
		if(flag1==0){
			x[j-1] = 0;
			continue;
		}

		for(k=0;k<w;k++){
			if(S[j-1][k].P == curr.P && S[j-1][k].W ==curr.W){
				flag2 =1;
				break;
			}
		}

		if(flag2 == 1)
				x[j-1] = 0;
		else if(flag2 == 0){
				x[j-1] = 1;
				curr.P -=P[j-1];
				curr.W -=W[j-1];
		}
	}

	printf("\nSolution: \n");
	int profit = 0;
	for(j=0;j<n;j++){
		printf("%d ",x[j]);
		profit+=x[j]*P[j];
	}

	


	printf("\n\nProfit: %d   Verified:  %lld\n", S[n][L-1].P,profit);



	return 0;
}


/*

Enter number of items: 3

Enter Weights: 10 20 30

Enter Profits: 60 100 120

Enter Maximum Capacity: 50

Solution:
0 1 1

Profit: 220   Verified:  220

*/


/*

Enter number of items: 4

Enter Weights: 22 15 2 11

Enter Profits: 31 33 11 21

Enter Maximum Capacity: 40

Solution:
1 1 1 0

Profit: 75   Verified:  75

*/

/*

Enter number of items: 6

Enter Weights: 100 50 20 10 7 3

Enter Profits: 100 50 20 10 7 3

Enter Maximum Capacity: 165

Solution:
1 1 0 1 0 1

Profit: 163   Verified:  163

*/