import GenerateFunctionParameters from "./GenerateFunctionParameters.mjs"
import GenerateFunctionReturn from "./GenerateFunctionReturn.mjs"
import ProcessFunctionParameters from "./ProcessFunctionParameters.mjs"

export default function GenerateClassFunctions(pageContent, lang) {
    const functions = pageContent.functions || []
    if (!functions.length) return ""

    const outfunctions = []

    for (const func of functions) {
        let name = func.name
        if (func.name.includes("/")) {
            const forLang = func.name.split("/")[0]
            if (forLang != lang) continue;
            name = func.name.split("/")[1];
        }

        const parms = GenerateFunctionParameters(func.arguments, lang)
        outfunctions.push(`## ${name}\n${func.description ? `${func.description}\n` : ""}\`\`\`${lang}${parms}
${GenerateFunctionReturn(func.return, lang)} ${pageContent.name.toLowerCase()}${lang == "lua" ? ":" : "."}${name}(${ProcessFunctionParameters(func.arguments, lang)})\n\`\`\``)
    }

    if (outfunctions.length == 0) return `# Functions\nThere are no functions available.`
    else return `# Functions\nHere are listed all the functions.\n${outfunctions.join("\n")}`
}