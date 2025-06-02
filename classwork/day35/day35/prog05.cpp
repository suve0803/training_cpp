#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

// Logging Levels
enum LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

// Convert log level to string
std::string levelToString(LogLevel level) {
    switch (level) {
    case DEBUG: return "DEBUG";
    case INFO: return "INFO ";
    case WARNING: return "WARN ";
    case ERROR: return "ERROR";
    default: return "UNKNOWN";
    }
}

// Get current time as string
std::string getCurrentTime() {
    std::time_t now = std::time(nullptr);
    std::tm* lt = std::localtime(&now);
    char buffer[32];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", lt);
    return std::string(buffer);
}

// Logger Class
class Logger {
    std::ofstream logFile;

public:
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios::app);  // Append mode
        if (!logFile.is_open()) {
            std::cerr << "Failed to open log file\n";
        }
    }

    ~Logger() {
        if (logFile.is_open())
            logFile.close();
    }

    void log(LogLevel level, const std::string& message) {
        if (logFile.is_open()) {
            logFile << "[" << getCurrentTime() << "] "
                << "[" << levelToString(level) << "] "
                << message << std::endl;
        }
    }
};

// Main Application
int main() {
    Logger logger("app.log");

    logger.log(INFO, "Application started");
    logger.log(DEBUG, "Initializing variables");

    int x = 10, y = 0;
    logger.log(DEBUG, "x = 10, y = 0");

    if (y == 0) {
        logger.log(WARNING, "Attempt to divide by zero");
        logger.log(ERROR, "Division failed due to zero denominator");
    }
    else {
        int z = x / y;
        logger.log(INFO, "Division successful: " + std::to_string(z));
    }

    logger.log(INFO, "Application ended");
    return 0;
}