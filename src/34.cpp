/** @file 34.cpp Problem 34: Digit factorials
 *
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are equal to the sum of the factorial of
 * their digits.
 *
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <iostream> // cout

int const factorial[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int sum(int n)
{
    int r = 0;
    for (; n; n /= 10)
        r += factorial[n % 10];
    return r;
}

int main()
{
    // So as it turns out, we don't need to check 8-digit numbers or longer.
    // The sum of factorials is upper-bounded at 9! * d, where d is the number
    // of digits, whereas the number itself is lower-bounded at pow(10, d - 1)
    // - 1. For d >= 8, there is no overlap.  This is the same principal
    // applied in problem 30; since the per-digit values are bounded (albeit to
    // large numbers), the sum grows only linearly with the number of digits,
    // whereas the minimum value grows exponentially.

    int r = 0;
    for (int i = 3; i < 10'000'000; ++i) {
        if (sum(i) == i)
            r += i;
    }
    std::cout << r << std::endl;
}
