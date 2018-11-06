#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	printf("Enter Number of jobs: ");
	int n;
	scanf("%d",&n);
	int d[n];
	int profit[n];
	int profitd[n];
	int i;
	printf("Enter Profits: \n");
	for(i=0;i<n;i++){
  		scanf("%d",&profit[i]);
  		profitd[i]=profit[i];
	}

	int max=0;
	printf("Enter Delay: \n");
	for(i=0;i<n;i++){
	  	scanf("%d",&d[i]);
	  	if(max<d[i])
	  		max=d[i];
	}

	int sequence[max+1];

	for(i=0;i<=max;i++){
		sequence[i]=-100;
	}

    int j;
	int priority[n];
	for(i=0;i<n;i++){

		int max=profitd[0];
		int k=0;
		for(j=0;j<n;j++){

			if(max<profitd[j]){

				max=profitd[j];
				k=j;
			}
		}
		priority[i]=k;
		profitd[k]=-100;
	}


	printf("\nPriority Order: \n");
	for (i = 0; i < n; ++i){

		printf("%d ",priority[i] );
	}

	printf("\n");
	printf("\n\nJob Sequence\n");

	for(i=0;i<n;i++){
		if(sequence[d[priority[i]]-1]==-100)
			sequence[d[priority[i]]-1]=priority[i];
		else
			{
				for(j=d[priority[i]]-1;j>=0;j--){
						if(sequence[j]==-100)
							{
								sequence[j]=priority[i];
								break;
							}
					}
			}
	}
	int total_profit=0;
	for(i=0;i<max;i++){
			if(sequence[i]>=0){
				
				printf("%d ",sequence[i] +1);
				total_profit+=profit[sequence[i]];
			}
		}

	printf("\n\n");

	printf("Total Profit=%d\n\n", total_profit );
	return 0;
}		