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

    static void* pushRawDotnet(EContext* ctx, void* context, std::any value)
    {
        return SerializeData(value, ctx).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, std::any value, bool shouldReturn = false)
    {
        if (shouldReturn) {
            context->SetResult(value);
        }
        else {
            context->PushArgument(value);
        }
    }

    static std::any getLua(EContext* ctx, int ref)
    {
        return DeserializeData(EValue(ctx, ref, false), ctx);
    }

    static std::any getRawDotnet(EContext* ctx, CallContext* context, void* value, int type)
    {
        return DeserializeData(EValue(ctx, value, type), ctx);
    }

    static std::any getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr(), context->GetReturnType());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index), context->GetArgumentType(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return true;
    }

    static bool IsDotnetInstance(EContext* ctx, CallContext* context, int index)
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

    static ClassData* pushRawDotnet(EContext* ctx, CallContext* context, Vector value)
    {
        return (ClassData*)MAKE_CLASS_INSTANCE_CTX(ctx, "Vector", { { "vector_ptr", value } }).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, Vector value, bool shouldReturn = false)
    {
        ClassData* val = pushRawDotnet(ctx, context, value);

        if (shouldReturn) {
            context->SetReturnType(typesMap[typeid(void*)]);
            context->SetResult(val);
        }
        else {
            context->SetArgumentType(context->GetArgumentCount(), typesMap[typeid(void*)]);
            context->PushArgument(val);
        }
    }

    static Vector getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector>("vector_ptr");
    }

    static Vector getRawDotnet(EContext* ctx, CallContext* context, void* value)
    {
        return EValue(ctx, value, 18).cast<ClassData*>()->GetData<Vector>("vector_ptr");
    }

    static Vector getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("vector_ptr");
    }

    static bool isDotnetInstance(EContext* ctx, CallContext* context, int index)
    {
        return EValue(ctx, context->GetArgumentPtr(index), 18).cast<ClassData*>()->HasData("vector_ptr");
    }
};

template<>
struct Stack<Vector2D>
{
    static void pushLua(EContext* ctx, Vector2D value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Vector2D", { { "Vector2D_ptr", value } }).pushLua();
    }

    static ClassData* pushRawDotnet(EContext* ctx, CallContext* context, Vector2D value)
    {
        return (ClassData*)MAKE_CLASS_INSTANCE_CTX(ctx, "Vector2D", { { "Vector2D_ptr", value } }).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, Vector2D value, bool shouldReturn = false)
    {
        ClassData* val = pushRawDotnet(ctx, context, value);

        if (shouldReturn) {
            context->SetReturnType(typesMap[typeid(void*)]);
            context->SetResult(val);
        }
        else {
            context->SetArgumentType(context->GetArgumentCount(), typesMap[typeid(void*)]);
            context->PushArgument(val);
        }
    }

    static Vector2D getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr");
    }

    static Vector2D getRawDotnet(EContext* ctx, CallContext* context, void* value)
    {
        return EValue(ctx, value, 18).cast<ClassData*>()->GetData<Vector2D>("Vector2D_ptr");
    }

    static Vector2D getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Vector2D_ptr");
    }

    static bool isDotnetInstance(EContext* ctx, CallContext* context, int index)
    {
        return EValue(ctx, context->GetArgumentPtr(index), 18).cast<ClassData*>()->HasData("Vector2D_ptr");
    }
};

template<>
struct Stack<Vector4D>
{
    static void pushLua(EContext* ctx, Vector4D value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Vector4D", { { "Vector4D_ptr", value } }).pushLua();
    }

    static ClassData* pushRawDotnet(EContext* ctx, CallContext* context, Vector4D value)
    {
        return (ClassData*)MAKE_CLASS_INSTANCE_CTX(ctx, "Vector4D", { { "Vector4D_ptr", value } }).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, Vector4D value, bool shouldReturn = false)
    {
        ClassData* val = pushRawDotnet(ctx, context, value);

        if (shouldReturn) {
            context->SetReturnType(typesMap[typeid(void*)]);
            context->SetResult(val);
        }
        else {
            context->SetArgumentType(context->GetArgumentCount(), typesMap[typeid(void*)]);
            context->PushArgument(val);
        }
    }

