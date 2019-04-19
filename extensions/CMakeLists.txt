set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
include(functions)

option(BUILD_CONSOLE "Console build" ON)

if(BUILD_CONSOLE)
    create_extension(console console/main.cpp)
endif()
