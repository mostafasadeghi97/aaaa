#include"MaxHeap.h"
#include<iostream>
#include <algorithm>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include <cmath> 


//based on clrs algorithm book
void MaxHeap::max_heapify(int n, int i) 
{
	int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        std::swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        max_heapify(n, largest); 
    } 
} 

void MaxHeap::build_max_heap(){
	for (int i = size / 2 - 1; i >= 0; i--) 
		max_heapify(size, i);
}


void MaxHeap::heapSort() 
{ 
	build_max_heap();

	for (int i=size-1; i>=0; i--) 
	{ 
		std::swap(arr[0], arr[i]);

		max_heapify(i,0); 
	}
	for (int i=0; i < size/2; ++i) { 
		
		int temp{arr[i]};
		arr[i] = arr[size-i-1];
		arr[size-i-1] = temp;

	} 
	for (int i = 0; i < size; ++i)
	{
	std::cout << arr[i] << " ";	 
	}
	std::cout << "\n";
} 

void MaxHeap::printArray() 
{ 
	for (int i=0; i<size; ++i) 
		std::cout << arr[i] << " "; 
	std::cout << "\n"; 
} 



void MaxHeap::add(int key){
	if (size == capacity)
	{
		int* new_arr{new int[capacity*2]};
		for (int i = 0; i < size; ++i)
		{
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
		new_arr = nullptr;
		capacity = capacity*2;
	}
	arr[size] = key;
	size++;
	build_max_heap();
}


void MaxHeap::Delete(){
	for (int i=0; i < size/2; ++i) { 
		
		int temp{arr[i]};
		arr[i] = arr[size-i-1];
		arr[size-i-1] = temp;

	}
	size--;
	build_max_heap();
}

int MaxHeap::Max(){
	if (size > 0)
	{
		if (arr[0] > arr[size-1])
		{
			return arr[0];
		}
		return arr[size-1];
	}
	return 0;
}

int MaxHeap::Parent(int i){
	if (i%2 == 0)
	{
		return arr[i/2-1];
	}
	return arr[i/2];
}

int MaxHeap::LeftChild(int i){
	return arr[2*i+1];
}

int MaxHeap::RightChild(int i){
	return arr[2*i+2];
}

int MaxHeap::operator[](int i) const{
	return arr[i];
}

int MaxHeap::getHeight() const{
	int height{};
	int index{size-1};
	while(true){
		if (index==0)
		{
			return height; 
		}
		if (index%2 == 0)
		{
			index = index/2-1;
		}
		else{
			index = index/2;
		}
		height++;
		
	}
}

std::ostream& operator<<(std::ostream& os, const MaxHeap maxheap){
	os << maxheap.arr[0] << "," << std::endl;
	for (int i = 1; i <= maxheap.getHeight(); ++i)
	{
		for (int j = std::pow(2,i)-1; j <= std::pow(2,i+1)-2; ++j)
		{
			if (j == maxheap.size)
			{
				break;
			}
			os << maxheap.arr[j] <<",";
		}

		os << std::endl;
	}
	return os;
}




MaxHeap::MaxHeap(){
	capacity = 1;
	size = 0;
	arr = new int[0];
}


int highestPowerof2(int n) 
{ 
   int p = (int)log2(n); 
   return (int)pow(2, p)*2;  
}

MaxHeap::MaxHeap(int* arr2, int size2){
	int capacity2{highestPowerof2(size2)};
	capacity = capacity2;
	arr = new int[capacity];
	for (int i = 0; i < size2; ++i)
	{
		arr[i] = arr2[i];
	}
	this->size = size2;
	// arr2 = nullptr;
	build_max_heap();
}

MaxHeap::~MaxHeap(){
	delete[] arr;
}



MaxHeap::MaxHeap(const MaxHeap& maxheap){
	size = maxheap.size;
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = maxheap.arr[i];
	}
}



MaxHeap& MaxHeap::operator=(const MaxHeap& maxheap){
	if (this == &maxheap)
	{
		return *this;
	}
	size = maxheap.size;
	delete[] arr;
	arr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = maxheap.arr[i];
	}
	return *this;
}

