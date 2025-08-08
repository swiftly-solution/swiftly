using SwiftlyS2.API.Scripting;

if (Convars.GetType("sv_cheats") == EConVarType.EConVarType_Bool){
    Console.WriteLine("sv_cheats is a boolean convar");
}