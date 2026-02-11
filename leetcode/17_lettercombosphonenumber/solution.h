#include <vector>
#include <string>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]

map<char, vector<char>> numpadMap = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d','e','f'}},
    {'4', {'g','h','i'}},
    {'5', {'j','k','l'}},
    {'6', {'m','n','o'}},
    {'7', {'p','q','r','s'}},
    {'8', {'t','u','v'}},
    {'9', {'w','x','y','z'}},
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //use a tree? for every number, add each possible letter outcome as a leaf?
        // might be better as a dynamically updated list though, updating the list each time and growing with the possibilities directly?
      
        vector<string> possibleStrings = {};
        vector<string> seedStrings = {};

        vector<string> combinations{""};
        for (char digit : digits) {
            vector<string> next;
            for (string s : combinations) {
                for (char c : numpadMap[digit]) {
                    next.push_back(s + c);
                }
            }
            combinations = next;
        }
        return combinations;
    }
};