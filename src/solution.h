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

    template<typename CollectionType>
    static void quick_sort(CollectionType &coll) {
        quick_sort(coll.begin(), coll.end());
    }
};

#endif // DINO_SOURCE_QUICK_SORT_H
