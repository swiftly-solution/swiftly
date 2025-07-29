import GenerateClassFunctions from "./GenerateClassFunctions.mjs"
import GenerateClassProperties from "./GenerateClassProperties.mjs"
import ProcessFunctionParameters from "./ProcessFunctionParameters.mjs"

export default function GenerateClassContent(pageContent, category) {

    let processedParams = ""
    if (typeof pageContent["constructor"] != "function") {
        processedParams = ProcessFunctionParameters(pageContent["constructor"].arguments, "lua")
        if (processedParams != "") processedParams = `, ${processedParams}`
    }

    if (category.includes("Game")) {
        return ""
    } else {
        return `public class ${pageContent.name} : ClassData
{
${typeof pageContent["constructor"] != "function" && !pageContent["constructor"].hide ? `    public ${pageContent.name}(${ProcessFunctionParameters(pageContent["constructor"].arguments, "cs")}): base(Internal_API.Invoker.CallNative<IntPtr>("${pageContent.name}", "${pageContent.name}", CallKind.ClassFunction${processedParams}))\n    {\n    }` : ""}${GenerateClassFunctions(pageContent, category)}${GenerateClassProperties(pageContent, category)}
}`
    }
}