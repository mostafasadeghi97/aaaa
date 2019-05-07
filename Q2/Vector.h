#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>

//================= MOSTAFA SADEGHI   9423067 =============


class Vector 
{ 
public: 
	Vector(){
		std::cout << "construct" << std::endl;
		capacity = 1;
		size = 0;
		array = new int[capacity];
	}
	~Vector(){
		std::cout << "destruct" << std::endl;
		delete[] array;
	};

	void push_back(int t);
	void pop_back();
	void resize(int n);

	Vector(const Vector&);
	Vector(Vector&&);
	// Vector& (int);
	bool operator<(const Vector&) const;
	bool operator==(const Vector&) const;
	Vector operator+(const Vector&);
	Vector& operator+=(const Vector&);
	int operator*(const Vector&);
	Vector& operator++();
	Vector operator++(int);
	Vector& operator=(const Vector&);
	Vector& operator=(Vector&& Vector);
	void show() const;
	int operator[](int) const;

    int* array;
	int size;
	int capacity;
}; 