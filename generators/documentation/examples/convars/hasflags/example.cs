using SwiftlyS2.API.Scripting;

if (Convars.HasFlags("sv_cheats", ConvarFlags.FCVAR_NOTIFY)){
    Console.WriteLine("sv_cheats is notifying the server for changes");
}