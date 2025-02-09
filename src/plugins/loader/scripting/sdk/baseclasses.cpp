#include "../../core.h"

EValue Vector_unm(Vector* v, EContext* ctx)
{
    Vector result = -(*v);
    return EValue(ctx, &result);
}

EValue Vector_sub(Vector* v1, Vector* v2, EContext* ctx)
{
    Vector result = *v1 - *v2;
    return EValue(ctx, &result);
}

EValue Vector_mul(Vector* v1, Vector* v2, EContext* ctx)
{
    Vector result = *v1 * *v2;
    return EValue(ctx, &result);
}

EValue Vector_div(Vector* v1, Vector* v2, EContext* ctx)
{
    Vector result = *v1 / *v2;
    return EValue(ctx, &result);
}

std::string Vector_tostring(Vector* v1)
{
    return string_format("Vector(%f,%f,%f)", v1->x, v1->y, v1->z);
}

EValue QAngle_unm(QAngle* v, EContext* ctx)
{
    QAngle result = -(*v);
    return EValue(ctx, &result);
}

EValue QAngle_sub(QAngle* v1, QAngle* v2, EContext* ctx)
{
    QAngle result = *v1 - *v2;
    return EValue(ctx, &result);
}

EValue QAngle_mul(QAngle* v1, QAngle* v2, EContext* ctx)
{
    QAngle result = *v1;
    result.x *= v2->x;
    result.y *= v2->y;
    result.z *= v2->z;
    return EValue(ctx, &result);
}

EValue QAngle_div(QAngle* v1, QAngle* v2, EContext* ctx)
{
    QAngle result = *v1;
    result.x /= v2->x;
    result.y /= v2->y;
    result.z /= v2->z;
    return EValue(ctx, &result);
}

std::string QAngle_tostring(QAngle* v1)
{
    return string_format("QAngle(%f,%f,%f)", v1->x, v1->y, v1->z);
}

EValue Vector2D_unm(Vector2D* v, EContext* ctx)
{
    Vector2D result = -(*v);
    return EValue(ctx, &result);
}

EValue Vector2D_sub(Vector2D* v1, Vector2D* v2, EContext* ctx)
{
    Vector2D result = *v1 - *v2;
    return EValue(ctx, &result);
}

EValue Vector2D_mul(Vector2D* v1, Vector2D* v2, EContext* ctx)
{
    Vector2D result = *v1;
    result.x *= v2->x;
    result.y *= v2->y;
    return EValue(ctx, &result);
}

EValue Vector2D_div(Vector2D* v1, Vector2D* v2, EContext* ctx)
{
    Vector2D result = *v1;
    result.x /= v2->x;
    result.y /= v2->y;
    return EValue(ctx, &result);
}

std::string Vector2D_tostring(Vector2D* v1)
{
    return string_format("Vector2D(%f,%f)", v1->x, v1->y);
}

EValue Vector4D_unm(Vector4D* v, EContext* ctx)
{
    Vector4D result = -(*v);
    return EValue(ctx, &result);
}

EValue Vector4D_sub(Vector4D* v1, Vector4D* v2, EContext* ctx)
{
    Vector4D result = *v1 - *v2;
    return EValue(ctx, &result);
}

EValue Vector4D_mul(Vector4D* v1, Vector4D* v2, EContext* ctx)
{
    Vector4D result = *v1;
    result.x *= v2->x;
    result.y *= v2->y;
    result.z *= v2->z;
    result.w *= v2->w;
    return EValue(ctx, &result);
}

