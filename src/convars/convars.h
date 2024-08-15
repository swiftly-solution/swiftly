#ifndef _convars_h
#define _convars_h

#include <any>
#include <string>
#include <map>
#include "../entrypoint.h"
#include "../common.h"
#include "../utils/utils.h"

ConVar* FetchCVar(std::string cvarname);
std::any FetchCVarValue(std::string cvarname);
EConVarType FetchCVarType(std::string cvarname);

class FakeConVar
{
private:
    std::any m_value;
    EConVarType m_type;
    std::string m_name;

public:
    FakeConVar(std::string name, EConVarType type, std::any defaultValue, bool prot);
    ~FakeConVar();

    EConVarType GetType();
    void SetValue(std::any value);
    std::any GetValue();
};

extern std::map<std::string, FakeConVar*> fakeConvars;

#endif