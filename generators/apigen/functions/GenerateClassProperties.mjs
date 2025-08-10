import GenerateType from "./GenerateType.mjs";

const numbers = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]

export default function GenerateClassProperties(pageData, category) {
    if (!pageData.properties) return "";

    const funcs = []

    for (const param of pageData.properties) {
        let skip = false;
        for (var num of numbers) {
            if (param.name.startsWith(num)) {
                skip = true;
                break;
            }
        }

        if (skip) continue;
        if (param.type.startsWith("CCS_") || param.type.startsWith("C_") || param.name == "IsValid") continue;

        funcs.push(`    public ${GenerateType(param.type, "cs")} ${param.name}
    {
        get { return Invoker.CallNative<${GenerateType(param.type, "cs")}>("${category.includes("Game") ? `SDKClass` : pageData.name}", "${param.name}", CallKind.ClassMember, m_classData); }${param.writable ? `\n        set { Invoker.CallNative("${category.includes("Game") ? `SDKClass` : pageData.name}", "${param.name}", CallKind.ClassMember, m_classData, value); }` : ""}
    }`)
    }

    return `\n` + funcs.join("\n");
}