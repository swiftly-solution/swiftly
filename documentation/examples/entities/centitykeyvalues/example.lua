local particle = CreateEntityByName("info_particle_system")
local particleSystem = CParticleSystem(particle)
local keyvals = CEntityKeyValues()

-- The effect needs to be precached
keyvals:SetString("effect_name", "particles/cs2fixes/player_beacon.vpcf")
keyvals:SetInt("tint_cp", 1)
keyvals:SetVector("origin", Vector(2.3, 4.5, 6.7))
keyvals:SetBool("start_active", true)

particleSystem.Tint = Color(0, 186, 105, 255)
particleSystem:Spawn(keyvals)
