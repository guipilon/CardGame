#pragma once
#include <vector>
#include <map>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;
    static void fisherYatesShuffle(std::vector<Card>& vec);
public:
    Deck();

    void initializeDeck();

    void shuffle();

    Card dealCard();

    int cardsLeft() const;

    std::map<Suit, int> cardsLeftBySuit() const;
};

