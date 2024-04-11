#include "std_lib_facilities.h"
#include "person.h"
#include "car.h"

Person::Person(string name, string email, unique_ptr<Car> carPtr)
    : name{name}, email{email}, carPtr{move(carPtr)} {}

string Person::getName() const{
    return name;
};

string Person::getEmail() const{
    return email;
};

void Person::setEmail(string newEmail) {
    email = newEmail;
}

bool Person::hasAvailableSeats(){
    if (carPtr!=nullptr && carPtr->hasFreeSeats())
    {
       return true;
    }

    else{
        return false;
    }
    
};

ostream& operator<<(ostream& os, const Person& p){
    os << "Navn: " << p.getName() << " Mail: " << p.getEmail() << endl;
    return os;
}

