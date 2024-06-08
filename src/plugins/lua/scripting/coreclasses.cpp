#include "core.h"

int Vector_index(lua_State *L)
{
    Vector *v = *static_cast<Vector **>(luaL_checkudata(L, 1, "Vector"));
    std::string key = luaL_checkstring(L, 2);

    if (key == "x")
    {
        lua_pushnumber(L, v->x);
        return 1;
    }
    else if (key == "y")
    {
        lua_pushnumber(L, v->y);
        return 1;
    }
    else if (key == "z")
    {
        lua_pushnumber(L, v->z);
        return 1;
    }

    luaL_getmetatable(L, "Vector");
    lua_pushstring(L, key.c_str());
    lua_rawget(L, -2);
    return 1;
}

int Vector_newindex(lua_State *L)
{
    Vector *v = *static_cast<Vector **>(luaL_checkudata(L, 1, "Vector"));
    std::string key = luaL_checkstring(L, 2);

    if (key == "x")
    {
        v->x = luaL_checknumber(L, 3);
        return 0;
    }
    else if (key == "y")
    {
        v->y = luaL_checknumber(L, 3);
        return 0;
    }
    else if (key == "z")
    {
        v->z = luaL_checknumber(L, 3);
        return 0;
    }

    return luaL_error(L, "Cannot add new fields to Vector");
}

int Vector_unm(lua_State *L)
{
    Vector *v = *static_cast<Vector **>(luaL_checkudata(L, 1, "Vector"));
    Vector result = -(*v);
    luabridge::push(L, result);
    return 1;
}

int Vector_sub(lua_State *L)
{
    Vector *v1 = *static_cast<Vector **>(luaL_checkudata(L, 1, "Vector"));
    Vector *v2 = *static_cast<Vector **>(luaL_checkudata(L, 2, "Vector"));
    Vector result = *v1 - *v2;
    luabridge::push(L, result);
    return 1;
}

int Vector_mul(lua_State *L)
{
    Vector *v1 = *static_cast<Vector **>(luaL_checkudata(L, 1, "Vector"));
    Vector *v2 = *static_cast<Vector **>(luaL_checkudata(L, 2, "Vector"));
    Vector result = *v1 * *v2;
    luabridge::push(L, result);
    return 1;
}

int Vector_div(lua_State *L)
{
    Vector *v1 = *static_cast<Vector **>(luaL_checkudata(L, 1, "Vector"));
    Vector *v2 = *static_cast<Vector **>(luaL_checkudata(L, 2, "Vector"));
    Vector result = *v1 / *v2;
    luabridge::push(L, result);
    return 1;
}

int Vector_tostring(lua_State *L)
{
    Vector *v1 = *static_cast<Vector **>(luaL_checkudata(L, 1, "Vector"));

    lua_pushstring(L, string_format("Vector(%f,%f,%f)", v1->x, v1->y, v1->z).c_str());
    return 1;
}

void SetupLuaCoreClasses(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<Vector>("Vector")
        .addConstructor<void (*)(float, float, float)>()
        .addFunction("__add", &Vector::operator+)
        .addFunction("__eq", &Vector::operator==)
        .addFunction("__len", &Vector::Length)
        .endClass();

    luaL_newmetatable(state, "Vector");
    lua_pushstring(state, "__index");
    lua_pushcfunction(state, Vector_index);
    lua_settable(state, -3);
    lua_pushstring(state, "__newindex");
    lua_pushcfunction(state, Vector_newindex);
    lua_settable(state, -3);
    lua_pushstring(state, "__unm");
    lua_pushcfunction(state, Vector_unm);
    lua_settable(state, -3);
    lua_pushstring(state, "__sub");
    lua_pushcfunction(state, Vector_sub);
    lua_settable(state, -3);
    lua_pushstring(state, "__mul");
    lua_pushcfunction(state, Vector_mul);
    lua_settable(state, -3);
    lua_pushstring(state, "__div");
    lua_pushcfunction(state, Vector_div);
    lua_settable(state, -3);
    lua_pushstring(state, "__tostring");
    lua_pushcfunction(state, Vector_div);
    lua_settable(state, -3);
}