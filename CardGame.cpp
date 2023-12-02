#include <iostream>
#include <vector>
#include <algorithm>
#include "CardGame.h"

void CardGame::addDeckToShoe() {
    shoe.emplace_back();
}

void CardGame::addPlayer(CardPlayer& player) {
    player.setPlayerNumber(players.size());
    players.push_back(player);
}

void CardGame::dealCards(int playerIndex, int numCards) {
    int i = 0;
    while (!shoe.empty() && i < numCards) {
        Card card = shoe.back().dealCard();
        if (card.suit == Suit::JOKER) {
            shoe.pop_back();
        }
        else {
            i++;
            players[playerIndex].receiveCard(card);
        }
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
        int index = players[i].getPlayerNumber();
        playerValues.emplace_back(totalValue, index);
    }

    //Assuming the winner is the player with the biggest hand value.
    //The player printed first is the winner
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
