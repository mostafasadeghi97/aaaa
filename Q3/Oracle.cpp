#include"Oracle.h"
#include<iostream>
#include"Human.h"



Oracle::Oracle(std::string Name){
	this->Name = Name;
}


bool Oracle::marry(Human* human1, Human* human2){
	if (human1->spouse != human2 && human1->getAge() >=18 && 
		human2->getAge() >=18 && human1->getGender() != human2->getGender())
	{
		human1->spouse = human2;
		human2->spouse = human1;
		return true;
	}
	return false;
}

