/** @file 31.cpp Problem 31: Coin sums
 *
 * In England the currency is made up of pound, #, and pence, p, and there are
 * eight coins in general circulation:
 *
 *      1p, 2p, 5p, 10p, 20p, 50p, 1# (100p) and 2# (200p).
 *
 * It is possible to make 2# in the following way:
 *
 *      1x1# + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p
 *
 * How many different ways can 2# be made using any number of coins?
 */

/// @cond
#include <iostream> // cout
/// @endcond

int vals[] = {200, 100, 50, 20, 10, 5, 2, 1, 0};

int f(int n, int* p)
{
    if (n == 0)
        return 1;
    int r = 0;
    if (*p) {
        for (int i = 0, v = *p, c = 200 / v, *q = p + 1; i <= c; ++i)
            r += f(n - i * v, q);
    }
    return r;
}


int main()
{
    std::cout<< f(200, vals) << std::endl;
}
