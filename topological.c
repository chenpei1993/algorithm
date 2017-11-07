/*
拓扑排序
G 邻接表表示的有向图
*/
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

#define isLetter(a)   ((((a)>='a') && ((a)<='z')) ||((a)>='A') &&((a)<='Z'))
#define LENGTH(a)		(sizeof(a)/sizeof(a[0]))

//邻接表中表对应的链表的顶点
typedef struct _ENode{
	int ivex;					//该边所指向的顶点的位置
	struct _ENode *next_edge; 	//指向吓一条弧的指针
}ENode,*PENode;


//邻接表中表的顶点
typedef struct _VNode{
	char data;					//顶点数据
	ENode *first_edge;			//指向第一条依附该顶点的弧
}VNode;

typedef struct _LGraph
{
	int vexnum;					//图的顶点的数目
	int edgnum;					//图的边的数目
	VNode *vexs;				//图的顶点数组
}LGraph;

//返回ch在matrix中的位置
static int get_position(LGraph G,char ch)
{
	for(int i=0;i <G.vexnum;i++){
		if(G.vexs[i].data==ch){
			return i;
		}
	}
	return -1;
}

//读取一个输入字符
static char read_char()
{
	char ch;
	do{
		ch=getchar();
	}while(!isLetter(ch));
	return ch;
}

//将node链接到list的末尾
static void link_last(ENode *list,ENode *node)
{
	ENode *p=list;
	while(p->next_edge){
		p = p->next_edge;
	}
	p->next_edge=node;
}

//
LGraph* create_lgraph()
{		
	char c1,c2;
	int v,e;
	int i,p1,p2;
	
	ENode *node1,*node2;
	LGraph* pG;

	printf("input vertex number: ");
	scanf("%d",&v);
	printf("input edge number: ");
	scanf("%d",&e);

	if((v<1) ||(e <1) || (e>(v*(v-1)))){
		printf("input error :invalid parameter");
		return NULL;
	}
	
	pG=(LGraph *)malloc(sizeof(LGraph));
	assert(pG!= NULL);
	
	//初始化
	pG->vexnum=v;
	pG->edgnum=e;
	pG->vexs=(VNode *)malloc(sizeof(VNode)*v);
	assert(pG->vexs!= NULL);

	for(i=0; i<pG->edgnum;i++){
		printf("edge(%d)",i);
		c1=read_char();
		c2=read_char();
	
		p1=get_position(*pG,c1);
		p2=get_position(*pG,c2);

		node1=(ENode*)malloc(sizeof(ENode));
		node1->ivex =p2;									//该边所指向的顶点位置，用于深度遍历
		if(pG->vexs[p1].first_edge=NULL){
			pG->vexs[p1].first_edge=node1;
		}else{
			link_last(pG->vexs[p1].first_edge,node1);
		}
	}
	return pG;

}

//exmaple
LGraph* create_exmaple_lgraph()
{	
	char c1,c2;
	char vexs[]={'A','B','C','D','E','F','G'};
	char edges[][2]={
		{'A','G'},
		{'B','A'},
		{'B','D'},
		{'C','F'},
		{'C','G'},
		{'D','E'},
		{'D','F'},
	};

	int vlen=LENGTH(vexs);
	int elen=LENGTH(edges);

	int i,p1,p2;
	ENode *node1,*node2;
	LGraph* pG;
	
	if((pG=(LGraph*)malloc(sizeof(LGraph)))==NULL)
	assert(pG!=NULL);
	memset(pG,0,sizeof(LGraph));

	pG->vexnum=vlen;
	pG->edgnum=elen;
	pG->vexs=(VNode *)malloc(sizeof(VNode)*pG->vexnum);
	assert(pG->vexs!= NULL);

	//初始化邻接表里元素
	for(i=0;i<pG->vexnum;i++){
		pG->vexs[i].data=vexs[i];
		pG->vexs[i].first_edge=NULL;

	}

	for(i=0;i<pG->edgnum;i++){
		c1=edges[i][0];	//读取起始顶点
		c2=edges[i][1]; //读取结束顶点

		p1=get_position(*pG,c1);
		p2=get_position(*pG,c2);

		node1=(ENode*)malloc(sizeof(ENode));
		node1->ivex=p2;
		
		if(pG->vexs[p1].first_edge==NULL){
			pG->vexs[p1].first_edge=node1;
		}else{
			link_last(pG->vexs[p1].first_edge,node1);
		}

	}

	
	return pG;

}

