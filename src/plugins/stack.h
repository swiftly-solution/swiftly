#ifndef _plugins_stack_h
#define _plugins_stack_h

#include <any>
#include <Embedder.h>
#include <public/tier1/utlstring.h>

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
        return JS_DupValue((JSContext*)ctx->GetState(), SerializeData(value, ctx).pushJS());
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
struct Stack<CUtlString>
{
    static void pushLua(EContext* ctx, CUtlString value)
    {
        Stack<std::string>::pushLua(ctx, value.Get());
    }

    static JSValue pushJS(EContext* ctx, CUtlString value)
    {
        return Stack<std::string>::pushJS(ctx, value.Get());
    }

    static CUtlString getLua(EContext* ctx, int ref)
    {
        return CUtlString(Stack<std::string>::getLua(ctx, ref).c_str());
    }

    static CUtlString getJS(EContext* ctx, JSValue value)
    {
        return CUtlString(Stack<std::string>::getJS(ctx, value).c_str());
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return Stack<std::string>::isLuaInstance(ctx, ref);
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return Stack<std::string>::isJSInstance(ctx, value);
    }
};

template<>
struct Stack<CUtlStringToken>
{
    static void pushLua(EContext* ctx, CUtlStringToken value)
    {
        Stack<int>::pushLua(ctx, value.GetHashCode());
    }

    static JSValue pushJS(EContext* ctx, CUtlStringToken value)
    {
        return Stack<int>::pushJS(ctx, value.GetHashCode());
    }

    static CUtlStringToken getLua(EContext* ctx, int ref)
    {
        return CUtlStringToken(Stack<int>::getLua(ctx, ref));
    }

    static CUtlStringToken getJS(EContext* ctx, JSValue value)
    {
        return CUtlStringToken(Stack<int>::getJS(ctx, value));
    }

    static bool isLuaInstance(EContext* ctx, int ref)
    {
        return Stack<int>::isLuaInstance(ctx, ref);
    }

    static bool isJSInstance(EContext* ctx, JSValue value)
    {
        return Stack<int>::isJSInstance(ctx, value);
    }
};

#endif