#include "../core.h"

int Vector_unm(lua_State* L)
{
    Vector* v = *static_cast<Vector**>(luaL_checkudata(L, 1, "Vector"));
    Vector result = -(*v);
    luabridge::push(L, result);
    return 1;
}

int Vector_sub(lua_State* L)
{
    Vector* v1 = *static_cast<Vector**>(luaL_checkudata(L, 1, "Vector"));
    Vector* v2 = *static_cast<Vector**>(luaL_checkudata(L, 2, "Vector"));
    Vector result = *v1 - *v2;
    luabridge::push(L, result);
    return 1;
}

int Vector_mul(lua_State* L)
{
    Vector* v1 = *static_cast<Vector**>(luaL_checkudata(L, 1, "Vector"));
    Vector* v2 = *static_cast<Vector**>(luaL_checkudata(L, 2, "Vector"));
    Vector result = *v1 * *v2;
    luabridge::push(L, result);
    return 1;
}

int Vector_div(lua_State* L)
{
    Vector* v1 = *static_cast<Vector**>(luaL_checkudata(L, 1, "Vector"));
    Vector* v2 = *static_cast<Vector**>(luaL_checkudata(L, 2, "Vector"));
    Vector result = *v1 / *v2;
    luabridge::push(L, result);
    return 1;
}

std::string Vector_tostring(Vector* v1)
{
    return string_format("Vector(%f,%f,%f)", v1->x, v1->y, v1->z);
}

int QAngle_unm(lua_State* L)
{
    QAngle* v = *static_cast<QAngle**>(luaL_checkudata(L, 1, "QAngle"));
    QAngle result = -(*v);
    luabridge::push(L, result);
    return 1;
}

int QAngle_sub(lua_State* L)
{
    QAngle* v1 = *static_cast<QAngle**>(luaL_checkudata(L, 1, "QAngle"));
    QAngle* v2 = *static_cast<QAngle**>(luaL_checkudata(L, 2, "QAngle"));
    QAngle result = *v1 - *v2;
    luabridge::push(L, result);
    return 1;
}

int QAngle_mul(lua_State* L)
{
    QAngle* v1 = *static_cast<QAngle**>(luaL_checkudata(L, 1, "QAngle"));
    QAngle* v2 = *static_cast<QAngle**>(luaL_checkudata(L, 2, "QAngle"));
    QAngle result = *v1;
    result.x *= v2->x;
    result.y *= v2->y;
    result.z *= v2->z;
    luabridge::push(L, result);
    return 1;
}

int QAngle_div(lua_State* L)
{
    QAngle* v1 = *static_cast<QAngle**>(luaL_checkudata(L, 1, "QAngle"));
    QAngle* v2 = *static_cast<QAngle**>(luaL_checkudata(L, 2, "QAngle"));
    QAngle result = *v1;
    result.x /= v2->x;
    result.y /= v2->y;
    result.z /= v2->z;
    luabridge::push(L, result);
    return 1;
}

std::string QAngle_tostring(QAngle* v1)
{
    return string_format("QAngle(%f,%f,%f)", v1->x, v1->y, v1->z);
}

int Vector2D_unm(lua_State* L)
{
    Vector2D* v = *static_cast<Vector2D**>(luaL_checkudata(L, 1, "Vector2D"));
    Vector2D result = -(*v);
    luabridge::push(L, result);
    return 1;
}

int Vector2D_sub(lua_State* L)
{
    Vector2D* v1 = *static_cast<Vector2D**>(luaL_checkudata(L, 1, "Vector2D"));
    Vector2D* v2 = *static_cast<Vector2D**>(luaL_checkudata(L, 2, "Vector2D"));
    Vector2D result = *v1 - *v2;
    luabridge::push(L, result);
    return 1;
}

int Vector2D_mul(lua_State* L)
{
    Vector2D* v1 = *static_cast<Vector2D**>(luaL_checkudata(L, 1, "Vector2D"));
    Vector2D* v2 = *static_cast<Vector2D**>(luaL_checkudata(L, 2, "Vector2D"));
    Vector2D result = *v1;
    result.x *= v2->x;
    result.y *= v2->y;
    luabridge::push(L, result);
    return 1;
}

