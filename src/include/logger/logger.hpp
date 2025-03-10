#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

class Logger {
public:
    void logOperation(const std::string &operation, double operand1, double operand2, double result);
};

#endif
