#pragma once
#include "std_lib_facilities.h"


//1.a
//public: alle kan bruke medlemsfunksjoner og medlemsvariabler
//private: kun den klassen som kan bruke medlemsfunksjoner og medlemsvariabler
//protected: child-klasser kan også bruke disse medlemsfunksjonene og medlemsvariablene

//Hva skjer hvis du fjerner virtual foran toString() i Animal-klassen?
//Error

//Gjør Animal-klassen abstrakt. Hva skjer hvis du prøver å lage et Animal objekt nå?
//Kan ikke lage instans av Animal

class Animal
{
protected:
    string name;
    int age;

public:
    Animal(string name, int age);

    virtual ~Animal() {};
    virtual string toString() = 0;
};

class Cat : public Animal
{
public:
    Cat(string name, int age);
    string toString() override;
};

class Dog : public Animal
{
public:
    Dog(string name, int age);
    string toString() override;
};

void testAnimal();