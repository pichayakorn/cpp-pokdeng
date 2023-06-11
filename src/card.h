#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

const int SUIT_MAX = 4;
const int RANK_MAX = 13;

const string category_Suit[SUIT_MAX] = {"H","D","S","C"};
const string category_Rank[RANK_MAX] = {" A"," 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10"," J"," Q"," K"};

class Card {
  friend class Deck;

public:
  Card();
  Card(int receiveSuit, int receiveRank);

  bool isHighCard() const;
  bool isAce() const;

  void showCard() const;
  int getSuit() const;
  int getRank() const;
private:
  int generateSuit();
  int generateRank();
  int suit;
  int rank;
};

#endif // CARD_H

