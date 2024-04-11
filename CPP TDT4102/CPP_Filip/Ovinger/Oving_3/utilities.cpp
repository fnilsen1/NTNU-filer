#include "std_lib_facilities.h"
#include "utilities.h"

int randomWithLimits(int min, int max){
random_device rd;
default_random_engine generator(rd());
uniform_int_distribution<int> distribution(min,max);

int number = distribution(generator);
return number;


}