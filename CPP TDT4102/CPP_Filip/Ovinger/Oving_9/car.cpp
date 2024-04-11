#include "car.h"
#include "std_lib_facilities.h"

bool Car::hasFreeSeats() const{
if(freeSeats>0){
return true;
}

else{
return false;
};

};

void Car::reserveFreeSeat(){
freeSeats--;
};