int Vector2D_div(lua_State* L)
{
    Vector2D* v1 = *static_cast<Vector2D**>(luaL_checkudata(L, 1, "Vector2D"));
    Vector2D* v2 = *static_cast<Vector2D**>(luaL_checkudata(L, 2, "Vector2D"));
    Vector2D result = *v1;
    result.x /= v2->x;
    result.y /= v2->y;
    luabridge::push(L, result);
    return 1;
}

std::string Vector2D_tostring(Vector2D* v1)
{
    return string_format("Vector2D(%f,%f)", v1->x, v1->y);
}

int Vector4D_unm(lua_State* L)
{
    Vector4D* v = *static_cast<Vector4D**>(luaL_checkudata(L, 1, "Vector4D"));
    Vector4D result = -(*v);
    luabridge::push(L, result);
    return 1;
}

int Vector4D_sub(lua_State* L)
{
    Vector4D* v1 = *static_cast<Vector4D**>(luaL_checkudata(L, 1, "Vector4D"));
    Vector4D* v2 = *static_cast<Vector4D**>(luaL_checkudata(L, 2, "Vector4D"));
    Vector4D result = *v1 - *v2;
    luabridge::push(L, result);
    return 1;
}

int Vector4D_mul(lua_State* L)
{
    Vector4D* v1 = *static_cast<Vector4D**>(luaL_checkudata(L, 1, "Vector4D"));
    Vector4D* v2 = *static_cast<Vector4D**>(luaL_checkudata(L, 2, "Vector4D"));
    Vector4D result = *v1;
    result.x *= v2->x;
    result.y *= v2->y;
    result.z *= v2->z;
    result.w *= v2->w;
    luabridge::push(L, result);
    return 1;
}

int Vector4D_div(lua_State* L)
{
    Vector4D* v1 = *static_cast<Vector4D**>(luaL_checkudata(L, 1, "Vector4D"));
    Vector4D* v2 = *static_cast<Vector4D**>(luaL_checkudata(L, 2, "Vector4D"));
    Vector4D result = *v1;
    result.x /= v2->x;
    result.y /= v2->y;
    result.z /= v2->z;
    result.w /= v2->w;
    luabridge::push(L, result);
    return 1;
}

std::string Vector4D_tostring(Vector4D* v1)
{
    return string_format("Vector4D(%f,%f,%f,%f)", v1->x, v1->y, v1->z, v1->w);
}

int Color_index(lua_State* L)
{
    Color* v = *static_cast<Color**>(luaL_checkudata(L, 1, "Color"));
    std::string key = luaL_checkstring(L, 2);

    if (key == "r")
    {
        lua_pushnumber(L, v->r());
        return 1;
    }
    else if (key == "g")
    {
        lua_pushnumber(L, v->g());
        return 1;
    }
    else if (key == "b")
    {
        lua_pushnumber(L, v->b());
        return 1;
    }
    else if (key == "a")
    {
        lua_pushnumber(L, v->a());
        return 1;
    }

    luaL_getmetatable(L, "Color");
    lua_pushstring(L, key.c_str());
    lua_rawget(L, -2);
    return 1;
}

int Color_newindex(lua_State* L)
{
    Color* v = *static_cast<Color**>(luaL_checkudata(L, 1, "Color"));
    std::string key = luaL_checkstring(L, 2);

    if (key == "r")
    {
        v->SetColor(luaL_checknumber(L, 3), v->g(), v->b(), v->a());
        return 0;
    }
    else if (key == "g")
    {
        v->SetColor(v->r(), luaL_checknumber(L, 3), v->b(), v->a());
        return 0;
    }
    else if (key == "b")
    {
        v->SetColor(v->r(), v->g(), luaL_checknumber(L, 3), v->a());
        return 0;
    }
    else if (key == "a")
    {
        v->SetColor(v->r(), v->g(), v->b(), luaL_checknumber(L, 3));
        return 0;
    }

    return luaL_error(L, "Cannot add new fields to Color");
}

