#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

class Blackjack{

private:
CardDeck deck;
vector<Card> playerHand;
vector<Card> dealerHand;
int playerhandSum;
int dealerhandSum;

public:
bool isAce(Card card);
int getCardValue(Card card);
int getHandScore(vector<Card> hand);
bool askPlayerDrawCard();
void drawPlayerCard();
void drawDealerCard();
};
