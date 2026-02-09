#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // if (m == 1 || n == 1) {
        //     return 1;
        // }
        // return uniquePaths(m-1,n) + uniquePaths(m, n-1);
        vector<vector<int>> pathsToSquares(m, vector<int>(n,0));

        pathsToSquares[0][0] = 1;
        for (int i = 0; i < m; i++) {
            pathsToSquares[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            pathsToSquares[0][i] = 1;
        }
       for (int y = 1; y < m; y++) {
        for (int x = 1; x < n; x++) {
            int uniqueCount = 0;
            if (x > 0) {
                uniqueCount += pathsToSquares[y][x-1];
            }
            if (y > 0) {
                uniqueCount += pathsToSquares[y-1][x];
            }
            pathsToSquares[y][x] = uniqueCount;
        }
       }

       return pathsToSquares[m-1][n-1];
    }
};