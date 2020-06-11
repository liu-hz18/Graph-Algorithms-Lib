
#include "Graph.h"
#include <fstream>

//打印从from 到to 的最短路
void Graph::printPath(int from, int to, int** mat, ofstream& fout){
	assert(0 <= from && from < n && 0 <= to && to < n && from != to);
	//printf("min path from (%d) to (%d): ", from+1, to+1);
	// log to file
	stack<int> temp = pathlist[from][to];//保存副本
	int v = from;
	list<int> weight;
	while(!temp.empty()){
		int u = temp.top();
		weight.push_back(mat[v][u]);
		//printf("%d, ", u+1); 
		fout << u << ", ";
		temp.pop();
		v = u;//(v,u) 边权
	}
	//打印最短路径上的边权
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

//打印所有点对之间的最短路
void Graph::printAllminPath(){
	//如果还要输出权重，就要再次邻接表转邻接矩阵
	int** mat = listToMatrix();
	// fout
	ofstream fout("./static/js/paths.js");
	fout << "var nodenumber = "  << n << ";" << endl;
	fout << "var path = new Array;" << endl;
	//run and log
	if (isDirected) {//有向图
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
	} else {//无向图
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
