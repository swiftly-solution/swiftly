import { existsSync, readFileSync } from "fs"
import FetchNames from "../languages/FetchNames.mjs"
import GenerateFunctionParameters from "./GenerateFunctionParameters.mjs"
import GenerateFunctionReturn from "./GenerateFunctionReturn.mjs"
import GenerateFunctionVariable from "./GenerateFunctionVariable.mjs"
import ProcessFunctionParameters from "./ProcessFunctionParameters.mjs"
import { currentPath } from "../index.mjs"

export default function GenerateFunctionPage(pageKey, pageContent, category) {
    let page = readFileSync("templates/function.tpl").toString()
    let path = currentPath.split("/").slice(0, -1).join("/")

    page = page.replace("{title}", pageContent.function)
    page = page.replace("{description}", pageContent.description)

    const langs = FetchNames()
    let considerLanguages = Object.keys(langs)
    if (pageContent.override_function) {
        considerLanguages = Object.keys(pageContent.override_function)
    }

    const str = `<Tabs defaultValue="${considerLanguages[0]}">
  <TabsList class="grid w-full grid-cols-${considerLanguages.length} flex">
	{tabtriggers}
  </TabsList>
{tabcontents}
</Tabs>`

    var tabsTrigger = []
    var tabContents = []

    for (const lang of considerLanguages) {
        const fvar = GenerateFunctionVariable(pageContent, category, lang)
        tabsTrigger.push(`<TabsTrigger value="${lang}">${langs[lang]}</TabsTrigger>`)
        tabContents.push(`<TabsContent value="${lang}">
\`\`\`${lang}${GenerateFunctionParameters(pageContent.arguments, lang)}
${GenerateFunctionReturn(pageContent.return, lang)} ${fvar}${fvar.includes("(") ? "" : "("}${ProcessFunctionParameters(pageContent.arguments, lang)})
\`\`\`${existsSync(`${path}/additional/${pageKey.split(".").join("/")}/${lang}.md`) ? "\n" + readFileSync(`${path}/additional/${pageKey.split(".").join("/")}/${lang}.md`) : ""}
${existsSync(`${path}/examples/${pageKey.split(".").join("/")}/example.${lang}`) ? `\n### Example\n\`\`\`${lang}\n${readFileSync(`${path}/examples/${pageKey.split(".").join("/")}/example.${lang}`)}\n\`\`\`` : ""}
</TabsContent>`)
    }

    return page.replace(
        "{code}",
        str.replace("{tabtriggers}", tabsTrigger.join("\n")).replace("{tabcontents}", tabContents.join("\n"))
    )
}