import GenerateClassPropertyType from './GenerateClassPropertyType.mjs'

export default function GenerateClassProperties(pageContent, lang) {
    const properties = pageContent.properties || []
    if (!properties.length) return ""

    const outprops = []

    for (const prop of properties) {
        if (/\d/g.test(prop.name)) continue;
        outprops.push(`## ${prop.name} ${prop.writable ? "" : "(Read-Only)"}\n\`\`\`${lang}\n${GenerateClassPropertyType(prop.type, lang)}\n${pageContent.name.toLowerCase()}.${prop.name}\n\`\`\``)
    }

    if (outprops.length == 0) return `# Properties\nThere are no properties available.`
    else return `# Properties\nHere are listed all the properties.\n${outprops.join("\n")}`
}