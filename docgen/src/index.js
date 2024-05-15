import { cpSync, existsSync, mkdirSync, readFileSync, rm, writeFileSync } from "fs";

const FetchData = () => {
    return JSON.parse(readFileSync("data/data.json").toString());
}

const FetchTemplates = () => {
    return JSON.parse(readFileSync("data/templates.json").toString())
}

const data = FetchData();
const templates = FetchTemplates();
const languages = ["lua", "cpp"];
const languagePrettyNames = {
    lua: "Lua",
    cpp: "C++"
}

let generatedFiles = 0;

const lua_datamap = {
    player: "number",
    "Entity*": "object",
    "Vector*": "vector3",
    "double*": "number",
    "Color*": "table ({ r -- number , g -- number, b -- number, a -- number })",
    "HTTPRequest*": "object",
    MessageType: "MessageType",
    ELogType: "LogType",
    ContentType: "ContentType",
    ENetworkDisconnectionReason: "DisconnectReason",
    HudDestination: "HudDestination",
    PlayerStat: "PlayerStat",
    gear_slot_t: "gear_slot_t",
    CSWeaponSilencerType: "CSWeaponSilencerType",
    PluginState: "PluginState",
    DataType: "string / number / boolean as number",
    void: "void",
    bool: "boolean as number",
    player: "number",
    int32_t: "number",
    uint32_t: "number",
    uint16_t: "number",
    uint64_t: "number",
    int: "number",
    uint8_t: "number",
    double: "number",
    "unsigned short": "number",
    "unsigned long long": "number",
    short: "number",
    long: "number",
    float: "number",
    "unsigned char": "number",
    "Weapon*": "number",
    CollisionGroup: "CollisionGroup",
    DamageTypes_t: "DamageTypes_t",
    TakeDamageFlags_t: "TakeDamageFlags_t",
    CSPlayerState: "CSPlayerState",
    CSPlayerBlockingUseAction_t: "CSPlayerBlockingUseAction_t",
    MoveType_t: "MoveType_t"
}

const GenerateLuaType = (param) => {
    if (param == "const char*" || param.includes("string")) return "string";
    else if (param == "callback" || param.includes("std::function")) return "callback";
    else if (param == "DB_Result" || param.includes("vector") || param == "const char**" || param.includes("std::unordered_map")) return "table";
    else if (param == "") return "args: string / number / boolean";
    else if (lua_datamap.hasOwnProperty(param)) return lua_datamap[param];
    else throw `${param} not implemented`;
}

const GenerateCPPType = (param) => {
    if (param == "player") return "Player*";
    else if (param == "callback") return "void*";
    else if (param == "MessageType") return "int";
    else return param;
}

const ProcessParameters = (params, language) => {
    const returnParams = [];
    for (const paramkey of Object.keys(params)) {
        let forlang = language;
        let name = paramkey
        if (paramkey.includes("/")) {
            forlang = paramkey.split("/")[0];
            name = paramkey.split("/")[1];
        }

        if (forlang == language) {
            if (language == "lua") {
                returnParams.push(`${(params[paramkey] == "player" || params[paramkey] == "Weapon*") ? `${name}id` : name} --[[ ${GenerateLuaType(params[paramkey])} ]]`)
            } else returnParams.push(`${GenerateCPPType(params[paramkey])} ${name}`);
        }
    }
    return returnParams.join(", ");
}

const GenerateType = (param, language) => {
    if (language == "lua") return GenerateLuaType(param);
    else return GenerateCPPType(param);
}

const GenerateEventString = (data, language) => {
    if (language == "lua") return `events:on("${data.title}", function({parameters}) --[[ ... ]] end)`
    else if (language == "cpp") return `${data.return} ${data.title}({parameters})`
}

const GenerateEventData = (data) => {
    const callouts = [];

    for (const lang of languages) {
        callouts.push(`<Tabs.Tab>
            \`\`\`${lang}
            @returns ${GenerateType(data.return, lang)}
            ${GenerateEventString(data, lang)}
            \`\`\`

            ${data.additional[lang] || ""}
        </Tabs.Tab>`.replace(/{parameters}/g, ProcessParameters(data.params, lang)))
    }

    return `<Tabs items={${JSON.stringify(Object.values(languagePrettyNames))}} defaultIndex="0">
        ${callouts.join("\n")}
    </Tabs>`
}

