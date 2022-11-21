#Source: http://derekmolloy.ie/hello-world-introductions-to-cmake/
cmake_minimum_required(VERSION 3.22)
project(helloworld)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

#Bring the headers, such as Student.h into the project
include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

# add_executable(<exe_name> <folder_w_src_code>)
add_executable(exe ${SOURCES})

link_directories(${CMAKE_SOURCE_DIR}/lib)

# this means that under the ./lib folder, there are the libfoo.so and libbar.so files
# target_link_libraries(foo bar)