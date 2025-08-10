import GenerateClassPropertyType from './GenerateClassPropertyType.mjs'

const numbers = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]

export default function GenerateClassProperties(pageContent, lang) {
    const properties = pageContent.properties || []
    if (!properties.length) return ""

    const outprops = []

    for (const prop of properties) {
        let skip = false;
        for (var num of numbers) {
            if (prop.name.startsWith(num)) {
                skip = true;
                break;
            }
        }

        if (skip) continue;
        outprops.push(`## ${prop.name} ${prop.writable ? "" : "(Read-Only)"}\n\`\`\`${lang}\n${GenerateClassPropertyType(prop.type, lang)}\n${pageContent.name.toLowerCase()}.${prop.name}\n\`\`\``)
    }

    if (outprops.length == 0) return `# Properties\nThere are no properties available.`
    else return `# Properties\nHere are listed all the properties.\n${outprops.join("\n")}`
}