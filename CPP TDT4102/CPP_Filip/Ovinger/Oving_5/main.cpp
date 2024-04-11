#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

#include <string>



int main() {
    // Rank r = Rank::king;
    // Suit s = Suit::hearts;
    // string rank = rankToString(r);
    // string suit = suitToString(s);
    // cout << "Rank: " << rank << " Suit: " << suit << endl;

    // Card c{Suit::spades, Rank::ace};
    // cout << c.toString() << '\n';

    CardDeck deck{};
    deck.shuffle();
    deck.print();

    return 0;

}

