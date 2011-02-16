/** @file factoring.cpp Implements the corresponding header interface. */

#include "factoring.hpp"

#include "int_util.hpp"

/// @cond
#include <cassert>  // assert
#include <numeric>  // accumulate
/// @endcond

namespace factoring {

/** Increments the number represented by the second elements of the pairs in
 * `r` (lowest-order column first), where the base of each column is specified
 * by the second element of the corresponding pair in `tops`.  Returns true on
 * carry-out.
 */
static bool ripple_carry(pair_vector* r, pair_vector const& tops)
{
    assert(r->size() == tops.size());
    auto q = tops.begin();
    for (auto& kv : *r) {
        if (++kv.second <= q->second)
            return false;
        kv.second = 0;
        ++q;
    }
    return true;
}

}

bool factoring::prime_predicate::operator()(int n) const
{
    return n < 2 ? false : (*this)(static_cast<uint64_t>(n));
}

bool factoring::prime_predicate::operator()(uint64_t n) const
{
    uint64_t m = m_cache.size();
    if (m <= n) {
        m_cache.clear();
        identify_primes(&m_cache, n ? n * 2 : 1);
    }
    return m_cache[n];
}

void factoring::find_proper_divisors(std::vector<uint64_t>* r, uint64_t n)
{
    pair_vector tops, factors;
    prime_factor(&tops, n);

    factors.reserve(n);
    for (auto const& x : tops)
        factors.emplace_back(x.first, 0);

    r->push_back(1);
    while (!ripple_carry(&factors, tops)) {
        uint64_t d = 1;
        for (auto const& x : factors)
            d *= int_util::pow(x.first, x.second);
        r->push_back(d);
    }
    r->pop_back();  // n is not its own proper divisor
}

void factoring::identify_primes(std::vector<bool>* result, std::size_t v)
{
    auto& r = *result;
    auto  n = v + 1;
    if (n < 3) {
        r.assign(n, false);
    } else {
        r.assign(n, true);
        r[0] = r[1] = false;
        for (std::size_t i = 4; i < n; i += 2)
            r[i] = false;
        for (std::size_t i = 3; i * i <= n; i += 2) {
            for (std::size_t j = i * 2; j < n; j += i)
                r[j] = false;
        }
    }
}

void factoring::prime_factor(pair_vector* r, uint64_t n)
{
    for (uint64_t i = 2; i <= n; ++i) {
        if (n % i == 0) {
            uint64_t p = 0;
            do {
                ++p;
                n /= i;
            } while (n % i == 0);
            r->emplace_back(i, p);
        }
    }
}

void factoring::prime_factor_unique(std::vector<uint64_t>* r, uint64_t n)
{
    pair_vector p;
    prime_factor(&p, n);
    for (auto const& kv : p)
        r->push_back(kv.first);
}

/** Returns the sum of all proper divisors of `n`.  Note that the result is 0
 * if `n < 2`.
 */
uint64_t factoring::sum_proper_divisors(uint64_t n)
{
    std::vector<uint64_t> ds;
    find_proper_divisors(&ds, n);
    return std::accumulate(ds.begin(), ds.end(), 0);
}
