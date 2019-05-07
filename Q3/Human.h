#ifndef HUMAN_H
#define HUMAN_H


#include<map>
#include<vector>
#include<fstream>
#include<iostream>
#include<random>
#include<string>

//================= MOSTAFA SADEGHI   9423067 =============



class Human 
{
	
public: 
	Human(std::string, std::string, int, int, int, bool, int);
	~Human();
	Human(const Human&);
	bool operator>(const Human&) const;
	bool operator==(const Human&) const;
	Human* operator+(Human&);
	void operator++();

	bool isChildOf(const Human*);
	bool isMotherOf(Human*);
	bool isFatherOf(Human*);
	std::string getFirstName();
	std::string getLastName();
	bool getGender();
	int getEyeColor();
	int getHairColor();
	int getNumberOfChildren();
	int getAge();
	void show() const;
	void printChildren() const;
	Human* father;
	Human* mother;
	Human* spouse;
	Human** children;
private:
	std::string firstName, lastName;
	int hairColor, eyeColor, age, numberOfChildren;
	bool gender;
	
}; 


#endif