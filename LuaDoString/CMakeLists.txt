
add_executable(LuaDoString)

target_sources(LuaDoString
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_libraries(LuaDoString
        PRIVATE
        liblua.a)