#include "TicTacToe.h"
#include <iostream>
int main() {
  TicTacToe TicTacToe;
  bool isWinner = false;
  bool isPlayerOneTurn = true;
  TicTacToe.initializeBoard();
  TicTacToe.printBoard();

  while (!isWinner) {
    if (isPlayerOneTurn) {
      TicTacToe.getPlayerInput();
      isWinner = TicTacToe.checkForWinner('X');
    } else {
      TicTacToe.getComputersInput();
      isWinner = TicTacToe.checkForWinner('O');
    }
    if (!isWinner) {
      isWinner = TicTacToe.checkForTie();
    }
    isPlayerOneTurn = !isPlayerOneTurn;
    std::cout << std::endl;
  }
  return 0;
}