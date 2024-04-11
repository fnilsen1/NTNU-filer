#pragma once

class CourseCatalog{
    map<string, string> emnemapping;

public:
// CourseCatalog();
void addCourse(string emnekode, string emnenavn);
void removeCourse(string emnekode);
string getCourse(string emnekode);
friend ostream& operator<<(ostream& os, const CourseCatalog& c);
void readFile();
void saveFile();

};

void testFunction();