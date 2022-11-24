#include <memory>

#include "Solution.h"
int main() {
    std::unique_ptr<Solution> ptr(std::make_unique<Solution>());
    std::vector<int> input{1, 2, 3, 4};
    std::vector<int> actualResult(ptr->runningSum(input));

    return 0;
}