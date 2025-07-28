import GenerateType from "./GenerateType.mjs";

export default function GenerateClassPropertyType(kind, lang) {
    if (lang == "lua") return `--- @type ${GenerateType(kind, lang)}`
    else if (lang == "js") return `/** @type ${GenerateType(kind, lang)} */`
    else if (lang == "cs") return `// @type ${GenerateType(kind, lang)}`
}