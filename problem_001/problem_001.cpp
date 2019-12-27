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

constexpr int upper_limit(int p,int n)
{
    int result = n/p;
    return result;
}

constexpr long long arithmethic_sum_p(int p, int upper_limit)
{
    return upper_limit * ((1+upper_limit)/2) * p;
}

int main()
{
    auto start_tick = Clock::now();

    // calculate the p sum of 3 to get all multiples of 3
    long long p_sum_3 = arithmethic_sum_p(3,upper_limit(3,1000));

    // all multiples of 5
    long long p_sum_5 = arithmethic_sum_p(5,upper_limit(5,1000));

    // all multiples of both 3 and 5
    long long p_sum_15 = arithmethic_sum_p(15,upper_limit(15,1000));

    // subtract the common 15 multiples and subtract 1000 since multiples need to be below 1000
    long long p_sum_3_5 = p_sum_3 + p_sum_5 - p_sum_15 - 1000;

    auto end_tick = Clock::now();

    std::cout << "solution to problem 001: " << p_sum_3_5 << std::endl;
    std::cout << "Delta t2-t1: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end_tick - start_tick).count()
              << " nanoseconds" << std::endl;

    return 0;
}