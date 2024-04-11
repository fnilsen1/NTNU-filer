#include "std_lib_facilities.h"
#include "filbehandling.h"
#include "emnekatalog.h"
#include "config.h"
#include "bouncingBall.h"

/*2a)
Feilen var at map capitalsMap er definert som konstant, derfor kan ikke [] operatoren brukes ettersom den kan legge til
/* nye land dersom de ikke eksisterer. Det bryter med const definisjonen.

/* Oppgave 3d)
Hvis man alt har brukt keyen (insert) skjer det ingenting. Bruker man []-operatoren endres den.
*/

const map<string, string> capitalsMap {
{"Norway", "Oslo"},
{"Sweden", "Stockholm"},
{"Denmark", "Copenhagen"}
};

string getCapital(const string& country) {
return capitalsMap.at(country);
}



int main() {

// writeToFile();
// makeNewFile();

// cout << "Capitals:" << endl;
// for (pair<const string, const string> elem : capitalsMap) {
// cout << getCapital(elem.first) << endl;
// }

// testFunction();


bouncingBall();



return 0;
}

