import GenerateType from "./GenerateType.mjs";
import ProcessFunctionParameters from "./ProcessFunctionParameters.mjs";

export default function GenerateFunctionContent(pageContent, category) {
    let args = ProcessFunctionParameters(pageContent.arguments, "lua")
    if (args != "") args = `, ${args}`

    const namespace = pageContent.override_variable ? "_G" : category
    if (pageContent.override_function) return ""

    return `public static ${GenerateType(pageContent.return, 'cs')} ${pageContent.function}(${ProcessFunctionParameters(pageContent.arguments, "cs")})
{
${!pageContent.override_variable ? `    InitializeContext();\n` : ""}${GenerateType(pageContent.return, 'cs') == "void"
            ? `    Internal_API.Invoker.CallNative("${namespace}", "${pageContent.function}", Internal_API.CallKind.${!pageContent.override_variable ? "ClassFunction, _ctx" : "Function"}${args});`
            : `    return Internal_API.Invoker.CallNative<${GenerateType(pageContent.return, 'cs')}>("${namespace}", "${pageContent.function}", Internal_API.CallKind.${!pageContent.override_variable ? "ClassFunction, _ctx" : "Function"}${args});`
        }
}`

}