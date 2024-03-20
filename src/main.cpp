#include "solution.h"

#include <vector>
#include <numeric>
#include <random>


int main() {
    namespace rng = std::ranges;

    std::vector<int> nums(20);
    std::iota(nums.begin(), nums.end(), 10);
    print(nums);

    rng::shuffle(nums, std::mt19937 {std::random_device{}()});
    print(nums);

    Solution::quick_sort(nums);
    print(nums);
}
