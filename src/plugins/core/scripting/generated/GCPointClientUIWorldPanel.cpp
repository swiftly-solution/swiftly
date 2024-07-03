#include "classes.h"

#include "../../../../sdk/entity/CBaseEntity.h"
#include "../../../../sdk/entity/CBaseModelEntity.h"

GCPointClientUIWorldPanel::GCPointClientUIWorldPanel(std::string ptr) {
    m_ptr = (void*)(strtol(ptr.c_str(), nullptr, 16));
}
GCPointClientUIWorldPanel::GCPointClientUIWorldPanel(void *ptr) {
    m_ptr = ptr;
}
bool GCPointClientUIWorldPanel::GetIgnoreInput() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bIgnoreInput");
}
void GCPointClientUIWorldPanel::SetIgnoreInput(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bIgnoreInput", false, value);
}
bool GCPointClientUIWorldPanel::GetLit() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bLit");
}
void GCPointClientUIWorldPanel::SetLit(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bLit", false, value);
}
bool GCPointClientUIWorldPanel::GetFollowPlayerAcrossTeleport() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bFollowPlayerAcrossTeleport");
}
void GCPointClientUIWorldPanel::SetFollowPlayerAcrossTeleport(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bFollowPlayerAcrossTeleport", false, value);
}
float GCPointClientUIWorldPanel::GetWidth() const {
    return GetSchemaValue<float>(m_ptr, "CPointClientUIWorldPanel", "m_flWidth");
}
void GCPointClientUIWorldPanel::SetWidth(float value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_flWidth", false, value);
}
float GCPointClientUIWorldPanel::GetHeight() const {
    return GetSchemaValue<float>(m_ptr, "CPointClientUIWorldPanel", "m_flHeight");
}
void GCPointClientUIWorldPanel::SetHeight(float value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_flHeight", false, value);
}
float GCPointClientUIWorldPanel::GetDPI() const {
    return GetSchemaValue<float>(m_ptr, "CPointClientUIWorldPanel", "m_flDPI");
}
void GCPointClientUIWorldPanel::SetDPI(float value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_flDPI", false, value);
}
float GCPointClientUIWorldPanel::GetInteractDistance() const {
    return GetSchemaValue<float>(m_ptr, "CPointClientUIWorldPanel", "m_flInteractDistance");
}
void GCPointClientUIWorldPanel::SetInteractDistance(float value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_flInteractDistance", false, value);
}
float GCPointClientUIWorldPanel::GetDepthOffset() const {
    return GetSchemaValue<float>(m_ptr, "CPointClientUIWorldPanel", "m_flDepthOffset");
}
void GCPointClientUIWorldPanel::SetDepthOffset(float value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_flDepthOffset", false, value);
}
uint32_t GCPointClientUIWorldPanel::GetOwnerContext() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPointClientUIWorldPanel", "m_unOwnerContext");
}
void GCPointClientUIWorldPanel::SetOwnerContext(uint32_t value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_unOwnerContext", false, value);
}
uint32_t GCPointClientUIWorldPanel::GetHorizontalAlign() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPointClientUIWorldPanel", "m_unHorizontalAlign");
}
void GCPointClientUIWorldPanel::SetHorizontalAlign(uint32_t value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_unHorizontalAlign", false, value);
}
uint32_t GCPointClientUIWorldPanel::GetVerticalAlign() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPointClientUIWorldPanel", "m_unVerticalAlign");
}
void GCPointClientUIWorldPanel::SetVerticalAlign(uint32_t value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_unVerticalAlign", false, value);
}
uint32_t GCPointClientUIWorldPanel::GetOrientation() const {
    return GetSchemaValue<uint32_t>(m_ptr, "CPointClientUIWorldPanel", "m_unOrientation");
}
void GCPointClientUIWorldPanel::SetOrientation(uint32_t value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_unOrientation", false, value);
}
bool GCPointClientUIWorldPanel::GetAllowInteractionFromAllSceneWorlds() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bAllowInteractionFromAllSceneWorlds");
}
void GCPointClientUIWorldPanel::SetAllowInteractionFromAllSceneWorlds(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bAllowInteractionFromAllSceneWorlds", false, value);
}
std::vector<CUtlSymbolLarge> GCPointClientUIWorldPanel::GetCSSClasses() const {
    CUtlVector<CUtlSymbolLarge>* vec = GetSchemaValue<CUtlVector<CUtlSymbolLarge>*>(m_ptr, "CPointClientUIWorldPanel", "m_vecCSSClasses"); std::vector<CUtlSymbolLarge> outVec; for(int i = 0; i < vec->Count(); i++) { outVec.push_back(vec->Element(i)); } return outVec;
}
void GCPointClientUIWorldPanel::SetCSSClasses(std::vector<CUtlSymbolLarge> value) {
    SetSchemaValueCUtlVector<CUtlSymbolLarge>(m_ptr, "CPointClientUIWorldPanel", "m_vecCSSClasses", false, value);
}
bool GCPointClientUIWorldPanel::GetOpaque() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bOpaque");
}
void GCPointClientUIWorldPanel::SetOpaque(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bOpaque", false, value);
}
bool GCPointClientUIWorldPanel::GetNoDepth() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bNoDepth");
}
void GCPointClientUIWorldPanel::SetNoDepth(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bNoDepth", false, value);
}
bool GCPointClientUIWorldPanel::GetRenderBackface() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bRenderBackface");
}
void GCPointClientUIWorldPanel::SetRenderBackface(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bRenderBackface", false, value);
}
bool GCPointClientUIWorldPanel::GetUseOffScreenIndicator() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bUseOffScreenIndicator");
}
void GCPointClientUIWorldPanel::SetUseOffScreenIndicator(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bUseOffScreenIndicator", false, value);
}
bool GCPointClientUIWorldPanel::GetExcludeFromSaveGames() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bExcludeFromSaveGames");
}
void GCPointClientUIWorldPanel::SetExcludeFromSaveGames(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bExcludeFromSaveGames", false, value);
}
bool GCPointClientUIWorldPanel::GetGrabbable() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bGrabbable");
}
void GCPointClientUIWorldPanel::SetGrabbable(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bGrabbable", false, value);
}
bool GCPointClientUIWorldPanel::GetOnlyRenderToTexture() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bOnlyRenderToTexture");
}
void GCPointClientUIWorldPanel::SetOnlyRenderToTexture(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bOnlyRenderToTexture", false, value);
}
bool GCPointClientUIWorldPanel::GetDisableMipGen() const {
    return GetSchemaValue<bool>(m_ptr, "CPointClientUIWorldPanel", "m_bDisableMipGen");
}
void GCPointClientUIWorldPanel::SetDisableMipGen(bool value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_bDisableMipGen", false, value);
}
int32_t GCPointClientUIWorldPanel::GetExplicitImageLayout() const {
    return GetSchemaValue<int32_t>(m_ptr, "CPointClientUIWorldPanel", "m_nExplicitImageLayout");
}
void GCPointClientUIWorldPanel::SetExplicitImageLayout(int32_t value) {
    SetSchemaValue(m_ptr, "CPointClientUIWorldPanel", "m_nExplicitImageLayout", false, value);
}
std::string GCPointClientUIWorldPanel::ToPtr() {
    return string_format("%p", m_ptr);
}
bool GCPointClientUIWorldPanel::IsValid() {
    return (m_ptr != nullptr);
}
GCBaseClientUIEntity GCPointClientUIWorldPanel::GetParent() const {
    GCBaseClientUIEntity value(m_ptr);
    return value;
}
void GCPointClientUIWorldPanel::SetParent(GCBaseClientUIEntity value) {
    PLUGIN_PRINT("Schema SDK", "Setting a value for 'Parent' is not possible.\n");
}
void SetupLuaClassCPointClientUIWorldPanel(LuaPlugin *plugin, lua_State *state)
{
    luabridge::getGlobalNamespace(state)
        .beginClass<GCPointClientUIWorldPanel>("CPointClientUIWorldPanel")
        .addConstructor<void (*)(std::string)>()
        .addProperty("IgnoreInput", &GCPointClientUIWorldPanel::GetIgnoreInput, &GCPointClientUIWorldPanel::SetIgnoreInput)
        .addProperty("Lit", &GCPointClientUIWorldPanel::GetLit, &GCPointClientUIWorldPanel::SetLit)
        .addProperty("FollowPlayerAcrossTeleport", &GCPointClientUIWorldPanel::GetFollowPlayerAcrossTeleport, &GCPointClientUIWorldPanel::SetFollowPlayerAcrossTeleport)
        .addProperty("Width", &GCPointClientUIWorldPanel::GetWidth, &GCPointClientUIWorldPanel::SetWidth)
        .addProperty("Height", &GCPointClientUIWorldPanel::GetHeight, &GCPointClientUIWorldPanel::SetHeight)
        .addProperty("DPI", &GCPointClientUIWorldPanel::GetDPI, &GCPointClientUIWorldPanel::SetDPI)
        .addProperty("InteractDistance", &GCPointClientUIWorldPanel::GetInteractDistance, &GCPointClientUIWorldPanel::SetInteractDistance)
        .addProperty("DepthOffset", &GCPointClientUIWorldPanel::GetDepthOffset, &GCPointClientUIWorldPanel::SetDepthOffset)
        .addProperty("OwnerContext", &GCPointClientUIWorldPanel::GetOwnerContext, &GCPointClientUIWorldPanel::SetOwnerContext)
        .addProperty("HorizontalAlign", &GCPointClientUIWorldPanel::GetHorizontalAlign, &GCPointClientUIWorldPanel::SetHorizontalAlign)
        .addProperty("VerticalAlign", &GCPointClientUIWorldPanel::GetVerticalAlign, &GCPointClientUIWorldPanel::SetVerticalAlign)
        .addProperty("Orientation", &GCPointClientUIWorldPanel::GetOrientation, &GCPointClientUIWorldPanel::SetOrientation)
        .addProperty("AllowInteractionFromAllSceneWorlds", &GCPointClientUIWorldPanel::GetAllowInteractionFromAllSceneWorlds, &GCPointClientUIWorldPanel::SetAllowInteractionFromAllSceneWorlds)
        .addProperty("CSSClasses", &GCPointClientUIWorldPanel::GetCSSClasses, &GCPointClientUIWorldPanel::SetCSSClasses)
        .addProperty("Opaque", &GCPointClientUIWorldPanel::GetOpaque, &GCPointClientUIWorldPanel::SetOpaque)
        .addProperty("NoDepth", &GCPointClientUIWorldPanel::GetNoDepth, &GCPointClientUIWorldPanel::SetNoDepth)
        .addProperty("RenderBackface", &GCPointClientUIWorldPanel::GetRenderBackface, &GCPointClientUIWorldPanel::SetRenderBackface)
        .addProperty("UseOffScreenIndicator", &GCPointClientUIWorldPanel::GetUseOffScreenIndicator, &GCPointClientUIWorldPanel::SetUseOffScreenIndicator)
        .addProperty("ExcludeFromSaveGames", &GCPointClientUIWorldPanel::GetExcludeFromSaveGames, &GCPointClientUIWorldPanel::SetExcludeFromSaveGames)
        .addProperty("Grabbable", &GCPointClientUIWorldPanel::GetGrabbable, &GCPointClientUIWorldPanel::SetGrabbable)
        .addProperty("OnlyRenderToTexture", &GCPointClientUIWorldPanel::GetOnlyRenderToTexture, &GCPointClientUIWorldPanel::SetOnlyRenderToTexture)
        .addProperty("DisableMipGen", &GCPointClientUIWorldPanel::GetDisableMipGen, &GCPointClientUIWorldPanel::SetDisableMipGen)
        .addProperty("ExplicitImageLayout", &GCPointClientUIWorldPanel::GetExplicitImageLayout, &GCPointClientUIWorldPanel::SetExplicitImageLayout)
        .addProperty("Parent", &GCPointClientUIWorldPanel::GetParent, &GCPointClientUIWorldPanel::SetParent)
        .addFunction("ToPtr", &GCPointClientUIWorldPanel::ToPtr)
        .addFunction("IsValid", &GCPointClientUIWorldPanel::IsValid)
        .endClass();
}