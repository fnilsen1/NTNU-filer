#include <iostream>
#include "optimizationTask.h"
#include "Stopwatch.h"
#include <array>
#include <memory>

using namespace std;

int main()
{
Stopwatch s;
s.start();
optimizationTask();
cout << s.stop();
int a;
cin >> a;
return 0;
};

