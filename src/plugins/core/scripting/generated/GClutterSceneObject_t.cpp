#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GClutterSceneObject_t::GClutterSceneObject_t(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GClutterSceneObject_t::GClutterSceneObject_t(void *ptr) {
    m_ptr = ptr;
}
GAABB_t GClutterSceneObject_t::GetBounds() const {
    GAABB_t value(GetSchemaPtr(m_ptr, "ClutterSceneObject_t", "m_Bounds"));
    return value;
}
void GClutterSceneObject_t::SetBounds(GAABB_t value) {
    SetSchemaValue(m_ptr, "ClutterSceneObject_t", "m_Bounds", true, value);
}
uint64_t GClutterSceneObject_t::GetFlags() const {
    return GetSchemaValue<uint64_t>(m_ptr, "ClutterSceneObject_t", "m_flags");
}
void GClutterSceneObject_t::SetFlags(uint64_t value) {
    SetSchemaValue(m_ptr, "ClutterSceneObject_t", "m_flags", true, value);
}
int16_t GClutterSceneObject_t::GetLayer() const {
    return GetSchemaValue<int16_t>(m_ptr, "ClutterSceneObject_t", "m_nLayer");
}
void GClutterSceneObject_t::SetLayer(int16_t value) {
    SetSchemaValue(m_ptr, "ClutterSceneObject_t", "m_nLayer", true, value);
}
std::vector<Vector> GClutterSceneObject_t::GetInstancePositions() const {
    CUtlVector<Vector>* vec = GetSchemaValue<CUtlVector<Vector>*>(m_ptr, "ClutterSceneObject_t", "m_instancePositions"); std::vector<Vector> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GClutterSceneObject_t::SetInstancePositions(std::vector<Vector> value) {
    SetSchemaValueCUtlVector<Vector>(m_ptr, "ClutterSceneObject_t", "m_instancePositions", true, value);
}
std::vector<float32> GClutterSceneObject_t::GetInstanceScales() const {
    CUtlVector<float32>* vec = GetSchemaValue<CUtlVector<float32>*>(m_ptr, "ClutterSceneObject_t", "m_instanceScales"); std::vector<float32> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GClutterSceneObject_t::SetInstanceScales(std::vector<float32> value) {
    SetSchemaValueCUtlVector<float32>(m_ptr, "ClutterSceneObject_t", "m_instanceScales", true, value);
}
std::vector<Color> GClutterSceneObject_t::GetInstanceTintSrgb() const {
    CUtlVector<Color>* vec = GetSchemaValue<CUtlVector<Color>*>(m_ptr, "ClutterSceneObject_t", "m_instanceTintSrgb"); std::vector<Color> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GClutterSceneObject_t::SetInstanceTintSrgb(std::vector<Color> value) {
    SetSchemaValueCUtlVector<Color>(m_ptr, "ClutterSceneObject_t", "m_instanceTintSrgb", true, value);
}
std::vector<GClutterTile_t> GClutterSceneObject_t::GetTiles() const {
    CUtlVector<GClutterTile_t>* vec = GetSchemaValue<CUtlVector<GClutterTile_t>*>(m_ptr, "ClutterSceneObject_t", "m_tiles"); std::vector<GClutterTile_t> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GClutterSceneObject_t::SetTiles(std::vector<GClutterTile_t> value) {
    SetSchemaValueCUtlVector<GClutterTile_t>(m_ptr, "ClutterSceneObject_t", "m_tiles", true, value);
}
std::string GClutterSceneObject_t::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GClutterSceneObject_t::IsValid() {
    return (m_ptr != nullptr);
}
void SetupLuaClassClutterSceneObject_t(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GClutterSceneObject_t>("ClutterSceneObject_t")
        .addConstructor<void (*)(std::string)>()
        .addProperty("Bounds", &GClutterSceneObject_t::GetBounds, &GClutterSceneObject_t::SetBounds)
        .addProperty("Flags", &GClutterSceneObject_t::GetFlags, &GClutterSceneObject_t::SetFlags)
        .addProperty("Layer", &GClutterSceneObject_t::GetLayer, &GClutterSceneObject_t::SetLayer)
        .addProperty("InstancePositions", &GClutterSceneObject_t::GetInstancePositions, &GClutterSceneObject_t::SetInstancePositions)
        .addProperty("InstanceScales", &GClutterSceneObject_t::GetInstanceScales, &GClutterSceneObject_t::SetInstanceScales)
        .addProperty("InstanceTintSrgb", &GClutterSceneObject_t::GetInstanceTintSrgb, &GClutterSceneObject_t::SetInstanceTintSrgb)
        .addProperty("Tiles", &GClutterSceneObject_t::GetTiles, &GClutterSceneObject_t::SetTiles)
        .addFunction("ToPtr", &GClutterSceneObject_t::ToPtr)
        .addFunction("IsValid", &GClutterSceneObject_t::IsValid)
        .endClass();
}