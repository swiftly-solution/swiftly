import GenerateType from "./GenerateType.mjs";

export default function GenerateFunctionReturn(returnval, language) {
    if (language == "lua") return `--- @return ${GenerateType(returnval, language)}\n`
    else if (language == "cs") return GenerateType(returnval, language)
}