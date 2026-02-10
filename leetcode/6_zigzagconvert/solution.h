#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
So I solved this using this multiple for loop way, but looking at how others have solved it, 
it seems the control flow setting a toggle for going up vs down is more effecient, my brain just didn't work that way 
*/

class Solution {
public:
      string convert(string s, int numRows) {
        // one vector for each row
        
        // loop is something like:
        // add a letter to each vector at the current index
        // from the second last to second first insert the next letters
        // probably something modulo?
        // then finally, read back each row in order
        int lengthS = s.size();
        vector<string> letterRows(numRows, "");
        int i = 0;
        while (i < s.size()) {
            for (int j = 0; j < numRows && i < s.size(); j++) {
                letterRows[j].push_back(s[i++]);
            }
                for (int j = numRows - 2; j > 0 && i < s.size(); j--) {
                    letterRows[j].push_back(s[i++]);
                }
            }
        string finalString = "";
            for (int j = 0; j < numRows; j++) {
                cout << letterRows[j].data() << endl;
                finalString.append(letterRows[j].data());
            }
        return finalString;
    }
};