#ifndef CIRCLE_H
#define CIRCLE_H


#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>
#include<string>
#include"TwoDimensionalShape.h"
#include<cmath>

//================= MOSTAFA SADEGHI   9423067 =============

class Circle : public TwoDimensionalShape
{
	
public: 
	Circle(double radius, double x, double y){
        this->radius = radius;
        this->x = x;
        this->y = y;
    }
    virtual double area(){
        return std::acos(-1) * radius * radius;
    }
    // double volume(){
    //     return 0;
    // }
    
    // virtual void print(){
        
    // }

    std::ostream&  print(std::ostream& out) {
        out << "Circle radius = " << radius << std::endl;
        out << "center-->(" << x << ", " << y << ")" << std::endl;
        out << "area of " << area() << std::endl;
        return Shape::print(out);
    }

    double radius,x,y;

	
}; 
// std::ostream& operator<<(std::ostream& os,Circle circle);

#endif