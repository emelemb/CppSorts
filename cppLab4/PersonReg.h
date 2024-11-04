#pragma once
#include <fstream>
#include "Person.h"
class PersonReg
{
	Person* personer;
	int antalpersoner{};
	const int maxStorlek{};

public:

	Person* begin();
	Person* end();

	PersonReg(int maxStorlek);

	Person* FreeSearch(const std::string& sökEfter, Person* startOnNext) const;

	bool ReadReg(PersonReg& reg, std::string fileName);

	bool AddPerson(const Person* const);

	bool AddPersonTest(const std::string& namn, const std::string& adress);

	void RemovePerson(Person* ptr);

	Person* SearchName(const std::string& namn) const;

	void Print();

	void Empty();

	~PersonReg();
};