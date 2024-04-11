#pragma once
#include "std_lib_facilities.h"
#include "Graph.h"
using namespace Graph_lib;

class Animal {
protected:
    std::string name;
    int age;

public:
    Animal(std::string name, int age);
    virtual ~Animal();
    virtual std::string toString() const;
};

class Cat : public Animal {
public:
    Cat(std::string name, int age);
    std::string toString() const override;
};

class Dog : public Animal {
public:
    Dog(std::string name, int age);
    std::string toString() const override;
};

void testAnimal();

#endif
