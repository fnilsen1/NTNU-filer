#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

bool Blackjack::isAce(Card card) {
    if(card.getRank()==Rank::ace) {
        return true;
    } else {
        return false;
    }
}

int Blackjack::getCardValue(Card card) {
    Rank rank = card.getRank();
    switch (rank)
    {
    case Rank::jack:
    case Rank::queen:
    case Rank::king:
        return 10;
        break;
    case Rank::ace:
        return 11;
        break;
    default:
        return static_cast<int>(rank);
        break;
    }
    
}


int Blackjack::getHandScore(vector<Card> hand) {
    int sum = 0;
    int numberOfAces = 0;
    for(Card card : hand) {
        sum += getCardValue(card);
        if(isAce(card)==true) {
            numberOfAces += 1;
        }
    }
    while(sum > 21) {
        if(numberOfAces == 0) {
            break;
        } else {
            sum -= 10;
            numberOfAces -= 1;
        }
    }
    return sum;
}


bool Blackjack::askPlayerDrawCard() {
    string reply = "";
    cout << "Vil du trekke ett kort til? (Skriv ja/nei): ";
    cin >> reply;
    if(reply == "ja") {
        return true;
}
    return false;

}

void Blackjack::drawPlayerCard() {
    playerHand.push_back(deck.drawCard());
    playerhandSum = getHandScore(playerHand);
}

void Blackjack::drawDealerCard() {
    dealerHand.push_back(deck.drawCard());
    dealerhandSum = getHandScore(dealerHand);
}
