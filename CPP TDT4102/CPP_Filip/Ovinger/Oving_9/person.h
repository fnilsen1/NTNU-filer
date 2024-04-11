#pragma once
#include "std_lib_facilities.h"
#include "car.h"

class Person{
private:
string name;
string email;
unique_ptr<Car> carPtr;

public:
Person(string name, string email, unique_ptr<Car> carPtr = nullptr);
string getName() const;
string getEmail() const;
void setEmail(string newEmail);
bool hasAvailableSeats();
friend ostream& operator<<(ostream& os, const Person& p);


};

ostream& operator<<(ostream& os, const Person& p);