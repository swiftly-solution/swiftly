const luaReplacer = {
    bool: "boolean",
    string: "string",
    int32: "number",
    int64: "number",
    uint64: "number",
    double: "number",
    float: "number",
    uint32: "number",
    uint8: "number",
    int8: "number",
    int16: "number",
    uint16: "number",
    Color: "Color",
    Vector: "Vector",
    Vector2D: "Vector2D",
    Vector4D: "Vector4D",
    void: "nil",
    any: "any",
    SDKClass: "ClassData"
}

const jsReplacer = {
    bool: "bool",
    string: "string",
    int32: "number",
    int64: "number",
    uint64: "number",
    double: "number",
    float: "number",
    uint32: "number",
    uint8: "number",
    int8: "number",
    int16: "number",
    uint16: "number",
    Color: "Color",
    Vector: "Vector",
    Vector2D: "Vector2D",
    Vector4D: "Vector4D",
    void: "void",
    any: "any",
    SDKClass: "ClassData"
}

const csReplacer = {
    bool: "bool",
    string: "string",
    int32: "int",
    int64: "long",
    uint64: "ulong",
    double: "double",
    float: "float",
    uint32: "uint",
    uint8: "byte",
    int8: "char",
    int16: "short",
    uint16: "ushort",
    Color: "Color",
    Vector: "Vector",
    Vector2D: "Vector2D",
    Vector4D: "Vector4D",
    void: "void",
    any: "object",
    SDKClass: "ClassData"
}

export default function GenerateType(data, language) {
    if (language == "lua") {
        if (typeof data == "object") {
            const args = Object.keys(data.arguments)
            let totalArgs = []
            for (const arg of args) {
                totalArgs.push(`${arg}:${GenerateType(data.arguments[arg], language)}`)
            }

            return `fun(${totalArgs.join(",")})${data.return == "void" ? "" : `:${GenerateType(data.return, language)}`}`
        } else {
            if (data.includes("[]")) return "table";
            else if (data.includes(")")) return "table"
            else if (data.includes(":")) return "table";
            else if (data.endsWith("?")) return `${GenerateType(data.split("?")[0], language)}|nil`
            else if (luaReplacer.hasOwnProperty(data)) return luaReplacer[data]
            else if (data.includes(",")) return data
            else {
                return data
            }
        }
    } else if (language == "js") {
        if (typeof data == "object") {
            const args = Object.keys(data.arguments)
            let totalArgs = []
            for (const arg of args) {
                totalArgs.push(`${arg}:${GenerateType(data.arguments[arg], language)}`)
            }

            return `(${totalArgs.join(", ")}) => ${GenerateType(data.return, language)}`
        } else {
            if (data.includes("[]")) return `${GenerateType(data.split("[")[data.split("[").length - 1], language)}[]`;
            else if (data.includes(")")) return GenerateType(data.split(")")[0].split("(")[1], language) + data.split(")")[1]
            else if (data.includes(":")) return `Object.<${GenerateType(data.split(":")[0], language)}, ${GenerateType(data.split(":")[1], language)}>`
            else if (data.endsWith("?")) return `${GenerateType(data.split("?")[0], language)}?`
            else if (jsReplacer.hasOwnProperty(data)) return jsReplacer[data]
            else if (data.includes(",")) return `[${data.split(",").map((v) => GenerateType(v, language)).join(", ")}]`
            else {
                return data
            }
        }
    } else if (language == "cs") {
        if (typeof data == "object") {
            const args = Object.values(data.arguments)
            let types = []
            for (const arg of args) {
                types.push(GenerateType(arg, language))
            }

            return `Func<${types.join(",")}${types.length != 0 ? ", " : ""}${GenerateType(data.return, language)}>`
        } else {
            if (data.includes(",")) return `(${data.split(",").map((v) => GenerateType(v, language)).join(", ")})`
            else if (data.includes("[]")) return `${GenerateType(data.split("[")[0], language)}[]`;
            else if (data.includes(")")) return GenerateType(data.split(")")[0].split("(")[1], language) + data.split(")")[1]
            else if (data.includes(":")) return `Dictionary<${data.split(":").map((v) => GenerateType(v, language)).join(", ")}>`
            else if (data.includes("?")) return `${GenerateType(data.split("?")[0], language)}?`
            else if (csReplacer.hasOwnProperty(data)) return csReplacer[data]
            else return data;
        }
    }
}