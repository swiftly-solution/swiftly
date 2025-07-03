commands.Register("configreload", (playerid, arguments, arguments_count, silent, prefix) => {
    config.Reload("configuration");
    console.log("Configuration reloaded for 'configuration'");
});