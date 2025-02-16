#include "logger.hpp"
#include <fstream>
#include <iostream>

void Logger::logOperation(const std::string& operation, double operand1, double operand2, double result) {
    std::ofstream logFile("calculator.log", std::ios::app);
    if (logFile.is_open()) {
        logFile << "Operation: " << operation << ", Operands: " << operand1 << ", " << operand2
                << ", Result: " << result << std::endl;
        logFile.close();
    } else {
        std::cout << "Unable to open log file" << std::endl;
    }
}

