find_package(Catch2 3 REQUIRED)

add_executable(${PROJECT_NAME}-test
    GreetingTest.cpp
)

target_link_libraries(${PROJECT_NAME}-test
    PRIVATE
        Catch2::Catch2WithMain
        ${PROJECT_NAME}
)

include(CTest)
include(Catch)
catch_discover_tests(${PROJECT_NAME}-test)
