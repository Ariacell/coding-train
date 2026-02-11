#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, 0, r, c)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word,
             int index, int r, int c) {

        if (index == word.size()) {
            return true;
        }

        if (r < 0 || c < 0 ||
            r >= board.size() || c >= board[0].size() ||
            board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found =
            dfs(board, word, index + 1, r + 1, c) ||
            dfs(board, word, index + 1, r - 1, c) ||
            dfs(board, word, index + 1, r, c + 1) ||
            dfs(board, word, index + 1, r, c - 1);

        board[r][c] = temp;

        return found;
    }
};
