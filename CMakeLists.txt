#Source: http://derekmolloy.ie/hello-world-introductions-to-cmake/
cmake_minimum_required(VERSION 3.22)

set(MY_EXE_NAME somethingoranother)
project("${MY_EXE_NAME}"
        DESCRIPTION "Hello world"
        LANGUAGES CXX)
set(CMAKE_C_COMPILER /usr/bin/gcc-12)
set(CMAKE_CXX_COMPILER /usr/bin/g++-12)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

# add_executable(<exe_name> <folder_w_src_code>)
add_executable("${MY_EXE_NAME}" ${SOURCES})

# Link libraries
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Link fmt
find_package(fmt)
target_link_libraries("${MY_EXE_NAME}" PRIVATE fmt::fmt)
target_compile_options ("${MY_EXE_NAME}" PRIVATE -Wall -Werror -O3 -fPIC -std=c++20 )

# this means that under the ./lib folder, there are the libfoo.so and libbar.so files
# target_link_libraries(foo bar)