
#pragma once
#include "util.h"
#include <string.h>

//��С��
template<typename T>
class MinHeap{
	int _size;//������
	T* arr;//���rank��rank
	int _currentSize;//��ǰ��С
	//����
	int percolateUp(int x){
		int i = x;
		while(i > 0){
			int j = i>>1;
			if(j <= 0)break;
			if(arr[j] < arr[i])break;
			T temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
			i = j;
		}
		return i;
	}
	//�ж�����rank��Ӧ�ڵ��ĸ�С
	int smaller(int i, int j){
		return arr[i] < arr[j] ? i : j;
	}
	//���ظ���������(�����)��С���Ǹ�
	int properParent(int i){
		if(i<<1 >= _currentSize)return i;
		if((i<<1|1) == _currentSize)return smaller(i, i<<1);
		return smaller(i<<1|1, smaller(i, i<<1));
	}
	//����
	int percolateDown(int x = 1){
		int j, i = x;//�Ѷ�
		while(i != (j = properParent(i))){
			T temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
			i = j;
		}
		return i;
	}
public:
	MinHeap(int k = 64):_size(k + 1), arr(new T[_size]), _currentSize(1){};
	//floyd ��������
	MinHeap(int _n, T* _arr): _size(_n+1), arr(new T[_size]), _currentSize(_n+1){
		memcpy(arr+1, _arr, _n*sizeof(T));
		for(int i = _n/2; i >= 1; i--){//�Ե�����
			percolateDown(i);//����
		}
	}
	~MinHeap(){
		delete[] arr;
	};
	//����Ԫ��,ά��sizeʼ��Ϊk
	void push(T data){
		arr[_currentSize++] = data;
		percolateUp(_currentSize-1);
	}
	//ɾ��Ԫ��
	T pop(){
		assert(_currentSize >= 1);
		T minNode = arr[1];
		arr[1] = arr[--_currentSize];
		percolateDown();
		return minNode;
	}
	//�����Сֵ
	T top()const{
		return arr[1];
	}
	bool empty(){
		return _currentSize <= 1;
	}
};
