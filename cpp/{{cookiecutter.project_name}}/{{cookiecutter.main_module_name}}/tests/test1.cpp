#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#include<catch2/catch_test_macros.hpp>

#include <Log.h>
#include<Sandbox.h>

logging::Log LOGGER = logging::Log();

TEST_CASE("sandbox.message() should always be `Hello!`", "[sandbox]"){
  Sandbox sandbox = Sandbox();
  LOG_INFO("Testing");
  
      std::string expected_message = "Simple starter created!";
  
  REQUIRE(sandbox.message() == expected_message);
}

#pragma clang diagnostic pop
