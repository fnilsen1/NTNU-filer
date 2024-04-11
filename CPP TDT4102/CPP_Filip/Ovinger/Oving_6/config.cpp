#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "config.h"



istream& operator>>(istream& is, Config& cfg){

is >> cfg.colorUp;
is >> cfg.colorDown;
is >> cfg.velocity;
return is;
}

