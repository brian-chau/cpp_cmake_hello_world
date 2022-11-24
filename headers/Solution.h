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
};
#endif