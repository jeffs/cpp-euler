/** @file 51.cpp Problem 51: Prime digit replacements
 *
 * By replacing the 1st digit of the 2-digit number *3, it turns out that six
 * of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
 *
 * By replacing the 3rd and 4th digits of 56**3 with the same digit, this
 * 5-digit number is the first example having seven primes among the ten
 * generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663,
 * 56773, and 56993. Consequently 56003, being the first member of this family,
 * is the smallest prime with this property.
 *
 * Find the smallest prime which, by replacing part of the number (not
 * necessarily adjacent digits) with the same digit, is part of an eight prime
 * value family.
 */

//  for each length n
//      for each quantity q from 1 to n
//          for each of the (n choose d) selections of columns
//              count the primes in the family

//  r = 56003
//  while !has_property(r):
//      r = next_prime(r)
//  print(r)

/// @cond
#include <cstdint>  // uint64_t
#include <iostream> // cout, endl
/// @endcond

using std::uint64_t;

bool prime(uint64_t n)
{
    if (n % 2 == 0 && n != 2)
        return false;
    for (uint64_t i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
}

/** Returns the first prime strictly greater than `n`. */
uint64_t next_prime(uint64_t n)
{
    if (n == 2)
        return 3;
    for (n += n % 2 ? 2 : 1; !prime(n); n += 2)
        ;
    return n;
}

uint64_t length(uint64_t n)
{
    uint64_t r = 1;
    while (n /= 10)
        ++r;
    return r;
}

auto each_subset = [](uint64_t bits, auto f) {
    uint64_t e = 1 << bits;
    uint64_t m = 1; // mask
    while (m < e)
        f(m);
};

bool match(uint64_t n)
{
    // for each length
    //      for each subset s of columns (excluding last)
    //          count = 0
    //          for each digit value 0 - 9
    //              if prime[replace(n, s, d)]
    //                  ++count
    //          if count > 7:
    //              return true
    //      return false
}

int main()
{
    std::uint64_t r = 56003;
    while (!match(r))
        r = next_prime(r);
    std::cout << r << std::endl;
}
