
#include <stdio.h>
#include <string.h>
#include "Graph.h"
#include "Timer.h"

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	//����ͼ
	Graph* G = new Graph(n, /*isDirect =*/ false);
	//����ͼ
	//Graph* G = new Graph(n, /*isDirect =*/ true);
	int f, t, w;
	//�ֶ��ӱ�
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &f, &t, &w);
		//f--, t--;//������1��ʼ
		G->insertEdge(f, t, w);
	}
	
	//�������ͼ, ���ͼ�����߱�������Ⱥ�������������ʺ���Ϊ��������
	//G->randomGraph(m, /*weight_max =*/ 1);
	//G->printEdge();
	
	//bfs����
	//G->bfs(/*s =*/0);//������ѡһ��[0, n)�ĵ����bfs
	
	//dfs����
	//G->dfs(/*s =*/0);
	
	//�����������
	//G->topoSortDFS(/*s =*/ 0, /* print =*/ true);
	//G->earlistStartTime();
	//G->latestStartTime();
	//G->printVetex();
	//G->topoSortKahn(/* print =*/ true);
	
	//dijktra����
	//G->dijkstraBrute(/*s =*/ 0);
	//G->printVetex();
	//G->dijkstraHeap(/*s =*/ 0);
	//G->printVetex();
	//��ý������Ķ�
	//G->getCloseCet(/*hasNegEdge =*/ false);


	//������㷨��ע�⣡��ʹ��Prim�㷨�����ҳ���v_iΪ���������������һ������Ȩ��̵�������Ϊ�����������ڵ�Ϊ��
	//prim ����
	//list<Edge>* treeList = new list<Edge>;
	//printf("%d\n", G->primBrute(/*root =*/ 0, treeList));
	//G->printVetex();
	//G->printEdge();
	//G->printSpanningTree(treeList);

	//treeList->clear();
	/*********************task2 finished ****************************/
	//printf("%d\n", G->primHeap(/*root =*/ 1-1, treeList));
	//G->printVetex();
	//G->printSpanningTree(treeList);
	//G->printEdge();
	
	{
		Timer timer;
		list<Edge>* treeList = new list<Edge>;
		timer.start();
		//task2
		printf("%d\n", G->primHeap(/*root =*/ 1-1, treeList));
		G->printEdge(); //edges.js
		//task1
		G->floyd(/*print =*/ false);//ͬʱ���betCent
		G->printAllminPath(); //paths.js
		//task3
		G->getCloseCet(/*hasNegEdge =*/ false);//���closeCet
		//task4
		printf("modularity:%f \n", G->communityDetecting(/*iter=*/200, /*thread_num=*/12));
		G->printVetex(); //nodes.js
		printf("Time Elasped: %.3f\n", timer.duration());
	}
	
	
	//Kruskal����ʵ����ȫ���������Ѱ�ң���Ϊ���㷨�Ա�Ϊ��λ��(��һ��ֻ��һ����������Ҳ���ǿ��Դ��ڷ���)
	//kruskal����
	//list<Edge>* treeList = new list<Edge>;
	//printf("%d\n", G->kruskal(treeList));
	//G->printVetex();
	//G->printSpanningTree(treeList);
	//G->printEdge();

	//bellman-Ford����
	//G->bellmanFord(/*s =*/0);
	//G->printVetex();

	//warshall����
	//G->warshall(/* print =*/ true);

	/*********************task1 finished ****************************/
	//floyd���ԣ�ͬʱ��ý������Ķ�
	//G->floyd(/*print =*/ false);
	//G->printVetex();//��ý������Ķ�
	//G->printAllminPath();//��ӡ���е��֮������·��

	//����������
	//printf("spanning tree number:%d\n", G->countSpanningTree());
	//����ͼ�ĸ��������1��ʼ
	//printf("%d\n", G->spanningTreeFromRoot(/* root=*/1));

	//��Ⱥ���ֲ���, ����Ⱥ�������������Ե�ͼ�����ԼӴ��������
	//printf("modularity:%f \n", G->communityDetecting(/*iter=*/80, /*thread_num=*/8));
	//G->printVetex();

	delete G;
	return 0;
}
