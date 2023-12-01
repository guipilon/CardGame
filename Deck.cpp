#include <ctime>
#include <algorithm>
#include <iostream>
#include "Deck.h"

Deck::Deck() {
    initializeDeck();
}

void Deck::initializeDeck() {
    cards.clear();
    for (int suit = HEARTS; suit <= DIAMONDS; ++suit) {
        for (int value = ACE; value <= KING; ++value) {
            cards.push_back({ static_cast<Suit>(suit), static_cast<Value>(value) });
        }
    }
}

void Deck::shuffle() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::dealCard() {
    if (!cards.empty()) {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }
    else {
        // You can handle the case when the deck is empty, e.g., reshuffling or indicating the end of the game.
        // For simplicity, let's assume the game ends when the deck is empty.
        std::cerr << "Error: Deck is empty!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int Deck::cardsLeft() const {
    return static_cast<int>(cards.size());
}
