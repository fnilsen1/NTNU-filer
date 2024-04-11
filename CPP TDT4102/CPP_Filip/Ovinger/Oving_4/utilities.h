#pragma once

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
int incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);
void swapNumbers(int& a, int& b);

struct Student{
string name;
string studyProgram;
int age;
};

void printStudent(Student a);
bool isInProgram(Student a, string program);
string randomizeString(int antall_tegn, int start, int slutt);
string readInputToString(int n, char lower_bound, char upper_bound);
int countChar(string toCheck, char toCount);
