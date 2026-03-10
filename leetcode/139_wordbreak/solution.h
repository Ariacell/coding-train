#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        auto next_word_index = [wordDict](string& sub) {
            for(int i = 0; i < wordDict.size()-1; i++) {
                if(sub.compare(0, wordDict[i].size()-1, wordDict[i]) == 0) {
                    return i;
                }
            }
            return -1;
        };
        int string_index = 0;
        while (string_index < s.size()) {
            auto next_str = s.substr(string_index);
            if(int i = next_word_index(next_str)) {
                string_index += wordDict[i].size();
            } else {
                return false;
            }
        }
        return true;

    }

    bool wordBreakDynamic(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};