add_executable(example)

target_sources(example
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp)
target_link_libraries(example
        PRIVATE
        liblua.a)
