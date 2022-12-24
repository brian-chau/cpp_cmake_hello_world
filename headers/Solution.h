#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>

class Solution {
public:
    Solution();
    ~Solution();
    std::vector<int> runningSum(std::vector<int>& nums);
    int pivotIndex(std::vector<int>& nums);
    bool isHappy(int n);
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<int> answerQueries(std::vector<int>& nums, std::vector<int>& queries);
};
#endif