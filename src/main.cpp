#include <memory>

#include "Student.h"
int main() {
    std::unique_ptr<Student> ptr(std::make_unique<Student>());
    ptr->SayHi();
    return 0;
}