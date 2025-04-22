#include <scripting/core.h>

#include <public/entity2/entitykeyvalues.h>
#include <utils/utils.h>

LoadScriptingComponent(memory_centitykeyvalues, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("CEntityKeyValues");

    ADD_CLASS_FUNCTION("CEntityKeyValues", "CEntityKeyValues", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("centitykeyvalues_ptr", (void*)(new CEntityKeyValues()));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetBool", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(false);

        context->SetReturn(((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetBool(key.c_str()));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetInt", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(0);

        context->SetReturn(((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetInt(key.c_str()));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetUint", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(0);

        context->SetReturn(((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetUint(key.c_str()));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(0);

        context->SetReturn(((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetInt64(key.c_str()));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetUint64", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(0);

        context->SetReturn(((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetUint64(key.c_str()));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetFloat", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(0.0);

        context->SetReturn(((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetFloat(key.c_str()));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(0.0);

        context->SetReturn(((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetDouble(key.c_str()));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetString", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn("");

        context->SetReturn(std::string(((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetString(key.c_str())));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetPtr", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn("0x0");

        context->SetReturn(string_format("%p", ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetPtr(key.c_str())));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetStringToken", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(0);

        context->SetReturn(((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetStringToken(key.c_str()).GetHashCode());
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetVector", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(MAKE_CLASS_INSTANCE("Vector", { { "vector_ptr", Vector(0.0,0.0,0.0) } }));

        context->SetReturn(MAKE_CLASS_INSTANCE("Vector", { { "vector_ptr", ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetVector(key.c_str()) } }));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetVector2D", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(MAKE_CLASS_INSTANCE("Vector2D", { { "Vector2D_ptr", Vector2D(0.0,0.0) } }));

        context->SetReturn(MAKE_CLASS_INSTANCE("Vector2D", { { "Vector2D_ptr", ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetVector2D(key.c_str()) } }));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetVector4D", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(MAKE_CLASS_INSTANCE("Vector4D", { { "Vector4D_ptr", Vector4D(0.0,0.0,0.0,0.0) } }));

        context->SetReturn(MAKE_CLASS_INSTANCE("Vector4D", { { "Vector4D_ptr", ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetVector4D(key.c_str()) } }));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetColor", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(MAKE_CLASS_INSTANCE("Color", { { "Color_ptr", Color(0,0,0,0) } }));

        context->SetReturn(MAKE_CLASS_INSTANCE("Color", { { "Color_ptr", ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetColor(key.c_str()) } }));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "GetQAngle", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return context->SetReturn(MAKE_CLASS_INSTANCE("QAngle", { { "QAngle_ptr", QAngle(0.0,0.0,0.0) } }));

        context->SetReturn(MAKE_CLASS_INSTANCE("QAngle", { { "QAngle_ptr", ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->GetQAngle(key.c_str()) } }));
    });

    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetBool", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        bool value = context->GetArgumentOr<bool>(1, false);

        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetBool(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetInt", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        int value = context->GetArgumentOr<int>(1, 0);
        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetInt(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetUint", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        uint32_t value = context->GetArgumentOr<uint32_t>(1, 0);
        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetUint(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetInt64", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        int64_t value = context->GetArgumentOr<int64_t>(1, 0);
        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetInt64(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetUint64", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        uint64_t value = context->GetArgumentOr<uint64_t>(1, 0);
        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetUint64(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetFloat", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        float value = context->GetArgumentOr<float>(1, 0.0);
        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetFloat(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetDouble", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        double value = context->GetArgumentOr<double>(1, 0.0);
        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetDouble(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetString", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        std::string value = context->GetArgumentOr<std::string>(1, "");
        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetString(key.c_str(), value.c_str());
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetPtr", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        std::string value = context->GetArgumentOr<std::string>(1, "0x0");
        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetPtr(key.c_str(), StringToPtr(value));
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetStringToken", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        uint32_t value = context->GetArgumentOr<uint32_t>(1, 0);
        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetStringToken(key.c_str(), CUtlStringToken(value));
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetVector", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        ClassData* cdata = context->GetArgumentOr<ClassData*>(1, nullptr);
        if(!cdata) return;
        Vector value = cdata->GetData<Vector>("vector_ptr");

        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetVector(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetVector2D", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        ClassData* cdata = context->GetArgumentOr<ClassData*>(1, nullptr);
        if(!cdata) return;
        Vector2D value = cdata->GetData<Vector2D>("Vector2D_ptr");

        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetVector2D(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetVector4D", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        ClassData* cdata = context->GetArgumentOr<ClassData*>(1, nullptr);
        if(!cdata) return;
        Vector4D value = cdata->GetData<Vector4D>("Vector4D_ptr");

        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetVector4D(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetColor", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        ClassData* cdata = context->GetArgumentOr<ClassData*>(1, nullptr);
        if(!cdata) return;
        Color value = cdata->GetData<Color>("Color_ptr");

        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetColor(key.c_str(), value);
    });
    
    ADD_CLASS_FUNCTION("CEntityKeyValues", "SetQAngle", [](FunctionContext* context, ClassData* data) -> void {
        std::string key = context->GetArgumentOr<std::string>(0, "");
        if(key == "") return;

        ClassData* cdata = context->GetArgumentOr<ClassData*>(1, nullptr);
        if(!cdata) return;
        QAngle value = cdata->GetData<QAngle>("QAngle_ptr");

        ((CEntityKeyValues*)(data->GetData<void*>("centitykeyvalues_ptr")))->SetQAngle(key.c_str(), value);
    });
    
})