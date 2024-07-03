#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCFlashbangProjectile::GCFlashbangProjectile(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCFlashbangProjectile::GCFlashbangProjectile(void *ptr) {
    m_ptr = ptr;
}
float GCFlashbangProjectile::GetTimeToDetonate() const {
    return GetSchemaValue<float>(m_ptr, "CFlashbangProjectile", "m_flTimeToDetonate");
}
void GCFlashbangProjectile::SetTimeToDetonate(float value) {
    SetSchemaValue(m_ptr, "CFlashbangProjectile", "m_flTimeToDetonate", false, value);
}
uint8_t GCFlashbangProjectile::GetNumOpponentsHit() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CFlashbangProjectile", "m_numOpponentsHit");
}
void GCFlashbangProjectile::SetNumOpponentsHit(uint8_t value) {
    SetSchemaValue(m_ptr, "CFlashbangProjectile", "m_numOpponentsHit", false, value);
}
uint8_t GCFlashbangProjectile::GetNumTeammatesHit() const {
    return GetSchemaValue<uint8_t>(m_ptr, "CFlashbangProjectile", "m_numTeammatesHit");
}
void GCFlashbangProjectile::SetNumTeammatesHit(uint8_t value) {
    SetSchemaValue(m_ptr, "CFlashbangProjectile", "m_numTeammatesHit", false, value);
}
std::string GCFlashbangProjectile::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCFlashbangProjectile::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseCSGrenadeProjectile GCFlashbangProjectile::GetParent() const {
    GCBaseCSGrenadeProjectile value(m_ptr);
    return value;
}
void GCFlashbangProjectile::SetParent(GCBaseCSGrenadeProjectile value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCFlashbangProjectile(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCFlashbangProjectile>("CFlashbangProjectile")
        .addConstructor<void (*)(std::string)>()
        .addProperty("TimeToDetonate", &GCFlashbangProjectile::GetTimeToDetonate, &GCFlashbangProjectile::SetTimeToDetonate)
        .addProperty("NumOpponentsHit", &GCFlashbangProjectile::GetNumOpponentsHit, &GCFlashbangProjectile::SetNumOpponentsHit)
        .addProperty("NumTeammatesHit", &GCFlashbangProjectile::GetNumTeammatesHit, &GCFlashbangProjectile::SetNumTeammatesHit)
        .addProperty("Parent", &GCFlashbangProjectile::GetParent, &GCFlashbangProjectile::SetParent)
        .addFunction("ToPtr", &GCFlashbangProjectile::ToPtr)
        .addFunction("IsValid", &GCFlashbangProjectile::IsValid)
        .endClass();
}