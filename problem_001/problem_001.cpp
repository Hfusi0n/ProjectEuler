//
//
// Created by Or Groman on 12/27/19.
//
// Problem 1
// If we list all the natural numbers below 10 that are multiples of 3 or 5,
// we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.
//

#include <iostream>
#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

int main()
{
    auto start_tick = Clock::now();

    long long sum = 0;

    // find all multiples of 3 and 5
    for(int i=3; i<1000; ++i)
    {
        if(i%3 ==0 || i%5 == 0 )
        {
            sum = sum + i;
        }
    }

    auto end_tick = Clock::now();

    std::cout << "solution to problem 001: " << sum << std::endl;

    std::cout << "Delta t2-t1: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end_tick - start_tick).count()
              << " nanoseconds" << std::endl;

    return 0;
}