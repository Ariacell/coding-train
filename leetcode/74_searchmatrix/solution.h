#include <vector>

using namespace std;

class Solution {
	public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> flattenedList = {};
        for (auto v: matrix) {
            for (auto i : v)
            flattenedList.push_back(i);
        }

        bool found = false;
        vector searchList = flattenedList;
        while (!found && searchList.size() > 1) {
            // for (auto i : searchList) {

            // cout<<(i)<<endl;
            // }

            int halfSize = searchList.size()/2 + (searchList.size() % 2);
            int mid = searchList[halfSize];
            // cout<<mid<<endl;
            if (mid == target) {
                return true;
            }
            if (mid > target) {
                searchList = vector(searchList.begin(), searchList.begin() + halfSize);
            } else {
                searchList = vector(searchList.begin()  + halfSize, searchList.end());
            }
        }

        if (searchList.size() == 1 && searchList[0] == target) return true;

        return false;
    }
};
