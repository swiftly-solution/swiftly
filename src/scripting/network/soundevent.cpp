#include <scripting/core.h>

#include <network/soundevents/soundevent.h>

LoadScriptingComponent(soundevent, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("SoundEvent");

    ADD_CLASS_FUNCTION("SoundEvent", "SoundEvent", [](FunctionContext* context, ClassData* data) -> void {
        auto classData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (classData) {
            if (classData->HasData("se_ptr")) {
                data->SetData("se_ptr", classData->GetData<Soundevent*>("se_ptr"));
            }
            else {
                data->SetData("se_ptr", new Soundevent());
            }
        }
        else {
            data->SetData("se_ptr", new Soundevent());
        }
    });

    ADD_CLASS_FUNCTION("SoundEvent", "~SoundEvent", [](FunctionContext* context, ClassData* data) -> void {
        if (data->HasData("se_ptr")) {
            delete data->GetData<Soundevent*>("se_ptr");
        }
    });
     
    ADD_CLASS_FUNCTION("SoundEvent", "Emit", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->Emit());
    });

    ADD_CLASS_FUNCTION("SoundEvent", "GetName", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->GetName());
    });

    ADD_CLASS_FUNCTION("SoundEvent", "SetName", [](FunctionContext* context, ClassData* data) -> void {
        std::string name = context->GetArgumentOr<std::string>(0, "");
        data->GetData<Soundevent*>("se_ptr")->SetName(name);
    });

    ADD_CLASS_FUNCTION("SoundEvent", "GetSourceEntityIndex", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->GetSourceEntityIndex());
    });

    ADD_CLASS_FUNCTION("SoundEvent", "SetSourceEntityIndex", [](FunctionContext* context, ClassData* data) -> void {
        int index = context->GetArgumentOr<int>(0, -1);
        data->GetData<Soundevent*>("se_ptr")->SetSourceEntityIndex(index);
    });

    ADD_CLASS_FUNCTION("SoundEvent", "AddClient", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = context->GetArgumentOr<int>(0, -1);
        if (playerid == -1) return;
        data->GetData<Soundevent*>("se_ptr")->AddClient(playerid);
    });

    ADD_CLASS_FUNCTION("SoundEvent", "RemoveClient", [](FunctionContext* context, ClassData* data) -> void {
        int playerid = context->GetArgumentOr<int>(0, -1);
        if (playerid == -1) return;
        data->GetData<Soundevent*>("se_ptr")->RemoveClient(playerid);
    });

    ADD_CLASS_FUNCTION("SoundEvent", "ClearClients", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<Soundevent*>("se_ptr")->ClearClients();
    });

    ADD_CLASS_FUNCTION("SoundEvent", "AddClients", [](FunctionContext* context, ClassData* data) -> void {
        data->GetData<Soundevent*>("se_ptr")->AddClients();
    });

    ADD_CLASS_FUNCTION("SoundEvent", "GetClients", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->GetClients());
    });

    ADD_CLASS_FUNCTION("SoundEvent", "HasField", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->HasField(field_name));
    });

    ADD_CLASS_FUNCTION("SoundEvent", "GetBool", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->GetBool(field_name));
    });

    ADD_CLASS_FUNCTION("SoundEvent", "SetBool", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        bool value = context->GetArgumentOr<bool>(1, false);
        data->GetData<Soundevent*>("se_ptr")->SetBool(field_name, value);
    });

    ADD_CLASS_FUNCTION("SoundEvent", "GetInt", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->GetInt(field_name));
    });

    ADD_CLASS_FUNCTION("SoundEvent", "SetInt", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        int value = context->GetArgumentOr<int>(1, 0);
        data->GetData<Soundevent*>("se_ptr")->SetInt(field_name, value);
    });

    ADD_CLASS_FUNCTION("SoundEvent", "GetUInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->GetUInt32(field_name));
    });

    ADD_CLASS_FUNCTION("SoundEvent", "SetUInt32", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        uint32_t value = context->GetArgumentOr<uint32_t>(1, 0);
        data->GetData<Soundevent*>("se_ptr")->SetUInt32(field_name, value);
    });

    ADD_CLASS_FUNCTION("SoundEvent", "GetUInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->GetUInt64(field_name));
    });

    ADD_CLASS_FUNCTION("SoundEvent", "SetUInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        uint64_t value = context->GetArgumentOr<uint64_t>(1, 0);
        data->GetData<Soundevent*>("se_ptr")->SetUInt64(field_name, value);
    });

    ADD_CLASS_FUNCTION("SoundEvent", "GetFloat", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->GetFloat(field_name));
    });

    ADD_CLASS_FUNCTION("SoundEvent", "SetFloat", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        float value = context->GetArgumentOr<float>(1, 0.0f);
        data->GetData<Soundevent*>("se_ptr")->SetFloat(field_name, value);
    });

    ADD_CLASS_FUNCTION("SoundEvent", "GetFloat3", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        context->SetReturn(data->GetData<Soundevent*>("se_ptr")->GetFloat3(field_name));
    });

    ADD_CLASS_FUNCTION("SoundEvent", "SetFloat3", [](FunctionContext* context, ClassData* data) -> void {
        std::string field_name = context->GetArgumentOr<std::string>(0, "");
        Vector value = context->GetArgumentOr<Vector>(1, Vector(0.0, 0.0, 0.0));
        data->GetData<Soundevent*>("se_ptr")->SetFloat3(field_name, value);
    });

})