#pragma once
#include "std_lib_facilities.h"


class Car{
private:
int freeSeats;

public:
bool hasFreeSeats() const;
void reserveFreeSeat();

Car(int f): freeSeats{f}{}
};

