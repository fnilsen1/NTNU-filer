#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
void testDeviation(double compareOperand, double toOperand, double maxError, string name);


int main() {
    // double maxError = 0.1;
    // testDeviation(posX(0.0,50.0,5.0), 250.0, maxError, "posX(0.0,50.0,5.0)");
    // int test = 1341;
    // double theta = degToRad(getUserInputTheta());
    // double velocity = getUserInputInitVelocity();
    // vector<double> vektor = getVelocityVector(theta, velocity);
    // double distance = getDistanceTraveled(vektor.at(0), vektor.at(1));
    // cout << targetPractice(21, vektor.at(0), vektor.at(1));
    // return 0;
playTargetPractice();

return 0;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    if(abs(compareOperand-toOperand) <= maxError){
        cout << name << " is valid" << endl;
    }

    else{
        cout << name << " is not valid." << " Expected " << toOperand << " got " << compareOperand << endl;
    }
}

