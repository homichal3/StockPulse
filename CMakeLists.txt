cmake_minimum_required(VERSION 3.25)

project(StockPulse VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(libs/core)
add_subdirectory(libs/ingest)
add_subdirectory(libs/analysis)
add_subdirectory(libs/strategy)
add_subdirectory(libs/execution)
add_subdirectory(apps/stockpulse)
add_subdirectory(tests)
