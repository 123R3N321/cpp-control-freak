#include "notifier/notifier.hpp"
#include "gtest/gtest.h"

// Mock Notifier class for testing alert functionality

class NotifierTest : public ::testing::Test {
protected:
    Notifier notifier{50};// Set threshold to 50
};

TEST_F(NotifierTest, SendAlertTest) {
    testing::internal::CaptureStdout();

    notifier.sendAlert(60);// This should trigger the mock function
    std::string captured_output = testing::internal::GetCapturedStdout();

    // Expect the alert to be called if the result exceeds threshold
    EXPECT_FALSE(captured_output.empty());
}

TEST_F(NotifierTest, NoAlertTest) {
    testing::internal::CaptureStdout();

    notifier.sendAlert(40);// No alert should be triggered
    std::string captured_output = testing::internal::GetCapturedStdout();

    // Expect the alert to NOT be called if the result is below threshold
    EXPECT_TRUE(captured_output.empty());
}
