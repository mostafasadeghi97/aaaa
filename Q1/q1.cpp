#include <iostream> 
#include"MaxHeap.h"
#include <vector>
#include <string>
#include<memory>
#include<algorithm> 

template <class T,class BidirectionalIterator>
void reverse (const T& v, BidirectionalIterator first, BidirectionalIterator last);


template <class T>
void display(const T& v);

int main() 
{ 
	std::vector<std::string> v;
	for (size_t i = 0; i < 1000; i++)
	{
		std::string vi = "Str";	
		if (i<10)
		{
			vi = vi + "00" + std::to_string(i);
		}
		else if (i < 100)
		{
			vi = vi + "0" + std::to_string(i);;
		}
		else {
			vi = vi + std::to_string(i);
		}
		v.push_back(vi);
		// display(v);
		
	}
	reverse(v, std::begin(v), std::end(v));
	
	return 0;
} 




template <class T,class BidirectionalIterator>
  void reverse (const T& v, BidirectionalIterator first, BidirectionalIterator last)
{
  while ((first!=last)&&(first!=--last)) {
    std::iter_swap (first,last);
    ++first;
	display(v);
  }
}

template <class T>
void display(const T& v){
	std::cout << "size: " << v.size() << ", capacity: " << v.capacity() << std::endl;
}