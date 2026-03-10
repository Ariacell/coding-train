#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return solve(s1, s2, s3, 0,0,0);
    }

    bool solve(string s1, string s2, string s3, int i1, int i2, int i3) {
        if (i3 == s3.size()-1 || s3.size() == 0) {
            return true;
        }

        if(s1[i1] == s3[i3]) {
            return solve(s1,s2,s3,i1+1,i2,i3+1);
        }
        
        if(s2[i2] == s3[i3]) {
            return solve(s1,s2,s3,i1,i2+1,i3+1);
        }
        //dead end, bail out and hope there's another way
        return false;
    }

    // The actual better way, using a dynamic table (reduced to a single row in this function)
    // basically work through each row and column of a truth table, where each cell says whether we would have been able
    // to arrive at that combination of characters via a valid combination of s1+s2 characters
    bool solve_dynamic(string s1, string s2, string s3) {
        // If lengths don't match, return false
        if (s1.size() + s2.size() != s3.size())
            return false;

        int n = s1.size(), m = s2.size();

        // Two rows for DP
        vector<bool> prev(m + 1, false), curr(m + 1, false);

        // Base case
        prev[0] = true;

        // Fill first row (s1 empty)
        for (int j = 1; j <= m; ++j)
            prev[j] = prev[j - 1] && (s2[j - 1] == s3[j - 1]);

        // Fill the DP rows
        for (int i = 1; i <= n; ++i)
        {
            // first column
            curr[0] = prev[0] && (s1[i - 1] == s3[i - 1]); 

            for (int j = 1; j <= m; ++j)
            {
                int k = i + j;
                curr[j] = (prev[j] && s1[i - 1] == s3[k - 1]) || 
                (curr[j - 1] && s2[j - 1] == s3[k - 1]);
            }
            
            // move current row to previous
            prev = curr;
        }

        return prev[m];
    }
};