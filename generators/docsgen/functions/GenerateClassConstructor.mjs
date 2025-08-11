import GenerateFunctionParameters from "./GenerateFunctionParameters.mjs";
import GenerateFunctionReturn from "./GenerateFunctionReturn.mjs";
import ProcessFunctionParameters from "./ProcessFunctionParameters.mjs";

export default function GenerateClassConstructor(pageContent, lang, category) {
    let constr = pageContent["constructor"]
    if (!constr || typeof constr == "function" || constr.hidden) return "";
    let outString = "## Constructor\n"
    outString += `\`\`\`${lang}${GenerateFunctionParameters(constr["arguments"], lang)}
${lang == "cs" ? `using SwiftlyS2.API.${category.category.includes("sdk") ? category.category.toUpperCase() : "Scripting"};\n` : GenerateFunctionReturn(constr.return, lang)}`

    let v = category.data.variable
    if (lang == "cs") {
        let cls = category.data.title.split(" ").join("")

        outString += `var ${pageContent.name.toLowerCase()} = new ${pageContent.override_class ? pageContent.override_class["cs"] : `${cls}.${pageContent.name}`}`
    } else if (lang == "lua") {
        if (pageContent.override_variable) v = ""
        outString += `local ${pageContent.name.toLowerCase()} = ${v}${v == "" ? "" : ":"}${pageContent.name}`
    }

    return outString + `(${ProcessFunctionParameters(constr["arguments"], lang)})\n\`\`\`\n`;
}