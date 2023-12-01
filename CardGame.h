#pragma once
#include "Deck.h"
#include "CardPlayer.h"

class CardGame {
private:
    std::vector<Deck> shoe;
    std::vector<CardPlayer> players;

public:
    void addDeckToShoe();

    void addPlayer(const CardPlayer& player);

    void dealCards(int playerIndex, int numCards);

    void shuffleShoe();

    void printPlayerHands() const;
};

