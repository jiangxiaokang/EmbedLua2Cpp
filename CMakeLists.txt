CMAKE_MINIMUM_REQUIRED(VERSION 3.21)

project(embed_lua)

set(CMAKE_CXX_STANDARD 14)

#lua
set(LUA_DIR "/opt/homebrew/Cellar/lua/5.4.3")
INCLUDE_DIRECTORIES(${LUA_DIR}/include/lua)
LINK_DIRECTORIES(${LUA_DIR}/lib)

add_subdirectory(LuaDoString)
