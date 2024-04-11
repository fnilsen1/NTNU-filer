#include "std_lib_facilities.h"
#include "Animal.h"
#include "Graph.h"
using namespace Graph_lib;

Animal::Animal(std::string name, int age) : name(name), age(age) {}

Animal::~Animal() {}

std::string Animal::toString() const {
    return "Animal: " + name + ", " + std::to_string(age);
}

Cat::Cat(std::string name, int age) : Animal(name, age) {}

std::string Cat::toString() const {
    return "Cat: " + name + ", " + std::to_string(age);
}

Dog::Dog(std::string name, int age) : Animal(name, age) {}

std::string Dog::toString() const {
    return "Dog: " + name + ", " + std::to_string(age);
}

// Implementasjon av testAnimal funksjonen
void testAnimal() {
    std::vector<std::unique_ptr<Animal>> animals;

    animals.emplace_back(new Cat("Pus", 3));
    animals.emplace_back(new Dog("Buddy", 5));
    animals.emplace_back(new Cat("Whiskers", 2));

    for (const auto& animal : animals) {
        std::cout << animal->toString() << std::endl;
    }
}
