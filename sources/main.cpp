#include <fmt/format.h>

#include <memory>

#include "Solution.h"
int main() {
    std::unique_ptr<Solution> ptr(std::make_unique<Solution>());
    std::vector<int> nums{3, 3};
    int target(6);
    std::vector<int> actualResult(ptr->twoSum(nums, target));
    for (auto i : actualResult) {
        fmt::print("{}\n", i);
    }
    return 0;
}