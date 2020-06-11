
#include "Graph.h"
#include <fstream>

//��ӡ��from ��to �����·
void Graph::printPath(int from, int to, int** mat, ofstream& fout){
	assert(0 <= from && from < n && 0 <= to && to < n && from != to);
	//printf("min path from (%d) to (%d): ", from+1, to+1);
	// log to file
	stack<int> temp = pathlist[from][to];//���渱��
	int v = from;
	list<int> weight;
	while(!temp.empty()){
		int u = temp.top();
		weight.push_back(mat[v][u]);
		//printf("%d, ", u+1); 
		fout << u << ", ";
		temp.pop();
		v = u;//(v,u) ��Ȩ
	}
	//��ӡ���·���ϵı�Ȩ
	/*
	printf(", edge weight: ");
	auto it = weight.begin();
	it++;
	for(; it != weight.end(); it++){
		printf("%d ", *it);
	}
	putchar(10);
	*/
}

//��ӡ���е��֮������·
void Graph::printAllminPath(){
	//�����Ҫ���Ȩ�أ���Ҫ�ٴ��ڽӱ�ת�ڽӾ���
	int** mat = listToMatrix();
	// fout
	ofstream fout("./static/js/paths.js");
	fout << "var nodenumber = "  << n << ";" << endl;
	fout << "var path = new Array;" << endl;
	//run and log
	if (isDirected) {//����ͼ
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i != j){
					fout << "path[" << i * n + j <<"] = [ ";
					printPath(i, j, mat, fout);
					fout << "];" << endl;
				} else {
					fout << "path[" << i * n + i <<"] = [ " << i << ", " << i << ", ];" << endl;
				}
			}
		}
	} else {//����ͼ
		for(int i = 0; i < n; i++){
			fout << "path[" << i * n + i <<"] = [ " << i << ", " << i << ", ];" << endl;
			for(int j = i+1; j < n; j++){
				fout << "path[" << i * n + j <<"] = [ ";
				printPath(i, j, mat, fout);
				fout << "];" << endl;
			}
		}
	}
	fout.close();
}
