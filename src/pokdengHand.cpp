#include "pokdengHand.h"
#include "deck.h"
#include <iostream>
#include <string>

using namespace std;

PokdengHand::PokdengHand()
{
  name = "Newbie";
  money = 0;
}

PokdengHand::PokdengHand(string handName)
{
  name = handName;
}

PokdengHand::PokdengHand(int startMoney)
{
  money = startMoney;
}

PokdengHand::PokdengHand(string handName, int startMoney)
{
  name = handName;
  money = startMoney;
}

string PokdengHand::getName() const
{
  return name;
}

int PokdengHand::getMoney() const
{
  return money;
}

void PokdengHand::setName(string newName)
{
  name = newName;
}

void PokdengHand::setMoney(int newMoney)
{
  money = newMoney;
}

void PokdengHand::setHand(string newName, int newMoney)
{
  name = newName;
  money = newMoney;
}

//Return total point of hand by sum all card point and modulation with 10
int PokdengHand::checkSum() const
{
  int sum = 0;
  for (int i = 0; i < getDeckSize() ; i++) {
    if (getCard(i).isHighCard())
      sum += 10;
    else
      sum += (getCard(i).getRank()) + 1;
  }
  return sum % 10;
}

//Option Hit(1) to draw 1 card from main deck, Stand(2) skip draw and end his turn
void PokdengHand::option(PokdengHand &mainDeck, int choice)
{
  try {
    if (choice != 1 && choice != 2)
      throw string("Invalid choice");

    switch(choice) {
      case 1:
        draw(mainDeck);
        break;
      case 2:
        break;
    }
  }
  catch (const string &error) {
    cerr << endl << "ERROR : " << error
         << ", please try again." << endl;
    terminate();
  }
}

//Play as Computer
void PokdengHand::dealerRule(PokdengHand &mainDeck)
{
  int currentPoint = checkSum();
  if (currentPoint != 9) {
    draw(mainDeck);
    int cheatPoint = checkSum();
    if (currentPoint > cheatPoint)
      mainDeck.draw(*this);
  }
}

bool PokdengHand::checkWin(const PokdengHand &checkDeck) const
{
  return (checkSum() > checkDeck.checkSum());
}

bool PokdengHand::checkDraw(const PokdengHand &checkDeck) const
{
  return (checkSum() == checkDeck.checkSum());
  //more...
}

bool PokdengHand::isPokNine() const
{
  return (checkSum() == 9);
}

/*For advance rule*/
bool PokdengHand::isDouble() const
{
  if (getDeckSize() == 2)
    return (getCard(0).getSuit() == getCard(1).getSuit());

  return false;
}

bool PokdengHand::isTriple() const
{
  if (getDeckSize() == 3)
    return (getCard(0).getSuit() == getCard(1).getSuit() &&
            getCard(0).getSuit() == getCard(2).getSuit());

  return false;
}
