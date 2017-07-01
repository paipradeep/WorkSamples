//Kruskal's algorithm for finding minimum spanning tree
//using Union-Find (disjoint set datastructure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Edge
{
	int src,dest,weight;
};

struct Graph
{
	int V,E;
	struct Edge* edge;
};
typedef struct Graph graph;

int find(int *parent,int i)
{
	if(parent[i] == -1)
		return i;
	return find(parent,parent[i]);

}

void Union(int *parent,int x,int y)
{
	int xset = find(parent,x);
	int yset = find(parent,y);
	parent[xset] = yset;
}

void swap(struct Edge* edge1,struct Edge* edge2)
{	//to swap two edges
	struct Edge temp = *edge1;
	*edge1 = *edge2;
	*edge2 = temp;
}

int partition(struct Edge* a,int low,int high)
{
	int pivot = a[high].weight;
	int i,j,temp;
	i = low-1;
	for(j=low;j<high;j++)
	{
		if(a[j].weight<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
			
		}
	}
	
	swap(&a[i+1],&a[high]);
	return i+1;
}

void quickSort(struct Edge* a,int low,int high)
{	
	if(low<=high)
	{
		int temp = partition(a,low,high);
		quickSort(a,low,temp-1);
		quickSort(a,temp+1,high);
	}
}	

void displayTree(struct Edge* spanning,int l)
{
	int i,weight=0;
	printf("\nEdges in the minimum spanning tree are: \n");
	for(i=0;i<l;i++)
	{	
		weight += spanning[i].weight;
		printf("%d --------------- %d\n",spanning[i].src,spanning[i].dest);
	}
	printf("The total spanning weight : %d",weight);
}
	
void Kruskal(graph *g)
{
	int i,j=0,index=-1;
	struct Edge spanning[10]; //to keep track of edges in the minimum spanning tree
	struct Edge next;
	int *parent = (int *)malloc(sizeof(int) * g->V);
	memset(parent,-1,sizeof(int) * g->V);
	quickSort(g->edge,0,g->E-1);	//for sorting of edges based on weight
	
	while(index<g->V-2)
	{
		next = g->edge[j++];
		
		if(find(parent,next.src) != find(parent,next.dest))
		{
			spanning[++index] = next;
			Union(parent,next.src,next.dest);
		}
	}
	
	displayTree(spanning,g->V-1);
}

void main()
{
	graph* g = (graph *)malloc(sizeof(graph));
	int i;
	int v,e,choice,src,dest;
	printf("\nEnter number of vertices and edges:");
	scanf("%d %d",&v,&e);
	g->V = v;
	g->E = e;
	g->edge = (struct Edge*)malloc(g->E * sizeof(struct Edge));
	for(i=0;i<g->E;i++)
	{
		printf("Enter source and destination of %d edge",i);
		scanf("%d %d",&src,&dest);
		g->edge[i].src = src;
		g->edge[i].dest = dest;
		printf("\nEnter weight of edge");
		scanf("%d",&g->edge[i].weight);
	}
	Kruskal(g); //this function finds the minimum spanning tree
}
	
	
