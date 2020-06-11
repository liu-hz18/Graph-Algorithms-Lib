
#include "Graph.h"
#include <fstream>

//���÷���״̬
void Graph::reset(){
	for(int i = 0;i < n;i ++){
		vertex[i].reset();
		for(auto& iter : edgeList[i]){
			iter.reset();
		}
	}
}

//����ͼ�ӱߣ�ֻ��Ҫ��һ����
void Graph::insertEdge(int from, int to, int w){
	edgeList[from].push_back(Edge(to, w));
	vertex[from].outDegree ++;
	vertex[to].inDegree ++;
	e++;
	//���������ͼ
	if(!isDirected){
		edgeList[to].push_back(Edge(from, w));
	}
	//����ͼ�Ķ���ֻ��ҪinDegree + outDegree����
}

//(f, t)���ڱ�
bool Graph::existEdge(int f, int t){
	for(auto& iter:edgeList[f]){
		if(iter.to == t)return true;
	}
	return false;
}

//��ӡ������Ϣ(�ֵ���ʽ���������python��������ÿ�е��ַ���ʹ��eval()�������ɣ������ֵ�)
void Graph::printVetex(){
	ofstream fout("./static/js/nodes.js");
	fout << "var nodes = [" << endl;
	for(int i = 0; i < n; i++){
		//printf("{'data':%d, 'dTime':%d, 'fTime':%d, 'parent':%d, 'inDegree':%d, 'outDegree':%d, 'priority':%d, 'state':%d, 'betCet':%f, 'cloCet':%f, 'topoRank':%d, 'earTime':%d, 'latTime':%d, 'community':%d}\n", \
		//	vertex[i].data+1, vertex[i].dTime, vertex[i].fTime, vertex[i].parent+1, vertex[i].inDegree, vertex[i].outDegree, vertex[i].priority,\
		//	vertex[i].state, vertex[i].betweenCentrality, vertex[i].closeCentrality, vertex[i].topoIndex, vertex[i].earStartTime, vertex[i].latStartTime, vertex[i].community);
		fout << "\t{ id: " << i << ", betCent: " << vertex[i].betweenCentrality << ", closeCent: " << vertex[i].closeCentrality << ", community: " << vertex[i].community << "}," << endl; 
	}
	fout << "];" << endl;
	fout.close();
	//putchar(10);
}

//��ӡ����Ϣ(�����������֧�����ṹ)
void Graph::printEdge(){
	ofstream fout("./static/js/edges.js");
	fout << "var edges = [" << endl;
	for(int i = 0; i < n; i++){
		for(auto& it : edgeList[i]){
			if(i < it.to && (i == vertex[it.to].parent || it.to == vertex[i].parent)){
				it.edgeType = TREE;
			}
			if (i < it.to)
				fout << "\t{ source: " << i << ", target: " << it.to << ", weight: " << it.weight <<", isTree: " << int(it.edgeType == TREE) << "}," << endl;
			//printf("Edge(%d, %d): weight:%d Type:", i, it.to, it.weight);
			//if(it.edgeType == UNETERMINED)printf("UNETERMINED\n");
			//else if(it.edgeType == TREE)printf("TREE\n");
			//else if(it.edgeType == CROSS)printf("FORWARD\n");
			//else if(it.edgeType == BACKWARD)printf("BACKWARD\n");
		}
	}
	fout << "];" << endl;
	fout.close();
	//putchar(10);
	//printf("tree number: %d\n", count);
}

//�����С֧��������
void Graph::printSpanningTree(list<Edge>* treeList){
	/*
	for(int i = 0; i < n; i++){
		printf("TREE EDGE:(%d, %d)\n", vertex[i].parent+1, i+1);
	}
	*/
	for(auto& edge : *treeList){
		printf("TREE EDGE:(%d,%d)\n", edge.data+1, edge.to+1);
	}
}

//�ڽӱ�ת�ڽӾ���,û�������ı���Ϊ����
int** Graph::listToMatrix(){
	int** distMatrix = new int*[n];//��С�������
	for(int i = 0; i < n; i++){//��ʼ��
		distMatrix[i] = new int[n];
		for(int j = 0; j < n; j++)distMatrix[i][j] = INT_MAX;
	}
	for(int i = 0; i < n; i++){
		for(auto& iter : edgeList[i]){
			distMatrix[i][iter.to] = iter.weight;
		}
		distMatrix[i][i] = 0;
	}
	return distMatrix;
}
