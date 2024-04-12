#if !defined(TicTacToe_H)
#define TicTacToe_H
#include <iostream>

class TicTacToe {
  char **board = new char *[3];
  // bool isPlayerOneTurn = true;

private:
public:
  //TicTacToe();

  void initializeBoard();

  void printBoard();

  void resetBoard();

  bool placeMarker(int row, int col, char marker);

  void getPlayerInput();

  bool checkForWinner(char marker);

  bool checkForTie();

  bool checkForRowWin(char marker);

  bool checkForColWin(char marker);

  bool checkForDigWin(char marker);

  void getComputersInput();
};
#endif
