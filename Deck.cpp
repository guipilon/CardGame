#include <ctime>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <thread>
#include <random>
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
    fisherYatesShuffle(cards);
}

void Deck::fisherYatesShuffle(std::vector<Card>& vec) {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = vec.size() - 1; i > 0; --i) {
        std::uniform_int_distribution<int> dist(0, i);
        int j = dist(gen);

        // Swap elements at i and j
        std::swap(vec[i], vec[j]);
    }
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

std::map<Suit, int> Deck::cardsLeftBySuit() const {

    std::map<Suit, int> result;

    for (Card card : cards) {
        if (result.find(card.suit) != result.end()) {
            result[card.suit]++;
        }
        else {
            result.insert(std::pair<Suit, int>(card.suit,0));
        }
    }

    return result;
}
