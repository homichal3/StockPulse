add_library(strategy STATIC src/strategy.cpp)
target_include_directories(strategy PUBLIC include)
target_link_libraries(strategy PUBLIC core)
