/** @file 19.cpp Problem 19: Counting Sundays
 *
 * You are given the following information, but you may prefer to do some research for yourself.
 *
 * * 1 Jan 1900 was a Monday.
 * * Thirty days has September,
 *   April, June and November.
 *   All the rest have thirty-one,
 *   Saving February alone,
 *   Which has twenty-eight, rain or shine.
 *   And on leap years, twenty-nine.
 * * A leap year occurs on any year evenly divisible by 4, but not on a century
 *   unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

/// @cond
#include <iostream> // cout
/// @endcond

enum day { sun, mon, tue, wed, thu, fri, sat };

enum month { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

int len(month m, int y)
{
    switch (m) {
      case jan: return 31;
      case feb: return y % 400 == 0 ? 29
              :        y % 100 == 0 ? 28
              :        y %   4 == 0 ? 29
              :        28;
      case mar: return 31;
      case apr: return 30;
      case may: return 31;
      case jun: return 30;
      case jul: return 31;
      case aug: return 31;
      case sep: return 30;
      case oct: return 31;
      case nov: return 30;
      case dec: return 31;
    }
}

int main()
{
    int   r = 0;
    int   d = 1;      // day of month
    month m = jan;
    int   y = 1900;
    day   w = mon;    // day of week
    while (y <= 2000) {
        if (y >= 1901 && d == 1 && w == sun)
            ++r;
        if (++d > len(m, y)) {  // next month
            d = 1;
            if (m == dec) {     // next year
                m = jan;
                ++y;
            } else {
                m = month(m + 1);
            }
        }
        w = day((w + 1) % 7);
    }
    std::cout << r << std::endl;
}
