#ifndef _engine_convars_manager_h
#define _engine_convars_manager_h

#include <core/entrypoint.h>
#include <string>
#include <any>
#include <map>
#include <embedder/src/Embedder.h>

class ConvarManager
{
private:
    std::map<std::string, void*> cvarsMap;
public:
    ~ConvarManager();

    EConVarType GetConvarType(std::string cvar_name);
    std::any GetConvarValue(std::string cvar_name);
    void SetConvarValue(std::string cvar_name, std::any value);

    void CreateConvar(std::string cvar_name, EConVarType type, std::string description, int flags, std::any defaultValue, bool min, std::any min_value, bool max, std::any max_value);
    void DeleteConvar(std::string cvar_name);

    std::map<std::string, void*> GetCvarMap();
};

template<class T>
T AnyCastOr(std::any value, T defaultVal)
{
    try {
        return std::any_cast<T>(value);
    }
    catch (std::bad_any_cast& e) {
        return defaultVal;
    }
}

template<class T>
T AnyCastClassData(std::any value, std::string str, T defaultVal)
{
    try {
        ClassData* data = std::any_cast<ClassData*>(value);
        if (!data) return defaultVal;

        return data->GetDataOr<T>(str, defaultVal);
    }
    catch (std::bad_any_cast& e) {
        return defaultVal;
    }
}

extern ConvarManager g_cvarManager;

#endif