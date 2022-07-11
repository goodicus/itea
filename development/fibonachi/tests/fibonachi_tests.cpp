#include "fibonachi.h"

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace asg::fibonachi::tests
{
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
// 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,

constexpr auto fib_10 {34};
constexpr auto fib_20 {4181};

constexpr auto iteration_10 {10};
constexpr auto iteration_20 {20};

TEST(Fibonachi, std_exchange)
{
    auto x {0};
    auto y {1};

    for(auto i {3}; i <= iteration_10; ++i)
    {
        x = std::exchange(y, y + x);
    }

    EXPECT_EQ(fib_10, y);
}

TEST(Fibonachi, lambda_with_std_exchange)
{
    auto l = [ x {0}, y {1} ]() mutable
    {
        x = std::exchange(y, y + x);
        return y;
    };

    auto fib_n {0};
    for(auto i {3}; i <= iteration_20; ++i)
    {
        fib_n = l();
    }

    EXPECT_EQ(fib_20, fib_n);
}
} // namespace asg::fibonachi::tests