/** @file 24.cpp Problem 24: Lexicographic permutations
 *
 * A permutation is an ordered arrangement of objects. For example, 3124 is one
 * possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
 * are listed numerically or alphabetically, we call it lexicographic order.
 * The lexicographic permutations of 0, 1 and 2 are:
 *
 *      012   021   102   120   201   210
 *
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
 * 5, 6, 7, 8 and 9?
 */

/// @cond
#include <algorithm>    // next_permutation
#include <cstdint>      // uint64_t
#include <iostream>     // cout
/// @endcond

int main()
{
    std::uint64_t xs[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for (auto n = 1'000'000; --n;)
        std::next_permutation(xs, xs + 10);

    for (auto x : xs)
        std::cout << x;
    std::cout << std::endl;
}
