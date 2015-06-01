/*
 ************************************************
 *Name : visit_graph.c                          *
 *Date : 2015-05-28                             *
 *Author : sniper                               *
 *Aim : The adjacency list storage the graph and*
 *      visit the graph.                        *
 ************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include "Adj_list.h"

int visit[MAX_VERTEX_NUM]={0};

ALGraph* create(ALGraph *G)
{
	int i,j;
	int node_pair1,node_pair2;
	ArcNode *arc;
	
	node_pair1=0;
	node_pair2=0;
	i=0;
	j=0;
	printf("please input the number of node and edge: ");
	scanf("%d %d",&G->vexnum,&G->arcnum);

	for(i=0;i<G->vexnum;i++)
	{
		G->vertices[i].data = 'A'+i;
		G->vertices[i].firstarc=NULL;
	}	
	printf("finish the Node!\n");

	for(j=0;j<G->arcnum;j++)
	{
		printf("please input the node pair: ");  
  
        scanf("%d %d",&node_pair1,&node_pair2);  
		node_pair1-=1;
		node_pair2-=1;
        /* 
         *Node pair get match with each other  
         *and storage into the adjacency list. 
         */  
		arc = (ArcNode *)malloc(sizeof(ArcNode));  
		arc->adjvex = node_pair2+'A';  
		arc->nextarc=G->vertices[node_pair1].firstarc;  
		G->vertices[node_pair1].firstarc=arc;        
	}
	printf("finish the Adjacency List\n");
	return G;
}

void DFS_Visit(ALGraph *G)
{
	int i,j=0;

	for(i=0;i<G->vexnum;i++)
	{
		visit[i]=0;
	}
	for(j=0;j<G->vexnum;j++)
	{
		if(visit[j]!=1)
			DFS(G,j);
	}
}

int DFS(ALGraph *G,int i)
{	
	int w;

	if(G->vertices[i].firstarc==NULL)
	{
		if(visit[i]!=1)
		{
			visit[i] = 1;
			printf("%c -> ",G->vertices[i].data);
			return 0;
		}	
	}
	printf("%c -> ",G->vertices[i].data);
	visit[i]=1;
	
	//for(w=G->vertices[i].firstarc->adjvex-'A';w>=0;w=NextArc(G,i,w))
	w=NextArc(G,i,w);
	if(visit[w]!=1)
		DFS(G,w);
	return 0;
}

int NextArc(ALGraph *G,int i,int w)
{
	ArcNode *arc;
	
	arc=G->vertices[i].firstarc->nextarc;
	w = arc->adjvex-'A';
	return w;
}

int main()
{
	ALGraph *G;
	int i;	
	
	i=0;
	G = (ALGraph *)malloc(sizeof(ALGraph));
	G = create(G);

	printf("print the DFS\n");

	DFS_Visit(G);
	
	/*
     *Print the Adjacency list
     */
	printf("\n print Adjacency list\n");
	for(i=0;i<G->vexnum;i++)
	{
		printf("%c -> ",G->vertices[i].data);
		while(G->vertices[i].firstarc!=NULL)
		{
			printf("%c -> ",G->vertices[i].firstarc->adjvex);
			G->vertices[i].firstarc=G->vertices[i].firstarc->nextarc;			
		}
		printf("\n");
	}

	
	
	
	return 0;
}

