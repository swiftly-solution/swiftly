commands.Register("configfetchsize", (playerid, arguments, arguments_count, silent, prefix) => {
    let size = config.FetchArraySize("configuration.test3")
    if (size > 0) {
        console.log("Configuration key 'test3' exists and the array size is " + size);
    } else {
        console.log("Configuration 'test3' does not exist or is not an array!");
    }
});