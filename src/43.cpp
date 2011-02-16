/** @file 43.cpp Problem 43: Sub-string divisibility
 *
 * The number, 1406357289, is a 0 to 9 pandigital number because it is made up
 * of each of the digits 0 to 9 in some order, but it also has a rather
 * interesting sub-string divisibility property.
 *
 * Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we
 * note the following:
 *
 *      d2d3d4=406 is divisible by 2
 *      d3d4d5=063 is divisible by 3
 *      d4d5d6=635 is divisible by 5
 *      d5d6d7=357 is divisible by 7
 *      d6d7d8=572 is divisible by 11
 *      d7d8d9=728 is divisible by 13
 *      d8d9d10=289 is divisible by 17
 *
 * Find the sum of all 0 to 9 pandigital numbers with this property.
 */

/// @cond
#include <cassert>  // assert
#include <cstdint>  // uint64_t
#include <iostream> // cout
#include <string>   // stoi, stoull, string
/// @endcond

using std::uint64_t;

bool predicate(std::string const& s)
{
    return stoi(s.substr(1, 3)) %  2 == 0
        && stoi(s.substr(2, 3)) %  3 == 0
        && stoi(s.substr(3, 3)) %  5 == 0
        && stoi(s.substr(4, 3)) %  7 == 0
        && stoi(s.substr(5, 3)) % 11 == 0
        && stoi(s.substr(6, 3)) % 13 == 0
        && stoi(s.substr(7, 3)) % 17 == 0;
}

int main()
{
    assert(predicate("1406357289"));

    uint64_t r = 0;
    std::string digits = "0123456789";
    for (int i = 3628800; i--;) {       // Check each of 10! permutations.
        if (predicate(digits))
            r += stoull(digits);
        std::next_permutation(begin(digits), end(digits));
    }
    std::cout << r << '\n';
}
