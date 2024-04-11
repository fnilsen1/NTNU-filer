#include "std_lib_facilities.h"
#include "filbehandling.h"
#include <fstream>
#include <map>

void writeToFile(){
    filesystem::path fileName{"oppg1.txt"};
    ofstream outputStream{fileName};

    while(true){
        cout << "Skriv et ord: ";
        string userInput; 
        cin >> userInput;

    if(userInput == "quit"){
        break;
    };

    outputStream << userInput << endl;

    }

}

void makeNewFile(){
    ifstream inputStream{"oppg1b.txt"};

    if (!inputStream) { 
    cout << "Kunne ikke åpne filen" << endl;
    return;
    //alternativt error("Kunne ikke åpne filen")
    }

    filesystem::path fileName{"new_oppg1b.txt"};
    ofstream outputStream{fileName};

    int counter = 1;
    string line;
    while(getline(inputStream, line)){

        outputStream << counter << ". " << line << endl;
        counter++;
    }



}