# ThreadSafeCounter

A modern C++ header-only library implementing a thread-safe counter using contemporary C++ utilities like `std::mutex` and `std::scoped_lock`.

## Overview

`ThreadSafeCounter` is a template-based counter class that provides thread-safe increment, decrement, get, and reset operations. It leverages modern C++ features to ensure safe concurrent access from multiple threads without data races.

### Features

- **Thread-Safe Operations**: All operations are protected by mutex locks
- **Customizable Mutex**: Template parameter allows using different mutex types
- **Header-Only**: Easy integration into any C++ project (C++20 or later)
- **Standard Library Only**: No external dependencies beyond the C++ standard library

## Building

### Prerequisites

- CMake 3.15 or higher
- A C++20 compatible compiler (GCC, Clang, MSVC, etc.)
- Threading support (pthread on Unix-like systems)

### Build Instructions

```bash
# Clone or navigate to the project directory
cd ThreadSafeCounter

# Create a build directory
mkdir build && cd build

# Configure the project
cmake ..

# Build the example
make

# Run the example
./Example
```

Optionally, you can specify the number of iterations as a command-line argument:

```bash
./Example 5000000
```

## Usage

```cpp
#include <ThreadSafeCounter.h>

// Create a counter
ThreadSafeCounter<> counter;

// Use in multiple threads
std::jthread worker([&counter] {
    for(int i = 0; i < 1000; i++) {
        counter.increment();
    }
});

// Access the value safely
int value = counter.get();

// Other operations
counter.decrement();
counter.reset();
```

## API

- `void increment()` - Safely increment the counter by 1
- `void decrement()` - Safely decrement the counter by 1
- `int get()` - Safely retrieve the current counter value
- `void reset()` - Safely reset the counter to 0

## Example

The included example demonstrates thread safety by:
1. Running two threads that both increment a `ThreadSafeCounter` one million times each
2. Running two regular threads that increment a non-thread-safe counter for comparison
3. Displaying the results to show the importance of thread safety

## License

See LICENSE file for details.
