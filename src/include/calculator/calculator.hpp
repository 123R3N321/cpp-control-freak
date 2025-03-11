#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "logger/logger.hpp"
#include "notifier/notifier.hpp"

class Calculator {
private:
    Logger logger;
    Notifier notifier;

public:
    Calculator(Logger logger, Notifier notifier);
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
};

#endif
