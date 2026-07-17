#ifndef SORT_H
#define SORT_H

#include<iostream>
#include<vector>
class Sort{
public:
	
	static void traverse(std::vector<int>& vec);
	static void bubbleSort(std::vector<int>& vec);
	static void selectionSort(std::vector<int>&vec);
	static void insertionSort(std::vector<int>& vec);
	static void shellSort(std::vector<int>& vec);
	static void mergeSort(std::vector<int>& vec);
	static void heapSort(std::vector<int>& vec);
	static void countingSort(std::vector<int>& vec);
//	radixSort
//	bucketSort
protected:
	virtual void quickSort(std::vector<int>& vec)=0;
	
	static void merge(std::vector<int>& vec,int l,int m,int r);
	static void mergeSort(std::vector<int>& vec,int l,int r);
private:
	static void heapify(std::vector<int>& vec,int n,int i);
};

class LomutoSort:public Sort{
public:
	void quickSort(std::vector<int>& vec);
private:
	int partition(std::vector<int>& vec,int low,int high);
	void quickSort(std::vector<int>& vec,int low,int high);
};

class HoareSort:public Sort{
public:
	void quickSort(std::vector<int>& vec);
private:
	int partition(std::vector<int>& vec,int low,int high);
	void quickSort(std::vector<int>& vec,int low,int high);
	int medianOfThree(std::vector<int>& vec,int low,int high);
};
#endif
