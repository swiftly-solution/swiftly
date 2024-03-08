#include "../../../inc/Scripting.h"

#ifdef _MSC_VER
#pragma warning(disable : 4146)
#pragma warning(disable : 4180)
#endif
#include <luacpp/luacpp.h>
#include <luacpp/func_utils.h>

#include <map>
#include <vector>

#include <rapidjson/document.h>

class LuaEntityClass
{
private:
    uint32_t entityID = 0;

public:
    LuaEntityClass(const char *clsname)
    {
        this->entityID = scripting_Entity_Create(clsname);
    }

    uint32_t GetEntityID()
    {
        return this->entityID;
    }
};

class LuaEntitiesClass
{
private:
    std::map<uint32_t, luacpp::LuaObject> entities;

public:
    LuaEntitiesClass() {}

    luacpp::LuaObject CreateEntity(luacpp::LuaClass<LuaEntityClass> entityClass, const char *clsname)
    {
        luacpp::LuaObject entityObject = entityClass.CreateInstance(clsname);
        LuaEntityClass *entity = static_cast<LuaEntityClass *>(entityObject.ToPointer());

        this->entities.insert(std::make_pair(entity->GetEntityID(), entityObject));

        return entityObject;
    }

    void DestroyEntity(int entityid)
    {
        if (this->EntityExists(entityid))
        {
            this->entities.erase(entityid);
            scripting_Entity_Destroy(entityid);
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

class LuaEntityArgsClass
{
public:
    uint32_t entityID;

    LuaEntityArgsClass(uint32_t m_entityID) : entityID(m_entityID) {}
};

void SetupLuaEntities(luacpp::LuaState *state, Plugin *plugin)
{
    auto entitiesClass = state->CreateClass<LuaEntitiesClass>("Entities").DefConstructor();
    auto entityClass = state->CreateClass<LuaEntityClass>().DefConstructor<const char *>();

    auto coordsClass = state->CreateClass<LuaEntityArgsClass>().DefConstructor<uint32_t>();
    auto anglesClass = state->CreateClass<LuaEntityArgsClass>().DefConstructor<uint32_t>();
    auto colorsClass = state->CreateClass<LuaEntityArgsClass>().DefConstructor<uint32_t>();

    entitiesClass.DefMember("Create", [entityClass](LuaEntitiesClass *base, luacpp::LuaObject clsObj) -> luacpp::LuaObject
                            { return base->CreateEntity(entityClass, clsObj.GetType() != LUA_TSTRING ? nullptr : clsObj.ToString()); })
        .DefMember("Destroy", [](LuaEntitiesClass *base, int entityid) -> void
                   { base->DestroyEntity(entityid); })
        .DefMember("Fetch", [state](LuaEntitiesClass *base, int entityID) -> luacpp::LuaObject
                   {
                if (base->EntityExists(entityID)) return base->FetchEntity(entityID);
                else return state->CreateNil(); })
        .DefMember("GetEntities", [state](LuaEntitiesClass *base) -> luacpp::LuaTable
                   {
                luacpp::LuaTable entitiesTbl = state->CreateTable();
                uint64_t index = 1;
                std::vector<luacpp::LuaObject> entities = base->FetchEntities();
                for (luacpp::LuaObject entity : entities)
                    entitiesTbl.Set((index++), entity);
                return entitiesTbl; })
        .DefMember("GetEntityIDs", [state](LuaEntitiesClass *base) -> luacpp::LuaTable
                   {
                            luacpp::LuaTable entitiesTbl = state->CreateTable();
                            uint64_t index = 1;
                            std::vector<luacpp::LuaObject> entities = base->FetchEntities();
                            for (luacpp::LuaObject entity : entities)
                                entitiesTbl.SetInteger((index++), static_cast<LuaEntityClass*>(entity.ToPointer())->GetEntityID());
                            return entitiesTbl; });

    entityClass.DefMember("Destroy", [](LuaEntityClass *base) -> void
                          { scripting_Entity_Destroy(base->GetEntityID()); })
        .DefMember("Spawn", [](LuaEntityClass *base) -> void
                   { scripting_Entity_Spawn(base->GetEntityID()); })
        .DefMember("GetEntityID", [](LuaEntityClass *base) -> uint32_t
                   { return base->GetEntityID(); })
        .DefMember("SetModel", [](LuaEntityClass *base, const char *model) -> void
                   { scripting_Entity_SetModel(base->GetEntityID(), model); })
        .DefMember("AcceptInput", [](LuaEntityClass *base, const char *input, const char *activator, const char *caller, double value) -> void
                   { scripting_Entity_AcceptInput(base->GetEntityID(), input, activator, caller, &value); })
        .DefMember("SetCollisionGroup", [](LuaEntityClass *base, int group) -> void
                   { scripting_Entity_SetCollisionGroup(base->GetEntityID(), (Collision_Group_t)group); })
        .DefMember("coords", [coordsClass](LuaEntityClass *base) -> luacpp::LuaObject
                   { return coordsClass.CreateInstance(base->GetEntityID()); })
        .DefMember("angles", [anglesClass](LuaEntityClass *base) -> luacpp::LuaObject
                   { return anglesClass.CreateInstance(base->GetEntityID()); })
        .DefMember("colors", [colorsClass](LuaEntityClass *base) -> luacpp::LuaObject
                   { return colorsClass.CreateInstance(base->GetEntityID()); });

    coordsClass.DefMember("Get", [state](LuaEntityArgsClass *base) -> luacpp::LuaObject
                          {
                        Vector coords = scripting_Entity_GetCoordsRaw(base->entityID);

                        float x = coords.x;
                        float y = coords.y;
                        float z = coords.z;

                        LuaFuncWrapper wrapper(state->Get("vector3"));
                        wrapper.PrepForExec();
                        luacpp::PushValues(wrapper.GetML(), x, y, z);
                        return wrapper.ExecuteWithReturnRaw("vector3", 3); })
        .DefMember("Set", [state](LuaEntityArgsClass *base, luacpp::LuaObject coordsObj) -> void
                   {
                            if (coordsObj.GetType() != LUA_TTABLE) {
                                PRINT("Runtime", "Coords field needs to be a vector3.\n");
                                return;
                            }

                            luacpp::LuaTable coords = luacpp::LuaTable(coordsObj);

                            if (coords.Get("x").GetType() == LUA_TNIL || coords.Get("y").GetType() == LUA_TNIL || coords.Get("z").GetType() == LUA_TNIL) {
                                PRINT("Runtime", "Coords field needs to be a vector3.\n");
                                return;
                            }

                            scripting_Entity_SetCoords(base->entityID, (float)coords.GetNumber("x"), (float)coords.GetNumber("y"), (float)coords.GetNumber("z")); });

    anglesClass.DefMember("Get", [state](LuaEntityArgsClass *base) -> luacpp::LuaObject
                          {
                            QAngle angle = scripting_Entity_GetAnglesRaw(base->entityID);

                            float x = angle.x;
                            float y = angle.y;
                            float z = angle.z;

                            LuaFuncWrapper wrapper(state->Get("vector3"));
                            wrapper.PrepForExec();
                            luacpp::PushValues(wrapper.GetML(), x, y, z);
                            return wrapper.ExecuteWithReturnRaw("vector3", 3); })
        .DefMember("Set", [state](LuaEntityArgsClass *base, luacpp::LuaObject coordsObj) -> void
                   {
                                if (coordsObj.GetType() != LUA_TTABLE) {
                                    PRINT("Runtime", "Coords field needs to be a vector3.\n");
                                    return;
                                }

                                luacpp::LuaTable coords = luacpp::LuaTable(coordsObj);

                                if (coords.Get("x").GetType() == LUA_TNIL || coords.Get("y").GetType() == LUA_TNIL || coords.Get("z").GetType() == LUA_TNIL) {
                                    PRINT("Runtime", "Coords field needs to be a vector3.\n");
                                    return;
                                }

                                scripting_Entity_SetAngles(base->entityID, (float)coords.GetNumber("x"), (float)coords.GetNumber("y"), (float)coords.GetNumber("z")); });

    colorsClass.DefMember("Get", [state](LuaEntityArgsClass *base) -> luacpp::LuaTable
                          {
                                    luacpp::LuaTable tbl = state->CreateTable();

                                    Color color = scripting_Entity_GetColorsRaw(base->entityID);

                                    tbl.SetInteger("r", color.r());
                                    tbl.SetInteger("g", color.g());
                                    tbl.SetInteger("b", color.b());
                                    tbl.SetInteger("a", color.a());

                                    return tbl; })
        .DefMember("Set", [state](LuaEntityArgsClass *base, luacpp::LuaObject colorsObj) -> void
                   {
                                        if (colorsObj.GetType() != LUA_TTABLE) {
                                            PRINT("Runtime", "Coords field needs to be a vector3.\n");
                                            return;
                                        }

                                        luacpp::LuaTable colors = luacpp::LuaTable(colorsObj);

                                        if (colors.Get("r").GetType() == LUA_TNIL || colors.Get("g").GetType() == LUA_TNIL || colors.Get("b").GetType() == LUA_TNIL || colors.Get("a").GetType() == LUA_TNIL) {
                                            PRINT("Runtime", "Value field needs to be a valid color table.\n");
                                            return;
                                        }
                                        scripting_Entity_SetColors(base->entityID, colors.GetInteger("r"), colors.GetInteger("g"), colors.GetInteger("b"), colors.GetInteger("a")); });

    state->DoString("entities = Entities()");
}