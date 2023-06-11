#ifndef POKDENGHAND_H
#define POKDENGHAND_H

#include "deck.h"
#include <string>

using namespace std;

class PokdengHand : public Deck {
public:
  PokdengHand();
  PokdengHand(string handName);
  PokdengHand(int startMoney);
  PokdengHand(string handName, int startMoney);

  string getName() const;
  int getMoney() const;

  void setName(string newName);
  void setMoney(int newMoney);
  void setHand(string newName, int newMoney);

  int checkSum() const;
  void option(PokdengHand &mainDeck, int choice);
  void dealerRule(PokdengHand &mainDeck);
  bool checkWin(const PokdengHand &checkDeck) const;
  bool checkDraw(const PokdengHand &checkDeck) const;
  bool isPokNine() const;
  bool isDouble() const;
  bool isTriple() const;
private:
  string name;
  int money;
};

#endif // POKDENGHAND_H