const GenerateGettingStarted = (data) => {
    const langs = [];
    if (data.language == "both") langs.push(...languages);
    else langs.push(data.language)

    const prettyNames = []
    for (const lang of langs) prettyNames.push(languagePrettyNames[lang]);

    const callouts = [];

    for (const lang of langs) {
        callouts.push(`<Tabs.Tab>
            ${data.content[lang]}

            ${data.additional ? data.additional[lang] : ""}
        </Tabs.Tab>`)
    }

    return `<Tabs items={${JSON.stringify(prettyNames)}} defaultIndex="0">
        ${callouts.join("\n")}
    </Tabs>`
}

const GenerateFunctionSyntax = (data) => {
    const langs = [];
    if (data.language == "both") langs.push(...languages);
    else langs.push(data.language)

    const prettyNames = []
    for (const lang of langs) prettyNames.push(languagePrettyNames[lang]);

    const callouts = [];

    for (const lang of langs) {
        callouts.push(`<Tabs.Tab>
            \`\`\`${lang}
            @returns ${GenerateType(data.return, lang)}
            ${data.variable[lang]}(${ProcessParameters(data.params, lang)})
            \`\`\`

            ${data.additional ? (data.additional[lang] || "") : ""}
        </Tabs.Tab>`)
    }

    return `<Tabs items={${JSON.stringify(prettyNames)}} defaultIndex="0">
        ${callouts.join("\n")}
    </Tabs>`
}

const GenerateTypeData = (data) => {
    const langs = languages;

    const prettyNames = []
    for (const lang of langs) prettyNames.push(languagePrettyNames[lang]);

    const callouts = [];

    for (const lang of langs) {
        callouts.push(`<Tabs.Tab>
            \`\`\`${lang}
${lang == "cpp" ? "enum " : ""}${data.title}${lang == "cpp" ? "" : " ="} {\n${(Object.keys(data.values).map((val) => `    ${val} = ${data.values[val]},`)).join("\n")}\n}
            \`\`\`
        </Tabs.Tab>`)
    }

    return `<Tabs items={${JSON.stringify(prettyNames)}} defaultIndex="0">
        ${callouts.join("\n")}
    </Tabs>`
}

const ProcessTemplate = (data) => {
    const template = templates[data.template]
    if (template == undefined) return "";

    if (data.template == "getting-started") return template.replace(/{description}/g, data.description).replace(/{callout}/g, GenerateGettingStarted(data));
    else if (data.template == "function-syntax") return template.replace(/{description}/g, data.description).replace(/{callout}/g, GenerateFunctionSyntax(data));
    else if (data.template == "event-syntax") return template.replace(/{description}/g, data.description).replace(/{callout}/g, GenerateEventData(data));
    else if (data.template == "types-syntax") return template.replace(/{callout}/g, GenerateTypeData(data));
}

const ProcessData = async (data, subfolder) => {
    for (const key of Object.keys(data)) {
        if (data[key].iscategory) {
            mkdirSync(`output/${subfolder}${key}`, { recursive: true });

            if (Object.keys(data[key].data).length > 0 && !existsSync(`output/${subfolder}${key}/_meta.json`)) writeFileSync(`output/${subfolder}${key}/_meta.json`, JSON.stringify({}, null, 4));
            if (existsSync(`output/${subfolder}_meta.json`)) {
                let jsonParsed = JSON.parse(readFileSync(`output/${subfolder}_meta.json`).toString())
                jsonParsed[key] = data[key].title
                writeFileSync(`output/${subfolder}_meta.json`, JSON.stringify(jsonParsed, null, 4))
            }
            generatedFiles++;
            ProcessData(data[key].data, `${subfolder}${key}/`)
        } else {
            writeFileSync(`output/${subfolder}${key}.mdx`,
                `import { Callout } from 'nextra/components'\nimport { Tabs } from 'nextra/components'\n\n# ${data[key].title}\n\n${ProcessTemplate(data[key])}`
            )
            if (existsSync(`output/${subfolder}_meta.json`)) {
                let jsonParsed = JSON.parse(readFileSync(`output/${subfolder}_meta.json`).toString())
                jsonParsed[key] = data[key].title
                writeFileSync(`output/${subfolder}_meta.json`, JSON.stringify(jsonParsed, null, 4))
            }
            generatedFiles++;
        }
    }
}

rm("output", { recursive: true }, () => {
    const start = Date.now();
    cpSync("data/static", "output", { recursive: true, force: true })
    ProcessData(data, "")
    console.log(`[Swiftly] [Documentation Generator] ${generatedFiles} files were generated from JSON data. (${Date.now() - start}ms)`)
});
