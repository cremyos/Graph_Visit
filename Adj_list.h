#ifndef __ADJ_LIST_H__
#define __ADJ_LIST_H__

#define MAX_VERTEX_NUM 20

typedef struct ArcNode
{
	char adjvex;
	struct ArcNode *nextarc;
	int *info;
}ArcNode;

typedef struct VNode
{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph
{
	AdjList vertices;
	int vexnum,arcnum;
	int kind;
}ALGraph;

void DFS_visit(ALGraph *G);
void DFS(ALGraph *G,int i);

#endif /* __ADJ_LIST_H__*/
