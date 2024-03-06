cmake_minimum_required(VERSION 3.23.3)
cmake_policy(SET CMP0135 NEW)

# Configure Complier
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)

project(trading_engine)

# Dependencies
find_package(nlohmann_json 3.11.2 REQUIRED)

# Libraries
add_subdirectory(utils)

# Binaries
add_subdirectory(server)
#add_subdirectory(client)
#add_subdirectory(messages)


# Configure GTest and unit tests 
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)
enable_testing()
#add_subdirectory(./tests/unit_tests)
