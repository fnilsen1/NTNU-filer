#include "std_lib_facilities.h"
#include "CardDeck.h"

CardDeck::CardDeck() {
    for(int i = 0; i < 4; i++) {
        for(int j = 2; j < 15; j++) {
            Card card{static_cast<Suit>(i), static_cast<Rank>(j)};
            cards.push_back(card);
        }
    }
}

void CardDeck::swap(int a, int b) {
    Card temporary = cards.at(a);
    cards.at(a) = cards.at(b);
    cards.at(b) = temporary;
}

void CardDeck::print(){
    for (size_t i = 0; i < cards.size(); i++) {
        cout << cards.at(i).toString() << endl;
    }
}

void CardDeck::shuffle(){
    srand(time(nullptr));

    int minNumber = 0;
    int maxNumber = 51;
    int randomNumber = minNumber + rand() % (maxNumber - minNumber + 1);    
    for(int i = 0; i < 52; i++){
    randomNumber = minNumber + rand() % (maxNumber - minNumber + 1);
    
    if(i == randomNumber){
        continue;
    }
    swap(i, randomNumber);
    }

}

Card CardDeck::drawCard(){
int size = cards.size();
Card drawnCard = cards.at((size-1));
cards.pop_back();
return drawnCard;
}
