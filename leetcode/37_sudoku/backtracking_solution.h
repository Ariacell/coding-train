#pragma once
#include <iostream>
#include <vector>

#define LEN 9  // LEN represents the side length of the board
char digits[] = "0123456789";

class BacktrackingSolution {
 public:
  void solveSudoku(std::vector<std::vector<char>>& board) {
    std::cout << "Sudoku Grid:" << std::endl;
    print_board(board);

    bool solved = solve(board, 0, 0);

    if (solved) {
      std::cout << "\nSolved Sudoku:" << std::endl;
      print_board(board);
    } else {
      std::cout << "\nNo solution exists." << std::endl;
    }
  }

 private:
  void print_board(const std::vector<std::vector<char>>& board) {
    for (int row = 0; row < LEN; ++row) {
      for (int col = 0; col < LEN; ++col) {
        std::cout << board[row][col] << " ";
        if ((col + 1) % 3 == 0 && col < LEN - 1) {
          std::cout << "| ";
        }
      }
      std::cout << std::endl;
      if ((row + 1) % 3 == 0 && row < LEN - 1) {
        std::cout << "------+-------+------" << std::endl;
      }
    }
  }

  // the board is passed by reference (&)
  bool is_possible(std::vector<std::vector<char>>& board, int row, int col,
                   char val) {
    // check if the column is valid
    for (int i = 0; i < LEN; i++) {
      if (board[i][col] == val) {
        return false;
      }
    }
    // check if the row is valid
    for (int i = 0; i < LEN; i++) {
      if (board[row][i] == val) {
        return false;
      }
    }
    // check if the 3x3 square is valid
    int startRow =
        3 * (row / 3);  // get if it is the 0,1 or 2 3x3 square then *3
    int startCol = 3 * (col / 3);

    /* alternative way
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    */

    for (int i = startRow; i < startRow + 3; i++) {
      for (int j = startCol; j < startCol + 3; j++) {
        if (board[i][j] == val) {
          return false;
        }
      }
    }
    // if every test passed
    return true;
  }

  bool solve(std::vector<std::vector<char>>& board, int row, int col) {
    if (col == LEN) {
      if (row == LEN - 1) {
        return true;  // we have filled the last square
                      // and add 1 to col (sudoku solved)
      }
      // we are at the end of a column
      col = 0;
      row++;
    }

    if (board[row][col] != '.')  // Already filled, solve for next square
    {
      return solve(board, row, col + 1);
    }

    for (int x = 1; x <= LEN; x++)  // try every value between 1 and 9
    {
      if (is_possible(board, row, col, digits[x])) {
        board[row][col] = digits[x];
        if (solve(board, row, col + 1))  // try x and check if it works
        {
          return true;
        }
      }
      board[row][col] = '.';  // previous x value didn't work
                            // reset and try another x
    }

    return false;  // We are in a dead end
                   // can't solve the sudoku with current values
  }
};
