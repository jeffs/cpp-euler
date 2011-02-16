/** @file file_util.cpp Implements the corresponding header interface. */

#include "file_util.hpp"

void file_util::slurp_words(std::deque<std::string>* r, std::string const& file)
{
    std::string text;
    {
        std::ifstream in(file);
        if (!in)
            throw std::runtime_error("cannot read file: " + file);
        for (std::string s; in >> s;)
            text += " " + s;
    }
    auto sep = boost::is_any_of(", \"");
    boost::split(*r, text, sep, boost::token_compress_on);
    r->pop_front();
    r->pop_back();
}

