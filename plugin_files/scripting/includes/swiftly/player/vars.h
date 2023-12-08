#ifndef _player_vars_h
#define _player_vars_h

#include <stdint.h>
#include "../swiftly_memory.h"

#include <type_traits>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <any>

class BaseVarsValue
{
public:
    virtual ~BaseVarsValue() {}
    virtual std::string getType() const = 0;
};

template <typename T>
class TypedVarsValue : public BaseVarsValue
{
public:
    TypedVarsValue(const T &value) : data(value) {}

    T getValue() const
    {
        return data;
    }

    std::string getType() const override
    {
        return typeid(T).name();
    }

private:
    T data;
};

std::any DeserializeVarsData(const char *jsonData);

class Vars
{
private:
    uint32_t m_playerSlot;

public:
    Vars(uint32_t playerSlot) : m_playerSlot(playerSlot) {}

    template <typename T>
    void Set(const char *name, T value)
    {
        int type = 0;

        if constexpr (std::is_same_v<T, const char *>)
            type = 1;
        else if constexpr (std::is_same_v<T, int>)
            type = 2;
        else if constexpr (std::is_same_v<T, unsigned int>)
            type = 3;
        else if constexpr (std::is_same_v<T, double>)
            type = 4;
        else if constexpr (std::is_same_v<T, long>)
            type = 5;
        else if constexpr (std::is_same_v<T, unsigned long>)
            type = 6;
        else if constexpr (std::is_same_v<T, bool>)
            type = 7;
        else if constexpr (std::is_same_v<T, long long>)
            type = 8;
        else if constexpr (std::is_same_v<T, unsigned long long>)
            type = 9;

        if (type == 0)
            return;

        void *player_SetVar = FetchFunctionPtr(nullptr, "scripting_Player_SetVar");
        if (player_SetVar != nullptr)
            reinterpret_cast<Player_SetVar>(player_SetVar)(this->m_playerSlot, name, type, value);
    }

    template <typename T>
    T Get(const char *key)
    {
        void *player_GetVar = FetchFunctionPtr(nullptr, "scripting_Player_GetVar");
        if (player_GetVar)
        {
            const char *value = reinterpret_cast<Player_GetVar>(player_GetVar)(this->m_playerSlot, key);

            try
            {
                return std::any_cast<T>(DeserializeVarsData(value));
            }
            catch (std::bad_any_cast err)
            {
                return 0;
            }
        }
        else
            return 0;
    }
};

#endif