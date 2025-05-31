#ifndef _entity_system_h
#define _entity_system_h

#include <core/entrypoint.h>
#include <memory/gamedata/gamedata.h>

#include <public/entity2/entitysystem.h>

SH_DECL_EXTERN3_void(INetworkServerService, StartupServer, SH_NOATTRIB, 0, const GameSessionConfiguration_t&, ISource2WorldSession*, const char*);

class CGameResourceService
{
public:
    CGameEntitySystem* GetGameEntitySystem()
    {
        return *reinterpret_cast<CGameEntitySystem**>((uintptr_t)(this) + g_GameData.GetOffset("GameEntitySystem"));
    }
};

class EntitySystem
{
public:
    void Initialize();
    void Shutdown();

    void StartupServer(const GameSessionConfiguration_t& config, ISource2WorldSession*, const char*);

    void Spawn(void* entity, void* keyvalues);
    void Despawn(void* entity);
    void* CreateByName(const char* name);
    void AcceptInput(void* entity, std::string input, void* activator, void* caller, std::string value, int outputID);

    bool IsValidEntity(void* entity);
};

class CEntityListener : public IEntityListener
{
    void OnEntityCreated(CEntityInstance* pEntity) override;
    void OnEntitySpawned(CEntityInstance* pEntity) override;
    void OnEntityDeleted(CEntityInstance* pEntity) override;
    void OnEntityParentChanged(CEntityInstance* pEntity, CEntityInstance* pNewParent) override;
};

extern CEntityListener g_entityListener;
extern EntitySystem g_entSystem;

extern void* gameRules;

#endif