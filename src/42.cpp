/** @file 42.cpp Problem 42: Coded triangle numbers
 *
 * The nth term of the sequence of triangle numbers is given by, tn = (1/2)n(n+1);
 * so the first ten triangle numbers are:
 *
 *      1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * By converting each letter in a word to a number corresponding to its
 * alphabetical position and adding these values we form a word value. For
 * example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word
 * value is a triangle number then we shall call the word a triangle word.
 *
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file
 * containing nearly two-thousand common English words, how many are triangle
 * words?
 */

#include "file_util.hpp"    // slurp_words
#include "monotonic.hpp"    // triangular_set

/// @cond
#include <cassert>          // assert
#include <deque>            // deque
#include <iostream>         // cout
#include <string>           // string
/// @endcond

int evaluate(std::string const& word)
{
    int r = 0;
    for (char c : word)
        r += c - 'A' + 1;
    return r;
}

int main()
{
    monotonic::triangular_set<int> triangular;
    assert(triangular[evaluate("SKY")]);

    std::deque<std::string> words;
    file_util::slurp_words(&words, "../etc/p042_words.txt");

    int r = 0;
    for (auto const& word : words) {
        if (triangular[evaluate(word)])
            ++r;
    }
    std::cout << r << '\n';
}
