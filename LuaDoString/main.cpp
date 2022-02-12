//
// Created by jxk on 2022/2/12.
//

#include <iostream>
#include <lua.hpp>

bool CheckLuaResult(lua_State* L, int ret){
    if(ret !=LUA_OK){
        std::string errmsg = lua_tostring(L,-1);
        std::cout<<errmsg<<std::endl;
        return false;
    }
    return true;
}


int main(){
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);//load lua standard libs
    if(CheckLuaResult(L,luaL_dofile(L,"../../LuaDoString/example.lua"))){
        lua_getglobal(L,"a");
        if(lua_isnumber(L,-1)){
            float a_in_cpp = (float ) lua_tonumber(L,-1);
            std::cout<<"a_in_cpp = "<<a_in_cpp<<std::endl;
        }
    }
    lua_close(L);
    return 0;
}
