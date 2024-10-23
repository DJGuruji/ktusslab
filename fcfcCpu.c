#include<stdio.h>

void main()
	{

	printf("Enter number of processes\n");
	int n;
	scanf("%d",&n);
	int i; 
	int bt[n];
	for(i=0; i<n; i++)
	{
		printf("Enter burst time for process%d\t",i+1);
		scanf("%d",&bt[i]);
	}

	int wt =0,tt=0;
	printf("p\tbt\twt\ttt\n");
	float twt = 0,ttt=0;
	for(i=0;i<n;i++)
	{
		tt+=wt+bt[i];
		printf("%d\t%d\t%d\t%d\n",i+1,bt[i],wt,tt);
		wt += bt[i];
		twt += wt;
		ttt += tt;
	}
	printf("avg WT = %.2f\n",twt/n);
	printf("avg TT =%.2f\n",ttt/n);

}
