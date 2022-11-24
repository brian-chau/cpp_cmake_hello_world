#include "Student.h"

#include <iostream>

Student::Student() {
}

Student::~Student() {
}

void Student::SayHi() {
    std::cout << "Hello World!" << std::endl;
}

int Student::ReturnOne() {
    return 1;
}