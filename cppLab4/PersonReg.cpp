#include "PersonReg.h"

PersonReg::PersonReg(const int maxStorlek) : maxStorlek(maxStorlek)
{
	personer = new Person[maxStorlek];

}

Person* PersonReg::begin() { return personer; }

Person* PersonReg::end() { return personer + antalpersoner; }

Person* PersonReg::FreeSearch(const std::string& sökEfter, Person* startOnNext) const
{
	Person* tPers;
	if (startOnNext == nullptr) {
		tPers = personer;
	}
	else {
		tPers = startOnNext;
	}

	for (Person* ptr = tPers; ptr != &personer[antalpersoner]; ptr++)
	{
		if (ptr->getAllInfo().find(sökEfter) != std::string::npos && ptr != startOnNext)
		{
			return ptr;
		}
	}
	std::cout << "Not found in register" << std::endl;
	return nullptr;

}



bool PersonReg::ReadReg(PersonReg& reg, std::string fileName)
{
	std::string line;
	std::ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			while (line.length() == 0 && getline(myfile, line));
			std::string name(line);
			std::string adress;
			getline(myfile, adress);
			Person p = Person(name, adress);
			reg.AddPerson(&p);
		}
		myfile.close();
		return true;
	}
	else {
		std::cout << "Unable to open file";
		return false;
	}
}

bool PersonReg::AddPerson(const Person* const person)
{
	if (antalpersoner < maxStorlek) {
		personer[antalpersoner] = *person;
		antalpersoner++;
		return true;
	}
	else {
		std::cout << "Register full. Can't add person." << std::endl;
		return false;
	}
}

bool PersonReg::AddPersonTest(const std::string& namn, const std::string& adress)
{
	if (antalpersoner < maxStorlek) {
		personer[antalpersoner] = Person(namn, adress);
		antalpersoner++;
		return true;
	}
	else {
		std::cout << "Fullt register. Kan inte lägga till." << std::endl;
		return false;
	}
}

void PersonReg::RemovePerson(Person* ptr)
{
	size_t indexToRemove = ptr - personer;
	std::swap(personer[indexToRemove], personer[antalpersoner - 1]);
	antalpersoner--;
}

Person* PersonReg::SearchName(const std::string& namn) const
{
	for (Person* ptr = personer; ptr != &personer[antalpersoner]; ptr++)
	{
		if (ptr->getName() == namn)
		{
			return ptr;
		}
	}
	return nullptr;
}

void PersonReg::Print()
{
	for (Person* ptr = personer; ptr != &personer[antalpersoner]; ptr++) {
		ptr->Print();
	}
	std::cout << "\n";
}

void PersonReg::Empty()
{
	antalpersoner = 0;
}

PersonReg::~PersonReg()
{
	delete[] personer;
}
