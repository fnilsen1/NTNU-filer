#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include "person.h"



class MeetingWindow : public AnimationWindow{
    
private:
static constexpr int inline btnW = 100;
static constexpr int inline pad = 4;
static constexpr int inline btnH = 20;
static constexpr int inline fieldW = 200;
static constexpr int inline fieldH = 20;
static constexpr int inline fieldPad = 80;
static constexpr int inline headerFontSize = 20;

Button quitBtn;
Button personNewBtn;
Button printBtn;
TextInput personName;
TextInput personEmail;
TextInput personSeats;
vector<shared_ptr<Person>> people;

public:
MeetingWindow(int x, int y, int w, int h, const string&title);
void cb_quit();
void newPerson();
void cb_new_person();
void cb_print();
void printPeople();
};

