//This program finds the maximum sub-ARRAY from a given input array
//it prints the max sum,left and the right sum
//The array should contain both positive and negative integers
#include<stdio.h>
#include<stdlib.h>
struct subarray
{
	int left;	//left index of resulting maximum sub array
	int right;	//right index of resulting maximum sub array
	int sum;	//Maximum sub array sum
};

typedef struct subarray SUB;

SUB subcross(int a[],int low,int mid,int high)
{	//The max Array sum may cross the left-right boundary
	int leftsum=-100,leftindex;
	int rightsum = -100,rightindex;
	int sum = 0;
	int i;
	for(i=mid;i>=low;i--)
	{
		sum = sum+a[i];
		if(sum > leftsum)
		{
			leftsum = sum;
			leftindex = i;
		}
	}
	for(i=mid+1;i<high;i++)
	{
		sum = sum+a[i];
		if(sum > rightsum)
		{
			rightsum = sum;
			rightindex = i;
		}
	}
	SUB s;
	s.left = leftindex;
	s.right = rightindex;
	s.sum = leftsum+rightsum;
	return s;
}

SUB subnormal(int a[],int low,int high)
{	//recursive divide and conquer algorithm for computing maximum subarray
	int mid;
	if(low==high)
	{	SUB s;
		s.left = low;
		s.right = high;
		s.sum = a[low];
		return s;
	}
	
	mid = (low+high)/2;
	SUB s1,s2,s3;
	s1 = subnormal(a,low,mid);
	s2 = subnormal(a,mid+1,high);
	s3 = subcross(a,low,mid,high);
	if(s1.sum>s2.sum && s1.sum>s3.sum)
		return s1;
	else if(s2.sum >s1.sum && s2.sum >s3.sum)
		return s2;
	else
		return s3;
}
	
			

void main()
{
	int n;
	printf("Enter size:");
	scanf("%d",&n);
	int *a = (int *)malloc(n*sizeof(int));
	printf("ENter arrray:");
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	SUB s = subnormal(a,0,n);
	printf("MAx sum:%d , from index %d to %d",s.sum,s.left,s.right);
	
}
