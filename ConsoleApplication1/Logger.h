#pragma once
#include <string>
#include <fstream>

class Logger {
private:
    std::ofstream logfile;

public:
    std::string getTime();
    void writeMessage(std::string message);
    void writeError(std::string error);
    Logger();
    ~Logger();
};

extern Logger LOGGER;