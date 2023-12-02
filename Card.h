#pragma once

enum Suit {
    HEARTS,
    SPADES,
    CLUBS,
    DIAMONDS,
    JOKER
};

enum Value {
    ACE = 1,
    TWO, 
    THREE, 
    FOUR,
    FIVE, 
    SIX, 
    SEVEN, 
    EIGHT, 
    NINE, 
    TEN,
    JACK, 
    QUEEN, 
    KING
};

struct Card {
    Suit suit;
    Value value;

    static Card getJoker() {
        Card joker;
        joker.suit = Suit::JOKER;
        joker.value = Value::ACE;

        return joker;
    }
};