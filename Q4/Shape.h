#ifndef SHAPE_H
#define SHAPE_H


#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>
#include<string>

//================= MOSTAFA SADEGHI   9423067 =============



class Shape 
{
	
public: 
    virtual double area(){return 0;}
    virtual double volume(){return 0;}
    // virtual void print(){std::cout <<"";};
    // friend std::ostream& operator << (std::ostream& out, const Parent& instance);
    virtual std::ostream&  print(std::ostream& out) {
        return out;
    }
    friend std::ostream& operator << (std::ostream& out,Shape& instance);

// 	Shape() = default;

}; 

#endif