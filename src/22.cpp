/** @file 22.cpp Problem 22: Names scores
 *
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
 * containing over five-thousand first names, begin by sorting it into
 * alphabetical order. Then working out the alphabetical value for each name,
 * multiply this value by its alphabetical position in the list to obtain a
 * name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which
 * is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
 * would obtain a score of 938 x 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */

#include "file_util.hpp"    // slurp_words

/// @cond
#include <cassert>      // assert
#include <cstdint>      // uint64_t
#include <fstream>      // ifstream
#include <iostream>     // cout
#include <deque>        // deque
/// @endcond

using std::uint64_t;

int main()
{
    std::deque<std::string> names;
    file_util::slurp_words(&names, "../etc/p022_names.txt");
    std::sort(names.begin(), names.end());

    uint64_t r = 0;
    for (uint64_t i = 0; i < names.size();) {
        auto const& name = names[i++];
        uint64_t score = 0;
        for (char c : name)
            score += c - 'A' + 1;
        r += score * i;
    }
    std::cout << r << std::endl;
}
