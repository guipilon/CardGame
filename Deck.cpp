#include <ctime>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>

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
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
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

        std::cout<< "Deck is empty!" << std::endl;
        return Card::getJoker();
    }
}

int Deck::cardsLeft() const {
    return static_cast<int>(cards.size());
}
