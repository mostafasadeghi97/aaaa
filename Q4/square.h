#ifndef SQUARE_H
#define SQUARE_H


#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>
#include<string>
#include<cmath>
#include"TwoDimensionalShape.h"

//================= MOSTAFA SADEGHI   9423067 =========rt====

class Square : public TwoDimensionalShape
{
	
public: 
	Square(double side_length,double  x,double y){
		this->side_length = side_length;
		this->x = x;
		this->y = y;
	}

	virtual double area(){
		return std::pow(this->side_length,2);
	}

	std::ostream&  print(std::ostream& out){
		std::cout << "Square side length = " << side_length << std::endl;
		std::cout << "center-->(" << x << ", " << y << ")" << std::endl;
		std::cout << "area of " << area() << std::endl; 
		return Shape::print(out);
	}

	double side_length,x,y;

	

	
}; 


#endif