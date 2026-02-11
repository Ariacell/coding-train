#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


/* 
Notes for myself:
 I naturally tend towards BFS I think generally in the way I write algorithms, need to be on the lookout 
 for when it's time to use DFS, and also get more used to writing backtracking algorithms - do NQueens next?
 see DFS version alongside this file.
*/



using namespace std;

struct Cell {
    int x;
    int y;
};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //first need to find a valid starting square
        // then for each subsequent square, need to confirm it's a valid connection to the parent, and not already used -> track used indices? switch used cell temporarily to "."?
        // if we hit the last letter of the target word, return true
        // if we fail, continue on to the next possible starting square -> feels queue-y?
        bool solved = false;
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[x].size(); y++) {
                if (board[x][y] == word[0]) {
                    Cell c = {.x = x, .y = y};
                    vector<vector<char>> newBoard = board;
                    newBoard[x][y] = '.';
                    solved = solve_next(newBoard, word.substr(1), c);
                }
                if (solved) {
                    return true;
                }
            }
        }
        return solved;


    }
    bool solve_next(vector<vector<char>>& board, string word, Cell current_cell) {
        if (word.size() <= 0) {
            return true;
        }
        cout << "trying to solve at cell " << current_cell.x << current_cell.y << word[0] << endl;
        int x = current_cell.x;
        int y = current_cell.y;
        vector<Cell> nextPossibleCells = {};
        if (x >= 1 && board[x-1][y] == word[0]) {
            vector<vector<char>> newBoard = board;
            Cell c = {.x = x-1, .y = y};
            nextPossibleCells.push_back(c);
        }
        if (y > 0 && board[x][y-1] == word[0]) {
            vector<vector<char>> newBoard = board;
            Cell c = {.x = x, .y = y-1};
            nextPossibleCells.push_back(c);
        }

        if (x < board.size()-1 && board[x+1][y] == word[0]) {
            vector<vector<char>> newBoard = board;
            Cell c = {.x = x+1, .y = y};
            nextPossibleCells.push_back(c);
        }
        if (y < board[x].size()-1 && board[x][y+1] == word[0]) {
            Cell c = {.x = x, .y = y+1};
            nextPossibleCells.push_back(c);
        }

        return std::any_of(
            nextPossibleCells.begin(),
            nextPossibleCells.end(),
            [&](const Cell& cell) {
                vector<vector<char>> newBoard = board;
                newBoard[cell.x][cell.y] = '.';
                return solve_next(newBoard, word.substr(1), cell);
            }
        );
    }
};