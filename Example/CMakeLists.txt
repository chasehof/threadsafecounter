add_executable(Example ExampleUsage.cpp)

target_include_directories(Example PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(Example PRIVATE ThreadSafeCounter)