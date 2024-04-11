#include "meeting.h"
#include "std_lib_facilities.h"

ostream& operator<<(ostream& os, const Campus& campus){
switch(campus){
case Campus::Trondheim:
    os << "Trondheim";
    break;

case Campus::Gjovik:
    os << "Gjovik";
    break;

case Campus::Alesund:
    os << "Alesund";
    break;

};
return os;
};

ostream& operator<<(ostream& os, Meeting& meeting){
os << "Subject: " << meeting.getSubject() << endl;
os << "Location: " << meeting.getLocation() << endl;
os << "Start time: "<<meeting.getStartTime() << endl;
os << "End Time: " << meeting.getEndTime() << endl;
os << "Leader: " << meeting.getLeader()->getName() << endl;
os << "Participants:" << endl;
for(auto navn : meeting.getParticipantList()){
os << navn << endl;
};

return os;
};

void Meeting::addParticipant(shared_ptr<Person> person){
    participants.push_back(person);
}

vector<string> Meeting::getParticipantList(){
    vector<string> participantList;
    for(auto element : participants){
        participantList.push_back(element->getName());
    }
    return participantList;
}

vector<shared_ptr<Person>> Meeting::findPotentialCoDriving(Meeting anotherMeeting){
vector<shared_ptr<Person>> newList;   

for(auto element : anotherMeeting.participants){
if (location == anotherMeeting.getLocation() && day == anotherMeeting.getDay() && 
abs(startTime - anotherMeeting.getStartTime()) <= 1 && abs(endTime - anotherMeeting.getEndTime()) <= 1) {
newList.push_back(element);
}

};
return newList;
};

