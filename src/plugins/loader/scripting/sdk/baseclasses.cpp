#include "../../core.h"

EValue Vector_add(Vector* v1, Vector* v2, EContext* ctx)
{
    Vector result = *v1 + *v2;
    return EValue(ctx, result);
}

bool Vector_eq(Vector* v1, Vector* v2, EContext* ctx)
{
    return (*v1 == *v2);
}

float Vector_len(Vector* v1)
{
    return FastSqrt(v1->x*v1->x + v1->y*v1->y + v1->z*v1->z);
}

EValue Vector_unm(Vector* v, EContext* ctx)
{
    Vector result = -(*v);
    return EValue(ctx, result);
}

EValue Vector_sub(Vector* v1, Vector* v2, EContext* ctx)
{
    Vector result = *v1 - *v2;
    return EValue(ctx, result);
}

EValue Vector_mul(Vector* v1, Vector* v2, EContext* ctx)
{
    Vector result = *v1 * *v2;
    return EValue(ctx, result);
}

EValue Vector_div(Vector* v1, Vector* v2, EContext* ctx)
{
    Vector result = *v1 / *v2;
    return EValue(ctx, result);
}

std::string Vector_tostring(Vector* v1)
{
    return string_format("Vector(%f,%f,%f)", v1->x, v1->y, v1->z);
}

EValue QAngle_add(QAngle* v1, QAngle* v2, EContext* ctx)
{
    QAngle result = *v1 + *v2;
    return EValue(ctx, result);
}

bool QAngle_eq(QAngle* v1, QAngle* v2, EContext* ctx)
{
    return (*v1 == *v2);
}

float QAngle_len(QAngle* v1)
{
    return FastSqrt(v1->x*v1->x + v1->y*v1->y + v1->z*v1->z);
}

EValue QAngle_unm(QAngle* v, EContext* ctx)
{
    QAngle result = -(*v);
    return EValue(ctx, result);
}

EValue QAngle_sub(QAngle* v1, QAngle* v2, EContext* ctx)
{
    QAngle result = *v1 - *v2;
    return EValue(ctx, result);
}

EValue QAngle_mul(QAngle* v1, QAngle* v2, EContext* ctx)
{
    QAngle result = *v1;
    result.x *= v2->x;
    result.y *= v2->y;
    result.z *= v2->z;
    return EValue(ctx, result);
}

EValue QAngle_div(QAngle* v1, QAngle* v2, EContext* ctx)
{
    QAngle result = *v1;
    result.x /= v2->x;
    result.y /= v2->y;
    result.z /= v2->z;
    return EValue(ctx, result);
}

std::string QAngle_tostring(QAngle* v1)
{
    return string_format("QAngle(%f,%f,%f)", v1->x, v1->y, v1->z);
}

EValue Vector2D_add(Vector2D* v1, Vector2D* v2, EContext* ctx)
{
    Vector2D result = *v1 + *v2;
    return EValue(ctx, result);
}

bool Vector2D_eq(Vector2D* v1, Vector2D* v2, EContext* ctx)
{
    return (*v1 == *v2);
}

float Vector2D_len(Vector2D* v1)
{
    return FastSqrt(v1->x*v1->x + v1->y*v1->y);
}

EValue Vector2D_unm(Vector2D* v, EContext* ctx)
{
    Vector2D result = -(*v);
    return EValue(ctx, result);
}

EValue Vector2D_sub(Vector2D* v1, Vector2D* v2, EContext* ctx)
{
    Vector2D result = *v1 - *v2;
    return EValue(ctx, result);
}

EValue Vector2D_mul(Vector2D* v1, Vector2D* v2, EContext* ctx)
{
    Vector2D result = *v1;
    result.x *= v2->x;
    result.y *= v2->y;
    return EValue(ctx, result);
}

EValue Vector2D_div(Vector2D* v1, Vector2D* v2, EContext* ctx)
{
    Vector2D result = *v1;
    result.x /= v2->x;
    result.y /= v2->y;
    return EValue(ctx, result);
}

std::string Vector2D_tostring(Vector2D* v1)
{
    return string_format("Vector2D(%f,%f)", v1->x, v1->y);
}

EValue Vector4D_add(Vector4D* v1, Vector4D* v2, EContext* ctx)
{
    Vector4D result = *v1 + *v2;
    return EValue(ctx, result);
}

