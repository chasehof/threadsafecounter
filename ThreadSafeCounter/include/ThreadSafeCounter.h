#include <mutex>

/**
 * @brief A thread-safe counter using modern C++ synchronization primitives.
 *
 * ThreadSafeCounter provides a template-based counter that ensures thread-safe
 * access through the use of mutex locks. All operations (increment, decrement,
 * get, reset) are atomic with respect to concurrent access.
 *
 * @tparam MutexType The type of mutex to use for synchronization. Defaults to
 *                   std::mutex but can be customized with other mutex types
 *                   like std::recursive_mutex or std::timed_mutex.
 *
 * @note This class requires C++20 or later for std::scoped_lock support.
 *
 * @example
 * @code
 * ThreadSafeCounter<> counter;
 * std::jthread worker([&counter] {
 *     for (int i = 0; i < 1000; ++i) {
 *         counter.increment();
 *     }
 * });
 * int value = counter.get();
 * @endcode
 */
template <typename MutexType = std::mutex>
class ThreadSafeCounter {

    public:
    
    /**
     * @brief Safely increments the counter by one.
     *
     * This operation acquires a lock on the internal mutex, increments the
     * counter, and then releases the lock. The operation is thread-safe and
     * will not lose updates due to concurrent access.
     *
     * @thread_safety Thread-safe. Can be safely called from multiple threads
     *                 simultaneously without external synchronization.
     */
    void increment(){
        std::scoped_lock lock(mtx_);
        count_++;
    }

    /**
     * @brief Safely decrements the counter by one.
     *
     * This operation acquires a lock on the internal mutex, decrements the
     * counter, and then releases the lock. The operation is thread-safe and
     * will not lose updates due to concurrent access.
     *
     * @thread_safety Thread-safe. Can be safely called from multiple threads
     *                 simultaneously without external synchronization.
     */
    void decrement(){
        std::scoped_lock lock(mtx_);
        count_--;
    }

    /**
     * @brief Safely retrieves the current value of the counter.
     *
     * This operation acquires a lock on the internal mutex, reads the counter
     * value, and then releases the lock. The operation is thread-safe and
     * guarantees a consistent view of the counter value at the time of the call.
     *
     * @return The current value of the counter.
     *
     * @thread_safety Thread-safe. Can be safely called from multiple threads
     *                 simultaneously without external synchronization.
     */
    int get(){
        std::scoped_lock lock(mtx_);
        return count_;
    }

    /**
     * @brief Safely resets the counter to zero.
     *
     * This operation acquires a lock on the internal mutex, sets the counter
     * to zero, and then releases the lock. The operation is thread-safe and
     * will not be interrupted by concurrent access.
     *
     * @thread_safety Thread-safe. Can be safely called from multiple threads
     *                 simultaneously without external synchronization.
     */
    void reset(){
        std::scoped_lock lock(mtx_);
        count_ = 0;
    }

    private:

    MutexType mtx_;           ///< Internal mutex for synchronization.
    int count_{};             ///< The actual counter value, initialized to 0.

};