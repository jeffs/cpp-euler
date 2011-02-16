/** @file factoring.hpp Supports factoring of numbers. */

#ifndef FACTORING_HPP
#define FACTORING_HPP

/// @cond
#include <cstdlib>          // uint64_t
#include <utility>          // pair
#include <vector>           // vector
/// @endcond

namespace factoring {

using std::uint64_t;

using pair_vector = std::vector<std::pair<uint64_t, uint64_t>>;

class prime_predicate {
    std::vector<bool> mutable m_cache;
  public:

    /** Returns true if `n` is prime. */
    bool operator()(int      n) const;
    bool operator()(uint64_t n) const;

    /** Not implemented; declared to avoid unintended implicit conversions. */
    template<typename T> bool operator()(T x) const;
};

/** Sets `*result` to `v + 1` bits, each true if its index is prime.  *Prime*
 * numbers are integers greater than 1 that are evenly divisible by only
 * themselves and 1.
 */
void identify_primes(std::vector<bool>* result, std::size_t v);

/** Adds to entries in `r` exponents for all prime factors of `n`.  For
 * example, if `n` is 18, adds 1 to `(*r)[2]` and 2 to `(*r)[3]`.
 */
/** Appends to `r` the prime factors of `n` with corresponding exponents. */
void prime_factor(pair_vector* r, uint64_t n);

/** Appends to `r` the prime factors of `n`.  Usage:
 * @code
 *     std::vector<uint64_t> ds;   // divisors
 *     prime_factor_unique(&ds, 600851475143ULL);
 * @endcode
 */
void prime_factor_unique(std::vector<uint64_t>* r, uint64_t n);

/** Appends to `r` all proper divisors of `n` (including 1), if `n > 1`. */
void find_proper_divisors(std::vector<uint64_t>* r, uint64_t n);

/** Returns the sum of all proper divisors of `n`, or 0 if `n < 2`. */
uint64_t sum_proper_divisors(uint64_t n);

}

#endif
