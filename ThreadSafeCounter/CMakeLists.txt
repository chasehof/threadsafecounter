add_library(ThreadSafeCounter INTERFACE)

target_include_directories(ThreadSafeCounter
                INTERFACE
                ${CMAKE_CURRENT_SOURCE_DIR}/include)


find_package(Threads REQUIRED)
target_link_libraries(ThreadSafeCounter INTERFACE Threads::Threads)