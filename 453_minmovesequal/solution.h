#include <vector>
#include <numeric>
#include <ranges>
#include <algorithm>



class Solution {
 public:
    int minMoves(std::vector<int>& nums) {
        //Naive approach, runs in O(n^2)
        // if entries aren't equal, raise all entries that are not the highest by 1
        // int movesRequired= 0;
        // while (!isEqualEntries(nums))
        // {
        //     auto [ currentMaxIndex, currentMaxValue ] = getCurrentMaxIndexAndValue(nums);
        //     auto [ currentMinIndex, currentMinValue ] = getCurrentMinIndexAndValue(nums);
        //     int gap = smallestGap(currentMaxValue, currentMinValue, nums);
        //     for(size_t i = 0; i < nums.size(); i++)
        //     {
        //         if (i!=(size_t)currentMaxIndex) {
        //             nums[i] += gap;
        //         }
        //     }
        //     movesRequired += gap;
        // }
        // return movesRequired;

        // More optimised solution from research after the fact, runs in O(n)
        const int mn = std::ranges::min(nums);
        return std::accumulate(nums.begin(), nums.end(), 0,
                      [&](int acc, int num) { return acc + (num - mn); });
    }

 private:
    std::pair<int, int> getCurrentMaxIndexAndValue(std::vector<int>& nums) {
        int maxIndex = std::distance(nums.begin(),std::max_element(nums.begin(), nums.end()));
        return std::make_pair(maxIndex, nums[maxIndex]);
    }

    std::pair<int, int> getCurrentMinIndexAndValue(std::vector<int>& nums) {
        int minIndex = std::distance(nums.begin(),std::min_element(nums.begin(), nums.end()));
        return std::make_pair(minIndex, nums[minIndex]);
    }

    int smallestGap(int max, int min, std::vector<int>& nums) {
        int gap = max-min;
        for (auto i : nums) {
            if (i != max && max - i < gap) {
                gap = max - i;
            }
        }
        return gap;
    }

    bool isEqualEntries(std::vector<int>& nums) {
        int value = nums[0];
        for(auto i : nums) {
            if (i!=value) {
                return false;
            }
        }
        return true;
    }
};