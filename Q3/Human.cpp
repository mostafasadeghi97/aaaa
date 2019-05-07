#include"Human.h"
#include<iostream>
#include <algorithm>
#include <string>
#include <cstdlib> 
#include <ctime> 



void Human::show() const{
	std::cout << firstName << " " << lastName << ",age:" << age  <<",numberOfChildren:"<<
	numberOfChildren << std::endl;
}

void Human::printChildren() const{
	std::cout << "children:";
	for (int i = 0; i < numberOfChildren; ++i)
	{
		if (children[i] != nullptr)
		{
			std::cout << children[i]->firstName << ",";
		}
		
	}
	std::cout << std::endl;
}




Human::Human(std::string firstName, std::string lastName, int hairColor,
	int eyeColor, int age, bool gender, int numberOfChildren){
	std::cout << "construct" << std::endl;
	std::transform(firstName.begin(), firstName.end(),firstName.begin(), ::toupper);
	std::transform(lastName.begin(), lastName.end(),lastName.begin(), ::toupper);
	this->firstName = firstName;
	this-> lastName = lastName;
	if (hairColor >=0 && hairColor <=10)
	{
		this->hairColor = hairColor;
	}
	else{
		this->hairColor = 0;
	}
	if (eyeColor >=0 && eyeColor <=10)
	{
		this->eyeColor = eyeColor;
	}
	else{
		this->eyeColor = 0;
	}
	this->age = age;
	this->gender = gender;
	this->numberOfChildren = numberOfChildren;
	children = new Human*[numberOfChildren];
	for (int i = 0; i < numberOfChildren; ++i)
	{
		children[i] = nullptr;
	}

}

Human::~Human(){
	std::cout << "destruct" << std::endl;
	delete[] children;
}


std::string Human::getFirstName(){
	return firstName;
}

std::string Human::getLastName(){
	return lastName;
}



bool Human::getGender(){
	return gender;
}
int Human::getEyeColor(){
	return eyeColor;
}
int Human::getHairColor(){
	return hairColor;
}

int Human::getAge(){
	return age; 
}

int Human::getNumberOfChildren(){
	return this->numberOfChildren;
}

bool Human::isChildOf(const Human* human){
	if ((this->father == human) || (this->mother == human))
	{
		return true;
	}
	return false;
}


bool Human::isMotherOf(Human* human){
	if (this == human->mother)
	{
		return true;
	}
	return false;
}


bool Human::isFatherOf(Human* human){
	if (this == human->father)
	{
		return true;
	}
	return false;
}


Human::Human(const Human& human){
	std::cout << "Copy constructor" << std::endl;
	firstName = human.firstName;
	lastName = human.lastName;
	hairColor = human.hairColor;
	eyeColor = human.eyeColor;
	gender = human.gender;
	age = human.age;
	numberOfChildren = human.numberOfChildren;
	father = human.father;
	mother = human.mother;
	spouse = human.spouse;
	children = new Human*[numberOfChildren];
	for (int i = 0; i < numberOfChildren; ++i)
	{
		children[i] = human.children[i];
	}
}


bool Human::operator>(const Human& human) const{
	return age > human.age;
}

bool Human::operator==(const Human& human) const {
	return firstName==human.firstName && lastName==human.lastName &&
	age==human.age && eyeColor==human.eyeColor && hairColor==human.hairColor &&
	gender==human.gender && numberOfChildren==human.numberOfChildren;
	// father==human.father && mother==human.mother && spouse==human.spouse &&
	// children==human.children;
}



Human* Human::operator+(Human& human){
	if (this->spouse == &human && human.spouse == this && this->gender!= human.gender)
	{
		srand((unsigned)time(0));
		int new_gender{};
		int new_eyeColor{},new_hairColor{};
		std::string new_firstName{};
		std::string new_lastName{};
		if (gender ==0)
		{
			new_lastName = lastName;
		}
		else{
			new_lastName = human.lastName;
		}
		
    	if (rand()%2 == 0)
    	{
    		new_gender = gender;
    		new_firstName = firstName;
    	}
    	else{
    		new_gender = human.gender;
    		new_firstName = human.firstName;	
    	}
    	if (rand()%2 == 0)
    	{
    		new_hairColor = hairColor;
    		new_eyeColor = eyeColor;
    	}
    	else{
    		new_hairColor = human.hairColor;
    		new_eyeColor = human.eyeColor;	
    	}
    	Human* h1{new Human(new_firstName, new_lastName, new_hairColor, new_eyeColor,0, new_gender,0)};
    	if (gender==0)
    	{
    		h1->father = this;
    		h1->mother = &human;
    	}
    	else{
    		h1->mother = this;
    		h1->father = &human;
    	}
    	Human** childs{new Human*[numberOfChildren]};
    	for (int i = 0; i < (this->numberOfChildren); ++i)
    	{
    		childs[i] = children[i];
    	}
    	delete[] children;
    	delete[] human.children;
    	children = new Human*[numberOfChildren+1];
    	human.children = new Human*[numberOfChildren+1];
    	for (int i = 0; i < numberOfChildren; ++i)
    	{
    		children[i] = childs[i];
    		human.children[i] = childs[i];
    	}
    	children[numberOfChildren] = h1;
    	human.children[numberOfChildren] = h1;
    	delete[] childs;
    	numberOfChildren+=1;
    	human.numberOfChildren+=1;


    	return h1;
	}
	return nullptr;

}

void Human::operator++(){
	age+=1;
}

