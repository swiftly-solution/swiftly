#include "convars.h"
#include <set>
#include "../gameevents/gameevents.h"

static void convarsCallback(const CCommandContext& context, const CCommand& args);
std::set<std::string> convarCreated;
std::map<std::string, FakeConVar*> fakeConvars;

bool FakeConvarExists(std::string name)
{
    return (fakeConvars.find(name) != fakeConvars.end());
}

FakeConVar* GetFakeConvar(std::string name)
{
    if (!FakeConvarExists(name)) return nullptr;

    return fakeConvars.at(name);
}

void DeleteFakeConvar(std::string name)
{
    if (!FakeConvarExists(name)) return;

    auto cvar = GetFakeConvar(name);
    if(cvar) delete cvar;

    fakeConvars.erase(name);
}

std::map<std::string, FakeConVar*> FetchFakeConvars()
{
    return fakeConvars;
}

void InsertFakeConvar(std::string name, EConVarType type, std::any defaultValue, bool prot)
{
    if (FakeConvarExists(name)) return;

    fakeConvars.insert({ name, new FakeConVar(name, type, defaultValue, prot) });
}

FakeConVar::FakeConVar(std::string name, EConVarType type, std::any defaultValue, bool prot)
{
    if (convarCreated.find(name) == convarCreated.end())
    {
        convarCreated.insert(name);

        m_cmd = new ConCommand(name.c_str(), convarsCallback, "Swiftly ConVar", FCVAR_LINKED_CONCOMMAND | FCVAR_SPONLY | (prot ? FCVAR_PROTECTED : FCVAR_NONE));
    }

    m_value = defaultValue;
    m_type = type;
    m_name = name;
}

FakeConVar::~FakeConVar()
{
    delete m_cmd;
}

EConVarType FakeConVar::GetType()
{
    return this->m_type;
}

void FakeConVar::SetValue(std::any value)
{
    this->m_value = value;

    if (g_gameEventManager->FindListener(eventManager, "server_cvar")) {
        IGameEvent* gEv = g_gameEventManager->CreateEvent("server_cvar");
        gEv->SetString("cvarname", this->m_name.c_str());
        gEv->SetString("cvarvalue", this->GetStringValue().c_str());

        g_gameEventManager->FireEvent(gEv);
    }
}

std::any FakeConVar::GetValue()
{
    if (!this->m_value.has_value()) return nullptr;

    return this->m_value;
}

std::string FakeConVar::GetStringValue()
{
    std::string value = "";

    if (GetType() == EConVarType_Int16)
        value = std::to_string(std::any_cast<int16_t>(GetValue()));
    else if (GetType() == EConVarType_UInt16)
        value = std::to_string(std::any_cast<uint16_t>(GetValue()));
    else if (GetType() == EConVarType_UInt32)
        value = std::to_string(std::any_cast<uint32_t>(GetValue()));
    else if (GetType() == EConVarType_Int32)
        value = std::to_string(std::any_cast<int32_t>(GetValue()));
    else if (GetType() == EConVarType_UInt64)
        value = std::to_string(std::any_cast<uint64_t>(GetValue()));
    else if (GetType() == EConVarType_Int64)
        value = std::to_string(std::any_cast<int64_t>(GetValue()));
    else if (GetType() == EConVarType_Bool)
        value = (std::any_cast<bool>(GetValue()) ? "true" : "false");
    else if (GetType() == EConVarType_Float32)
        value = std::to_string(std::any_cast<float>(GetValue()));
    else if (GetType() == EConVarType_Float64)
        value = std::to_string(std::any_cast<double>(GetValue()));
    else if (GetType() == EConVarType_String)
        value = std::any_cast<std::string>(GetValue());
    else if (GetType() == EConVarType_Color) {
        Color col = std::any_cast<Color>(GetValue());
        value = string_format("%d,%d,%d,%d", col.r(), col.g(), col.b(), col.a());
    }
    else if (GetType() == EConVarType_Vector2) {
        Vector2D vec = std::any_cast<Vector2D>(GetValue());
        value = string_format("%f,%f", vec.x, vec.y);
    }
    else if (GetType() == EConVarType_Vector3) {
        Vector vec = std::any_cast<Vector>(GetValue());
        value = string_format("%f,%f,%f", vec.x, vec.y, vec.z);
    }
    else if (GetType() == EConVarType_Vector4) {
        Vector4D vec = std::any_cast<Vector4D>(GetValue());
        value = string_format("%f,%f,%f,%f", vec.x, vec.y, vec.z, vec.w);
    }
    else if (GetType() == EConVarType_Qangle) {
        QAngle ang = std::any_cast<QAngle>(GetValue());
        value = string_format("%f,%f,%f", ang.x, ang.y, ang.z);
    }
    else {
        value = "(null)";
    }

    return value;
}

