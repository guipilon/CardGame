#include <iostream>
#include <vector>
#include <algorithm>
#include "CardGame.h"

void CardGame::addDeckToShoe() {
    shoe.emplace_back();
}

void CardGame::addPlayer(const CardPlayer& player) {
    players.push_back(player);
}

void CardGame::dealCards(int playerIndex, int numCards) {
    for (int i = 0; i < numCards; ++i) {
        Card card = shoe.back().dealCard();
        players[playerIndex].receiveCard(card);
    }
}

void CardGame::shuffleShoe() {
    for (Deck& deck : shoe) {
        deck.shuffle();
    }
}

void CardGame::printPlayerHands() const {
    std::vector<std::pair<int, int>> playerValues;

    for (size_t i = 0; i < players.size(); ++i) {
        int totalValue = players[i].calculateHandValue();
        playerValues.emplace_back(totalValue, i);
    }

    std::sort(playerValues.rbegin(), playerValues.rend());

    for (const auto& entry : playerValues) {
        int index = entry.second;
        const CardPlayer& player = players[index];

        std::cout << "Player " << index + 1 << ": ";
        for (const Card& card : player.getHand()) {
            std::cout << "(" << card.value << ", " << card.suit << ") ";
        }
        std::cout << "Total Value: " << entry.first << std::endl;
    }
}