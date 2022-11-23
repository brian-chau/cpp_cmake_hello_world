#include <memory>
#include <semaphore>

#include "Student.h"
int main() {
    std::unique_ptr<Student> ptr(std::make_unique<Student>());
    std::binary_semaphore a{1};

    ptr->SayHi();
    return 0;
}