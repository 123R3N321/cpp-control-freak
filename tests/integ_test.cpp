#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Components/calculator.hpp"
#include "../Components/notifier.hpp"
#include "../Components/logger.hpp"
#include <fstream>
#include <sstream>


class MockNotifier : public Notifier {
public:
    MockNotifier(int threshold) : Notifier(threshold) {}
    MOCK_METHOD(void, sendAlert, (double));
};

class IntegTest : public ::testing::Test {
protected:
    Logger logger;
    MockNotifier notifier{10};
    Calculator calculator{logger, notifier};

    std::string captureLog() {
        std::ifstream logFile("calculator.log");
        std::stringstream buffer;
        buffer << logFile.rdbuf();
        return buffer.str();
    }
};

TEST_F(IntegTest, LogOperationTest) {
    // Calculate an operation and verify if it's correctly written to the log file    
    int result = calculator.add(2, 6);
    std::string logContent = captureLog();

    EXPECT_DOUBLE_EQ(result, 8);
    EXPECT_NE(logContent.find("Operation: Addition"), std::string::npos);
    EXPECT_NE(logContent.find("Operands: 2, 6"), std::string::npos);
    EXPECT_NE(logContent.find("Result: 8"), std::string::npos);
}
