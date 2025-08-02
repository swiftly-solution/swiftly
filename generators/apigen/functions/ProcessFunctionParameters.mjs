import GenerateType from "./GenerateType.mjs"

export default function ProcessFunctionParameters(args, language) {
    const returnValues = []

    if (language == "cs") {
        for (const [arg, data] of Object.entries(args)) {
            if (arg == "...") {
                returnValues.push(`params ${GenerateType(data, language)}[] args`);
            } else {
                returnValues.push(`${GenerateType(data, language)} ${arg}`)
            }
        }
    } else {
        for (const [arg, data] of Object.entries(args)) {
            if (arg == "...") {
                returnValues.push("(object)args")
            } else {
                returnValues.push(GenerateType(data, "cs").includes("[]") ? `(object)${arg}` : arg)
            }
        }
    }

    return returnValues.join(", ")
}