#include "std_lib_facilities.h"
#include <cmath>
#include "AnimationWindow.h"
#include "iostream"

void menu();
void inputAndPrintInteger();
int inputInteger();
void inputIntegersAndPrintSum();
bool isOdd(int number);
void loopSum();
void readInteger();
double inputDouble();
void convert();

double discriminant(double a, double b, double c);
void printRealRoots(double a, double b, double c);
void solveQuadraticEquation();
vector<int> calculateBalance(int innskudd, int rente, int aar);
void printBalance(vector<int> intVector);

//1a
void menu() {

	while (1) {
		cout << "Menu\n"
			<< "0.\tquit\n"
			<< "1.\tinputAndPrintInteger\n"
			<< "2.\tinputInteget\n"
			<< "3.\tinputIntegersAndPrintSum\n"
            << "4.\tisOdd\n"
            << "5.\tsolveQuadraticEquation\n"
			<< "Input: ";

		int menu_choice;
		cin >> menu_choice;
		
		switch (menu_choice)
		{
		case 1:
            inputAndPrintInteger();
			break;

		case 2:{
            int number = inputInteger();
            cout << "Du skrev " << number << endl;
			break;
            }

		case 3:
			inputIntegersAndPrintSum();
			break;

		case 4:
			for(int i = 0; i<16; i++){
                cout << isOdd(i) << endl;
            }
			break;
		
        case 5:
			solveQuadraticEquation();
			break;

		default:
			return; // quit program
			break;
		}
	}
}


//1b
void inputAndPrintInteger(){
    cout << "Skriv inn et tall: ";
    int input;
    cin >> input;
    cout << "Du skrev: " << input;
    
}

//1c
int inputInteger(){
    cout << "Skriv inn et tall: ";
    int input;
    cin >> input;
    return input;
}

//1d
void inputIntegersAndPrintSum(){
    int a = inputInteger();
    int b = inputInteger();
    cout << "Summen av tallene: " << a+b << endl;

}

//1e: Jeg brukte inputInteger() fordi man lagrer returverdien og kan bruke den videre. Den printer også ingenting når man kaller på den.

//1f
bool isOdd(int number){
    if(number % 2 == 1){
        return true;
    }
    else{
        return false;
    }
}

//2a
void loopSum(){
    cout << "Hvor mange tall vil du summere: ";
    int amount;
    cin >> amount;

    int sum = 0;
    int input;
    for(int i = 0; i < amount; i++){
        cout << "Skriv inn et tall: ";
        cin >> input;
        sum+=input;
    }
    cout << sum << endl;

}

//2b
void readInteger(){
int input;
int sum = 0;
while(true){
    cout << "Skriv inn et tall: ";
    cin >> input;
    sum+=input;
    if(input == 0){
        break;
    }

}
cout << sum << endl;

}


//2c: for loop i oppgave a fordi vi vet antall iterasjoner. While i b fordi vi ikke vet antall iterasjoner.

//2d
double inputDouble(){
    double desimaltall;
    cout << "Skriv inn et desimaltall: ";
    cin >> desimaltall;
    return desimaltall;
}

//2e
void convert(){
double input;
while(true){
    input = inputDouble();
    if(input > 0){
        break;
    }
}
cout << "Det er " << fixed << setprecision(2) << input/9.75 << " Euro" << endl;

}

//2f: Vi må ha double siden man kan ha f.eks 25,4kr    

//2g
void gangetabell(){
    int height;
    int width;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width; 

    for(int i = 1; i < height+1; i++){
        for(int j = 1; j < width+1; j++){
            cout << setw(4) << i*j;
        }
        cout << endl;
    }

}

//3a
double discriminant(double a, double b, double c){
    return pow(b,2)-4*a*c;
}

//3b
void printRealRoots(double a, double b, double c){
    double root = discriminant(a,b,c);
    if(root < 0){
        cout << "Det er ingen losninger" << endl;
    }
    else if(root == 0){
        cout << "Losningen er " << -b/a << endl;
    }

    else{
        cout << "Losningene er " << (-b + discriminant(a,b,c))/2*a << " og " << (-b - discriminant(a,b,c))/2*a << endl;
    }

}

//3c
void solveQuadraticEquation(){
    double a;
    double b;
    double c;
    cout << "Skriv inn a: ";
    cin >> a;

    cout << "Skriv inn b: ";
    cin >> b;

    cout << "Skriv inn c: ";
    cin >> c;

    printRealRoots(a, b, c);
            
}

void pythagoras(){
    AnimationWindow win{100,100, 500, 500, "Pythagoras"};
    Point point1{200, 200};
    Point point2{200, 300};
    Point point3{300, 300};
    win.draw_triangle(point1, point2, point3, Color::red);


    win.draw_quad(Point{100, 200}, Point{200, 200}, Point{200, 300}, Point{100, 300}, Color::blue);
    win.draw_quad(Point{200, 300}, Point{300, 300}, Point{300, 400}, Point{200, 400}, Color::yellow);
    win.draw_quad(Point{200, 200}, Point{300, 100}, Point{400, 200}, Point{300, 300}, Color::green);

    win.wait_for_close();
}

//5a
vector<int> calculateBalance(int innskudd, int rente, int aar){
    vector<int> intVector;
    intVector.push_back(innskudd);
    cout << intVector.at(0);
    for(int i = 1; i<aar+1; i++){
        intVector.push_back(static_cast<int>(innskudd * pow(1+rente/100.0, i)));
    }
    return intVector;
}

//5b
void printBalance(vector<int> intVector){
cout << setw(10) << "Aar" << setw(10) << "Saldo" << endl;
for(int i = 0; i<intVector.size(); i++){
    cout << setw(10) << i << setw(10) << intVector.at(i) << endl;
}


}

//5c Feilen skyldes at de prøver å printe ut hele vektoren direkte. Man må bruke en for loop. 
//5d i <= v.size() gir en iterasjon for mye. Det elementet finnes ikke i vektoren

int main() {
     
    // int innskudd = 1000.0;
    // int rente = 5;
    // int aar = 2;

    // printBalance(calculateBalance(innskudd, rente, aar));
    int value = 5;
    const int& reference = value;
    value = 10;
    cout << reference;


    return 0;
}
