const { readFileSync, writeFileSync } = require("fs")

const file = "sdk.json"
writeFileSync(file, JSON.stringify(JSON.stringify(JSON.parse(readFileSync(file)))))