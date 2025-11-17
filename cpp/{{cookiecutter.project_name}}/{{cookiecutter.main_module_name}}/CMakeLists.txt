set(PROJECT ${CPACK_PROJECT_NAME}-sandbox)

project(${PROJECT} VERSION 0.1.0)

add_subdirectory(tests)




add_executable(${PROJECT_NAME} src/EntryPoint.cpp src/Sandbox.cpp src/Sandbox.h)
add_library(${PROJECT_NAME}-lib EXCLUDE_FROM_ALL src/Sandbox.cpp src/Sandbox.h)


target_link_libraries(${PROJECT_NAME}
        Logging)
target_link_libraries(${PROJECT_NAME}-lib
        Logging)

