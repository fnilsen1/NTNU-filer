#include "Cafeteria.h"

Cafeteria::Cafeteria(string n, Location l) : name{n}, location{l} {
    for(auto p : mainDishPrices) {
        stock.insert({p.first, 0});
    }
    for(auto p : sideDishPrices) {
        stock.insert({p.first, 0});
    }
}

vector<DailyMenu> Cafeteria::getWeeklyMenu() {
    return weeklyMenu;
}

void Cafeteria::setWeeklyMenu(vector<DailyMenu> menu) {
    weeklyMenu = menu;
}

int Cafeteria::getStock (string item) {
    return stock.at(item);
}

void Cafeteria::setStock(string item, int amount) {
    stock.at(item) = amount;
}

void Cafeteria::removeStock(string item) {
    stock.at(item)--;
}

//------------------------------------------------------------------------------------------------

DailyMenu Cafeteria::getDailyMenu(Weekday w) {
    // BEGIN: 1c
    
    DailyMenu dummy;
    dummy = weeklyMenu.at(static_cast<int>(w));
    return dummy;

    // END: 1c
}

bool Cafeteria::isInStock(DailyMenu menu) {
    // BEGIN: 1d
    //Vet ikke om jeg forstod oppgaven

    if(stock.at(menu.mainDish) && stock.at(menu.sideDish)){
        return true;
    }

    return false;

    // END: 1d
}

void Cafeteria::saveToFile(string fileName) {
    // BEGIN: 1e

    filesystem::path outputFilePath = fileName;
    ofstream outputFileStream(outputFilePath);
    for(int i = 0; i<7; i++){
        outputFileStream << weeklyMenu.at(i);
    };

    // END: 1e
}


void Cafeteria::importStock(string fileName) {
    // BEGIN: 2a

    filesystem::path inputFilePath = fileName;
    ifstream inputFileStream(inputFilePath);
    string line;


    while(getline(inputFileStream, line)){
        std::istringstream iss(line);
        std::string dish;
        int amount;
        if (std::getline(iss, dish, ',') && iss >> amount) {
            stock[dish] = amount;
        }
}
    // END: 2a
}


vector<DailyMenu> generateWeeklyMenu() {
    // BEGIN: 2c

    vector<DailyMenu> dummy;
    for(int i = 0; i<7; i++){
        dummy.push_back(getRandomMenu());
    };

    return dummy;

    // END: 2c
}