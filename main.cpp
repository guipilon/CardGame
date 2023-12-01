#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "Deck.h"
#include "CardPlayer.h"
#include "CardGame.h"

int main() {
    CardGame game;

    // Add a deck to the shoe
    game.addDeckToShoe();

    // Add players to the game
    CardPlayer player1, player2;
    game.addPlayer(player1);
    game.addPlayer(player2);

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
