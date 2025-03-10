#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "calculator/calculator.hpp"
#include "logger/logger.hpp"
#include "notifier/notifier.hpp"


class MockNotifier : public Notifier {
public:
    MockNotifier(int threshold) : Notifier(threshold) {}
    MOCK_METHOD(void, sendAlert, (double));
};

class MockLogger : public Logger {
public:
    MockLogger() : Logger() {}
    MOCK_METHOD(void, logOperation, (const std::string, double, double, double));
};

class CalculatorTest : public ::testing::Test {
protected:
    MockLogger logger;
    MockNotifier notifier{50}; // Set threshold to 50
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

