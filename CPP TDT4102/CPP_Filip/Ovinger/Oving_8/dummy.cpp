#include "dummy.h"

Dummy::Dummy(Dummy &dum) {
    num = new int{*dum.num};
}

Dummy& Dummy::operator=(Dummy rhs){
    swap(num,rhs.num);
    return *this;
}


void dummyTest() {
    Dummy a;
        *a.num = 4;
        //kaller kopikonstruktør
        Dummy b{a};
        Dummy c;
        c = a;
        cout << "a: " << *a.num << '\n';
        cout << "b: " << *b.num << '\n';
        cout << "c: " << *c.num << '\n';
        *b.num = 3;
        *c.num = 5;
        cout << "a: " << *a.num << '\n';
        cout << "b: " << *b.num << '\n';
        cout << "c: " << *c.num << '\n';
}

// 3 a) Forventer:
// 4
// 4 - b opprettes som/lik a
// 4 - c blir satt lik a
// 5 - Alle *x.num er pekere på den samme variabelen, den endres til 5 av "*c.num = 5".
// 5
// 5

// 3 b) Får:
//4 4 4 5 5 5 