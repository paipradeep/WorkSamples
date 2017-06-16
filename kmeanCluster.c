//Forming of the clusters in range r1 to r2 
//Limited to formation of 3 clusters only
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int r1,r2;//range
int size[3];
int min(int d[])
{
	if(d[0]<d[1])				
	{	if(d[0]<d[2])
			return 0;
		else
			return 2;
	}
	else 
	{
		if(d[1]<d[2])
			return 1;
		else
			return 2;
	}
}

int test(int new[],int old[],int i)
{
	for(i=0;i<3;i++)
		if(new[i]!=old[i])
			return 0;
	
	return 1;
}

int* cluster(int dataset[],int n,int **a)
{	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<15;j++)
			a[i][j]=0;
	int *centroid,*newcentroid;
	centroid = (int*) malloc(3*sizeof(int));
	newcentroid = (int *) malloc(3*sizeof(int));
	for(i=0;i<3;i++)
	{
		centroid[i] = r1 + rand()%r2;
		newcentroid[i] = 0;
	}
	int dist[3];
	for(i=0;i<3;i++)
		size[i] = 0;
	
	for(;;)
	{	//grouping
		for(i=0;i<n;i++)
		{	for(j=0;j<3;j++)
				dist[j] = abs(dataset[i] - centroid[j]); 	
			int t = min(dist); //return the index
			
			
			a[t][size[t]++] = dataset[i];
		}
		//forming centroid
		for(i=0;i<3;i++)
		{
		 	
			
			for(j=0;j<size[i];j++)
				newcentroid[i] += a[i][j];
			if(size[i])
			newcentroid[i] = (int)newcentroid[i]/size[i];
			else
			newcentroid[i] = 0;
			
		}
		//if(newcentroid == centroid)		
		if(test(newcentroid,centroid,3))
			return newcentroid;
		for(i=0;i<3;i++)
			centroid[i] = newcentroid[i];
	}
	
}

void main()
{
	int n;
	int *centroid;
	printf("\nEnter numer of datasets");
	scanf("%d",&n);
	printf("Enter range:");
	scanf("%d %d",&r1,&r2);
	int *dataset = (int *)malloc(sizeof(int)*n);
	
	int **a = (int **)malloc(3*sizeof(int *));			
	int i,j;
	for(i=0;i<3;i++)
		a[i] = (int *)malloc(15*sizeof(int));
	for(i=0;i<n;i++)
		dataset[i] =  r1 + rand()%r2;
	centroid = cluster(dataset,n,a);
	printf("The centroids are:");
	for(i=0;i<3;i++)
		printf("%d\t",centroid[i]);
	for(i=0;i<3;i++)
	{
		printf("The dataset for cluster %d\n",i+1);
		for(j=0;j<size[i];j++)
			printf("%d\t",a[i][j]);
	
	}
		
}	
