//
// Created by jiangxiaokang on 2022/2/12.
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

struct PlayerInfo{
    std::string title;
    std::string name;
    std::string family;
    int level = 0;
};

int main(){
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);//load lua standard libs
    if(CheckLuaResult(L,luaL_dofile(L,"../../EmbeddingLua/example.lua"))){
        lua_getglobal(L,"player");
        if(lua_istable(L,-1)) {
            PlayerInfo player;
            lua_pushstring(L,"Name");//player= {...},"Name"
            lua_gettable(L,-2);
            player.name = lua_tostring(L,-1);
            lua_pop(L,1);

            lua_pushstring(L,"Title");//player= {...},"Title"
            lua_gettable(L,-2);
            player.title = lua_tostring(L,-1);
            lua_pop(L,1);

            lua_pushstring(L,"Family");//player= {...},"Family"
            lua_gettable(L,-2);
            player.family = lua_tostring(L,-1);
            lua_pop(L,1);

            lua_pushstring(L,"Level");//player= {...},"Level"
            lua_gettable(L,-2);
            player.level = lua_tointeger(L,-1);
            lua_pop(L,1);
            std::cout<<player.title<<" "<<player.name<<" of "<<player.family<<" "<<player.level<<std::endl;
        }
    }
    lua_close(L);
    return 0;
}
