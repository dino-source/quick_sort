#ifndef DINO_SOURCE_QUICK_SORT_H
#define DINO_SOURCE_QUICK_SORT_H

#include <iostream>
#include <iterator>
#include <algorithm>


template <typename CollectionType>
void print(CollectionType const &coll) {
    for (auto const &elem : coll) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

class Solution {
public:
    template<typename Iter>
    static void quick_sort(Iter begin, Iter end) {
        if (begin < end) {
            auto pivot {std::next(end, -1)};
            auto i {std::next(begin, -1)};

            for (auto j {begin}; j != end; ++j) {
                if (*j < *pivot) {
                    std::iter_swap(++i, j);
                }
            }
            std::iter_swap(++i, pivot);

            pivot = i;
            quick_sort(begin, pivot);
            quick_sort(std::next(pivot, 1), end);
        }
    }

    // This second overloaded version of quick_sort is optional.
    // The purpose of this version is to be able calling quick_sort
    // function with one argument only (a collection of elements).
    template<typename CollectionType>
    static void quick_sort(CollectionType &coll) {
        if (coll.begin() < coll.end()) {
            auto pivot {std::next(coll.end(), -1)};
            auto i {std::next(coll.begin(), -1)};

            for (auto j {coll.begin()}; j != coll.end(); ++j) {
                if (*j < *pivot) {
                    std::iter_swap(++i, j);
                }
            }
            std::iter_swap(++i, pivot);

            pivot = i;
            quick_sort(coll.begin(), pivot);
            quick_sort(std::next(pivot, 1), coll.end());
        }
    }
};

#endif // DINO_SOURCE_QUICK_SORT_H
