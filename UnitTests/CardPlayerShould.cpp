#include "pch.h"
#include "CppUnitTest.h"
#include "../CardPlayer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CardPlayerUnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:

		TEST_METHOD(CardPlayerReceiveTheCorrectHand)
		{
			CardPlayer player;

			Card card = {Suit::CLUBS, Value::ACE};

			player.receiveCard(card);

			auto& returnedCards = player.getHand();

			Assert::AreEqual(1, (int)returnedCards.size());
		}
	};
}
