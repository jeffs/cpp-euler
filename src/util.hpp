#ifndef INCLUDED_UTIL
#define INCLUDED_UTIL

/// @cond
#include <ostream>          // ostream
#include <unordered_map>    // unordered_map
#include <vector>           // vector
/// @endcond

namespace util {

template<typename K, typename V>
std::ostream& operator<<(std::ostream& out, std::vector<std::pair<K, V>> const& kvs)
{
    out << '{';
    if (!kvs.empty()) {
        auto i = kvs.begin(), e = kvs.end();
        out << i->first << ": " << i->second;
        while (++i != e)
            out << ", " << i->first << ": " << i->second;
    }
    return out << '}';
}

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> const& xs)
{
    out << '{';
    if (!xs.empty()) {
        auto i = xs.begin(), e = xs.end();
        out << *i;
        while (++i != e)
            out << ", " << *i;
    }
    return out << '}';
}


template<typename K, typename V>
std::ostream& operator<<(std::ostream& out, std::unordered_map<K, V> const& kvs)
{
    typedef std::pair<K, V> pair_t;
    std::vector<pair_t> xs(kvs.begin(), kvs.end());
    std::sort(xs.begin(), xs.end(), [](pair_t const& a, pair_t const& b) {
            return a.first < b.first;
    });
    return out << xs;
}

}

#endif
