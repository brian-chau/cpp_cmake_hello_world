#include <memory>
#include <semaphore>

#include "Student.h"
int main() {
    std::unique_ptr<Student> ptr(std::make_unique<Student>());
    std::binary_semaphore a{1};
    // Uncomment this to verify that the compiler flags are enabled properly
    // int b(0), c(0), d(0);
    ptr->SayHi();
    return 0;
}