add_library(ingest STATIC src/ingest.cpp)
target_include_directories(ingest PUBLIC include)
target_link_libraries(ingest PUBLIC core)
