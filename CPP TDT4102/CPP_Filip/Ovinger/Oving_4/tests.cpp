#pragma once
#include "std_lib_facilities.h"
#include "utilities.h"
#include "tests.h"

void testCallByValue() {
int v0 = 5;
int increment = 2;
int iterations = 10;
int result = incrementByValueNumTimes(v0, increment, iterations);
cout << "v0: " << v0
<< " increment: " << increment
<< " iterations: " << iterations
<< " result: " << result << endl;
}

void testCallByReference() {
int v0 = 5;
int increment = 3;
int iterations = 10;
int result = incrementByValueNumTimesRef(v0, increment, iterations);
cout << "v0: " << v0
<< " increment: " << increment
<< " iterations: " << iterations
<< " result: " << result << endl;
}


void testString() {
    string grades = randomizeString(8, 'A', 'F');
    cout << "Karakterlista di: " << grades << '\n';
    vector<int> gradevector;
    for(int i = 0; i < 6; i++) {
        gradevector.push_back(countChar(grades, char(int('A')+i)));
    }
    int sum = 0;
    for(int j = 0; j < 6; j++) {
        sum += (5-j)*gradevector[j];
    }
    double snittkarakter = sum/static_cast<double>(grades.length());
    cout << "Snittkarakteren blir da: " << snittkarakter << endl;
}