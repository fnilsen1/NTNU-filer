#include "cannonball.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "cannonball_viz.h"
#include <math.h>

double acclY(){
    return -9.81;
}

double velY(double initVelocityY, double time){
    double velY = initVelocityY + acclY()*time;
    return velY;
}

double posX(double initPositionX, double initVelocityX, double time){
    double posX = initPositionX + initVelocityX*time;
    return posX;
}

double posY(double initPositionY, double initVelocityY, double time){
    double posY = initPositionY + initVelocityY*time + acclY()*pow(time, 2)/2;
    return posY;
}

void printTime(double time){
    int timer = 0;
    int minutter = 0;

        timer = static_cast<int>(time/3600);
        time-=3600*timer;

        minutter = static_cast<int>(time/60);
        time-=60*minutter;

        cout << timer << " timer " << minutter << " minutter " << time << " sekunder" << endl;

}

double flightTime(double initVelocityY){
    double time = -2*initVelocityY/acclY();
    return time;
}

// Ber brukeren om en vinkel i grader
double getUserInputTheta(){
    double theta;
    cout << "Skriv inn vinkel: ";
    cin >> theta;
    return theta;
}

//Ber brukeren om en startfart
double getUserInputInitVelocity(){
    double startfart;
    cout << "Skriv inn startfart: ";
    cin >> startfart;
    return startfart;
}


// Konverterer fra grader til radianer
double degToRad(double deg){
    return M_PI/180*deg;
}



// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta i grader og en startfart initVelocity.
double getVelocityX(double theta, double initVelocity){
    double velocityX = initVelocity*cos(theta);
    return velocityX;
}
    
double getVelocityY(double theta, double initVelocity){
    double velocityY = initVelocity*sin(theta);
    return velocityY;
}

// Dekomponerer farten gitt av initVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double initVelocity){
    vector<double> velocities = {getVelocityX(theta, initVelocity), getVelocityY(theta, initVelocity)};
    return velocities;
}

double getDistanceTraveled(double velocityX, double velocityY){
    double time = flightTime(velocityY);
    return posX(0, velocityX, time);

}
double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    return distanceToTarget-getDistanceTraveled(velocityX, velocityY);
}

void playTargetPractice(){
    int goal = randomWithLimits(100,1000);
    for (int i = 0; i<10; i++){
        double vinkel = getUserInputTheta();
        double startfart = getUserInputInitVelocity();
        cannonBallViz(goal, 1000, getVelocityX(vinkel, startfart), getVelocityY(vinkel, startfart), 20);
        cout << "Du var " << targetPractice(goal, getVelocityX(vinkel, startfart), getVelocityY(vinkel, startfart)) << " meter unna" << endl;

        printTime(flightTime(getVelocityY(vinkel, startfart)));
        if(abs(targetPractice(goal, getVelocityX(vinkel, startfart), getVelocityY(vinkel, startfart))) < 5){
            cout << "Gratulerer du vant";
            break;
        }
        else{
            cout << "Prov igjen" << endl;
        }

}


}