EValue Vector4D_div(Vector4D* v1, Vector4D* v2, EContext* ctx)
{
    Vector4D result = *v1;
    result.x /= v2->x;
    result.y /= v2->y;
    result.z /= v2->z;
    result.w /= v2->w;
    return EValue(ctx, &result);
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

std::string Color_tostring(Color* v1)
{
    return string_format("Color(%d,%d,%d,%d)", v1->r(), v1->g(), v1->b(), v1->a());
}

std::string Vector_GetPtr(Vector* vec)
{
    return string_format("%p", vec);
}

std::string QAngle_GetPtr(QAngle* ang)
{
    return string_format("%p", ang);
}

std::string Color_GetPtr(Color* col)
{
    return string_format("%p", col);
}

std::string Vector2D_GetPtr(Vector2D* vec)
{
    return string_format("%p", vec);
}

std::string Vector4D_GetPtr(Vector4D* vec)
{
    return string_format("%p", vec);
}

void LoadBaseClass(Plugin* plugin, EContext* state)
{
    // GetGlobalNamespace(state)
    //     .beginClass<Vector>("Vector")
    //     .addConstructor<float, float, float>()
    //     .addProperty("x", &Vector::x, true)
    //     .addProperty("y", &Vector::y, true)
    //     .addProperty("z", &Vector::z, true)
    //     .addFunction("GetPtr", Vector_GetPtr)
    //     .addLuaFunction("__add", &Vector::operator+)
    //     .addLuaFunction("__eq", &Vector::operator==)
    //     .addLuaFunction("__len", &Vector::Length)
    //     .addLuaFunction("__tostring", Vector_tostring)
    //     .addLuaFunction("__unm", Vector_unm)
    //     .addLuaFunction("__sub", Vector_sub)
    //     .addLuaFunction("__mul", Vector_mul)
    //     .addLuaFunction("__div", Vector_div)
    //     .addJSFunction("toString", Vector_tostring)
    //     .endClass();

    // GetGlobalNamespace(state)
    //     .beginClass<Color>("Color")
    //     .addConstructor<int, int, int, int>()
    //     .addFunction("GetPtr", Color_GetPtr)
    //     .addLuaFunction("__index", Color_index)
    //     .addLuaFunction("__newindex", Color_newindex)
    //     .addLuaFunction("__tostring", Color_tostring)
    //     .addLuaFunction("toString", Color_tostring)
    //     .endClass();

    // GetGlobalNamespace(state)
    //     .beginClass<QAngle>("QAngle")
    //     .addConstructor<float, float, float>()
    //     .addProperty("x", &QAngle::x, true)
    //     .addProperty("y", &QAngle::y, true)
    //     .addProperty("z", &QAngle::z, true)
    //     .addFunction("GetPtr", QAngle_GetPtr)
    //     .addFunction("__add", &QAngle::operator+)
    //     .addFunction("__eq", &QAngle::operator==)
    //     .addFunction("__len", &QAngle::Length)
    //     .addLuaFunction("__unm", QAngle_unm)
    //     .addLuaFunction("__sub", QAngle_sub)
    //     .addLuaFunction("__mul", QAngle_mul)
    //     .addLuaFunction("__div", QAngle_div)
    //     .addLuaFunction("__tostring", QAngle_tostring)
    //     .addJSFunction("toString", QAngle_tostring)
    //     .endClass();

    // GetGlobalNamespace(state)
    //     .beginClass<Vector2D>("Vector2D")
    //     .addConstructor<float, float>()
    //     .addProperty("x", &Vector2D::x, true)
    //     .addProperty("y", &Vector2D::y, true)
    //     .addFunction("GetPtr", Vector2D_GetPtr)
    //     .addFunction("__add", &Vector2D::operator+)
    //     .addFunction("__eq", &Vector2D::operator==)
    //     .addFunction("__len", &Vector2D::Length)
    //     .addLuaFunction("__unm", Vector2D_unm)
    //     .addLuaFunction("__sub", Vector2D_sub)
    //     .addLuaFunction("__mul", Vector2D_mul)
    //     .addLuaFunction("__div", Vector2D_div)
    //     .addLuaFunction("__tostring", Vector2D_tostring)
    //     .addJSFunction("toString", Vector2D_tostring)
    //     .endClass();

    // GetGlobalNamespace(state)
    //     .beginClass<Vector4D>("Vector4D")
    //     .addConstructor<float, float, float, float>()
    //     .addProperty("x", &Vector4D::x, true)
    //     .addProperty("y", &Vector4D::y, true)
    //     .addProperty("z", &Vector4D::z, true)
    //     .addProperty("w", &Vector4D::w, true)
    //     .addFunction("GetPtr", Vector4D_GetPtr)
    //     .addLuaFunction("__add", &Vector4D::operator+)
    //     .addLuaFunction("__eq", &Vector4D::operator==)
    //     .addLuaFunction("__len", &Vector4D::Length)
    //     .addLuaFunction("__unm", Vector4D_unm)
    //     .addLuaFunction("__sub", Vector4D_sub)
    //     .addLuaFunction("__mul", Vector4D_mul)
    //     .addLuaFunction("__div", Vector4D_div)
    //     .addLuaFunction("__tostring", Vector4D_tostring)
    //     .addJSFunction("toString", Vector4D_tostring)
    //     .endClass();
}

LoadScriptingComponent(
    baseclasses,
    LoadBaseClass
)