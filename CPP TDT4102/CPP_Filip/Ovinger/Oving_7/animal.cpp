#include "std_lib_facilities.h"
#include "animal.h"


Animal::Animal(string name, int age): name{name}, age{age} {};

string Animal::toString(){
    return "Animal: " + name + ", " + to_string(age) + "\n";
}

Cat::Cat(string name, int age) : Animal{name, age} {};

string Cat::toString(){
    return "Cat: " + name + ", " + to_string(age) + "\n";
}

Dog::Dog(string name, int age) : Animal{name, age} {};

string Dog::toString(){
    return "Dog: " + name + ", " + to_string(age) + "\n";
}

void testAnimal() {


    vector<unique_ptr<Animal>> v;
    v.emplace_back(new Cat{"A", 8}); 
    v.emplace_back(new Dog{"B", 8});
    v.emplace_back(new Dog{"C", 8});
    v.emplace_back(new Cat{"D", 8});

    for(const auto& animal : v) {
        cout << animal->toString();
    } 
}