#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#include <Greeting.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("greeting.message then returns expected message", "[greeting]") {
    Greeting greeting = Greeting();

    std::string expected_message = "Basic project setup complete";
    REQUIRE(greeting.message() == expected_message);
}

#pragma clang diagnostic pop
