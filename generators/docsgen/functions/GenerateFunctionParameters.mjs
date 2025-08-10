import GenerateType from "./GenerateType.mjs";

export default function GenerateFunctionParameters(args, language) {
    const returnParams = [];
    for (const paramkey of Object.keys(args)) {
        let forlang = language;
        let name = paramkey
        if (paramkey.includes("/")) {
            forlang = paramkey.split("/")[0];
            name = paramkey.split("/")[1];
        }

        if (forlang == language) {
            const type = GenerateType(args[paramkey], language);

            if (language == "lua") returnParams.push(`--- @param ${name} ${type}`)
        }
    }

    if (language == "lua") {
        if (returnParams.length == 0) return "";
        else return `\n${returnParams.join("\n")}`
    } else if (language == "cs") {
        return ""
    }
}