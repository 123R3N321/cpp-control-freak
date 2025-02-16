#include "notifier.hpp"
#include <iostream>

Notifier::Notifier(double threshold) : threshold(threshold) {}

void Notifier::sendAlert(double result) {
    if (result > threshold) {
        std::cout << "Alert! The result exceeds the threshold: " << result << std::endl;
    }
}
