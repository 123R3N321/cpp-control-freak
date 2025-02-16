#include "gtest/gtest.h"
#include "../Components/notifier.hpp"
#include <gmock/gmock.h>

// Mock Notifier class for testing alert functionality
class MockNotifier : public Notifier {
public:
    MockNotifier(double threshold) : Notifier(threshold) {}
    MOCK_METHOD(void, sendAlert, (double result));
};

class NotifierTest : public ::testing::Test {
protected:
    MockNotifier mockNotifier{50};  // Set threshold to 50
};

TEST_F(NotifierTest, SendAlertTest) {
    // Expect the alert to be called if the result exceeds threshold
    EXPECT_CALL(mockNotifier, sendAlert(60)).Times(1);
    
    mockNotifier.sendAlert(60);  // This should trigger the mock function
}

TEST_F(NotifierTest, NoAlertTest) {
    // Expect the alert to NOT be called if the result is below threshold
    EXPECT_CALL(mockNotifier, sendAlert(40)).Times(0);
    
    mockNotifier.sendAlert(40);  // No alert should be triggered
}