static void convarsCallback(const CCommandContext& context, const CCommand& args)
{
    CCommand tokenizedArgs;
    tokenizedArgs.Tokenize(args.GetCommandString());

    std::string cvar = tokenizedArgs[0];
    if (fakeConvars.find(cvar) == fakeConvars.end()) return;

    auto convar = fakeConvars.at(cvar);

    if (args.ArgC() < 2) {
        PLUGIN_PRINTF("ConVar", "%s %s\n", cvar.c_str(), convar->GetStringValue().c_str());
    }
    else {
        if (convar->GetType() == EConVarType_Int16)
            convar->SetValue(V_StringToInt16(tokenizedArgs[1], std::any_cast<int16_t>(convar->GetValue())));
        else if (convar->GetType() == EConVarType_UInt16)
            convar->SetValue(V_StringToUint16(tokenizedArgs[1], std::any_cast<uint16_t>(convar->GetValue())));
        else if (convar->GetType() == EConVarType_UInt32)
            convar->SetValue(V_StringToUint32(tokenizedArgs[1], std::any_cast<uint32_t>(convar->GetValue())));
        else if (convar->GetType() == EConVarType_Int32)
            convar->SetValue(V_StringToInt32(tokenizedArgs[1], std::any_cast<int32_t>(convar->GetValue())));
        else if (convar->GetType() == EConVarType_UInt64)
            convar->SetValue(V_StringToUint64(tokenizedArgs[1], std::any_cast<uint64_t>(convar->GetValue())));
        else if (convar->GetType() == EConVarType_Int64)
            convar->SetValue(V_StringToInt64(tokenizedArgs[1], std::any_cast<int64_t>(convar->GetValue())));
        else if (convar->GetType() == EConVarType_Bool)
            convar->SetValue(V_StringToBool(tokenizedArgs[1], std::any_cast<bool>(convar->GetValue())));
        else if (convar->GetType() == EConVarType_Float32)
            convar->SetValue(V_StringToFloat32(tokenizedArgs[1], std::any_cast<float>(convar->GetValue())));
        else if (convar->GetType() == EConVarType_Float64)
            convar->SetValue(V_StringToFloat64(tokenizedArgs[1], std::any_cast<double>(convar->GetValue())));
        else if (convar->GetType() == EConVarType_String)
            convar->SetValue(std::string(tokenizedArgs[1]));
        else if (convar->GetType() == EConVarType_Color) {
            Color col = std::any_cast<Color>(convar->GetValue());
            V_StringToColor(tokenizedArgs[1], col);
            convar->SetValue(col);
        }
        else if (convar->GetType() == EConVarType_Vector2) {
            Vector2D vec = std::any_cast<Vector2D>(convar->GetValue());
            V_StringToVector2D(tokenizedArgs[1], vec);
            convar->SetValue(vec);
        }
        else if (convar->GetType() == EConVarType_Vector3) {
            Vector vec = std::any_cast<Vector>(convar->GetValue());
            V_StringToVector(tokenizedArgs[1], vec);
            convar->SetValue(vec);
        }
        else if (convar->GetType() == EConVarType_Vector4) {
            Vector4D vec = std::any_cast<Vector4D>(convar->GetValue());
            V_StringToVector4D(tokenizedArgs[1], vec);
            convar->SetValue(vec);
        }
        else if (convar->GetType() == EConVarType_Qangle) {
            QAngle ang = std::any_cast<QAngle>(convar->GetValue());
            V_StringToQAngle(tokenizedArgs[1], ang);
            convar->SetValue(ang);
        }
    }
}