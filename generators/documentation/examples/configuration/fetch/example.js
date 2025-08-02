commands.Register("configfetch", (playerid, arguments, arguments_count, silent, prefix) => {
    let value = config.Fetch("configuration.test");
    if (value) {
        if (typeof (value) == "object") {
            console.log(`Configuration is an object: ${JSON.stringify(value)}`);
        } else {
            console.log(`Configuration value: ${value}`);
        }
    } else {
        console.log("Configuration key not found!");
    }
});