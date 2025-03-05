#include "gtest/gtest.h"
#include "../src/calculator.hpp"
#include <fstream>
#include <sstream>

class E2ETest : public ::testing::Test {
protected:
    Logger logger;
    Notifier notifier{10}; // Set threshold to 10
    Calculator calculator{logger, notifier};

    std::string captureLog() {
        std::ifstream logFile("calculator.log");
        std::stringstream buffer;
        buffer << logFile.rdbuf();
        return buffer.str();
    }
};

TEST_F(E2ETest, AddTest) {
    testing::internal::CaptureStdout();

    // verify addition
    int result = calculator.add(10, 5);
    EXPECT_DOUBLE_EQ(result, 15);

    // verify log output
    std::string logContent = captureLog();
    EXPECT_NE(logContent.find("Operation: Addition"), std::string::npos);
    EXPECT_NE(logContent.find("Operands: 2, 6"), std::string::npos);
    EXPECT_NE(logContent.find("Result: 8"), std::string::npos);

    // verify notification
    std::string captured_output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(captured_output.empty());
}

