#pragma once
#include <iostream>
#include <assert.h>  
using namespace std;

class Dummy { 
public:
    int *num; 
    Dummy() {
        num = new int{0}; 
    }
    
    Dummy(Dummy &dum);
    ~Dummy() { 
        delete num;
    } 
    Dummy& operator=(Dummy rhs);
};

void dummyTest();