#ifndef ORACLE_H
#define ORACLE_H

#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>
#include<string>
#include"Human.h"

//================= MOSTAFA SADEGHI   9423067 =============

class Oracle 
{
	
public: 
	Oracle(std::string);
	bool marry(Human*, Human*);
private:
	std::string Name;
	
}; 

#endif