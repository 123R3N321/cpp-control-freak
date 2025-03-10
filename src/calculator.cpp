#include "calculator/calculator.hpp"
#include <iostream>

Calculator::Calculator(Logger logger, Notifier notifier) : logger(logger), notifier(notifier) {}

double Calculator::add(double a, double b) {
    double result = a + b;
    logger.logOperation("Addition", a, b, result);
    notifier.sendAlert(result);
    return result;
}

double Calculator::subtract(double a, double b) {
    double result = a - b;
    logger.logOperation("Subtraction", a, b, result);
    notifier.sendAlert(result);
    return result;
}

double Calculator::multiply(double a, double b) {
    double result = a * b;
    logger.logOperation("Multiplication", a, b, result);
    notifier.sendAlert(result);
    return result;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        logger.logOperation("Division", a, b, -1);  // Log error for division by zero
        notifier.sendAlert(-1);
        std::cout << "Error: Division by zero" << std::endl;
        return -1;  // Returning -1 as an error code for division by zero
    }
    double result = a / b;
    logger.logOperation("Division", a, b, result);
    notifier.sendAlert(result);
    return result;
}
