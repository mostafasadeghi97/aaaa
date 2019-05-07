#ifndef MAXHEAP_H
#define MAXHEAP_H


#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>
#include<string>


//================= MOSTAFA SADEGHI   9423067 =============



class MaxHeap 
{
	
public: 
	void max_heapify(int, int);
	void build_max_heap();
	void heapSort();
	void printArray(); 
	int* arr;
	int size;
	int capacity;
	MaxHeap();
	MaxHeap(int*, int);
	void add(int);
	void Delete();
	int Max();
	int Parent(int);
	int LeftChild(int);
	int RightChild(int);
	int operator[](int) const;
	int& operator[](int i) {
    	return arr[i];
    }
	int getHeight() const;
	~MaxHeap();	
	MaxHeap(const MaxHeap&);
	MaxHeap& operator=(const MaxHeap&);	
}; 

std::ostream& operator<<(std::ostream& os, const MaxHeap);

#endif