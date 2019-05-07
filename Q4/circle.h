#ifndef CIRCLE_H
#define CIRCLE_H


#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>
#include<string>
#include"TwoDimensionalShape.h"

//================= MOSTAFA SADEGHI   9423067 =============

class Circle : public TwoDimensionalShape
{
	
public: 
	Circle(int radius, int x, int y){
        this->radius = radius;
        this->x = x;
        this->y = y;
    }
    

    int radius,x,y;

	
}; 

#endif