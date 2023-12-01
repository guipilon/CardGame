#include "CardPlayer.h"

void CardPlayer::receiveCard(const Card& card) {
    hand.push_back(card);
}

int CardPlayer::calculateHandValue() const {
    int totalValue = 0;
    for (const Card& card : hand) {
        totalValue += std::min((int)card.value, 10); // Face cards have a value of 10
    }
    return totalValue;
}

const std::vector<Card>& CardPlayer::getHand() const {
    return hand;
}
