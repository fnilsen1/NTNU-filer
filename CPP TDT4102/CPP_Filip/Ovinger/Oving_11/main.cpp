#include <iostream>
#include "optimizationTask.h"
#include "Stopwatch.h"
#include <array>
#include <memory>
#include "Template.h"
using namespace std;

//4a) Hva kreves av objektene for at denne funksjonen skal kunne brukes?
//Objektene må ha en operatoroverlastning. Man må overlaste sammenligningsoperatoren ">" for at det skal funke

constexpr int arraySize = 10000;

void timeOperation(void (*func)(), int iterations){
Stopwatch stopwatch;
stopwatch.start();
for(int i = 0; i<iterations; i++){
func();
}
cout <<"Det tok " << stopwatch.stop()/iterations << " sekunder" << endl;

};

void createUniquePtr(){
unique_ptr<int> ptr = make_unique<int>(10);
};

void createSharedPtr(){
shared_ptr<int> ptr = make_unique<int>(10);
};


void stackAllocation() {
    std::array<int, arraySize> arr1;
}

void heapAllocation(){
array<int, arraySize>* arr2 = new array<int, arraySize>;
delete arr2;
};

void testVector(){
vector<int> vec;
for(int i = 0; i<20; i++){
vec.push_back(i);    
cout << "Size: " << vec.size() << " Capacity: " << vec.capacity() << endl;
};

};

void reserveVector(){
vector<int> vec;
vec.reserve(20);
for(int i = 0; i<20; i++){
vec.push_back(i);    
cout << "Size: " << vec.size() << " Capacity: " << vec.capacity() << endl;
};

};

void resizeVector(){
vector<int> vec;
vec.resize(20);

for(int i = 0; i<20; i++){
vec.at(i)=i;    
cout << "Size: " << vec.size() << " Capacity: " << vec.capacity() << endl;
};

};

void millionVector(){

vector<int> vec;
for(int i = 0; i<1000000000; i++){
vec.push_back(1);
};

};

void optimizedMillionVector(){
Stopwatch stopwatch;

cout << "Med reserve" << endl;
stopwatch.start();
vector<int> vec;
vec.reserve(1000000000);
for(int i = 0; i<1000000000; i++){
vec.push_back(1);
};

cout << "Det tok " << stopwatch.stop() << " sekunder" << endl;

cout << "Med resize" << endl;
stopwatch.start();
vector<int> vec1;
vec1.resize(1000000000);
for(int i = 0; i<1000000000; i++){
vec1.at(i)=i;
};

cout << "Det tok " << stopwatch.stop() << " sekunder" << endl;
};



int main(){

int n = 10000;
cout << "Unique pointer" << endl;
timeOperation(createUniquePtr, n);

cout << "Shared pointer" << endl;
timeOperation(createSharedPtr, n);

cout << "Stack" << endl;
timeOperation(stackAllocation, n);

cout << "Heap" << endl;
timeOperation(heapAllocation, n);

//Den dobler kapasiteten når lengden overskrider kapasiteten til arrayet
testVector();

//Den setter capacity til 20 med en gang pga reserve(20)
reserveVector();

//resize setter size og capacity til 20    
resizeVector();

//30.7462 sekunder
// cout << "Legge til 1 million elementer i vektor" << endl;
// timeOperation(millionVector, 1);

//17 sekunder med reserve og 19 med resize
cout << "1 millioner elementer optimalisert med reserve og resize" << endl;
optimizedMillionVector();

//12.8104 vs 6.53327 sekunder før og etter optimalisering
timeOperation(optimizationTask, 1);

int a = 1;
int b = 2;
int c = maximum<int>(a, b);
// c er nå 2.
// cout << c << endl;

double d = 2.4;
double e = 3.2;
double f = maximum(d,e);
cout << f << endl;
// f er nå 3.2

std::vector<int> g{1, 2, 3, 4, 5, 6, 7};
shuffle(g); // Resultat, rekkefølgen i a er endret.

std::vector<double> h{1.2, 2.2, 3.2, 4.2};
shuffle(h); // Resultat, rekkefølgen i b er endret.

std::vector<std::string> i{"one", "two", "three", "four"};
shuffle(i); // Resultat, rekkefølgen i c er endret.

MyArray<string, 5> intArray;
intArray.fill("Hei");
for(int i = 0; i<intArray.getSize(); i++){
cout << intArray.at(i) << endl;
}


MyArray<int, 10> intArray1;
intArray1.fill(13);

try{
intArray1.at(10) = 5; // Dette vil kaste et unntak
}

catch (const std::out_of_range& e) {
    std::cout << "Unntak: " << e.what() << std::endl;
}


return 0;
};