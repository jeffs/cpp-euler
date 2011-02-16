/** @file monotonic.hpp Supports analysis of monotonic sequences. */

#ifndef INCLUDED_MONOTONIC
#define INCLUDED_MONOTONIC

#include "cpp_int_util.hpp" // hash

/// @cond
#include <cassert>          // assert
#include <cstdint>          // uint64_t
#include <algorithm>        // all_of
#include <climits>          // CHAR_MAX
#include <string>           // string
#include <unordered_set>    // unordered_set
/// @endcond

/** Each sequence is represented by three class templates: A *set* for testing
 * membership (e.g., telling whether a number is triangular), a *seq* for
 * getting the nth element of a sequence, and a *src* for iterating over
 * sequence members.
 */
namespace monotonic {

using std::uint64_t;

/** Retrieves successive values of type `T` from a sequence of type `V`.
 *
 * @tparam T is an integer type
 * @tparam V is a monolithic *seq*
 */
template<typename T, typename V>
class shape_src {
    V m_v;
    T m_n = T();
  public:

    using value_type = T;

    T next() { return m_v[++m_n]; }
};

template<typename S>
struct set {
    using T = typename S::value_type;
  private:
    std::unordered_set<T> mutable m_set;
    S                     mutable m_src;
    T                     mutable m_max = T();
  public:
    bool operator[](T n) const;
};

#define MONOTONIC_DEFINE(name, expr)                \
    struct name##_seq {                             \
        template<typename T>                        \
        T operator[](T n) const { return expr; };   \
    };                                              \
                                                    \
    template<typename T>                            \
    using name##_src = shape_src<T, name##_seq>;    \
                                                    \
    template<typename T>                            \
    using name##_set = set<name##_src<T>>;

MONOTONIC_DEFINE(triangular, n * (n + 1) / 2)
MONOTONIC_DEFINE(pentagonal, n * (3 * n - 1) / 2)
MONOTONIC_DEFINE(hexagonal,  n * (2 * n - 1))

#undef MONOTONIC_DEFINE

}

template<typename S>
bool monotonic::set<S>::operator[](T n) const
{
    while (m_max < n)
        m_set.insert(m_max = m_src.next());
    return m_set.count(n);
}

#endif
