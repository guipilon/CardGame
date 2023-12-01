#pragma once
#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();

    void initializeDeck();

    void shuffle();

    Card dealCard();

    int cardsLeft() const;
};

