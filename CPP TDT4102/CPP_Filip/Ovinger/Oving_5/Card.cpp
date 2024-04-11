#include "Card.h"
#include "std_lib_facilities.h"

//1.e) Det er ikke åpenbart for andre hvilket tall som tilhører hvilken streng. Du får feilmelding hvis du tilordner feil verdi til enum

string suitToString(Suit suit){
    const map<Suit, string> mapping {
    {Suit::clubs, "clubs"},
    {Suit::diamonds, "diamonds"}, 
    {Suit::hearts, "hearts"},
    {Suit::spades, "spades"}
};
return mapping.at(suit);

};

string rankToString(Rank rank){
    const map<Rank, string> dict {
    {Rank::two, "two"}, 
    {Rank::three, "three"}, 
    {Rank::four, "four"}, 
    {Rank::five, "five"}, 
    {Rank::six, "six"},
    {Rank::seven, "seven"}, 
    {Rank::eight, "eight"}, 
    {Rank::nine, "nine"}, 
    {Rank::ten, "ten"}, 
    {Rank::jack, "jack"}, 
    {Rank::queen, "queen"}, 
    {Rank::king, "king"}, 
    {Rank::ace, "ace"}

};
return dict.at(rank);
  
}

Card::Card(Suit a, Rank b){
    s = a;
    r = b;
}

Suit Card::getSuit(){
    return s;
}

Rank Card::getRank(){
    return r;
}

string Card::toString(){
    string suit = suitToString(s);
    string rank = rankToString(r);
    string cardName = rank + " of " + suit;
    return cardName;
}