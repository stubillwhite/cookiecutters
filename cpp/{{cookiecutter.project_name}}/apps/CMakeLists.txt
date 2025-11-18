set(PROJECT ${CMAKE_PROJECT_NAME}-app)

project(${PROJECT} VERSION 0.1.0)

add_executable(${PROJECT_NAME}
    my-app/EntryPoint.cpp
)

target_link_libraries(${PROJECT_NAME}
    Logging
    Greeting
)
