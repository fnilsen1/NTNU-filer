#include "std_lib_facilities.h"
#include "car.h"
#include "person.h"
#include "meeting.h"
#include "meetingwindow.h"

//2d Med const referanse, så unngår vi å kopiere + forhindrer endring av objektet.
//Vi kan ikke bruke const-parameter når vi skal endre objektet.

//3e Smartpekere kaller destruktørene automatisk


int main() {
    unique_ptr<Car> car1 = make_unique<Car>(4);
    
    shared_ptr<Person> person1 = make_shared<Person>("Nome", "nome@gmail.com");
    shared_ptr<Person> person2 = make_shared<Person>("Morten", "morten@gmail.com", std::move(car1));
    // cout << person2 << endl;
    // cout << person2.hasAvailableSeats() << endl;

    
    Meeting meeting{5, 14, 16, Campus::Trondheim, "Skole", person1};
    cout << meeting << endl;

    MeetingWindow meetingwindow{100,100,1000,700,"Meeting Window"};
    meetingwindow.wait_for_close();

    return 0;
}

