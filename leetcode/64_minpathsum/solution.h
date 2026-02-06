#include <vector>
using namespace std;

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int edgeSizeX = grid.size();
        int edgeSizeY = grid[0].size();
        vector<vector<int>> totalCellWeights(edgeSizeX, vector<int>(edgeSizeY, 0));

        //set up our initial 2 left and top columns to simplify bounds checking
        totalCellWeights[0][0] = grid[0][0];
        for (int i = 1; i < edgeSizeX; i++){
          totalCellWeights[i][0] = totalCellWeights[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < edgeSizeY; i++){
          totalCellWeights[0][i] = totalCellWeights[0][i-1] + grid[0][i];
        }

      for (int i = 1; i <edgeSizeX; i++){
        for (int j = 1; j <edgeSizeY; j++){
          totalCellWeights[i][j] = grid[i][j] + min(totalCellWeights[i-1][j], totalCellWeights[i][j-1]);
        }
        }
        return totalCellWeights[edgeSizeX-1][edgeSizeY-1];
    }
};