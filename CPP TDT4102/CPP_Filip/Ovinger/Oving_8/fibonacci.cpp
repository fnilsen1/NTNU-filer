# include <iostream>
#include "fibonacci.h"
using namespace std;

void fillInFibonacciNumbers(int* result, int length) {
    int a = 0;
    int b = 1;
    int c = 0;
    for (int i=0; i < (length); i++) {
        result[i] = a;
        c = a + b;
        a = b;
        b = c; 
    }
}

void printArray(int* arr, int length) {
    cout << "Her er Fibonaccitallene:\n";
    for (int i = 0; i < (length); i++) {
        cout << arr[i] << '\n';
    }
}

void createFibonacci(){
    int length = 0;
    cout << "Hvor mange tall fra Fibonccifolgen ønsker du? "<<endl;
    cin >> length;
    int* array = new int[length];
    fillInFibonacciNumbers(array,length);
    printArray(array,length);
    delete[] array;
}  