#pragma once
#include <assert.h>

#include <unordered_set>
#include <vector>

std::vector<char> POSSIBLE_VALUES = {'1', '2', '3', '4', '5',
                                     '6', '7', '8', '9'};

class Solution {
 public:
  void solveSudoku(std::vector<std::vector<char>>& board) {
    int solved = false;
    int iterationCap = 100;
    int iteration = 0;
    while (!solved && iteration < iterationCap) {
      iteration++;
      solveBoard(board);
      solved = IsAnyUnsolvedSquareRemaining(
          board);  // assume this step solved us unless proven otherwise
    }

    if (solved)
      std::cout << "solved!" << std::endl;
    else {
      std::cout << "Could not solve within 100 iterations. Board state was: "
                << std::endl;
      PrintBoardCSV(board);
    }
  }

  void solveBoard(std::vector<std::vector<char>>& board) {
    // for each box
    std::vector<char> box;
    box.resize(9);
    for (int x = 0; x < 3; x++) {
      for (int y = 0; y < 3; y++) {
        auto currentBox = getBox(x, y, box, board);
        int boxIndex = x + 3 * y;
        // for each number
        // if the number is already in the box, break
        // if the number isn't already in the box, check whether there's a
        // unique solution for that number in the box.
        auto [possibleValues, possibleLocations] = getValuesForBox(currentBox);
        for (auto value : possibleValues) {
          auto viableLocations = GetViableLocationsInBox(
              value, possibleLocations, boxIndex, board);
          if (viableLocations.size() == 1) {
            auto [x, y] =
                LocationInBoxToPuzzleLocation(viableLocations[0], boxIndex);
            board[x][y] = value;
          }
        }
      }
    }
    FinishRowsAndColumns(board);
    // very memory inefficient, and doesn't solve harder puzzles.
    //  I'd like to improve this to work more like a human solve, I don't like
    //  the backtracking solution as it feels lazy Doing it again, I would
    //  create a data-oriented approach with each iteration calculating the
    //  candidates for each square and then
  }

  std::vector<int> GetViableLocationsInBox(
      char valueToTry, std::vector<int> openLocations, int boxIndex,
      std::vector<std::vector<char>>& board) {
    int horizontalBoxIndex = boxIndex / 3;

    int verticalBoxIndex = boxIndex % 3;

    std::vector<int> viableLocations = {};
    for (int location : openLocations) {
      int locationRowIndex = location / 3 + horizontalBoxIndex * 3;
      int locationColumnIndex = location % 3 + verticalBoxIndex * 3;

      if (!valueInRow(valueToTry, locationRowIndex, board) &&
          !valueInColumn(valueToTry, locationColumnIndex, board)) {
        viableLocations.push_back(location);
      }
    }
    return viableLocations;
  }

 private:
  bool IsAnyUnsolvedSquareRemaining(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          return false;
        }
      }
    }
    return true;
  }

  void PrintBoardCSV(const std::vector<std::vector<char>>& board) {
    for (auto vec : board) {
      for (auto c : vec) {
        std::cout << c << ",";
      }
      std::cout << "\n" << std::endl;
    }
  }

  void FinishRowsAndColumns(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
      std::vector<char> flattenedColumn;
      std::vector<int> possibleLocations = {};
      for (int j = 0; j < 9; j++) {
        flattenedColumn.push_back(board[i][j]);
        if (board[i][j] == '.') {
          possibleLocations.push_back(j);
        }
      }

      std::unordered_set<char> colSet(flattenedColumn.begin(),
                                      flattenedColumn.end());
      std::vector<char> colDiff;
      for (char c : POSSIBLE_VALUES) {
        if (!colSet.count(c)) {
          colDiff.push_back(c);
        }
      }
      if (colDiff.size() == 1 && possibleLocations.size() == 1) {
        std::cout << i << "row and col" << possibleLocations[0]
                  << "can be completed with " << colDiff[0] << std::endl;
        board[i][possibleLocations[0]] = colDiff[0];
      }
    }
  }

  std::pair<int, int> LocationInBoxToPuzzleLocation(int locationInBox,
                                                    int boxIndex) {
    int horizontalBoxIndex = boxIndex / 3;
    int verticalBoxIndex = boxIndex % 3;
    int locationRowIndex = locationInBox / 3 + horizontalBoxIndex * 3;
    int locationColumnIndex = locationInBox % 3 + verticalBoxIndex * 3;
    return std::make_pair(locationRowIndex, locationColumnIndex);
  }

  bool valueInRow(char value, int row, std::vector<std::vector<char>>& board) {
    assert(row >= 0 && row <= 8);
    assert(value != '.');

    bool match = false;
    for (auto val : board[row]) {
      if (val == value) match = true;
    }
    return match;
  }

  bool valueInColumn(char value, int column,
                     std::vector<std::vector<char>>& board) {
    assert(column >= 0 && column <= 8);
    assert(value != '.');

    bool match = false;
    std::vector<char> flattenedColumn;
    for (int i = 0; i < 9; i++) {
      flattenedColumn.push_back(board[i][column]);
    }
    for (auto val : flattenedColumn) {
      if (val == value) match = true;
    }
    return match;
  }

  std::pair<std::vector<char>, std::vector<int>> getValuesForBox(
      std::vector<char> box) {
    std::unordered_set<char> setB(box.begin(), box.end());
    std::vector<char> diff;
    std::vector<int> locations;
    for (char c : POSSIBLE_VALUES) {
      if (!setB.count(c)) {
        diff.push_back(c);
      }
    }
    for (size_t i = 0; i < box.size(); i++) {
      if (box[i] == '.') {
        locations.push_back(i);
      }
    }
    return std::make_pair(diff, locations);
  }

  // Get box at position x y
  // 0 1 2
  // 3 4 5
  // 6 7 8
  std::vector<char> getBox(int x, int y, std::vector<char>& box,
                           std::vector<std::vector<char>>& board) {
    assert(x >= 0 && x <= 2);
    assert(y >= 0 && y <= 2);
    int xIndex = 3 * x;
    int yIndex = 3 * y;

    box[0] = board[yIndex][xIndex];
    box[1] = board[yIndex][xIndex + 1];
    box[2] = board[yIndex][xIndex + 2];
    box[3] = board[yIndex + 1][xIndex];
    box[4] = board[yIndex + 1][xIndex + 1];
    box[5] = board[yIndex + 1][xIndex + 2];
    box[6] = board[yIndex + 2][xIndex];
    box[7] = board[yIndex + 2][xIndex + 1];
    box[8] = board[yIndex + 2][xIndex + 2];
    return box;
  }
};