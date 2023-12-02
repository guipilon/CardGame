#include "pch.h"
#include "CppUnitTest.h"
#include "../Deck.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<Suit>(const enum Suit& t) {
				switch (t)
				{
					case Suit::JOKER:
						return L"JOKER";
					default:
						return L"KING";
				}
			}
		}
	}
}

namespace DeckUnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(DeckShouldBeInitializedWithAllCards)
		{
			Deck deck;
			deck.initializeDeck();
			Assert::AreEqual(52, deck.cardsLeft());
		}

		TEST_METHOD(DeckShouldShrinkAfterDealACard)
		{
			Deck deck;
			deck.initializeDeck();
			auto& card = deck.dealCard();
			Assert::AreEqual(51, deck.cardsLeft());
		}

		TEST_METHOD(DeckShouldReturnAJokerWhenNoMoreCardsToDeal)
		{
			Deck deck;
			deck.initializeDeck();

			while (deck.cardsLeft() > 0) {
				deck.dealCard();
			}

			Card card = deck.dealCard();
			Assert::AreEqual(Suit::JOKER, card.suit);
		}
	};
}
