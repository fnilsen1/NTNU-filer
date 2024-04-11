#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "mastermind.h"

int checkCharactersAndPosition(string code, string guess) {
    int correct = 0;
    for(int i = 0; i < code.length(); i++) {
        if(code[i]==guess[i]) {
            correct += 1;
        }
    }
    return correct;
}

int checkCharacters(string code, string guess) {
    int correct = 0;
    int frequency = -1;
    for(int i = 0; i < guess.length(); i++) {
        frequency = countChar(code, guess[i]);
        if(frequency>0) {
            correct += 1;
        }
    }
    return correct;
}

void playMastermind() {
    constexpr int size = 4;
    constexpr int letters = 6;
    const string code = randomizeString(size, 'A', ('A' + (letters - 1)));
    cout << code << '\n';

    int numberOfCorrectCharacters = 0;
    string guess = "????";
    constexpr int max_attempts = 8;
    int attempts = 0;


    while (numberOfCorrectCharacters < size and attempts < max_attempts) {
        cout << "\nGjett koden, som er " << size << " bokstaver lang.\n";
        guess = readInputToString(size, 'A', ('A' + (letters - 1)));
        numberOfCorrectCharacters = checkCharactersAndPosition(code, guess);
        cout << "Du gjettet " << (checkCharacters(code, guess)) << " bokstaver riktig, \n";
        cout << numberOfCorrectCharacters << " var paa rett plass." << '\n';
        attempts += 1;
        cout << "Du har " << (max_attempts-attempts) << " forsok igjen.\n";
    }
    if(guess == code) {
        cout << "\nDu gjettet den riktige koden: " << code << endl;
    } else {
        cout << "\nDu tapte! Den riktige koden var: " << code << ". Prov igjen" << endl;
    }
}