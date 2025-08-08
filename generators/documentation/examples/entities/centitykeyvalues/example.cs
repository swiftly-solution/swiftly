using SwiftlyS2.API.Scripting;
using SwiftlyS2.API.SDK;

var particle = Generic.CreateEntityByName("info_particle_system");
var particleSystem = new CS2.CParticleSystem(particle);
var keyvals = new CoreClasses.CEntityKeyValues();

keyvals.SetString("effect_name", "particles/cs2fixes/player_beacon.vpcf");
keyvals.SetInt("tint_cp", 1);
keyvals.SetVector("origin", new CoreClasses.Vector(2.3, 4.5, 6.7));
keyvals.SetBool("start_active", true);

particleSystem.Tint = new CoreClasses.Color(0, 186, 105, 255);
particleSystem.Spawn(keyvals);