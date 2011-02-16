/** @file 18.cpp Problem 18: Maximum path sum I
 *
 * By starting at the top of the triangle below and moving to adjacent numbers
 * on the row below, the maximum total from top to bottom is 23.
 *
 *      3
 *      7 4
 *      2 4 6
 *      8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 *
 *      75
 *      95 64
 *      17 47 82
 *      18 35 87 10
 *      20 04 82 47 65
 *      19 01 23 75 03 34
 *      88 02 77 73 07 63 67
 *      99 65 04 28 06 16 70 92
 *      41 41 26 56 83 40 80 70 33
 *      41 48 72 33 47 32 37 16 94 29
 *      53 71 44 65 25 43 91 52 97 51 14
 *      70 11 33 28 77 73 17 78 39 68 17 57
 *      91 71 52 38 17 14 91 43 58 50 27 29 48
 *      63 66 04 68 89 53 67 30 73 16 69 87 40 31
 *      04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 *
 * NOTE: As there are only 16384 routes, it is possible to solve this problem
 * by trying every route. However, Problem 67, is the same challenge with a
 * triangle containing one-hundred rows; it cannot be solved by brute force,
 * and requires a clever method! ;o)
 */

/// @cond
#include <boost/graph/adjacency_list.hpp>           // adjacency_list
#include <boost/graph/dijkstra_shortest_paths.hpp>  // dijkstra_shortest_paths

#include <algorithm>    // max_element
#include <iostream>     // cout
#include <vector>       // vector
/// @endcond

template<int N>
int max(int const (&triangle)[N])
{
    // Treat the triangle as a directed graph having a node for each number,
    // with the number corresponding to the weight of an edge entering the
    // node.  The graph additionally has a start node, so that just getting to
    // the top of the triangle incurs the cost of the first weight.
    //
    // The edge weights are not actually the input numbers, but the differences
    // between those numbers and their max value, so that the Boost shortest-
    // path algorithm is tricked into find the longest path,

    boost::adjacency_list<
        boost::listS,                       // store edges in lists
        boost::vecS,                        // store nodes in a vector
        boost::directedS,                   // edges go only one way
        boost::no_property,                 // nodes are not decorated
        boost::property<                    // edges have
            boost::edge_weight_t,           //  weights
            int                             //  represented by ints
        >
    > graph(N + 1);                         // triangle nodes and start node

    int big = *std::max_element(triangle, triangle + N);
    add_edge(0, 1, big - triangle[0], graph);    // from start node to triangle top

    int n = 0;  // triangle nodes traversed so far
    int i = 1;  // length of current row
    for (; n < N; n += i++) {
        for (int c = 0; c < i; ++c) {       // index within column
            int k = n + c;                  // index within triangle
            int lc = k + i, rc = lc + 1;    // left and right child indexes
            if (lc < N) {
                add_edge(k + 1, lc + 1, big - triangle[lc], graph);
                add_edge(k + 1, rc + 1, big - triangle[rc], graph);
            }
        }
    }

    auto start = *vertices(graph).first;
    std::vector<int> distance(num_vertices(graph));
    dijkstra_shortest_paths(
            graph,
            start,
            boost::distance_map(distance.data()));

    int r = 0;
    auto nodes = vertices(graph);
    for(auto p = nodes.first + (N + 2 - i); p != nodes.second; ++p) {
        int d = (i - 1) * big - distance[*p];
        if (d > r)
            r = d;
    }
    return r;
}

int main()
{
    int triangle1[] = {
      3,
      7, 4,
      2, 4, 6,
      8, 5, 9, 3
    };
    assert(max(triangle1) == 23);

    int triangle2[] = {
        75,
        95, 64,
        17, 47, 82,
        18, 35, 87, 10,
        20,  4, 82, 47, 65,
        19,  1, 23, 75,  3, 34,
        88,  2, 77, 73,  7, 63, 67,
        99, 65,  4, 28,  6, 16, 70, 92,
        41, 41, 26, 56, 83, 40, 80, 70, 33,
        41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
        53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
        70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
        91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
        63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
         4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23
    };
    std::cout << max(triangle2) << std::endl;
}