bool Vector4D_eq(Vector4D* v1, Vector4D* v2, EContext* ctx)
{
    return (*v1 == *v2);
}

float Vector4D_len(Vector4D* v1)
{
    return FastSqrt(v1->x*v1->x + v1->y*v1->y + v1->z*v1->z + v1->w*v1->w);
}

EValue Vector4D_unm(Vector4D* v, EContext* ctx)
{
    Vector4D result = -(*v);
    return EValue(ctx, result);
}

EValue Vector4D_sub(Vector4D* v1, Vector4D* v2, EContext* ctx)
{
    Vector4D result = *v1 - *v2;
    return EValue(ctx, result);
}

EValue Vector4D_mul(Vector4D* v1, Vector4D* v2, EContext* ctx)
{
    Vector4D result = *v1;
    result.x *= v2->x;
    result.y *= v2->y;
    result.z *= v2->z;
    result.w *= v2->w;
    return EValue(ctx, result);
}

EValue Vector4D_div(Vector4D* v1, Vector4D* v2, EContext* ctx)
{
    Vector4D result = *v1;
    result.x /= v2->x;
    result.y /= v2->y;
    result.z /= v2->z;
    result.w /= v2->w;
    return EValue(ctx, result);
}

std::string Vector4D_tostring(Vector4D* v1)
{
    return string_format("Vector4D(%f,%f,%f,%f)", v1->x, v1->y, v1->z, v1->w);
}

int Color_index(lua_State* L)
{
    Color* v = *static_cast<Color**>(luaL_checkudata(L, 1, typeid(Color).name()));
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

    luaL_getmetatable(L, typeid(Color).name());
    lua_pushstring(L, key.c_str());
    lua_rawget(L, -2);
    return 1;
}

JSValue Color_indexJS(JSContext* ctx, JSValue this_arg, int argc, JSValue* argv)
{
    EContext* ct = GetContextByState(ctx);
    std::string key = EValue::fromJSStack(ct, argv[1]).cast<std::string>();
    Color* v = EValue::fromJSStack(ct, argv[2]).cast<Color*>();

    if(key == "r") return Stack<int>::pushJS(ct, v->r());
    else if(key == "g") return Stack<int>::pushJS(ct, v->g());
    else if(key == "b") return Stack<int>::pushJS(ct, v->b());
    else if(key == "a") return Stack<int>::pushJS(ct, v->a());

    return JS_UNDEFINED;
}

