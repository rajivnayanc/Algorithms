#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;

	printf("\nEnter the size of array: ");
	scanf("%d",&n);

	int p[n],w[n],priority[n];
	float pw[n],x[n],ckc;
	int i,j,M;

	printf("\nEnter Profit: ");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}

	printf("\nEnter Weights: ");
	for(i=0;i<n;i++){
		scanf("%d",&w[i]);
	}

	for(i=0;i<n;i++){
		pw[i]=(float)p[i]/(float)w[i];
		x[i]=0;
	}

	printf("\nEnter the capacity of Knapsack: ");
	scanf("%d",&M);
	ckc= M;

	printf("\nArray of profit per unit weight: \n");
	for (i = 0; i < n; ++i){

		printf("%.2f ",pw[i] );
	}
	printf("\n");


	for(i=0;i<n;i++){

		float max=pw[0];
		int k=0;
		for(j=0;j<n;j++){

			if(max<pw[j]){

				max=pw[j];
				k=j;
			}
		}
		priority[i]=k;
		pw[k]=-100;
	}


	printf("\nPriority Order: \n");
	for (i = 0; i < n; ++i){

		printf("%d ",priority[i] );
	}

	printf("\n");

	for(i=0;i<n;i++){
		
		if(ckc>=w[priority[i]]) {

			x[priority[i]]=1;
			ckc=ckc-w[priority[i]];

		}
		else if(ckc>0 && ckc<=w[priority[i]]){
			x[priority[i]]=ckc/(float)w[priority[i]];
			ckc=ckc-w[priority[i]];

		}
		if(ckc==0){
			break;
		}

	}
	
	printf("\nValues of X-array: \n");
	for (i = 0; i < n; ++i){

		printf("%0.2f ",x[i] );
	}
	printf("\n");

	printf("\nTotal Profit: ");
	float totalprofit=0;
	for (i = 0; i < n; ++i){

		totalprofit+=(float)x[i]*p[i];
	}
	printf("%0.2f\n",totalprofit );
	printf("\n");

	return 0;
}