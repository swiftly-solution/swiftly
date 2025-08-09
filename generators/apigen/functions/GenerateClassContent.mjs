import GenerateClassFunctions from "./GenerateClassFunctions.mjs"
import GenerateClassProperties from "./GenerateClassProperties.mjs"
import GenerateType from "./GenerateType.mjs"
import ProcessFunctionParameters from "./ProcessFunctionParameters.mjs"

export default function GenerateClassContent(pageContent, category) {

    let processedParams = ""
    if (typeof pageContent["constructor"] != "function") {
        processedParams = ProcessFunctionParameters(pageContent["constructor"].arguments, "lua")
        if (processedParams != "") processedParams = `, ${processedParams}`
    }

    if (pageContent.name.startsWith("CCS_") || pageContent.name.startsWith("C_") || pageContent.name.startsWith("CBasePulse") || pageContent.name.startsWith("CPulse")) return "";

    if (category == "Classes") {
        const parentProp = pageContent.properties.filter((v) => v.name == "Parent" && GenerateType(v.type, "cs") == v.type)[0]
        const constructorArgs = ProcessFunctionParameters(pageContent["constructor"].arguments, "cs")
        let constructor = ``
        if (constructorArgs.includes("|")) {
            const splitArgs = constructorArgs.split(" ")[0].split("|")
            const argument = constructorArgs.split(" ")[1]

            for (const arg of splitArgs) {
                if (typeof pageContent["constructor"] != "function" && !pageContent["constructor"].hide) {
                    if (constructor != "") constructor += "\n";
                    constructor += `    public ${pageContent.name}(${GenerateType(arg, "cs")} ${argument})\n    {\n        this.m_classData = Internal_API.Invoker.CallNative<IntPtr>("${pageContent.name}", "${pageContent.name}", Internal_API.CallKind.ClassFunction, ${argument});\n    }`;
                }
            }
            constructor += `\n    public ${pageContent.name}()\n    {\n    }`;
            constructor += `\n    public ${pageContent.name}(IntPtr ptr_or_class)\n    {\n        this.m_classData = Internal_API.Invoker.CallNative<IntPtr>("${pageContent.name}", "${pageContent.name}", Internal_API.CallKind.ClassFunction, $"0x{ptr_or_class:X}");\n    }`;
        } else {
            if (typeof pageContent["constructor"] != "function" && !pageContent["constructor"].hide) {
                constructor += `    public ${pageContent.name}(${ProcessFunctionParameters(pageContent["constructor"].arguments, "cs")}): base(Internal_API.Invoker.CallNative<IntPtr>("${pageContent.name}", "${pageContent.name}", Internal_API.CallKind.ClassFunction${processedParams}))\n    {\n    }`;
            }
        }

        if (parentProp) {
            if (parentProp.type.startsWith("CCS_") || parentProp.type.startsWith("C_") || parentProp.type.startsWith("CBasePulse") || parentProp.type.startsWith("CPulse")) return ""
        }

        return `public class ${pageContent.name} : ${parentProp ? parentProp.type : "ClassData"}
{
${constructor}${GenerateClassFunctions(pageContent, category).replace(new RegExp(`\"${pageContent.name}\"`, "g"), "\"SDKClass\"")}${GenerateClassProperties(pageContent, category).replace(new RegExp(`\"${pageContent.name}\"`, "g"), "\"SDKClass\"")}
    public override string ToString() => $"${pageContent.name}(ptr={this.m_classData})";
}`
    } else {
        const constructorArgs = ProcessFunctionParameters(typeof pageContent["constructor"] == "object" ? pageContent["constructor"].arguments : {}, "cs")
        let constructor = ``
        if (constructorArgs.includes("|")) {
            const splitArgs = constructorArgs.split(" ")[0].split("|")
            const argument = constructorArgs.split(" ")[1]

            for (const arg of splitArgs) {
                if (typeof pageContent["constructor"] != "function" && !pageContent["constructor"].hide) {
                    if (constructor != "") constructor += "\n";
                    constructor += `    public ${pageContent.name}(${GenerateType(arg, "cs")} ${argument}): base(ClassData(Internal_API.Invoker.CallNative<IntPtr>("${pageContent.name}", "${pageContent.name}", Internal_API.CallKind.ClassFunction, ${argument})))\n    {\n    }`;
                }
            }
        } else {
            if (typeof pageContent["constructor"] != "function" && !pageContent["constructor"].hide) {
                constructor += `    public ${pageContent.name}(${ProcessFunctionParameters(pageContent["constructor"].arguments, "cs")}): base(Internal_API.Invoker.CallNative<IntPtr>("${pageContent.name}", "${pageContent.name}", Internal_API.CallKind.ClassFunction${processedParams}))\n    {\n    }`;
            }
        }

        return `public class ${pageContent.name} : ClassData
{
${constructor}${GenerateClassFunctions(pageContent, category)}${GenerateClassProperties(pageContent, category)}
}`
    }
}