int Color_newindex(lua_State* L)
{
    Color* v = *static_cast<Color**>(luaL_checkudata(L, 1, typeid(Color).name()));
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

JSValue Color_newindexJS(JSContext* ctx, JSValue this_arg, int argc, JSValue* argv)
{
    EContext* ct = GetContextByState(ctx);
    std::string key = EValue::fromJSStack(ct, argv[1]).cast<std::string>();
    int value = EValue::fromJSStack(ct, argv[2]).cast<int>();
    Color* v = EValue::fromJSStack(ct, argv[3]).cast<Color*>();

    if(key == "r") v->SetColor(value, v->g(), v->b(), v->a());
    else if(key == "g") v->SetColor(v->r(), value, v->b(), v->a());
    else if(key == "b") v->SetColor(v->r(), v->g(), value, v->a());
    else if(key == "a") v->SetColor(v->r(), v->g(), v->b(), value);

    return JS_UNDEFINED;
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
    BeginClass<Vector>("Vector", state)
        .addConstructor<float, float, float>()
        .addProperty("x", &Vector::x, true)
        .addProperty("y", &Vector::y, true)
        .addProperty("z", &Vector::z, true)
        .addFunction("GetPtr", Vector_GetPtr)
        .addLuaFunction("__add", Vector_add)
        .addLuaFunction("__eq", Vector_eq)
        .addLuaFunction("__len", Vector_len)
        .addLuaFunction("__tostring", Vector_tostring)
        .addLuaFunction("__unm", Vector_unm)
        .addLuaFunction("__sub", Vector_sub)
        .addLuaFunction("__mul", Vector_mul)
        .addLuaFunction("__div", Vector_div)
        .addJSFunction("toString", Vector_tostring)
        .addJSFunction("add", Vector_add)
        .addJSFunction("equal", Vector_eq)
        .addJSFunction("length", Vector_len)
        .addJSFunction("unm", Vector_unm)
        .addJSFunction("sub", Vector_sub)
        .addJSFunction("mul", Vector_mul)
        .addJSFunction("div", Vector_div)
    .endClass();

    BeginClass<Color>("Color", state)
        .addConstructor<int, int, int, int>()
        .addFunction("GetPtr", Color_GetPtr)
        .addLuaFunction("__tostring", Color_tostring)
        .addLuaFunction("toString", Color_tostring)
        .addLuaCustomIndex(Color_index, Color_newindex)
        .addJSCustomIndex(Color_indexJS, Color_newindexJS)
    .endClass();

    BeginClass<QAngle>("QAngle", state)
        .addConstructor<float, float, float>()
        .addProperty("x", &QAngle::x, true)
        .addProperty("y", &QAngle::y, true)
        .addProperty("z", &QAngle::z, true)
        .addFunction("GetPtr", QAngle_GetPtr)
        .addLuaFunction("__add", QAngle_add)
        .addLuaFunction("__eq", QAngle_eq)
        .addLuaFunction("__len", QAngle_len)
        .addLuaFunction("__unm", QAngle_unm)
        .addLuaFunction("__sub", QAngle_sub)
        .addLuaFunction("__mul", QAngle_mul)
        .addLuaFunction("__div", QAngle_div)
        .addLuaFunction("__tostring", QAngle_tostring)
        .addJSFunction("toString", QAngle_tostring)
        .addJSFunction("add", QAngle_add)
        .addJSFunction("equal", QAngle_eq)
        .addJSFunction("length", QAngle_len)
        .addJSFunction("unm", QAngle_unm)
        .addJSFunction("sub", QAngle_sub)
        .addJSFunction("mul", QAngle_mul)
        .addJSFunction("div", QAngle_div)
    .endClass();

    BeginClass<Vector2D>("Vector2D", state)
        .addConstructor<float, float>()
        .addProperty("x", &Vector2D::x, true)
        .addProperty("y", &Vector2D::y, true)
        .addFunction("GetPtr", Vector2D_GetPtr)
        .addFunction("__add", Vector2D_add)
        .addFunction("__eq", Vector2D_eq)
        .addFunction("__len", Vector2D_len)
        .addLuaFunction("__unm", Vector2D_unm)
        .addLuaFunction("__sub", Vector2D_sub)
        .addLuaFunction("__mul", Vector2D_mul)
        .addLuaFunction("__div", Vector2D_div)
        .addLuaFunction("__tostring", Vector2D_tostring)
        .addJSFunction("toString", Vector2D_tostring)
        .addJSFunction("add", Vector2D_add)
        .addJSFunction("equal", Vector2D_eq)
        .addJSFunction("length", Vector2D_len)
        .addJSFunction("unm", Vector2D_unm)
        .addJSFunction("sub", Vector2D_sub)
        .addJSFunction("mul", Vector2D_mul)
        .addJSFunction("div", Vector2D_div)
    .endClass();

    BeginClass<Vector4D>("Vector4D", state)
        .addConstructor<float, float, float, float>()
        .addProperty("x", &Vector4D::x, true)
        .addProperty("y", &Vector4D::y, true)
        .addProperty("z", &Vector4D::z, true)
        .addProperty("w", &Vector4D::w, true)
        .addFunction("GetPtr", Vector4D_GetPtr)
        .addLuaFunction("__add", Vector4D_add)
        .addLuaFunction("__eq", Vector4D_eq)
        .addLuaFunction("__len", Vector4D_len)
        .addLuaFunction("__unm", Vector4D_unm)
        .addLuaFunction("__sub", Vector4D_sub)
        .addLuaFunction("__mul", Vector4D_mul)
        .addLuaFunction("__div", Vector4D_div)
        .addLuaFunction("__tostring", Vector4D_tostring)
        .addJSFunction("toString", Vector4D_tostring)
        .addJSFunction("add", Vector4D_add)
        .addJSFunction("equal", Vector4D_eq)
        .addJSFunction("length", Vector4D_len)
        .addJSFunction("unm", Vector4D_unm)
        .addJSFunction("sub", Vector4D_sub)
        .addJSFunction("mul", Vector4D_mul)
        .addJSFunction("div", Vector4D_div)
    .endClass();
}

LoadScriptingComponent(
    baseclasses,
    LoadBaseClass
)