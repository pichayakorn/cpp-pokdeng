# Pokdeng - Thai gambling card game

C++ Project - Pok Deng, Thai gambling card game.

## Basic steps of play

1. The players place their bets.
2. The dealer shuffles and deals two cards to each player, ending with the dealer.
3. Each player may stay or draw one card.
4. The dealer may compare his or her hand against select players.
5. The dealer may draw a card.
6. The dealer compares his or her hand against the rest of the players.

## Player decides how to play hand

`Hit` – If you would like one more card to improve your hand total, the dealer will deal you more card, one at a time or you choose to stand.

`Stand` – If your first two cards are acceptable, you can stand and the dealer will move on to the next player.

## Sample (Player Vs Dealer Bot)

**Game start: Decide number of player (maximum at 3)**

```
Enter number of player (maximum at 3):
```

**Game start: player decision**

```
Dealer  : XX-X XX-X (? point)
Player 1:  5-H  K-D (5 point)

Player 1: Choose 1 for HIT, Choose 2 for STAND:
```

**Game end: player lose**

```
Dealer  :  8-D  9-H (7 point)
Player 1:  5-H  K-D  9-S (4 point) You Lose!
```

**Game end: player win**

```
Dealer  :  2-S 10-H  4-D (6 point)
Player 1: 10-C  7-S (7 point) You Win!
```

## How to run

```sh
cd src && g++ card.cpp deck.cpp main.cpp pokdengHand.cpp -o ../output/main.exe
../output/main.exe
```

## License

MIT license

Check out [LICENSE](/LICENSE) for more detail.
