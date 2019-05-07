#ifndef SPHERE_H
#define SPHERE_H


#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>
#include<string>
#include<cmath>
#include"ThreeDimensionalShape.h"

//================= MOSTAFA SADEGHI   9423067 =============

class Sphere : public ThreeDimensionalShape
{
	
public: 
	Sphere(double radius,double x,double y, double z){
		this->radius = radius;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	virtual double volume(){
		return 4.0/3.0 * std::acos(-1) * std::pow(this->radius,3);
	}

	virtual double area(){
		return 4.0 * std::acos(-1) * std::pow(this->radius,2) ;
	}

	std::ostream&  print(std::ostream& out){
		std::cout << "Cube radius = " << radius << std::endl;
		std::cout << "center-->(" << x << ", " << y <<", " << z << ")" << std::endl;
		std::cout << "area of " << area() << " & " << "volume of " << volume() << std::endl;
		return Shape::print(out);	
	}

	double radius,x,y,z;

	
}; 


#endif