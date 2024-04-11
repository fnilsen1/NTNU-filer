#include <iostream>
#include "fibonacci.h"
#include "matrix.h"
#include "dummy.h"

using namespace std;


int main(){
    createFibonacci();

	Matrix A{2};
	Matrix B{2};
	Matrix C{2};

	A.set(0,0,1.0);
	A.set(1,0,3.0);
	A.set(0,1,2.0);
	A.set(1,1,4.0);

	B.set(0,0,4.0);
	B.set(1,0,2.0);
	B.set(0,1,3.0);
	B.set(1,1,1.0);

	C.set(0,0,1.0);
	C.set(1,0,1.5);
	C.set(0,1,3.0);
	C.set(1,1,2.0);

	A += (B + C);
	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
    // dummyTest();

    return 0;
}
