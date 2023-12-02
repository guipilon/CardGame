#pragma once
#include <vector>
#include "Card.h"

class CardPlayer {
private:
    std::vector<Card> hand;

    int playerNumber;

public:
    void setPlayerNumber(int playerNumber);

    int getPlayerNumber() const;

    void receiveCard(const Card& card);

    int calculateHandValue() const;

    const std::vector<Card>& getHand() const;
};

