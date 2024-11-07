//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
using namespace std;


bool primeChecker(int n){
for(int i = 2; i<n; i++){

if(n%i==0){
cout << n << " er ikke et primtall" << endl;
return 0;
}

}
cout << n << " er et primtall" << endl;
return 1;

};

int main() {
int c = 3;
c++;
cout << c << endl;
cout << c << endl;

return 0;
}
