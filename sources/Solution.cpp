#include "Solution.h"

#include <iostream>

Solution::Solution() {
}

Solution::~Solution() {
}

std::vector<int> Solution::runningSum(std::vector<int>& nums) {
    std::vector<int> result;
    int sum(0);
    for (auto val : nums) {
        sum += val;
        result.push_back(sum);
    }
    return result;
}
