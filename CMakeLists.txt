cmake_minimum_required(VERSION 3.15)
project(ThreadSafeCounterLib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only library interface
add_library(ThreadSafeCounter INTERFACE)

target_include_directories(ThreadSafeCounter
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/ThreadSafeCounter/include)

find_package(Threads REQUIRED)
target_link_libraries(ThreadSafeCounter INTERFACE Threads::Threads)

# Build example executable directly in build folder
add_executable(Example Example/ExampleUsage.cpp)
target_include_directories(Example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ThreadSafeCounter/include)
target_link_libraries(Example PRIVATE ThreadSafeCounter)