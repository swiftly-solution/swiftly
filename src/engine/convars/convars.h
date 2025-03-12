#ifndef _convars_h
#define _convars_h

#include <any>
#include <string>
#include <map>
#include "../../entrypoint.h"
#include "../../common.h"
#include "../../utils/utils.h"
#include "netmessages.pb.h"

ConVarRefAbstract FetchCVar(std::string cvarname);
std::any FetchCVarValue(std::string cvarname);
EConVarType FetchCVarType(std::string cvarname);

class FakeConVar
{
private:
    std::any m_value;
    EConVarType m_type;
    std::string m_name;
    ConCommand* m_cmd;

public:
    FakeConVar(std::string name, EConVarType type, std::any defaultValue, bool prot);
    ~FakeConVar();

    EConVarType GetType();
    void SetValue(std::any value);
    std::any GetValue();
    std::string GetStringValue();
};

bool FakeConvarExists(std::string name);
FakeConVar* GetFakeConvar(std::string name);
void DeleteFakeConvar(std::string name);
std::map<std::string, FakeConVar*> FetchFakeConvars();
void InsertFakeConvar(std::string name, EConVarType type, std::any defaultValue, bool prot);

class ConvarQuery
{
public:
    void Initialize();
    void Destroy();

    bool OnConVarQuery(const CNetMessagePB<CCLCMsg_RespondCvarValue>& msg);

    void QueryCvarClient(CPlayerSlot slot, std::string cvarName);
};

extern ConvarQuery* g_cvarQuery;

#endif