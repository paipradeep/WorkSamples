/*Assigning of n tasks of variable duration to m similar parallely running machines
so as to minimize the total time taken to complete all the tasks*/
//A greedy solution
#include<stdio.h>
#include<stdlib.h>
struct task
{
	int num;	//task number
	int duration;	//task duration
	
};
typedef struct task Task;
struct machine
{
	//struct task a[10];
	int tt;
};
typedef struct machine Mac;

void sort(Task *t,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(t[j].duration<t[j+1].duration)
			{
				Task temp;
				temp = t[j];
				t[j] = t[j+1];
				t[j+1] = temp;
			}
		}
	
}
int min(int a,int b){
	if(a<b) return a;
	return b;
}

int max(Mac *m,int n)
{
	int i,r = m[0].tt;
	for(i=1;i<n;i++)
		if(m[i].tt>r)
			r = m[i].tt;
	return r;
}

int addtask(Mac *m,int n)
{
	int min =0,i,val = m[0].tt;
	for(i=1;i<n;i++)
		if(m[i].tt<val)
		{
			val = m[i].tt;
			min =i;
		}
	return min;
}		
void main()
{	
	int n,time=0;
	printf("Enter number of machines");
	scanf("%d",&n);
	Mac m[10];
	Task t[20];
	int i=0;
	int flag = 1;
	do
	{	int number,d;
		scanf("%d",&number);
		//TASK input from file with 11111 as the explicit end-of-file character
		if(number== 11111)	
			break;
		scanf("%d",&d);
		t[i].num = number;
		t[i++].duration = d;
	}while(flag);
	int no_of_tasks = i;
	
	for(i=0;i<n;i++)
		m[i].tt = 0;
	
	sort(t,no_of_tasks);
	
	int j=0;
	while(j!=no_of_tasks)
	{
		int k= addtask(m,n);
		m[k].tt += t[j].duration;
		j++;
	}
	
	time = max(m,n);
	
	printf("Total time taken:%d",time);

			
	
}
			
