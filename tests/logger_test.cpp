#include "gtest/gtest.h"
#include "../Components/logger.hpp"
#include <fstream>
#include <sstream>

class LoggerTest : public ::testing::Test {
protected:
    Logger logger;

    std::string captureLog() {
        std::ifstream logFile("calculator.log");
        std::stringstream buffer;
        buffer << logFile.rdbuf();
        return buffer.str();
    }
};

TEST_F(LoggerTest, LogOperationTest) {
    // Log an operation and verify if it's correctly written to the file
    logger.logOperation("Addition", 10, 5, 15);
    std::string logContent = captureLog();
    
    EXPECT_NE(logContent.find("Operation: Addition"), std::string::npos);
    EXPECT_NE(logContent.find("Operands: 10, 5"), std::string::npos);
    EXPECT_NE(logContent.find("Result: 15"), std::string::npos);
}

