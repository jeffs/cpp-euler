/** @file 17.cpp Problem 17: Number letter counts
 *
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 * letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 */

/// @cond
#include <cassert>  // assert
#include <iostream> // cout
/// @endcond

int const ones[] = {
    0,  // zero is not explicitly written
    sizeof( "one"   ) - 1,
    sizeof( "two"   ) - 1,
    sizeof( "three" ) - 1,
    sizeof( "four"  ) - 1,
    sizeof( "five"  ) - 1,
    sizeof( "six"   ) - 1,
    sizeof( "seven" ) - 1,
    sizeof( "eight" ) - 1,
    sizeof( "nine"  ) - 1
};

int const teens[] = {
    sizeof( "ten"       ) - 1,
    sizeof( "eleven"    ) - 1,
    sizeof( "twelve"    ) - 1,
    sizeof( "thirteen"  ) - 1,
    sizeof( "fourteen"  ) - 1,
    sizeof( "fifteen"   ) - 1,
    sizeof( "sixteen"   ) - 1,
    sizeof( "seventeen" ) - 1,
    sizeof( "eighteen"  ) - 1,
    sizeof( "nineteen"  ) - 1
};

int const tens[] = {
    0,  // ones are defined separately
    0,  // teens are defined separately
    sizeof( "twenty" ) - 1,
    sizeof( "thirty" ) - 1,
    sizeof( "forty"  ) - 1,
    sizeof( "fifty"  ) - 1,
    sizeof( "sixty"  ) - 1,
    sizeof( "seventy") - 1,
    sizeof( "eighty" ) - 1,
    sizeof( "ninety" ) - 1
};

int const hundred       =           sizeof( "hundred"  ) - 1;
int const hundred_and   = hundred + sizeof( "and"      ) - 1;
int const thousand      =           sizeof( "thousand" ) - 1;

int count(int n)
{
    assert(n <= 1000);
    return n <   10 ? ones[n]
        :  n <   20 ? teens[n - 10]
        :  n <  100 ? tens[n / 10] + ones[n % 10]
        :  n < 1000 ? ones[n / 100] + (
                n % 100 == 0 ? hundred : hundred_and + count(n % 100))
        :  ones[1] + thousand;
}

int sum(int n)
{
    int r = 0;
    for (int i = 1; i <= n; ++i)
        r += count(i);
    return r;
}

int main()
{
    assert(count(342) == 23);
    assert(count(115) == 20);
    assert(sum(5) == 19);
    std::cout << sum(1000) << std::endl;
}
