#pragma once
#include "std_lib_facilities.h"
#include "person.h"

enum class Campus{
Trondheim = 0, Alesund = 1, Gjovik = 2
};

class Meeting{
private:
int day;
int startTime;
int endTime;
Campus location;
string subject;
const shared_ptr<Person> leader;
vector<shared_ptr<Person>> participants;

public:
int getDay(){return day;}
int getStartTime(){return startTime;}
int getEndTime(){return endTime;}
Campus getLocation(){return location;}
string getSubject(){return subject;}
shared_ptr<Person> getLeader(){return leader;}

Meeting(int day, int startTime, int endTime, Campus location, string subject, shared_ptr<Person> leader):
    day{day},
    startTime{startTime},
    endTime{endTime},
    location{location},
    subject{subject},
    leader{leader}
{
addParticipant(leader);
};

void addParticipant(shared_ptr<Person> person);
vector<string> getParticipantList();

vector<shared_ptr<Person>> findPotentialCoDriving(Meeting anotherMeeting);


};
ostream& operator<<(ostream& os, const Campus& campus);
ostream& operator<<(ostream& os, Meeting& meeting);