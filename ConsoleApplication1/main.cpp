#include "main.h"
#include "Logger.h"
#include <string>
#include <iostream>

#define WINVER 0x0501
#define _WIN32_WINNT 0x0501
#include <windows.h>


std::string getTime();

int main()
{
	std::cout << "Attempting to write a log. Writing to Log file...";
	logSomething();
	std::cout << "Finished!";
}

void logSomething() {
    LOGGER.writeMessage("This is a message log");
	LOGGER.writeError("This is an error log");
}