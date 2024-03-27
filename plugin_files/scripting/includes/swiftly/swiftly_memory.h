#ifndef _swiftly_memory_h
#define _swiftly_memory_h

#include "swiftly_oslink.h"
#include <map>
#include <fstream>
#include "types.h"

#include <functional>

#define REGISTER_METHOD_VOID_NOARGS(method)         \
    typedef void (*FuncType)();                     \
    void *ptr = FetchFunctionPtr(nullptr, #method); \
    if (ptr != nullptr)                             \
    {                                               \
        reinterpret_cast<FuncType>(ptr)();          \
    }                                               \
    else                                            \
        NOT_SUPPORTED(#method);

#define REGISTER_METHOD_VOID(method, ...)             \
    typedef void (*FuncType)(...);                    \
    void *ptr = FetchFunctionPtr(nullptr, #method);   \
    if (ptr != nullptr)                               \
    {                                                 \
        reinterpret_cast<FuncType>(ptr)(__VA_ARGS__); \
    }                                                 \
    else                                              \
        NOT_SUPPORTED(#method);

#define REGISTER_METHOD_NOARGS(TYPE, VALUE, method) \
    typedef TYPE (*FuncType)();                     \
    void *ptr = FetchFunctionPtr(nullptr, #method); \
    if (ptr != nullptr)                             \
    {                                               \
        return reinterpret_cast<FuncType>(ptr)();   \
    }                                               \
    else                                            \
    {                                               \
        NOT_SUPPORTED(#method);                     \
        return VALUE;                               \
    }

#define REGISTER_METHOD(TYPE, VALUE, method, ...)            \
    typedef TYPE (*FuncType)(...);                           \
    void *ptr = FetchFunctionPtr(nullptr, #method);          \
    if (ptr != nullptr)                                      \
    {                                                        \
        return reinterpret_cast<FuncType>(ptr)(__VA_ARGS__); \
    }                                                        \
    else                                                     \
    {                                                        \
        NOT_SUPPORTED(#method);                              \
        return VALUE;                                        \
    }

typedef const char *(*Player_GetVar)(uint32_t, const char *);

typedef const char *(*Database_EscapeString)(const char *, const char *);
typedef bool (*Database_Connect)(const char *);

typedef const char *(*Configuration_Fetch)(const char *);
typedef uint32_t (*Configuration_FetchArraySize)(const char *);
typedef bool (*Configuration_Exists)(const char *);

typedef uint64_t (*HTTP_CreateRequest)(const char *);

typedef void (*HTTP_Get)(uint64_t, const char *);
typedef void (*HTTP_Delete)(uint64_t, const char *);
typedef void (*HTTP_Post)(uint64_t, const char *);
typedef void (*HTTP_Put)(uint64_t, const char *);
typedef void (*HTTP_Patch)(uint64_t, const char *);

void *FetchFunctionPtr(const char *filePath, const char *function_name);

#endif