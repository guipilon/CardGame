#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

enum Suit {
    HEARTS,
    SPADES,
    CLUBS,
    DIAMONDS
};

enum Value {
    ACE = 1,
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING
};

struct Card {
    Suit suit;
    Value value;
};

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck() {
        initializeDeck();
    }

    void initializeDeck() {
        cards.clear();
        for (int suit = HEARTS; suit <= DIAMONDS; ++suit) {
            for (int value = ACE; value <= KING; ++value) {
                cards.push_back({ static_cast<Suit>(suit), static_cast<Value>(value) });
            }
        }
    }

    void shuffle() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        std::random_shuffle(cards.begin(), cards.end());
    }

    Card dealCard() {
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

    int cardsLeft() const {
        return static_cast<int>(cards.size());
    }
};

class Player {
private:
    std::vector<Card> hand;

public:
    void receiveCard(const Card& card) {
        hand.push_back(card);
    }

    int calculateHandValue() const {
        int totalValue = 0;
        for (const Card& card : hand) {
            totalValue += std::min((int)card.value, 10);
        }
        return totalValue;
    }

    const std::vector<Card>& getHand() const {
        return hand;
    }
};

class Game {
private:
    std::vector<Deck> shoe;
    std::vector<Player> players;

public:
    void addDeckToShoe() {
        shoe.emplace_back();
    }

    void addPlayer() {
        players.emplace_back();
    }

    void dealCards(int playerIndex, int numCards) {
        for (int i = 0; i < numCards; ++i) {
            Card card = shoe.back().dealCard();
            players[playerIndex].receiveCard(card);
        }
    }

    void shuffleShoe() {
        for (Deck& deck : shoe) {
            deck.shuffle();
        }
    }

    void printPlayerHands() const {
        std::vector<std::pair<int, int>> playerValues;

        for (size_t i = 0; i < players.size(); ++i) {
            int totalValue = players[i].calculateHandValue();
            playerValues.emplace_back(totalValue, i);
        }

        std::sort(playerValues.rbegin(), playerValues.rend());

        for (const auto& entry : playerValues) {
            int index = entry.second;
            const Player& player = players[index];

            std::cout << "Player " << index + 1 << ": ";
            for (const Card& card : player.getHand()) {
                std::cout << "(" << card.value << ", " << card.suit << ") ";
            }
            std::cout << "Total Value: " << entry.first << std::endl;
        }
    }
};

int main() {
    Game game;

    // Add a deck to the shoe
    game.addDeckToShoe();

    // Add players to the game
    game.addPlayer();
    game.addPlayer();

    // Shuffle the shoe
    game.shuffleShoe();

    // Deal cards to players
    for (int i = 0; i < 52; ++i) {
        game.dealCards(0, 1); // Deal one card to player 1
    }

    // Print player hands
    game.printPlayerHands();

    return 0;
}
