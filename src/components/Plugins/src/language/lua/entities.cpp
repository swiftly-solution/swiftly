#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

#include <map>
#include <vector>

class LuaEntitiesClass
{
private:
    std::map<uint32_t, luacpp::LuaObject> entities;

public:
    LuaEntitiesClass() {}

    luacpp::LuaObject CreateEntity(luacpp::LuaClass<LuaEntityClass> entityClass)
    {
        luacpp::LuaObject entityObject = entityClass.CreateInstance();
        LuaEntityClass *entity = static_cast<LuaEntityClass *>(entityObject.ToPointer());

        this->entities.insert(std::make_pair(entity->GetEntityID(), entityObject));

        return entityObject;
    }

    void DestroyEntity(void *entityPointer)
    {
        LuaEntityClass *entity = static_cast<LuaEntityClass *>(entityPointer);
        if (this->EntityExists(entity->GetEntityID()))
        {
            this->entities.erase(entity->GetEntityID());
            scripting_Entity_Destroy(entity->GetEntityID());
        }
    }

    bool EntityExists(int entityID)
    {
        return (this->entities.find(entityID) != this->entities.end());
    }

    luacpp::LuaObject FetchEntity(int entityID)
    {
        return this->entities.at(entityID);
    }

    std::vector<luacpp::LuaObject> FetchEntities()
    {
        std::vector<luacpp::LuaObject> objs;
        for (std::map<uint32_t, luacpp::LuaObject>::iterator it = this->entities.begin(); it != this->entities.end(); ++it)
            objs.push_back(it->second);
        return objs;
    }
};

class LuaEntityClass
{
private:
    uint32_t entityID = 0;

public:
    LuaEntityClass()
    {
        this->entityID = scripting_Entity_Create();
    }

    uint32_t GetEntityID()
    {
        return this->entityID;
    }
};

void SetupLuaEntities(luacpp::LuaState *state, Plugin *plugin)
{
    auto entitiesClass = state->CreateClass<LuaEntitiesClass>("Entities").DefConstructor();
    auto entityClass = state->CreateClass<LuaEntityClass>().DefConstructor();

    entitiesClass.DefMember("Create", [entityClass](LuaEntitiesClass *base) -> luacpp::LuaObject
                            { return base->CreateEntity(entityClass); })
        .DefMember("Destroy", [](LuaEntitiesClass *base, luacpp::LuaObject entityObj) -> void
                   { base->DestroyEntity(entityObj.ToPointer()); })
        .DefMember("Fetch", [state](LuaEntitiesClass *base, int entityID) -> luacpp::LuaObject
                   {
            if(base->EntityExists(entityID)) return base->FetchEntity(entityID);
            else return state->CreateNil(); })
        .DefMember("GetEntities", [state](LuaEntitiesClass *base) -> luacpp::LuaTable
                   {
            luacpp::LuaTable entitiesTbl = state->CreateTable();
            uint64_t index = 1;
            std::vector<luacpp::LuaObject> entities = base->FetchEntities();
            for(luacpp::LuaObject entity : entities) 
                entitiesTbl.Set((index++), entity);
            return entitiesTbl; })
        .DefMember("GetEntityIDs", [state](LuaEntitiesClass *base) -> luacpp::LuaTable
                   {
            luacpp::LuaTable entitiesTbl = state->CreateTable();
            uint64_t index = 1;
            std::vector<luacpp::LuaObject> entities = base->FetchEntities();
            for(luacpp::LuaObject entity : entities) 
                entitiesTbl.SetInteger((index++), static_cast<LuaEntityClass*>(entity.ToPointer())->GetEntityID());
            return entitiesTbl; });

    entityClass.DefMember("Destroy", [](LuaEntityClass *base) -> void
                          { scripting_Entity_Destroy(base->GetEntityID()); })
        .DefMember("Spawn", [](LuaEntityClass *base) -> void
                   { scripting_Entity_Spawn(base->GetEntityID()); })
        .DefMember("GetEntityID", [](LuaEntityClass *base) -> uint32_t
                   { return base->GetEntityID(); })
        .DefMember("SetModel", [](LuaEntityClass *base, const char *model) -> void
                   { scripting_Entity_SetModel(base->GetEntityID(), model); });

    state->DoString("entities = Entities()");

    PRINT("Scripting - Lua", "Entities loaded.\n");
}