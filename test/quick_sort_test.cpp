#include <gtest/gtest.h>
#include "../src/solution.h"

#include <vector>
#include <numeric>
#include <random>

namespace rng = std::ranges;

TEST(TestTopic, quick_sort_test1) {
    std::vector<int> nums {8, 2, 4, 7, 1, 3, 9, 6, 5};
    Solution::quick_sort(nums.begin(), nums.end());

    EXPECT_TRUE(rng::is_sorted(nums));
}

TEST(TestTopic, quick_sort_test2) {
    std::vector<int> nums {8, 2};
    Solution::quick_sort(nums.begin(), nums.end());

    EXPECT_TRUE(rng::is_sorted(nums));
}

TEST(TestTopic, quick_sort_test3) {
    std::vector<int> nums {8};
    Solution::quick_sort(nums.begin(), nums.end());

    EXPECT_TRUE(rng::is_sorted(nums));
}

TEST(TestTopic, quick_sort_test4) {
    std::vector<int> nums;
    Solution::quick_sort(nums.begin(), nums.end());

    EXPECT_TRUE(rng::is_sorted(nums));
}

// Caution: this test takes approx. 7.6 seconds to be completed
TEST(TestTopic, quick_sort_test5) {
    namespace rng = std::ranges;
    std::vector<int> nums(16'777'216); // 2^24
    std::iota(nums.begin(), nums.end(), -8'000'000);
    rng::shuffle(nums, std::mt19937 {std::random_device{}()});

    EXPECT_FALSE(rng::is_sorted(nums));

    Solution::quick_sort(nums.begin(), nums.end());

    EXPECT_TRUE(rng::is_sorted(nums));
}

TEST(TestTopic, quick_sort_test6) {
    std::vector<int> nums {8, 2, 4, 7, 1, 3, 9, 6, 5};
    Solution::quick_sort(nums);

    EXPECT_TRUE(rng::is_sorted(nums));
}

TEST(TestTopic, quick_sort_test7) {
    std::vector<int> nums {8, 2};
    Solution::quick_sort(nums);

    EXPECT_TRUE(rng::is_sorted(nums));
}

TEST(TestTopic, quick_sort_test8) {
    std::vector<int> nums {8};
    Solution::quick_sort(nums);

    EXPECT_TRUE(rng::is_sorted(nums));
}

TEST(TestTopic, quick_sort_test9) {
    std::vector<int> nums;
    Solution::quick_sort(nums);

    EXPECT_TRUE(rng::is_sorted(nums));
}

// Caution: this test takes approx. 7.6 seconds to be completed
TEST(TestTopic, quick_sort_test10) {
    std::vector<int> nums(16'777'216); // 2^24
    std::iota(nums.begin(), nums.end(), -8'000'000);
    rng::shuffle(nums, std::mt19937 {std::random_device{}()});

    EXPECT_FALSE(rng::is_sorted(nums));

    Solution::quick_sort(nums);

    EXPECT_TRUE(rng::is_sorted(nums));
}
