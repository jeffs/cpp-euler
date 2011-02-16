/** @file file_util.hpp Supports interaction with filesystems. */

#ifndef INCLUDED_FILE_UTIL
#define INCLUDED_FILE_UTIL

/// @cond
#include <boost/algorithm/string/classification.hpp>    // is_any_of
#include <boost/algorithm/string/constants.hpp>         // token_compress_on
#include <boost/algorithm/string/split.hpp>             // split

#include <fstream>  // ifstream
#include <string>   // string
#include <deque>    // deque
/// @endcond

namespace file_util {

/** Loads quoted, comma-separated words from `file` into `r`. */
void slurp_words(std::deque<std::string>* r, std::string const& file);

}

#endif