    static Vector4D getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr");
    }

    static Vector4D getRawDotnet(EContext* ctx, CallContext* context, void* value)
    {
        return EValue(ctx, value, 18).cast<ClassData*>()->GetData<Vector4D>("Vector4D_ptr");
    }

    static Vector4D getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Vector4D_ptr");
    }

    static bool isDotnetInstance(EContext* ctx, CallContext* context, int index)
    {
        return EValue(ctx, context->GetArgumentPtr(index), 18).cast<ClassData*>()->HasData("Vector4D_ptr");
    }
};

template<>
struct Stack<Color>
{
    static void pushLua(EContext* ctx, Color value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "Color", { { "Color_ptr", value } }).pushLua();
    }

    static ClassData* pushRawDotnet(EContext* ctx, CallContext* context, Color value)
    {
        return (ClassData*)MAKE_CLASS_INSTANCE_CTX(ctx, "Color", { { "Color_ptr", value } }).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, Color value, bool shouldReturn = false)
    {
        ClassData* val = pushRawDotnet(ctx, context, value);

        if (shouldReturn) {
            context->SetReturnType(typesMap[typeid(void*)]);
            context->SetResult(val);
        }
        else {
            context->SetArgumentType(context->GetArgumentCount(), typesMap[typeid(void*)]);
            context->PushArgument(val);
        }
    }

    static Color getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<Color>("Color_ptr");
    }

    static Color getRawDotnet(EContext* ctx, CallContext* context, void* value)
    {
        return EValue(ctx, value, 18).cast<ClassData*>()->GetData<Color>("Color_ptr");
    }

    static Color getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("Color_ptr");
    }

    static bool isDotnetInstance(EContext* ctx, CallContext* context, int index)
    {
        return EValue(ctx, context->GetArgumentPtr(index), 18).cast<ClassData*>()->HasData("Color_ptr");
    }
};

template<>
struct Stack<QAngle>
{
    static void pushLua(EContext* ctx, QAngle value)
    {
        MAKE_CLASS_INSTANCE_CTX(ctx, "QAngle", { { "QAngle_ptr", value } }).pushLua();
    }

    static ClassData* pushRawDotnet(EContext* ctx, CallContext* context, QAngle value)
    {
        return (ClassData*)MAKE_CLASS_INSTANCE_CTX(ctx, "QAngle", { { "QAngle_ptr", value } }).getPointer();
    }

    static void pushDotnet(EContext* ctx, CallContext* context, QAngle value, bool shouldReturn = false)
    {
        ClassData* val = pushRawDotnet(ctx, context, value);

        if (shouldReturn) {
            context->SetReturnType(typesMap[typeid(void*)]);
            context->SetResult(val);
        }
        else {
            context->SetArgumentType(context->GetArgumentCount(), typesMap[typeid(void*)]);
            context->PushArgument(val);
        }
    }

    static QAngle getLua(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->GetData<QAngle>("QAngle_ptr");
    }

    static QAngle getRawDotnet(EContext* ctx, CallContext* context, void* value)
    {
        return EValue(ctx, value, 18).cast<ClassData*>()->GetData<QAngle>("QAngle_ptr");
    }

    static QAngle getDotnet(EContext* ctx, CallContext* context, int index)
    {
        if (index == -1) return getRawDotnet(ctx, context, context->GetResultPtr());
        else return getRawDotnet(ctx, context, context->GetArgumentPtr(index));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return EValue(ctx, ref, false).cast<ClassData*>()->HasData("QAngle_ptr");
    }

    static bool isDotnetInstance(EContext* ctx, CallContext* context, int index)
    {
        return EValue(ctx, context->GetArgumentPtr(index), 18).cast<ClassData*>()->HasData("QAngle_ptr");
    }
};
