#ifndef CUBE_H
#define CUBE_H


#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>
#include<string>
#include"ThreeDimensionalShape.h"

//================= MOSTAFA SADEGHI   9423067 =============

class Cube : public ThreeDimensionalShape
{
	
public: 
	Cube(double side_length, double x, double y, double z){
		this->side_length = side_length;
		this->x = x;
		this->y = y;
		this->z = z;
	}
	virtual double volume(){
		return std::pow(this->side_length,3);
	}
	virtual double area(){
		return 6.0 * std::pow(this->side_length,2);
	}

	std::ostream&  print(std::ostream& out){
		std::cout  << "Cube side length = " << side_length << std::endl;
		std::cout << "center-->(" << x << ", " << y <<", " << z << ")" << std::endl;
		std::cout << "area of " << area() << " & " << "volume of " << volume() << std::endl;
		return Shape::print(out);
	}

	double side_length,x,y,z;
	
}; 

#endif