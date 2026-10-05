add_library(analysis STATIC src/analysis.cpp)
target_include_directories(analysis PUBLIC include)
target_link_libraries(analysis PUBLIC core)
