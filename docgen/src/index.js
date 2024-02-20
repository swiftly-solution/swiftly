import { cpSync, mkdirSync, readFileSync, rm, writeFileSync } from "fs";

const FetchData = () => {
    return JSON.parse(readFileSync("data/data.json").toString());
}

const FetchTemplates = () => {
    return JSON.parse(readFileSync("data/templates.json").toString())
}

const data = FetchData();
const templates = FetchTemplates();

let generatedFiles = 0

const GenerateLuaType = (param) => {
    if (param == "const char*" || param.includes("string")) return "string";
    else if (param == "callback" || param.includes("std::function")) return "callback";
    else if (param == "player") return "number";
    else if (param == "bool") return "boolean as number";
    else if (param == "void") return "void";
    else if (param == "int32_t" || param == "uint32_t" || param == "uint16_t" || param == "uint64_t" || param == "int" || param == "uint8_t" || param == "unsigned short" || param == "unsigned long long" || param == "short" || param == "long" || param == "float" || param == "unsigned char" || param == "Weapon*") return "number";
    else if (param == "DataType") return "string / number / boolean as number";
    else if (param == "DB_Result" || param.includes("vector") || param == "const char**" || param.includes("std::unordered_map")) return "table";
    else if (param == "Entity*" || param == "HTTPRequest*") return "object";
    else if (param == "Vector*") return "vector3";
    else if (param == "Color*") return "table ({ r -- number , g -- number, b -- number, a -- number })";
    else if (param == "MessageType") return "MessageType";
    else if (param == "") return "args: string / number / boolean";
    else if (param == "ELogType") return "LogType";
    else if (param == "ContentType") return "ContentType";
    else if (param == "ENetworkDisconnectionReason") return "DisconnectReason";
    else if (param == "HudDestination") return "HudDestination";
    else if (param == "PlayerStat") return "PlayerStat";
    else if (param == "WeaponSlot") return "WeaponSlot";
    else if (param == "WeaponSilencerType") return "WeaponSilencerType";
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

const GenerateEventData = (data, language) => {
    if (language == "lua") return `events:on("${data.title}", function({parameters}) --[[ ... ]] end)`
    else if (language == "cpp") return `${data.return} ${data.title}({parameters})`
}

const ProcessTemplate = (data, language) => {
    const template = templates[data.template]
    if (template == undefined) return "";

    if (data.template == "getting-started") return template.replace(/{description}/g, data.description).replace(/{content}/g, data.content[language]).replace(/{additional}/g, (data.additional || ""));
    else if (data.template == "function-syntax") return template.replace(/{description}/g, data.description).replace(/{return_type}/g, GenerateType(data.return, language)).replace(/{highlight_lang}/g, language).replace(/{variable}/g, data.variable[language]).replace(/{parameters}/g, ProcessParameters(data.params, language)).replace(/{additional}/g, (data.additional[language] || ""));
    else if (data.template == "event-syntax") return template.replace(/{description}/g, data.description).replace(/{highlight_lang}/g, language).replace(/{return_type}/g, GenerateType(data.return, language)).replace(/{variable}/g, GenerateEventData(data, language)).replace(/{parameters}/g, ProcessParameters(data.params, language)).replace(/{additional}/g, (data.additional[language] || ""))
}


const languages = ["lua", "cpp"];

const ProcessData = async (data, subfolder) => {
    for (const key of Object.keys(data)) {
        if (data[key].iscategory == true) {
            const langs = [];
            if (data[key].language == "both") langs.push(...languages);
            else langs.push(data[key].language)

            for (const lang of langs) {
                mkdirSync(`output/${lang}/${subfolder}${key}`, { recursive: true });

                writeFileSync(`output/${lang}/${subfolder}${key}/_category_.json`, JSON.stringify({
                    label: data[key].title,
                    position: 2,
                    link: {
                        type: "generated-index",
                        description: data[key].description
                    }
                }, null, 4));
                generatedFiles++;
            }
            ProcessData(data[key].data, `${subfolder}${key}/`)
        } else {
            const langs = [];
            if (data[key].language == "both") langs.push(...languages);
            else langs.push(data[key].language)

            for (const lang of langs) {
                writeFileSync(`output/${lang}/${subfolder}${key}.md`,
                    `${data[key].position != undefined ? `---\nsidebar_position: ${data[key].position}\n---\n\n` : ""}# ${data[key].title}\n\n${ProcessTemplate(data[key], lang)}`
                )
                generatedFiles++;
            }
        }
    }
}

rm("output", { recursive: true }, () => {
    const start = Date.now();
    cpSync("data/static", "output", { recursive: true, force: true })
    ProcessData(data, "")
    console.log(`[Swiftly] [Documentation Generator] ${generatedFiles} files were generated from JSON data. (${Date.now() - start}ms)`)
});