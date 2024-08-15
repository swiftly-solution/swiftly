#include "convars.h"

static void convarsCallback(const CCommandContext& context, const CCommand& args);
std::map<std::string, bool> convarCreated;

FakeConVar::FakeConVar(std::string name, EConVarType type, std::any defaultValue, bool prot)
{
    if (convarCreated.find(name) == convarCreated.end())
    {
        convarCreated.insert({ name, true });

        ConCommandRefAbstract convarRef;
        new ConCommand(&convarRef, name.c_str(), convarsCallback, "Swiftly ConVar", FCVAR_LINKED_CONCOMMAND | FCVAR_SPONLY | (prot ? FCVAR_PROTECTED : FCVAR_NONE));
    }

    m_value = defaultValue;
    m_type = type;
    m_name = name;
}

FakeConVar::~FakeConVar()
{
}

EConVarType FakeConVar::GetType()
{
    return this->m_type;
}

void FakeConVar::SetValue(std::any value)
{
    this->m_value = value;
}

std::any FakeConVar::GetValue()
{
    return this->m_value;
}

static void convarsCallback(const CCommandContext& context, const CCommand& args)
{
    CCommand tokenizedArgs;
    tokenizedArgs.Tokenize(args.GetCommandString());

    std::string cvar = tokenizedArgs[0];
    if (fakeConvars.find(cvar) == fakeConvars.end()) return;

    auto convar = fakeConvars.at(cvar);

    if (args.ArgC() < 2) {
        std::string convarOutput = string_format("%s {VALUE}\n", cvar.c_str());
        std::string value = "";
        if (convar->GetType() == EConVarType_Int16)
            value = std::to_string(std::any_cast<int16_t>(convar->GetValue()));
        else if (convar->GetType() == EConVarType_UInt16)
            value = std::to_string(std::any_cast<uint16_t>(convar->GetValue()));
        else if (convar->GetType() == EConVarType_UInt32)
            value = std::to_string(std::any_cast<uint32_t>(convar->GetValue()));
        else if (convar->GetType() == EConVarType_Int32)
            value = std::to_string(std::any_cast<int32_t>(convar->GetValue()));
        else if (convar->GetType() == EConVarType_UInt64)
            value = std::to_string(std::any_cast<uint64_t>(convar->GetValue()));
        else if (convar->GetType() == EConVarType_Int64)
            value = std::to_string(std::any_cast<int64_t>(convar->GetValue()));
        else if (convar->GetType() == EConVarType_Bool)
            value = (std::any_cast<bool>(convar->GetValue()) ? "true" : "false");
        else if (convar->GetType() == EConVarType_Float32)
            value = std::to_string(std::any_cast<float>(convar->GetValue()));
        else if (convar->GetType() == EConVarType_Float64)
            value = std::to_string(std::any_cast<double>(convar->GetValue()));
        else if (convar->GetType() == EConVarType_String)
            value = std::any_cast<std::string>(convar->GetValue());
        else if (convar->GetType() == EConVarType_Color) {
            Color col = std::any_cast<Color>(convar->GetValue());
            value = string_format("%d,%d,%d,%d", col.r(), col.g(), col.b(), col.a());
        }
        else if (convar->GetType() == EConVarType_Vector2) {
            Vector2D vec = std::any_cast<Vector2D>(convar->GetValue());
            value = string_format("%f,%f", vec.x, vec.y);
        }
        else if (convar->GetType() == EConVarType_Vector3) {
            Vector vec = std::any_cast<Vector>(convar->GetValue());
            value = string_format("%f,%f,%f", vec.x, vec.y, vec.z);
        }
        else if (convar->GetType() == EConVarType_Vector4) {
            Vector4D vec = std::any_cast<Vector4D>(convar->GetValue());
            value = string_format("%f,%f,%f,%f", vec.x, vec.y, vec.z, vec.w);
        }
        else if (convar->GetType() == EConVarType_Qangle) {
            QAngle ang = std::any_cast<QAngle>(convar->GetValue());
            value = string_format("%f,%f,%f", ang.x, ang.y, ang.z);
        }
        else {
            value = "(null)";
        }

        PLUGIN_PRINTF("ConVar", "%s %s\n", cvar.c_str(), value.c_str());
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