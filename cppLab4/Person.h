#pragma once
#include <string>
#include <iostream>
class Person
{
    std::string fullname;
    std::string adress;

public:
    bool operator<(const Person& that);
    Person();
    Person(const std::string Fullname, const std::string Adress);
    virtual void Print();
    virtual ~Person();

    const std::string getName();
    const std::string getAddress();
    const std::string getAllInfo();
};



