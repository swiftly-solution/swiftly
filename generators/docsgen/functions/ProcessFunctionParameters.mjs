import GenerateType from "./GenerateType.mjs"

export default function ProcessFunctionParameters(args, language) {
    const returnValues = []

    if (language == "cs") {
        for (const [arg, data] of Object.entries(args)) {
            returnValues.push(`${GenerateType(data, language)} ${arg}`)
        }
    } else {
        for (const arg of Object.keys(args)) {
            returnValues.push(arg)
        }
    }

    return returnValues.join(", ")
}