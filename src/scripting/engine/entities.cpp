#include <scripting/core.h>

#include <entities/system.h>

LoadScriptingComponent(entities, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_FUNCTION("CreateEntityByName", [](FunctionContext* context) -> void {
        std::string class_name = context->GetArgumentOr<std::string>(0, "");
        if(class_name == "") return context->SetReturn(MakeSDKClassInstance("CEntityInstance", nullptr, context->GetPluginContext()));

        context->SetReturn(MakeSDKClassInstance("CEntityInstance", g_entSystem.CreateByName(class_name.c_str()), context->GetPluginContext()));
    });

    ADD_FUNCTION("FindEntitiesByClassname", [](FunctionContext* context) -> void {
        std::string class_name = context->GetArgumentOr<std::string>(0, "");
        std::vector<EValue> entities;
        if(class_name != "") {
            CEntityIdentity* pEntity = g_pEntitySystem->m_EntityList.m_pFirstActiveEntity;

            for (; pEntity; pEntity = pEntity->m_pNext)
                if (pEntity->m_designerName.String() == class_name)
                    entities.push_back(MakeSDKClassInstance("CEntityInstance", pEntity->m_pInstance, context->GetPluginContext()));
        }

        context->SetReturn(entities);
    });
})