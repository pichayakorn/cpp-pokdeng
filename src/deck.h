#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <string>

using namespace std;

const int DECK_MAX = SUIT_MAX*RANK_MAX;

class Deck {
public:
  Deck();

  int	getDeckSize() const;
  bool isEmpty() const;
  bool isFull() const;

  const Card getCard(int cardPosition) const;

  void setFullDeck();
  void showDeck();
  void shuffle();
  void swapPosition(Card &Position_1st, Card &position_2nd);

  void addCard(const Card &cd);
  const Card getTopCard();
  const Card pickCard(int cardPosition);

  void draw(Deck &chooseDeck, int amount = 1);
  void chooseCard(Deck &chooseDeck, int cardPosition);

  /** For 1 - 4 player(deck) only **/
  void deal(Deck &deck1,int amount);
  void deal(Deck &deck1, Deck &deck2, int amount);
  void deal(Deck &deck1, Deck &deck2, Deck &deck3, int amount);
  void deal(Deck &deck1, Deck &deck2, Deck &deck3, Deck &deck4, int amount);
private:
  vector<Card> n_deck;
};

#endif // DECK_H
