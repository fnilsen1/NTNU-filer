#pragma once
#include <fstream>

class Config{


public:
int colorUp;
int colorDown;
int velocity;
friend istream& operator>>(istream& is, Config& cfg);
};

