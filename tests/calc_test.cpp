#include "gtest/gtest.h"
#include "../Components/calculator.hpp"
#include "../Components/logger.hpp"
#include "../Components/notifier.hpp"

class CalculatorTest : public ::testing::Test {
protected:
    Logger logger;
    Notifier notifier{50}; // Set threshold to 50
    Calculator calc{logger, notifier};
};

TEST_F(CalculatorTest, AddTest) {
    EXPECT_DOUBLE_EQ(calc.add(10, 5), 15);
    EXPECT_DOUBLE_EQ(calc.add(-10, 5), -5);
}

TEST_F(CalculatorTest, SubtractTest) {
    EXPECT_DOUBLE_EQ(calc.subtract(10, 5), 5);
    EXPECT_DOUBLE_EQ(calc.subtract(10, 20), -10);
}

TEST_F(CalculatorTest, MultiplyTest) {
    EXPECT_DOUBLE_EQ(calc.multiply(10, 5), 50);
    EXPECT_DOUBLE_EQ(calc.multiply(-10, 5), -50);
}

