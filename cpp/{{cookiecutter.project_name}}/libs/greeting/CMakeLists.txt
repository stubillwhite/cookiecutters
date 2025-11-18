set(PROJECT Greeting)

project(${PROJECT} VERSION 0.1.0)

add_library(${PROJECT_NAME}
    Greeting.cpp
    Greeting.h
)

target_link_libraries(${PROJECT_NAME}
    Logging
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Add tests subdirectory if testing is enabled
include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
