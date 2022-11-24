#include <fmt/format.h>

#include <memory>

#include "Solution.h"
int main() {
    std::unique_ptr<Solution> ptr(std::make_unique<Solution>());
    int input(19);
    bool actualResult(ptr->isHappy(input));
    fmt::print("{}\n", actualResult);
    return 0;
}