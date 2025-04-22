#include <scripting/core.h>
#include <dynlibutils/module.h>

#include <memory/gamedata/gamedata.h>
#include <utils/utils.h>

DynLibUtils::CModule DetermineModuleByLibrary(std::string library);

LoadScriptingComponent(memory, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Memory");

    ADD_CLASS_FUNCTION("Memory", "Memory", [](FunctionContext* context, ClassData* data) -> void {
        auto classData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if(classData) {
            if(classData->HasData("ptr")) {
                data->SetData("ptr", classData->GetData<void*>("ptr"));
            }
        } else {
            auto strptr = context->GetArgumentOr<std::string>(0, "");
            if(starts_with(strptr, "0x")) {
                data->SetData("ptr", (void*)StringToPtr(strptr));
            } else {
                data->SetData("ptr", nullptr);
            }
        }
    });
    
    ADD_CLASS_FUNCTION("Memory", "~Memory", [](FunctionContext* context, ClassData* data) -> void {
        if(data->HasData("should_free")) {
            if(data->GetData<bool>("should_free")) {
                free(data->GetData<void*>("ptr"));
            }
        }    
    });

    ADD_CLASS_FUNCTION("Memory", "Allocate", [](FunctionContext* context, ClassData* data) -> void {
        uint64_t size = context->GetArgumentOr<uint64_t>(0, 0);
        if(size == 0) return;
        
        if(data->HasData("should_free") && data->GetData<bool>("should_free")) {
            free(data->GetData<void*>("ptr"));
        }

        data->SetData("ptr", malloc(size));
        data->SetData("should_free", true);
    });

    ADD_CLASS_FUNCTION("Memory", "Deallocate", [](FunctionContext* context, ClassData* data) -> void {
        if(data->HasData("should_free") && data->GetData<bool>("should_free")) {
            free(data->GetData<void*>("ptr"));
            data->SetData("should_free", false);
            data->SetData("ptr", nullptr);
        }
    });

    ADD_CLASS_FUNCTION("Memory", "GetPtr", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(string_format("%p", data->GetData<void*>("ptr")));
    });

    ADD_CLASS_FUNCTION("Memory", "IsValid", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetData<void*>("ptr") != nullptr);
    });

    ADD_CLASS_FUNCTION("Memory", "LoadFromAddress", [](FunctionContext* context, ClassData* data) -> void {

        auto classData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if(classData) {
            if(classData->HasData("ptr")) {
                if(data->HasData("should_free") && data->GetData<bool>("should_free")) {
                    free(data->GetData<void*>("ptr"));
                    data->SetData("should_free", false);
                    data->SetData("ptr", nullptr);
                }

                data->SetData("ptr", classData->GetData<void*>("ptr"));
            }
        } else {
            auto strptr = context->GetArgumentOr<std::string>(0, "");
            if(starts_with(strptr, "0x")) {
                if(data->HasData("should_free") && data->GetData<bool>("should_free")) {
                    free(data->GetData<void*>("ptr"));
                    data->SetData("should_free", false);
                    data->SetData("ptr", nullptr);
                }

                data->SetData("ptr", (void*)StringToPtr(strptr));
            }
        }
    });

    ADD_CLASS_FUNCTION("Memory", "LoadFromSignatureName", [](FunctionContext* context, ClassData* data) -> void {
        auto signame = context->GetArgumentOr<std::string>(0, "");
        if(signame == "") return;

        if(data->HasData("should_free") && data->GetData<bool>("should_free")) {
            free(data->GetData<void*>("ptr"));
            data->SetData("should_free", false);
            data->SetData("ptr", nullptr);
        }
        data->SetData("ptr", g_GameData.FetchRawSignature(signame));
    });

    ADD_CLASS_FUNCTION("Memory", "LoadFromSignatureName", [](FunctionContext* context, ClassData* data) -> void {
        auto md = context->GetArgumentOr<std::string>(0, "");
        if(md == "") return;
        auto signature = context->GetArgumentOr<std::string>(1, "");
        if(signature == "") return;

        void* sig = nullptr;
        auto mod = DetermineModuleByLibrary(md);

        if (signature.at(0) == '@') sig = mod.GetFunctionByName((signature.c_str() + 1)).RCast<void*>();
        else sig = mod.FindPattern(signature).RCast<void*>();

        if(!sig) return;

        if(data->HasData("should_free") && data->GetData<bool>("should_free")) {
            free(data->GetData<void*>("ptr"));
            data->SetData("should_free", false);
            data->SetData("ptr", nullptr);
        }
        data->SetData("ptr", sig);
    });

    ADD_CLASS_FUNCTION("Memory", "AddOffsetByName", [](FunctionContext* context, ClassData* data) -> void {
        std::string offsetName = context->GetArgumentOr<std::string>(0, "");
        if(offsetName == "") return;

        auto offset = g_GameData.GetOffset(offsetName);
        uintptr_t ptr = (uintptr_t)data->GetData<void*>("ptr");
        ptr += offset;
        data->SetData("ptr", (void*)ptr);
    });

    ADD_CLASS_FUNCTION("Memory", "RemoveOffsetByName", [](FunctionContext* context, ClassData* data) -> void {
        std::string offsetName = context->GetArgumentOr<std::string>(0, "");
        if(offsetName == "") return;

        auto offset = g_GameData.GetOffset(offsetName);
        uintptr_t ptr = (uintptr_t)data->GetData<void*>("ptr");
        ptr -= offset;
        data->SetData("ptr", (void*)ptr);
    });

    ADD_CLASS_FUNCTION("Memory", "AddOffset", [](FunctionContext* context, ClassData* data) -> void {
        int64_t offset = context->GetArgumentOr<int64_t>(0, 0);
        if(offset == 0) return;

        uintptr_t ptr = (uintptr_t)data->GetData<void*>("ptr");
        ptr += offset;
        data->SetData("ptr", (void*)ptr);
    });

    ADD_CLASS_FUNCTION("Memory", "RemoveOffset", [](FunctionContext* context, ClassData* data) -> void {
        int64_t offset = context->GetArgumentOr<int64_t>(0, 0);
        if(offset == 0) return;

        uintptr_t ptr = (uintptr_t)data->GetData<void*>("ptr");
        ptr -= offset;
        data->SetData("ptr", (void*)ptr);
    });

    ADD_CLASS_FUNCTION("Memory", "AccessVTableFromOffset", [](FunctionContext* context, ClassData* data) -> void {
        std::string offsetName = context->GetArgumentOr<std::string>(0, "");
        if(offsetName == "") return;

        auto offset = g_GameData.GetOffset(offsetName);
        data->SetData("ptr", ((void***)data->GetData<void*>("ptr"))[0][offset]);
        data->SetData("accessed_vtable", true);
    });

    ADD_CLASS_FUNCTION("Memory", "AccessIndexFromOffset", [](FunctionContext* context, ClassData* data) -> void {
        std::string offsetName = context->GetArgumentOr<std::string>(0, "");
        if(offsetName == "") return;

        auto offset = g_GameData.GetOffset(offsetName);
        data->SetData("ptr", ((void**)data->GetData<void*>("ptr"))[offset]);
    });

    ADD_CLASS_FUNCTION("Memory", "AccessVTable", [](FunctionContext* context, ClassData* data) -> void {
        int64_t offset = context->GetArgumentOr<int64_t>(0, 0);
        if(offset == 0) return;

        data->SetData("ptr", ((void***)data->GetData<void*>("ptr"))[0][offset]);
        data->SetData("accessed_vtable", true);
    });

    ADD_CLASS_FUNCTION("Memory", "AccessIndex", [](FunctionContext* context, ClassData* data) -> void {
        int64_t offset = context->GetArgumentOr<int64_t>(0, 0);
        if(offset == 0) return;

        data->SetData("ptr", ((void**)data->GetData<void*>("ptr"))[offset]);
    });

    ADD_CLASS_FUNCTION("Memory", "AccessedVTable", [](FunctionContext* context, ClassData* data) -> void {
        context->SetReturn(data->GetDataOr<bool>("accessed_vtable", false));
    });

    ADD_CLASS_FUNCTION("Memory", "Clear", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("ptr", (void*)nullptr);
    });

    ADD_CLASS_FUNCTION("Memory", "Dereference", [](FunctionContext* context, ClassData* data) -> void {
        data->SetData("ptr", *(void**)data->GetData<void*>("ptr"));
    });

    ADD_CLASS_FUNCTION("Memory", "SetBool", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        bool value = context->GetArgumentOr<bool>(0, false);
        *((bool*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetInt", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        int value = context->GetArgumentOr<int>(0, 0);
        *((int*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetInt64", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        int64_t value = context->GetArgumentOr<int64_t>(0, 0);
        *((int64_t*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetUint", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        uint32_t value = context->GetArgumentOr<uint32_t>(0, 0);
        *((uint32_t*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetUint64", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        uint64_t value = context->GetArgumentOr<uint64_t>(0, 0);
        *((uint64_t*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetFloat", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        float value = context->GetArgumentOr<float>(0, 0.0);
        *((float*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetDouble", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        double value = context->GetArgumentOr<double>(0, 0.0);
        *((double*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetVector", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        ClassData* cdata = context->GetArgumentOr<ClassData*>(0, nullptr);
        if(!cdata) return;
        Vector value = cdata->GetData<Vector>("vector_ptr");

        *((Vector*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetVector2D", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        ClassData* cdata = context->GetArgumentOr<ClassData*>(0, nullptr);
        if(!cdata) return;
        Vector2D value = cdata->GetData<Vector2D>("Vector2D_ptr");

        *((Vector2D*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetVector4D", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        ClassData* cdata = context->GetArgumentOr<ClassData*>(0, nullptr);
        if(!cdata) return;
        Vector4D value = cdata->GetData<Vector4D>("Vector4D_ptr");

        *((Vector4D*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetColor", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        ClassData* cdata = context->GetArgumentOr<ClassData*>(0, nullptr);
        if(!cdata) return;
        Color value = cdata->GetData<Color>("Color_ptr");

        *((Color*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "SetQAngle", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        ClassData* cdata = context->GetArgumentOr<ClassData*>(0, nullptr);
        if(!cdata) return;
        QAngle value = cdata->GetData<QAngle>("QAngle_ptr");

        *((QAngle*)(m_ptr)) = value;
    });

    ADD_CLASS_FUNCTION("Memory", "GetBool", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(false);

        context->SetReturn(*((bool*)(m_ptr)));
    });

    ADD_CLASS_FUNCTION("Memory", "GetInt", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(0);

        context->SetReturn(*((int*)(m_ptr)));
    });

    ADD_CLASS_FUNCTION("Memory", "GetInt64", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(0);

        context->SetReturn(*((int64_t*)(m_ptr)));
    });

    ADD_CLASS_FUNCTION("Memory", "GetUint", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(0);

        context->SetReturn(*((uint32_t*)(m_ptr)));
    });

    ADD_CLASS_FUNCTION("Memory", "GetUint64", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(0);

        context->SetReturn(*((uint64_t*)(m_ptr)));
    });

    ADD_CLASS_FUNCTION("Memory", "GetFloat", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(0.0);

        context->SetReturn(*((float*)(m_ptr)));
    });

    ADD_CLASS_FUNCTION("Memory", "GetDouble", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(0.0);

        context->SetReturn(*((double*)(m_ptr)));
    });

    ADD_CLASS_FUNCTION("Memory", "GetVector", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(MAKE_CLASS_INSTANCE("Vector", { { "vector_ptr", Vector(0.0,0.0,0.0) } }));

        context->SetReturn(MAKE_CLASS_INSTANCE("Vector", { { "vector_ptr", *((Vector*)(m_ptr)) } }));
    });

    ADD_CLASS_FUNCTION("Memory", "GetVector2D", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(MAKE_CLASS_INSTANCE("Vector2D", { { "Vector2D_ptr", Vector2D(0.0,0.0) } }));

        context->SetReturn(MAKE_CLASS_INSTANCE("Vector2D", { { "Vector2D_ptr", *((Vector2D*)(m_ptr)) } }));
    });

    ADD_CLASS_FUNCTION("Memory", "GetVector4D", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(MAKE_CLASS_INSTANCE("Vector4D", { { "Vector4D_ptr", Vector4D(0.0,0.0,0.0,0.0) } }));

        context->SetReturn(MAKE_CLASS_INSTANCE("Vector4D", { { "Vector4D_ptr", *((Vector4D*)(m_ptr)) } }));
    });

    ADD_CLASS_FUNCTION("Memory", "GetColor", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(MAKE_CLASS_INSTANCE("Color", { { "Color_ptr", Color(0,0,0,0) } }));

        context->SetReturn(MAKE_CLASS_INSTANCE("Color", { { "Color_ptr", *((Color*)(m_ptr)) } }));
    });

    ADD_CLASS_FUNCTION("Memory", "GetQAngle", [](FunctionContext* context, ClassData* data) -> void {
        void* m_ptr = data->GetData<void*>("ptr");
        if(!m_ptr) return context->SetReturn(MAKE_CLASS_INSTANCE("QAngle", { { "QAngle_ptr", QAngle(0.0,0.0,0.0) } }));

        context->SetReturn(MAKE_CLASS_INSTANCE("QAngle", { { "QAngle_ptr", *((QAngle*)(m_ptr)) } }));
    });
})