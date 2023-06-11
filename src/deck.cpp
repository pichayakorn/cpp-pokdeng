#include "deck.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

Deck::Deck() {} //Empty Deck

int	Deck::getDeckSize() const
{
  return n_deck.size();
}

bool Deck::isEmpty() const
{
  return n_deck.empty();
}

bool Deck::isFull() const
{
  return n_deck.size() == DECK_MAX;
}

//Return one card form position you choose in your deck
const Card Deck::getCard(int cardPosition) const
{
  try {
    if (isEmpty())
      throw string("Can not get card from empty deck");
    if (cardPosition < 0 || static_cast<unsigned int>(cardPosition) > n_deck.size())
      throw string("Invalid position");

    return n_deck[cardPosition];
  }
  catch (const string &error) {
    cerr << "ERROR : " << error
         << ", please try again." <<endl;
    terminate();
  }
}

//Set deck to full of deck,
//sort by "Heart","Diamond","Spade" and "Clubs" each suit sort by "Ace" to "King"
void Deck::setFullDeck()
{
  n_deck.clear(); // Play again
  for (unsigned int i = 0; i < SUIT_MAX; i++)
    for (unsigned int j = 0; j < RANK_MAX; j++)
      n_deck.push_back(Card(i, j));
}

//Show deck and new line when show 13 card
void Deck::showDeck()
{
  int count = 1;
  for (unsigned int i = 0; i < n_deck.size(); i++) {
    n_deck[i].showCard(); cout << " ";
    if (count == 13) {
      cout << endl;
      count = 0;
    }
    ++count;
  }
  if (isEmpty()) {
    cout << "Empty deck" << endl;
  }
}

//Shuffle deck by using swapPosition-function
void Deck::shuffle()
{
  for(unsigned int i = n_deck.size()-1; i > 1; i--) {
    int randPosition = rand() % i;
    swapPosition(n_deck[i], n_deck[randPosition]);
  }
}

//Swap position
void Deck::swapPosition(Card &position_1st, Card &position_2nd)
{
  Card temp = position_1st;
  position_1st = position_2nd;
  position_2nd = temp;
}

//Add card to deck insert next to the last element
void Deck::addCard(const Card &cd)
{
  try {
    if (isFull())
      throw string("Can not add card to full deck");

    n_deck.push_back(cd);
  }
  catch (const string &error) {
    cerr << "ERROR : " << error
         << ", please try again." <<endl;
    terminate();
  }
}

//Return card from the last element, then delete that element
const Card Deck::getTopCard()
{
  try {
    if (isEmpty())
      throw string("Can not get card from empty deck");

    Card cd = n_deck.back();
    n_deck.pop_back();
    return cd;
  }
  catch (const string &error) {
    cerr << "ERROR : " << error
         << ", please try again." <<endl;
    terminate();
  }
}

//Return one card form position you choose in your deck, then delete that element
const Card Deck::pickCard(int cardPosition)
{
  try {
    if (isEmpty())
      throw string("Can not pick card from empty deck");
    if (cardPosition < 1 || static_cast<unsigned int>(cardPosition) > n_deck.size())
      throw string("Invalid position");

    Card cd = n_deck[cardPosition-1];
    n_deck.erase(n_deck.begin()+cardPosition-1);
    return cd;
  }
  catch (const string &error) {
    cerr << "ERROR : " << error
         << ", please try again." <<endl;
    terminate();
  }
}

//*********************************************************//
//Combine add card and get top card in this function
void Deck::draw(Deck &chooseDeck, int amount)
{
  for (int i = 0; i < amount; i++)
    addCard(chooseDeck.getTopCard());
}

//Combine add card and pick card in this function
void Deck::chooseCard(Deck &chooseDeck, int cardPosition)
{
  addCard(chooseDeck.pickCard(cardPosition));
}

//*********************************************************//
//deal card from 1 deck to another deck
void Deck::deal(Deck &deck1,int amount)
{
  deck1.draw(*this, amount);
}

void Deck::deal(Deck &deck1, Deck &deck2, int amount)
{
  for (int i = 0; i < amount; i++) {
    deck1.addCard(getTopCard());
    deck2.addCard(getTopCard());
  }
}

void Deck::deal(Deck &deck1, Deck &deck2, Deck &deck3, int amount)
{
  for (int i = 0; i < amount; i++) {
    deck1.addCard(getTopCard());
    deck2.addCard(getTopCard());
    deck3.addCard(getTopCard());
  }
}

void Deck::deal(Deck &deck1, Deck &deck2, Deck &deck3, Deck &deck4, int amount)
{
  for (int i = 0; i < amount; i++) {
    deck1.addCard(getTopCard());
    deck2.addCard(getTopCard());
    deck3.addCard(getTopCard());
    deck4.addCard(getTopCard());
  }
}
