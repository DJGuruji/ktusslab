#include<stdio.h>
void bubblesort(int a[50],int n,int p[50])
{
	int i,temp,al;
	for(i=0; i<n; i++)
	{
		for(int j=i+1; j<n;j++)
		{
			if(a[i] > a[j])
			{
 				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
 
				al = p[i];
				p[i] = p[j];
				p[j] = al;
			}
		}

	}
 }


void main()
{
	int n;
	printf("Enter total number of processes:\t");
	scanf("%d",&n);
	int i,bt[n];
	for(i=0; i<n; i++)
	{
		printf("Enter burst time for process %d\t",i+1);
		scanf("%d",&bt[i]);
	}
	int p[n];
	for(i=0; i<=n; i++)
	{
		p[i] = i+1;
	}
	bubblesort(bt ,n,p);

	int wt =0,tt=0;
	printf("p\tbt\twt\ttt\n");
	float twt = 0,ttt=0;
	for(i=0;i<n;i++)
	{
		tt+=wt+bt[i];
		printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt,tt);
		wt += bt[i];
		twt+=wt;
		ttt += tt;
	}

        float m = twt/n;

	printf("avg WT = %.2f\n",m);
	printf("avg TT =%.2f\n",ttt/n);

}
