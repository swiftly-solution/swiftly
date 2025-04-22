#pragma once

#include <any>
#include <embedder/src/Embedder.h>
#include <core/entrypoint.h>

std::any DeserializeData(EValue ref, EContext* state);
EValue SerializeData(std::any data, EContext* state);

template<class T>
struct Stack;

template<>
struct Stack<std::any>
{
    static void pushLua(EContext* ctx, std::any value)
    {
        SerializeData(value, ctx).pushLua();
    }

    static JSValue pushJS(EContext* ctx, std::any value)
    {
        return JS_DupValue(ctx->GetJSState(), SerializeData(value, ctx).pushJS());
    }

    static std::any getLua(EContext* ctx, int ref)
    {
        return DeserializeData(EValue(ctx, ref, false), ctx);
    }

    static std::any getJS(EContext* ctx, JSValue value)
    {
        return DeserializeData(EValue(ctx, value), ctx);
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return true;
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return true;
    }
};

template<>
struct Stack<Vector>
{
    static void pushLua(EContext* ctx, Vector value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Vector", { { "vector_ptr", value } }).pushLua();
    }

    static JSValue pushJS(EContext* ctx, Vector value)
    {
        return JS_DupValue(ctx->GetJSState(), MAKE_CLASS_INSTANCE_CTX(ctx, "Vector", { { "vector_ptr", value } }).pushJS());
    }

    static Vector getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector>("vector_ptr");
    }

    static Vector getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Vector>("vector_ptr");
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("vector_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("vector_ptr");
    }
};

template<>
struct Stack<Vector2D>
{
    static void pushLua(EContext* ctx, Vector2D value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Vector2D", { { "Vector2D_ptr", value } }).pushLua();
    }

    static JSValue pushJS(EContext* ctx, Vector2D value)
    {
        return JS_DupValue(ctx->GetJSState(), MAKE_CLASS_INSTANCE_CTX(ctx, "Vector2D", { { "Vector2D_ptr", value } }).pushJS());
    }

    static Vector2D getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr");
    }

    static Vector2D getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr");
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Vector2D_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("Vector2D_ptr");
    }
};

template<>
struct Stack<Vector4D>
{
    static void pushLua(EContext* ctx, Vector4D value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Vector4D", { { "Vector4D_ptr", value } }).pushLua();
    }

    static JSValue pushJS(EContext* ctx, Vector4D value)
    {
        return JS_DupValue(ctx->GetJSState(), MAKE_CLASS_INSTANCE_CTX(ctx, "Vector4D", { { "Vector4D_ptr", value } }).pushJS());
    }

    static Vector4D getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr");
    }

    static Vector4D getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr");
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Vector4D_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("Vector4D_ptr");
    }
};

template<>
struct Stack<Color>
{
    static void pushLua(EContext* ctx, Color value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Color", { { "Color_ptr", value } }).pushLua();
    }

    static JSValue pushJS(EContext* ctx, Color value)
    {
        return JS_DupValue(ctx->GetJSState(), MAKE_CLASS_INSTANCE_CTX(ctx, "Color", { { "Color_ptr", value } }).pushJS());
    }

    static Color getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Color>("Color_ptr");
    }

    static Color getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<Color>("Color_ptr");
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Color_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("Color_ptr");
    }
};

template<>
struct Stack<QAngle>
{
    static void pushLua(EContext* ctx, QAngle value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "QAngle", { { "QAngle_ptr", value } }).pushLua();
    }

    static JSValue pushJS(EContext* ctx, QAngle value)
    {
        return JS_DupValue(ctx->GetJSState(), MAKE_CLASS_INSTANCE_CTX(ctx, "QAngle", { { "QAngle_ptr", value } }).pushJS());
    }

    static QAngle getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<QAngle>("QAngle_ptr");
    }

    static QAngle getJS(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->GetData<QAngle>("QAngle_ptr");
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("QAngle_ptr");
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return EValue(ctx, value).cast<ClassData*>()->HasData("QAngle_ptr");
    }
};
