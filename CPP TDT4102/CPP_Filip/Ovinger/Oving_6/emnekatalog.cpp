#include "std_lib_facilities.h"
#include "emnekatalog.h"


//konstruktør youtube
void CourseCatalog::addCourse(string emnekode, string emnenavn){
// emnemapping.insert({emnekode, emnenavn});
emnemapping[emnekode] = emnenavn;

};

void CourseCatalog::removeCourse(string emnekode){
emnemapping.erase(emnekode);

};


string CourseCatalog::getCourse(string emnekode){
return emnemapping.at(emnekode);

};

ostream& operator<<(ostream& os, const CourseCatalog& c){
for(auto c : c.emnemapping){
    os << c.first <<": "  << c.second << endl;
};
return os;
};

void testFunction(){
CourseCatalog katalog;
katalog.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
katalog.addCourse("TDT4102",  "Prosedyre- og objektorientert programmering");
katalog.addCourse("TDT4102",  "C++");
katalog.addCourse("TMA4100",  "Matematikk 1");

// cout << katalog;
katalog.saveFile();
katalog.readFile();



};

void CourseCatalog::readFile(){
    ifstream inputStream{"oppg3f.txt"};

    if (!inputStream) { 
    cout << "Kunne ikke åpne filen" << endl;
    return;
    //alternativt error("Kunne ikke åpne filen")
    }

    string line;
    while(getline(inputStream, line)){
        cout << line << endl;
    }
}

void CourseCatalog::saveFile(){
    filesystem::path fileName{"oppg3f.txt"};
    ofstream outputStream{fileName};
        
    for(auto c : emnemapping){
         outputStream << c.first << ": " << c.second << endl;
    };


};
