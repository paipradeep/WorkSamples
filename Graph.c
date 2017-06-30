//Directed Graph
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
int a[15],j=0;
struct Queue
{
	int *a;
	int front,rear;
};
typedef struct Queue queue;

struct Node
{
	int data;
	struct Node* link;
};
typedef struct Node node;

struct List
{
	node* head;
	
};
typedef struct List list;

struct Graph
{
	int v;
	list* pointer;
};
typedef struct Graph graph;


node* getNode()
{
	return (node *)malloc(sizeof(node));
}

graph* addEdge(graph *g,int src,int dest)
{	//Directed Graph
	//the edge will be added only once
	node* NN = getNode();
	NN->data = dest;
	NN->link = g->pointer[src].head;
	g->pointer[src].head = NN;
	return g;
}

void display(graph* g)
{
	//To verify whether added edges are correct
	int i;
	node* CN;
	for(i=0;i<g->v;i++)
	{
		printf("%d-->",i);
		CN = g->pointer[i].head;
		while(CN!=NULL)
		{
			printf("\t%d",CN->data);
			CN = CN->link;
		}
		printf("\n");
	}
}

void enqueue(queue *q,int data)
{
	q->a[++q->rear] = data;
	
}
		
int dequeue(queue *q)
{
	if(q->front>q->rear)
	{
		printf("Queueempty error");
		return 0;
	}
	int t = q->a[q->front++];
	if(q->front>q->rear)
	{
		q->front =0;
		q->rear = -1;
	}
	return t;
}

int isEmpty(queue *q)
{
	if(q->front>q->rear)
		return 1;
	else
		return 0;
}

void call_bfs(graph *g,int src,int *visited,queue *q)
{	if(visited[src])
		return;
	int temp;
	node* CN;
	visited[src] = TRUE;
	enqueue(q,src);
	while(!isEmpty(q))
	{
		temp = dequeue(q);
		printf("%d\t",temp);
		CN = g->pointer[temp].head;
		while(CN!=NULL)
		{
			if(!visited[CN->data])
			{
				visited[CN->data] = 1;
				enqueue(q,CN->data);
				//call_bfs(g,CN->data,visited,q);
			}
			CN = CN->link;
		}
	}
	
}

void bfs(graph *g,int src)
{
	queue q;
	q.front = 0;
	q.rear =-1;
	q.a = (int *)malloc(sizeof(int) * g->v);
	int i;
	int *visited = (int *)malloc(g->v*sizeof(int));
	for(i=0;i<g->v;i++)
		visited[i] == 0;
	//visited[src] = 1;
	for(i=0;i<g->v;i++)
		call_bfs(g,i,visited,&q);
	

}



void dfs_call(graph *g,int src,int *visited)
{
	printf("%d\t",src);					
	visited[src] = TRUE;
	node *CN = g->pointer[src].head;
	while(CN!=NULL)
	{	if(!visited[CN->data])
			dfs_call(g,CN->data,visited);
		CN = CN->link;
		
	}
	a[j++] = src; // for topological sorting only		
}
void dfs(graph *g)
{
	int *visited = (int *)malloc(g->v * sizeof(int));
	int i;
	for(i=0;i<g->v;i++)
		visited[i] = FALSE;
	for(i=0;i<g->v;i++)
		if(!visited[i])
			dfs_call(g,i,visited);
}

void dfs_call_topo(graph *g,int src,int *visited)
{
				
	visited[src] = TRUE;
	node *CN = g->pointer[src].head;
	while(CN!=NULL)
	{	if(!visited[CN->data])
			dfs_call_topo(g,CN->data,visited);
		CN = CN->link;
		
	}
	a[j++] = src; // for topological sorting only		
}

void dfs_topo(graph *g)
{
	int *visited = (int *)malloc(g->v * sizeof(int));
	int i;
	for(i=0;i<g->v;i++)
		visited[i] = FALSE;
	for(i=0;i<g->v;i++)
		if(!visited[i])
			dfs_call_topo(g,i,visited);
}						

int call_isCycle(graph *g,int src,int* visited,int* inStack)
{
	if(!visited[src])
	{
		visited[src] = TRUE;
		inStack[src] = TRUE;
		node *CN = g->pointer[src].head;
		while(CN!=NULL)
		{
			if(call_isCycle(g,CN->data,visited,inStack))
				return TRUE;
			else if(inStack[CN->data])
				return TRUE;
			CN = CN->link;
		}
	}
	inStack[src] = FALSE;
	return FALSE;
}

int isCycle(graph *g)
{
	int i;
	int *visited = (int *)malloc(g->v * sizeof(int));
	int *inStack = (int *)malloc(g->v * sizeof(int));
	for(i=0;i<g->v;i++)
	{
		visited[i] = FALSE;
		inStack[i] = FALSE;
	}
	for(i=0;i<g->v;i++)
		if(call_isCycle(g,i,visited,inStack))
			return TRUE;
		else
		return FALSE;
}

void TopoSort(graph *g)
{
	if(isCycle(g))
	{
		printf("Cycle exists graph cant be sorted");
		return;
	}
	int i;
	for(i=0;i<g->v;i++)
		dfs_topo(g);
	printf("Toplogically sorted order");
	for(i=g->v-1;i>=0;i--)
		printf("%d\t",a[i]);
}
	
		
void main()
{
	int v,i,choice,src,dest,t;
	graph *g = (graph *)malloc(sizeof(graph));
	printf("Enter number of vertices:");
	scanf("%d",&v);
	g->v = v;
	g->pointer = (list *)malloc(v * sizeof(list));
	for(i=0;i<v;i++)
		g->pointer[i].head = NULL;
			
	for(;;)
	{
		printf("Enter choice:\n1-Add edge\n2-display\n3-bfs\n4-dfs\n5-Cyclicity\n6-Topological sorting");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("Enter source and destination:");
				scanf("%d %d",&src,&dest);
				g = addEdge(g,src,dest);
				break;
			case 2: display(g);
				break;
			case 3: bfs(g,0);
				break;
			case 4: dfs(g);
				break;
			case 5:	if(isCycle(g))
					printf("\n\tThe graph has cycle\n");
				else
					printf("\n\tThe graph doesnt have cycle");
				break;
			case 6:	TopoSort(g);
				break;
				
			default:	exit(0);
		}
	}
}
				
