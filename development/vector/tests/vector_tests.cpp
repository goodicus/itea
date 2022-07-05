#include "vector.h"

#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace asg::tests
{
TEST(Constructor_and_size, Init_size_0)
{
    constexpr size_t init_size {0};

    vector<char> v_char(init_size);
    EXPECT_EQ(v_char.size(), init_size);

    vector<unsigned char> v_unsigned_char(init_size);
    EXPECT_EQ(v_unsigned_char.size(), init_size);

    vector<int> v_int(init_size);
    EXPECT_EQ(v_int.size(), init_size);

    vector<unsigned int> v_unsigned_int(init_size);
    EXPECT_EQ(v_unsigned_int.size(), init_size);

    vector<float> v_float(init_size);
    EXPECT_EQ(v_float.size(), init_size);

    vector<double> v_double(init_size);
    EXPECT_EQ(v_double.size(), init_size);
}

TEST(Constructor_and_size, Init_size_1)
{
    constexpr size_t init_size {1};

    vector<char> v_char(init_size);
    EXPECT_EQ(v_char.size(), init_size);

    vector<unsigned char> v_unsigned_char(init_size);
    EXPECT_EQ(v_unsigned_char.size(), init_size);

    vector<int> v_int(init_size);
    EXPECT_EQ(v_int.size(), init_size);

    vector<unsigned int> v_unsigned_int(init_size);
    EXPECT_EQ(v_unsigned_int.size(), init_size);

    vector<float> v_float(init_size);
    EXPECT_EQ(v_float.size(), init_size);

    vector<double> v_double(init_size);
    EXPECT_EQ(v_double.size(), init_size);
}

TEST(Initializer_list_and_size, Init_size_1)
{
    {
        std::initializer_list il_ {0};
        const auto init_size {il_.size()};
        vector<int> v_int(il_);

        const std::vector<int> expected_v(il_);
        EXPECT_EQ(v_int.size(), init_size);
        // TODO Implement necessary methods to be able to verify vector content
        // EXPECT_THAT(v_int, ::testing::ContainerEq(expected_v));
    }
    {
        std::initializer_list il_ {0, 1};
        const size_t init_size {il_.size()};

        vector<int> v_int(il_);
        EXPECT_EQ(v_int.size(), init_size);
    }
    {
        std::initializer_list il_ {0, 1, 2};
        const size_t init_size {il_.size()};

        vector<int> v_int(il_);
        EXPECT_EQ(v_int.size(), init_size);
    }
}

TEST(Capacity, Init_size_0)
{
    constexpr size_t init_size {0};

    vector<int> v_int(init_size);
    constexpr size_t expected_capacity = 16;

    EXPECT_EQ(v_int.capacity(), expected_capacity);
}

TEST(Capacity, Init_size_1)
{
    constexpr size_t init_size {12};
    constexpr size_t minimun_size {16};

    vector<int> v_int(init_size);
    EXPECT_EQ(v_int.capacity(), minimun_size);
}

TEST(Empty, Init_size_0)
{
    constexpr size_t init_size {0};

    vector<int> v_int(init_size);
    EXPECT_TRUE(v_int.empty());
}

TEST(Empty, Init_size_10)
{
    constexpr size_t init_size {10};

    vector<int> v_int(init_size);
    EXPECT_FALSE(v_int.empty());
}

TEST(Front, empty)
{
    constexpr size_t init_size {0};
    vector<int> v_int(init_size);
    EXPECT_EQ(v_int.size(), init_size);

    EXPECT_EQ(v_int.front(), nullptr);
}

TEST(Front, One_element)
{
    constexpr std::initializer_list<int> il_ {1};
    constexpr size_t init_size = il_.size();
    vector v_int(il_);

    EXPECT_EQ(v_int.size(), init_size);
    EXPECT_EQ(*v_int.front(), *il_.begin());
}
} // namespace asg::tests
