export default function GenerateTypeContent(pageContent) {

    return `public enum ${pageContent.name}
{
${Object.keys(pageContent.values).map((v) => `    ${v} = ${pageContent.values[v]}`).join(",\n")}    
}`

}