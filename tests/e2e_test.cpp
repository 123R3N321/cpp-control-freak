#include "calculator/calculator.hpp"
#include "gtest/gtest.h"
#include <fstream>
#include <sstream>

class E2ETest : public ::testing::Test {
protected:
    Logger logger;
    Notifier notifier{10};// Set threshold to 10
    Calculator calculator{logger, notifier};

    std::string captureLog() {
        std::ifstream logFile("calculator.log");
        std::stringstream buffer;
        buffer << logFile.rdbuf();
        return buffer.str();
    }
};

TEST_F(E2ETest, AddTest) {
    // verify addition
    int result = calculator.add(2, 6);
    EXPECT_DOUBLE_EQ(result, 8);

    // verify log output
    std::string logContent = captureLog();
    EXPECT_NE(logContent.find("Operation: Addition"), std::string::npos);
    EXPECT_NE(logContent.find("Operands: 2, 6"), std::string::npos);
    EXPECT_NE(logContent.find("Result: 8"), std::string::npos);

    // verify notification
    bool thresholdCheck = notifier.sendAlert(result);
    EXPECT_FALSE(thresholdCheck);
}
