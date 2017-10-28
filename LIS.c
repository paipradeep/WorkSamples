//Longest increasing subsequence
#include<stdio.h>

void findlis(int arr[],int lis[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++){
			if(arr[j]<arr[i] && 1+lis[j]>lis[i])
				lis[i] = 1+lis[j];

		}
	}
}
void main()
{
	int arr[10],i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int lis[10];
	for(i=0;i<n;i++)
		lis[i] = 1;
	findlis(arr,lis,n);
	int max = 0;
	for(i=0;i<n;i++)
	{	//printf("%d",lis[i]);
		if(lis[i]>max)
			max = lis[i];
	}
	printf("%d",max);
}
