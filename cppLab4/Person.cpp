#include "Person.h"

#include "Person.h"
#include <string>

Person::Person()
{
}

Person::Person(const std::string Fullname, const std::string Adress)
	: fullname(Fullname), adress(Adress){
}

bool Person::operator<(const Person& that) {      // används för att sortera baklänges på adress
	return this->adress > that.adress;
}

//bool Person::operator<(const Person& that) {   // används för att sortera baserat på namn 
//	return this->fullname < that.fullname;
//}

void Person::Print()
{
	std::cout << "Name: " << getName() << " Address: " << getAddress() << std::endl;
}

Person::~Person()
{
}

const std::string Person::getName()
{
	return fullname;
}

const std::string Person::getAddress()
{
	return adress;
}

const std::string Person::getAllInfo()
{
	return fullname + adress;
}


