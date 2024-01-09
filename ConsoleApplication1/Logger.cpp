#include "Logger.h"
#include <iostream>
#include <chrono>
#include <sstream>

#define WINVER 0x0501
#define _WIN32_WINNT 0x0501
#include <windows.h>


Logger LOGGER;

Logger::Logger() {
    std::string logdir = "C:\\MyLogs\\";
    CreateDirectoryA(logdir.c_str(), NULL);
    std::string filename = logdir + getTime() + "-MyLog.txt";
    std::cout << filename << std::endl;
    logfile.open(filename, std::ofstream::out | std::ofstream::app);
}

Logger::~Logger() {
    logfile.close();
}

void Logger::writeMessage(std::string message) {
    logfile << getTime() << " MESSAGE " << message << std::endl;
}

void Logger::writeError(std::string error) {
    logfile << getTime() << " ERROR " << error << std::endl;
}

std::string Logger::getTime() {
    std::time_t time = std::time({});
    char timeString[std::size("yyyy-mm-ddThh:mm:ssZ")];
    std::strftime(std::data(timeString), std::size(timeString),
        "%FT%H.%M.%SZ", std::gmtime(&time));
    std::stringstream ss;
    ss << timeString;
    return ss.str();
}
