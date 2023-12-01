#pragma once

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