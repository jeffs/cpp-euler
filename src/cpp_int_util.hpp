/** @file cpp_int_util.hpp Supports the use of Boost cpp_int. */

#ifndef INCLUDED_CPP_INT_UTIL
#define INCLUDED_CPP_INT_UTIL

/// @cond
#include <boost/multiprecision/cpp_int.hpp> // cpp_int

// TODO cassert
#include <algorithm>                        // count
#include <climits>                          // CHAR_MAX
#include <cstdlib>                          // size_t
#include <string>                           // string
/// @endcond

namespace cpp_int_util {

using boost::multiprecision::cpp_int;

/** STL-compatible hash functor for use with unordered containers. */
struct hash {
    std::size_t operator()(cpp_int const& n) const;
};

int sum_digits(cpp_int const& n);

}

inline
std::size_t cpp_int_util::hash::operator()(cpp_int const& n) const {
    return n.convert_to<std::size_t>();
}

template<>
struct std::hash<boost::multiprecision::cpp_int>: cpp_int_util::hash { };

#endif
