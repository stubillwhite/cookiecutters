#include <Log.h>

#include <iostream>

#include "Greeting.h"

int main(int argc, char* argv[]) {
    logging::Log LOGGER = logging::Log();
    LOG_INFO("Logging initialized");
    LOG_ERROR("Example error message");

    auto* greeting = new Greeting();
    std::cout << greeting->message() << std::endl;
    
    delete greeting;
}
