import { existsSync, readFileSync } from "fs"
import { currentPath } from "../index.mjs"
import FetchNames from "../languages/FetchNames.mjs"

export default function GenerateTypePage(pageKey, pageContent, category) {
    let page = readFileSync("templates/types.tpl").toString()
    let path = currentPath.split("/").slice(0, -1).join("/")

    page = page.replace("{title}", pageContent.name)
    page = page.replace("{description}", pageContent.description)

    const langs = FetchNames()
    let considerLanguages = Object.keys(langs)

    const str = `<Tabs defaultValue="${considerLanguages[0]}">
      <TabsList class="grid w-full grid-cols-${considerLanguages.length} flex">
        {tabtriggers}
      </TabsList>
    {tabcontents}
    </Tabs>`

    var tabsTrigger = []
    var tabContents = []

    for (const lang of considerLanguages) {
        tabsTrigger.push(`<TabsTrigger value="${lang}">${langs[lang]}</TabsTrigger>`)
        if (lang == "cs") {
            tabContents.push(`<TabsContent value="${lang}">
\`\`\`${lang}
using SwiftlyS2.API.Scripting.${category.data.variable != "" ? category.data.variable : "Generic"};
enum ${pageContent.name}
{
${Object.keys(pageContent.values).map((k) => `        ${k} = ${pageContent.values[k]}`).join(",\n")}
}
\`\`\`${existsSync(`${path}/additional/${pageKey.split(".").join("/")}/${lang}.md`) ? "\n" + readFileSync(`${path}/additional/${pageKey.split(".").join("/")}/${lang}.md`) : ""}
</TabsContent>`)
        } else {
            tabContents.push(`<TabsContent value="${lang}">
\`\`\`${lang}
${category.data.variable != "" ? category.data.variable.toLowerCase() + "." : ""}${pageContent.name} = {
${Object.keys(pageContent.values).map((k) => {
                if (lang == "js") return `        "${k}": ${pageContent.values[k]}`
                else if (lang == "lua") return `        ${k} = ${pageContent.values[k]}`
            }).join(",\n")}
}
\`\`\`${existsSync(`${path}/additional/${pageKey.split(".").join("/")}/${lang}.md`) ? "\n" + readFileSync(`${path}/additional/${pageKey.split(".").join("/")}/${lang}.md`) : ""}
</TabsContent>`)
        }
    }

    return page.replace(
        "{code}",
        str.replace("{tabtriggers}", tabsTrigger.join("\n")).replace("{tabcontents}", tabContents.join("\n"))
    )
}