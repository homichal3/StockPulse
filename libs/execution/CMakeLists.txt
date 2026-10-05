add_library(execution STATIC src/execution.cpp)
target_include_directories(execution PUBLIC include)
target_link_libraries(execution PUBLIC core)
