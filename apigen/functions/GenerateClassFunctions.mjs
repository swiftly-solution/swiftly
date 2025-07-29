import GenerateType from "./GenerateType.mjs";
import ProcessFunctionParameters from "./ProcessFunctionParameters.mjs";

export default function GenerateClassFunctions(pageData, category) {
    if (!pageData.functions) return "";

    const funcs = []

    for (const func of pageData.functions) {
        let funcname = func.name
        if (funcname.includes("/")) {
            const lang = funcname.split("/")[0]
            if (lang != "cs") continue;

            funcname = funcname.split("/")[1]
        }
        let args = ProcessFunctionParameters(func.arguments, "lua")
        if (args != "") args = `, ${args}`

        funcs.push(`    public ${GenerateType(func.return, 'cs')} ${funcname}(${ProcessFunctionParameters(func.arguments, "cs")})
    {
${GenerateType(func.return, 'cs') == "void"
                ? `        Internal_API.Invoker.CallNative("${category.includes("Game") ? `SDKClass` : pageData.name}", "${funcname}", Internal_API.CallKind.ClassFunction, m_classData${args});`
                : `        return Internal_API.Invoker.CallNative<${GenerateType(func.return, 'cs')}>("${category.includes("Game") ? `SDKClass` : pageData.name}", "${funcname}", Internal_API.CallKind.ClassFunction, m_classData${args});`
            }
    }`)
    }

    return `\n` + funcs.join("\n");
}