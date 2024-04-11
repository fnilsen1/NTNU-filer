#include "meetingwindow.h"
#include "std_lib_facilities.h"

void MeetingWindow::cb_quit(){
    this->close();
};  

void MeetingWindow::cb_new_person(){
    this->newPerson();
};

void MeetingWindow::cb_print(){
this->printPeople();
};

void MeetingWindow::printPeople(){
cout << "Personer:" << endl;
for(auto element : people){
cout << element->getName() << endl;
};

};


MeetingWindow::MeetingWindow(int x, int y, int w, int h, const string&title)
:AnimationWindow(x,y,w,h,title),
quitBtn({900,20}, 100, 30, "Quit"),
printBtn({100,300}, 200, 30, "Print people"),
personNewBtn({100,250}, 200, 30, "New Person"),
personName({100, 100}, 200, 30, "Name"),
personEmail({100, 150}, 200, 30, "Email"),
personSeats({100, 200}, 200, 30, "Seats"){

add(quitBtn);
add(printBtn);
add(personName);
add(personEmail);
add(personSeats);
add(personNewBtn);

quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
personNewBtn.setCallback(std::bind(&MeetingWindow::cb_new_person, this));
printBtn.setCallback(std::bind(&MeetingWindow::cb_print, this));
}

void MeetingWindow::newPerson(){
string name = personName.getText();
string email = personEmail.getText();
int seats = stoi(personSeats.getText());
if(seats>0){
unique_ptr<Car> car = make_unique<Car>(seats);
car->reserveFreeSeat();
people.emplace_back(new Person(name, email, move(car)));
}

else{
shared_ptr<Person> person = make_shared<Person>(name, email);
};

personName.setText("");
personEmail.setText("");
personSeats.setText("");

};