//深度优先搜索遍历图的递归实现
static void DFS(LGraph G,int i,int *visited)
{
	int w;
	ENode* node;
	visited[i]=1;
	printf(" %c",G.vexs[i].data);
	node=G.vexs[i].first_edge;
	while(node != NULL){
		if(!visited[node->ivex]){
			DFS(G,node->ivex,visited); 			//深度遍历
		}
		node=node->next_edge; //深度i遍历返回后，指向下一个边
	}
}

//深度优先搜索遍历图
void DFS_traverse(LGraph G)
{
	int i;
	int * visited;
	visited=(int *)malloc(G.vexnum*sizeof(int));
	assert(visited !=NULL);
	memset(visited,0,sizeof(visited));

	printf("DFS \n");
	for(i=0;i<G.vexnum;i++){
		if(!visited[i]){
			DFS(G,i,visited);
		}
	}
	printf("\n");
	free(visited);
}
//广度优先搜索遍历图

void BFS(LGraph G)
{
	int head=0;
	int rear=0;
	int *queue;
	int *visited;
	int i,j,k;
	ENode *node;


	queue=(int *)malloc(G.vexnum*sizeof(int));
	visited=(int *)malloc(G.vexnum*sizeof(int));
	assert(queue!=NULL && visited !=NULL);
	memset(queue,0,G.vexnum*sizeof(int));
	memset(visited,0,sizeof(visited));

	printf("BFS \n");

	for(i=0;i<G.vexnum;i++){
		if(!visited[i]){
			visited[i]=1;
			printf("%c",G.vexs[i].data);
			queue[rear++]=i;
		}
		
		while(head!=rear){

			j=queue[head++];
			node=G.vexs[j].first_edge;
			while(node!=NULL){
				k=node->ivex;
				if(!visited[k]){
					visited[k]=1;
					printf("%c",G.vexs[k].data);
					queue[rear++]=k;
				}
				node=node->next_edge;
			}
		}
	}
	printf("\n");
	free(visited);
	free(queue);
	
}

//拓扑排序
int topological_sort(LGraph G)
{
	int i,j;
	int index=0;
	int head=0;	//辅助队列头部
	int rear=0;	//辅助队列尾部
	int *queue;	//辅助队列
	int *ins;	//入度数组
	char *tops; //拓扑排序结果数组，记录每个节点的排序后的序号
	
	ENode *node;

	queue=(int *)malloc(G.vexnum*sizeof(int));
	tops=(char *)malloc(G.vexnum*sizeof(char));
	ins=(int *)malloc(G.vexnum*sizeof(int));
	assert(queue!=NULL && ins!=NULL && tops!=NULL);
	memset(queue,0,G.vexnum*sizeof(int));
	memset(tops,0,G.vexnum*sizeof(char));
	memset(ins,0,G.vexnum*sizeof(int));

	
	//统计每个顶点的入度数
	for(i=0;i<G.vexnum;i++){
		node=G.vexs[i].first_edge; //
		while(node!=NULL){
			ins[node->ivex]++;
			node=node->next_edge;
		}

	}


	//将所有入度数为零的顶点如队列
	for(i=0;i<G.vexnum;i++){
		if(ins[i]==0){
			queue[rear++]=i;
		}
	}

	//
	while(head!=rear)
	{
		j=queue[head++];
		tops[index++]=G.vexs[j].data;
		node=G.vexs[j].first_edge;
		
		while(node != NULL){
			ins[node->ivex]--;
			if(ins[node->ivex]==0){
				queue[rear++]=node->ivex;
			}
			node=node->next_edge;
		
		}
	}

	if(index != G.vexnum ){
		printf("Graph has a cycle \n");
		free(queue);
		free(ins);
		free(tops);

		return 1;
	}

	//打印结果
	printf("Topological Sort: ");
	for(i=0;i<G.vexnum;i++){
		printf("%c ",tops[i]);
	}
	printf("\n");

	free(queue);
	free(ins);
	free(tops);
	return 0;
}

//打印邻接表
void print_lgraph(LGraph G)
{
	int i;
	ENode *node;
	printf("List Graph: \n");
	for(i=0;i<G.vexnum;i++){
		printf("%d(%c)",i,G.vexs[i].data);
		node=G.vexs[i].first_edge;
		while(node != NULL){
			printf("%d(%c)",node->ivex,G.vexs[node->ivex].data);
			node=node->next_edge;
		}
		printf("\n");
	}
}


void main()
{
	LGraph* pG;
	printf("starting \n");
	pG=create_exmaple_lgraph();
	print_lgraph(*pG);
	DFS_traverse(*pG);
	BFS(*pG);
	topological_sort(*pG);
}
