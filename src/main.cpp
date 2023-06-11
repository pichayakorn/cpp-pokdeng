#include "pokdengHand.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

int main()
{
  srand(time(NULL));

  int choice = 0;
  int numPlayer = 0;

  PokdengHand mainDeck("Main deck");
  PokdengHand dealer("Dealer");

  mainDeck.setFullDeck();
  mainDeck.shuffle();

  //Ask for number of player
  while (numPlayer < 1 || numPlayer > 3) {
    try {
      cout << "Enter number of player (maximum at 3): ";
      cin >> numPlayer;
      if (numPlayer < 1 || numPlayer > 3 || !cin)
        throw string("Invalid number of player");
    }
    catch (const string &error) {
      cerr << "ERROR : " << error
           << ", please try again." << endl << endl;
      cin.clear();
      cin.ignore(100,'\n');
      numPlayer = 0;
    }
  }
  /**********/
  system("CLS");
  /**********/

  //Create Player hand
  PokdengHand player[numPlayer];
  for (int i = 0; i < numPlayer; i++) {
    stringstream n;
    n << (i + 1);
    string num = n.str();
    player[i] = PokdengHand("Player " + num);
  }

  //Deal to all hand
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < numPlayer; j++) {
      player[j].draw(mainDeck);
    }
    dealer.draw(mainDeck);
  }

  //Start player-loop
  //Player Option p1 -> p2 -> p3
  for (int i = 0; i < numPlayer; i++) {
    //If dealer get 9 point at begin, show his hand and skip his option at the end player-loop
    if (dealer.isPokNine()) {
      cout << dealer.getName() << "  : ";
      dealer.showDeck();
      cout << "(" << dealer.checkSum() << " point)"<< endl;
    }
    else { //Start Board (Hide dealer hand)
      cout << dealer.getName() << "  : XX-X XX-X ";
      cout << "(? point)" << endl;
    }

    //Show all player hand
    for (int j = 0; j < numPlayer; j++) {
      cout << player[j].getName() << ": ";
      player[j].showDeck();
      cout << "(" << player[j].checkSum() << " point)"<< endl;
    }

    //If player get 9 point at begin, skip his option
    if ( !player[i].isPokNine() ){
      cout << endl;
      cout << player[i].getName() << ": ";
      cout << "Choose 1 for HIT, Choose 2 for STAND: ";
      cin >> choice;

      while (choice < 1 || choice > 2 || !cin){
        cerr << "ERROR : Invalid choice, please try again." << endl << endl;
        cin.clear();
        cin.ignore(100,'\n');
        choice = 0;

        cout << player[i].getName() << ": ";
        cout << "Choose 1 for HIT, Choose 2 for STAND: ";
        cin >> choice;
      }
      player[i].option(mainDeck,choice);
    }
    /**********/
    system("CLS");
    /**********/

  } //End player-loop

  //Dealer(computer) auto option(skip when dealer get 9 point)
  if (!dealer.isPokNine())
    dealer.dealerRule(mainDeck);


  //Show final board with player check win
  cout << dealer.getName() << "  : ";
  dealer.showDeck();
  cout << "(" << dealer.checkSum() << " point)"<< endl;

  for (int i = 0; i < numPlayer; i++) {
    cout << player[i].getName() << ": ";
    player[i].showDeck();
    cout << "(" << player[i].checkSum() << " point) ";

    //PLAYER CHECK WIN
    if ( player[i].checkDraw(dealer) )
      cout << "DRAW!" << endl;
    else if ( player[i].checkWin(dealer) )
      cout << "You Win!" << endl;
    else
      cout << "You Lose!" << endl;
  }

  cout << endl;
  system("PAUSE");
  return 0;
}
