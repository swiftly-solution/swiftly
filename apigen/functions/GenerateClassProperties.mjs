import GenerateType from "./GenerateType.mjs";

export default function GenerateClassProperties(pageData, category) {
    if (!pageData.properties) return "";

    const funcs = []

    for (const param of pageData.properties) {
        funcs.push(`    public ${GenerateType(param.type, "cs")} ${param.name}
    {
        get { return Invoker.CallNative<${GenerateType(param.type, "cs")}>("${category.includes("Game") ? `SDKClass` : pageData.name}", "${param.name}", CallKind.ClassMember, m_classData); }${param.writable ? `\n        set { Invoker.CallNative("${category.includes("Game") ? `SDKClass` : pageData.name}", "${param.name}", CallKind.ClassMember, m_classData, value); }` : ""}
    }`)
    }

    return `\n` + funcs.join("\n");
}