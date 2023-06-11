#include "card.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//Random a card
Card::Card()
{
  suit = generateSuit();
  rank = generateRank();
}

Card::Card(int receiveSuit, int receiveRank)
{
  try {
    if (receiveSuit < 0 || receiveSuit > SUIT_MAX - 1 || receiveRank < 0 || receiveRank > RANK_MAX - 1)
      throw string("Invalid Constructor parameter");

    suit = receiveSuit;
    rank = receiveRank;
  }
  catch (const string &error) {
    cerr << "ERROR : " << error
         << ", please try again." <<endl;
    terminate();
  }
}

bool Card::isHighCard() const
{
  return ( rank == 10 || rank == 11 || rank == 12 );
}

bool Card::isAce() const
{
  return ( rank == 0 );
}

void Card::showCard() const
{
  cout << category_Rank[rank] + "-" + category_Suit[suit];
}

int Card::getSuit() const
{
  return suit;
}

int Card::getRank() const
{
  return rank;
}

//Return random suit
int Card::generateSuit()
{
  return rand() % SUIT_MAX;
}

//Return random rank
int Card::generateRank()
{
  return rand() % RANK_MAX;
}