LoadLuaScriptingComponent(
    baseclasses,
    [](LuaPlugin* plugin, lua_State* state)
    {
        luabridge::getGlobalNamespace(state)
            .beginClass<Vector>("Vector")
            .addConstructor<void (*)(float, float, float)>()
            .addProperty("x", &Vector::x, true)
            .addProperty("y", &Vector::y, true)
            .addProperty("z", &Vector::z, true)
            .addFunction("__add", &Vector::operator+)
            .addFunction("__eq", &Vector::operator==)
            .addFunction("__len", &Vector::Length)
            .addFunction("__tostring", Vector_tostring)
            .endClass();

        luaL_newmetatable(state, "Vector");
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

        luabridge::getGlobalNamespace(state)
            .beginClass<Color>("Color")
            .addConstructor<void (*)(int, int, int, int)>()
            .endClass();

        luaL_newmetatable(state, "Color");
        lua_pushstring(state, "__index");
        lua_pushcfunction(state, Color_index);
        lua_settable(state, -3);
        lua_pushstring(state, "__newindex");
        lua_pushcfunction(state, Color_newindex);
        lua_settable(state, -3);

        luabridge::getGlobalNamespace(state)
            .beginClass<QAngle>("QAngle")
            .addConstructor<void (*)(float, float, float)>()
            .addProperty("x", &QAngle::x, true)
            .addProperty("y", &QAngle::y, true)
            .addProperty("z", &QAngle::z, true)
            .addFunction("__add", &QAngle::operator+)
            .addFunction("__eq", &QAngle::operator==)
            .addFunction("__len", &QAngle::Length)
            .addFunction("__tostring", QAngle_tostring)
            .endClass();

        luaL_newmetatable(state, "QAngle");
        lua_pushstring(state, "__unm");
        lua_pushcfunction(state, QAngle_unm);
        lua_settable(state, -3);
        lua_pushstring(state, "__sub");
        lua_pushcfunction(state, QAngle_sub);
        lua_settable(state, -3);
        lua_pushstring(state, "__mul");
        lua_pushcfunction(state, QAngle_mul);
        lua_settable(state, -3);
        lua_pushstring(state, "__div");
        lua_pushcfunction(state, QAngle_div);
        lua_settable(state, -3);

        luabridge::getGlobalNamespace(state)
            .beginClass<Vector2D>("Vector2D")
            .addConstructor<void (*)(float, float)>()
            .addProperty("x", &Vector2D::x, true)
            .addProperty("y", &Vector2D::y, true)
            .addFunction("__add", &Vector2D::operator+)
            .addFunction("__eq", &Vector2D::operator==)
            .addFunction("__len", &Vector2D::Length)
            .addFunction("__tostring", Vector2D_tostring)
            .endClass();

        luaL_newmetatable(state, "Vector2D");
        lua_pushstring(state, "__unm");
        lua_pushcfunction(state, Vector2D_unm);
        lua_settable(state, -3);
        lua_pushstring(state, "__sub");
        lua_pushcfunction(state, Vector2D_sub);
        lua_settable(state, -3);
        lua_pushstring(state, "__mul");
        lua_pushcfunction(state, Vector2D_mul);
        lua_settable(state, -3);
        lua_pushstring(state, "__div");
        lua_pushcfunction(state, Vector2D_div);
        lua_settable(state, -3);

        luabridge::getGlobalNamespace(state)
            .beginClass<Vector4D>("Vector4D")
            .addConstructor<void (*)(float, float, float, float)>()
            .addProperty("x", &Vector4D::x, true)
            .addProperty("y", &Vector4D::y, true)
            .addProperty("z", &Vector4D::z, true)
            .addProperty("w", &Vector4D::w, true)
            .addFunction("__add", &Vector4D::operator+)
            .addFunction("__eq", &Vector4D::operator==)
            .addFunction("__len", &Vector4D::Length)
            .addFunction("__tostring", Vector4D_tostring)
            .endClass();

        luaL_newmetatable(state, "Vector4D");
        lua_pushstring(state, "__unm");
        lua_pushcfunction(state, Vector4D_unm);
        lua_settable(state, -3);
        lua_pushstring(state, "__sub");
        lua_pushcfunction(state, Vector4D_sub);
        lua_settable(state, -3);
        lua_pushstring(state, "__mul");
        lua_pushcfunction(state, Vector4D_mul);
        lua_settable(state, -3);
        lua_pushstring(state, "__div");
        lua_pushcfunction(state, Vector4D_div);
        lua_settable(state, -3);
    }
)