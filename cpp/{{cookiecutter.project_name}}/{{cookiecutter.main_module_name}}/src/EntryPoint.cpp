#include <Log.h>
#include <iostream>

#include "Sandbox.h"

int main(int argc, char* argv[])
{
    logging::Log LOGGER = logging::Log();
    LOG_ERROR("example of logger");
   
    std::string addToMessage = "Console support has not been included!";

    std::cout << "Catch2 unit testing framework activated!" << std::endl;
    auto* sandbox = new Sandbox();
    std::cout << sandbox->message() << std::endl;
    std::cout << addToMessage << std::endl;
    delete sandbox;
}
