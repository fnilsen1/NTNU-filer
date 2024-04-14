#pragma once
#include <algorithm>
#include <random>
#include <vector>

template<typename T>
T maximum(T a, T b){
return std::max(a,b);
}

template<typename T>
void shuffle(std::vector<T>& vec){
std::random_device rd;
std::default_random_engine generator(rd());
std::uniform_int_distribution<int> distribution(0, vec.size()-1);


for(int i = 0; i<1000; i++){
int a = distribution(generator);
int b = distribution(generator);

if(a != b){
std::swap(vec.at(a), vec.at(b));
}

}


};

template<typename Type, int Size>
class MyArray{
Type* elements = new Type[Size];

public:

int getSize(){
return Size;

};

Type& at(int indeks){

if (indeks < 0 || indeks >= Size) {
    throw std::out_of_range("Indeks ikke i array");
}
return elements[indeks];


}
//Må deklareres
void fill(Type verdi);
};

//Man kan definere funksjoner utenfor klassen
template<typename Type, int Size>
void MyArray<Type, Size>::fill(Type verdi){
for(int i = 0; i<Size; i++){
at(i)=verdi;
}

}