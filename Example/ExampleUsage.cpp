#include <iostream>
#include <ThreadSafeCounter.h>
#include <string>
#include <stdexcept>
#include <thread>



int main(int argc, char* argv[]) {

    long long iterations{1000000};

    if(argc > 2)
    {
        std::cerr << "You have entered more than one command argument which is not allowed" << '\n';
        return 1;
    }

    if(argc == 2)
    {
        try
        {
            iterations = std::stoull(argv[1]);

        }
        catch(std::invalid_argument)
        {
            std::cerr << "Invalid command line argument please enter a number" << '\n';
        }
        catch(std::out_of_range)
        {
            std::cerr << "Number out of bounds try again" << '\n';
        }

    }

    ThreadSafeCounter<> counter;
    {
        std::jthread thread1([&counter, &iterations] 
        {   
            for(int i = 0; i < iterations; i++){counter.increment();}

        }
    );
        std::jthread thread2([&counter, &iterations] 
        {   
            for(int i = 0; i < iterations; i++){counter.increment();}

        }
    );


    }

    std::cout << "Expected Value after thread safe iterations is: " << iterations * 2 << '\n';
    std::cout << "Acutal Value After thread safe iterations is: " << counter.get() << '\n';

    int not_thread_safe_count{0};

    {
        std::jthread thread1([&iterations, &not_thread_safe_count] 
        {   
            for(int i = 0; i <= iterations; i++){not_thread_safe_count++;}

        }
    );
        std::jthread thread2([&iterations, &not_thread_safe_count] 
        {   
            for(int i = 0; i <= iterations; i++){not_thread_safe_count++;}

        }
    );


    }


    std::cout << "Expected value after NON thread safe iterations is: " << iterations * 2 << '\n';
    std::cout << "Acutal value after NON thread safe iterations is: " << not_thread_safe_count << '\n';






    return 0;
}