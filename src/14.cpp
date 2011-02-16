/** @file 14.cpp Problem 14: Longest Collatz sequence
 *
 * The following iterative sequence is defined for the set of positive
 * integers:
 *
 *      n -> n/2 (n is even)
 *      n -> 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following
 * sequence:
 *
 *      13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1)
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it
 * is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

/// @cond
#include <cassert>          // assert
#include <cstdint>          // uint64_t
#include <iostream>         // cout
#include <unordered_map>    // unordered_map
/// @endcond

using std::uint64_t;

std::unordered_map<uint64_t, uint64_t> memo;

uint64_t step(uint64_t n)
{
    auto p = memo.find(n), e = memo.end();
    if (p == e)
        p = memo.emplace(n, n % 2 == 0 ? n / 2 : n * 3 + 1).first;
    return p->second;
}

uint64_t count(uint64_t n)
{
    uint64_t r = 1;
    for (; n != 1; ++r)
        n = step(n);
    return r;
}

int main()
{
    assert(count(13) == 10);

    uint64_t n = 0, z = 0;
    for (uint64_t i = 1; i < 1000000; ++i) {
        uint64_t c = count(i);
        if (c > z) {
            n = i;
            z = c;
        }
    }
    std::cout << n << '\n';
}
