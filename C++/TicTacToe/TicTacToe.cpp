#include "TicTacToe.h"
#include <cmath>
#include <iostream>
#include <random>
#include <vector>
#include <array>

void TicTacToe::initializeBoard() {
  board[0] = new char[3];
  board[1] = new char[3];
  board[2] = new char[3];
  resetBoard();
}

void TicTacToe::printBoard() {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      std::cout << board[row][col] << " ";
    }
    std::cout << std::endl;
  }
}

void TicTacToe::resetBoard() {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      board[row][col] = '~';
    }
  }
}

bool TicTacToe::placeMarker(int row, int col, char marker) {
  if (!(board[row][col] == '~')) {
    std::cout << "That spot is already taken. Try again." << std::endl;
    return false;
  } else {
    board[row][col] = marker;
    return true;
  }
}

void TicTacToe::getPlayerInput() {
  int row;
  int col;
  bool isInputValid = false;
  bool isMarkerPlaced = false;
  while (!isMarkerPlaced) {
    while (!isInputValid) {
      std::cout << "Enter a row number: ";
      std::cin >> row;
      if (row < 0 || row > 2) {
        std::cout << "Invalid input. Row can only be 0, 1 or 2.Try again."
                  << std::endl;
      } else {
        isInputValid = true;
      }
    }
    isInputValid = false;
    while (!isInputValid) {
      std::cout << "Enter a column number: ";
      std::cin >> col;
      if (col < 0 || col > 2) {
        std::cout << "Invalid input. Col can only be 0, 1 or 2.Try again."
                  << std::endl;
      } else {
        isInputValid = true;
      }
    }
    if (placeMarker(row, col, 'X')) {
      isMarkerPlaced = true;
    } else {
      std::cout << "Invalid input. That place is already taken. Try again.";
      isInputValid = false;
    }
  }
  printBoard();
}

bool TicTacToe::checkForWinner(char marker) {
  if (checkForRowWin(marker) || checkForColWin(marker) ||
      checkForDigWin(marker)) {
    std::cout << "The Winner Is " << marker << std::endl;
    delete[] board;
    return true;
  }
  return false;
}

bool TicTacToe::checkForTie() {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (board[row][col] == '~') {
        return false;
      }
    }
  }
  std::cout << "Tie Game" << std::endl;
  return true;
}

bool TicTacToe::checkForRowWin(char marker) {

  for (int col = 0; col < 3; col++) {
    if (board[0][col] == board[1][col] && board[1][col] == board[2][col] &&
        board[0][col] == marker) {
      return true;
    }
  }
  return false;
}

bool TicTacToe::checkForColWin(char marker) {

  for (int row = 0; row < 3; row++) {
    if (board[row][0] == board[row][1] && board[row][1] == board[row][2] &&
        board[row][0] == marker) {
      return true;
    }
  }
  return false;
}

bool TicTacToe::checkForDigWin(char marker) {
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
      board[1][1] == marker) {
    return true;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
      board[1][1] == marker) {
    return true;
  }
  return false;
}

void TicTacToe::getComputersInput() {
  std::vector<std::array<int, 2>> markers;
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (board[row][col] == '~') {
        std::array<int, 2> temp = {row, col};
        markers.push_back(temp);
      }
    }
  }
  int randomMarker = rand() % markers.size();
  placeMarker(markers[randomMarker][0], markers[randomMarker][1], 'O');
  printBoard();
}
