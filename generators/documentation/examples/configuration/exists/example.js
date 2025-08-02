commands.Register("configexists", (playerid, arguments, arguments_count, silent, prefix) => {
    if (config.Exists("configuration.test")) {
        console.log("Configuration key 'test' exists!");
    } else {
        console.log("Configuration 'test' does not exist!");
    }
});