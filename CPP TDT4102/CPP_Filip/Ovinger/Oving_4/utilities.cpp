#include "std_lib_facilities.h"
#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
for (int i = 0; i < numTimes; i++) {
startValue += increment;
}
return startValue;
}

int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes) {
for (int i = 0; i < numTimes; i++) {
startValue += increment;
}
return startValue;
}

//Bør bruke referanser fordi vi skal endre på variabler utenfor funksjonen. 
void swapNumbers(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void printStudent(Student a){
    cout << "Name: " << a.name << endl;
    cout << "Studyprogram: " << a.studyProgram << endl;
    cout << "Age: " << a.age << endl;

}

bool isInProgram(Student a, string program){
    if(a.studyProgram == program){
        return true;
    };
    return false;
}

string randomizeString(int antall_tegn, int start, int slutt){
  
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(start, slutt);
    
    string random_string = "";
    char a = distribution(generator);
    for(int i = 0; i<antall_tegn; i++){
        a = distribution(generator);
        random_string+=a;
    }
    return random_string;

}

//legg til
string readInputToString(int n, char lower_bound, char upper_bound) {
    int lower = int(lower_bound);
    int upper = int(upper_bound);
    string to_return;
    char newchar = char(upper+1);
    while(to_return.length() < n) {
        cout << "Skriv inn char mellom " << lower_bound << " og " << upper_bound << ": ";
        cin >> newchar;
        newchar = toupper(newchar);
        int checker = int(newchar);
        if(checker<lower) {
            cout << newchar << "er under grensen, prov igjen.\n";
        } else if (checker>upper) {
            cout << newchar << " er over grensen, prov igjen.\n";
        } else {
            to_return.push_back(newchar);
        }
        
    }
    return to_return;
}

int countChar(string toCheck, char toCount) {
    int counter = 0;
    for(int i = 0; i < toCheck.length(); i++) {
        if(toCheck[i]==toCount) {
            counter += 1;
        }
    }
    return counter;
}