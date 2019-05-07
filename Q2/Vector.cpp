#include"Vector.h"
#include<iostream>



void Vector::push_back(int t)
{
    if(size == capacity)
        resize(2*capacity);
    array[size] = t;
    size++;
}

void Vector::pop_back()
{
    if(size > 0 && size == (capacity/2 + 1 )){
    	if (capacity != 1)
    	{
    		resize(capacity/2);
    	} 
    }

    if (size > 0)
    {
    	size--;
    }
    
}

void Vector::resize(int n) // make the size of the internal array exactly n
{
    if(n > capacity) 
    {
        int* new_array{new int[n]};
        for(int i=0; i < size; i++)
        {
            new_array[i] = array[i];
        }

        delete[] array;
        array = new_array;
        new_array = nullptr;
        capacity = n;
    }
    else if (n < capacity)
    {
    	int* new_array{new int[n]};
    	for (int i = 0; i < n; ++i)
    	{
    		new_array[i] = array[i];
    	}
    	delete[] array;
    	array = new_array;
    	new_array = nullptr;
    	capacity = n;
    }
}




void Vector::show() const{
	std::cout << "capacity:" <<  capacity << ",size:" << size << " values(";
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i];
		if (i!= size-1)
		{
			std::cout << ",";
		}
	}
	std::cout << ")" << std::endl;
}



int Vector::operator[](int i) const{
	return array[i];
}




Vector::Vector(const Vector& vector){
	std::cout << "Copy constructor" << std::endl;
	size = vector.size;
	capacity = vector.capacity;
	array = new int[capacity];
	for (int i = 0; i < size; ++i)
	{
		array[i] = vector.array[i];
	}

}

Vector::Vector(Vector&& vector){
	std::cout << "Move constructor" << std::endl;
	size = vector.size;
	capacity = vector.capacity;
	array = vector.array;
	vector.array = nullptr;
}


bool Vector::operator<(const Vector& vector) const{
	return size < vector.size;
}

bool Vector::operator==(const Vector& vector) const {
	return size == vector.size;
}

Vector& Vector::operator+=(const Vector& vector){
	if (size == vector.size)
	{
		for (int i = 0; i < size; ++i)
		{
			array[i] += vector.array[i]; 
		}
	}
	else{
		std::cout << "Vectors do not have equal size" << std::endl;
	}
	return *this;
}

Vector Vector::operator+(const Vector& vector){
	Vector copy{*this};
	copy+=vector;
	return copy;
}

int Vector::operator*(const Vector& vector){
	if (size == vector.size)
	{
		int sum{};
		for (int i = 0; i < size; ++i)
		{
			sum += array[i] * vector.array[i];
		}
		return sum;
	}
	else{
		std::cout << "Vectors do not have equal size" << std::endl;
	}
	return 32222;
}



Vector& Vector::operator++(){
	for (int i = 0; i < size; ++i)
	{
		array[i]+=1;
	}
	return *this;
}


Vector Vector::operator++(int){
	Vector copy{*this};
	for (int i = 0; i < size; ++i)
	{
		array[i]+=1;
	}
	return copy;
}

Vector& Vector::operator=(const Vector& vector){
	std::cout << "Vector = copy version operator" << std::endl;
	if (this == &vector)
	{
		return *this;
	}
	size = vector.size;
	capacity = vector.capacity;
	delete[] array;
	array = new int[capacity];
	for (int i = 0; i < size; ++i)
	{
		array[i] = vector.array[i];
	}
	return *this;
}

Vector& Vector::operator=(Vector&& vector){
	std::cout << "Vector = move version operator" << std::endl;
	if (this == &vector)
	{
		return *this;
	}
	size = vector.size;
	capacity = vector.capacity;
	delete[] array;
	array = vector.array;
	vector.array = nullptr;
	return *this;
}
