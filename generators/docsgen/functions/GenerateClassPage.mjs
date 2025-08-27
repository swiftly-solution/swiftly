import { existsSync, readFileSync } from 'fs'
import FetchNames from '../languages/FetchNames.mjs'
import GenerateClassProperties from './GenerateClassProperties.mjs'
import { currentPath } from '../index.mjs'
import GenerateClassFunctions from './GenerateClassFunctions.mjs'
import GenerateClassConstructor from './GenerateClassConstructor.mjs'

export default function GenerateClassPage(pageKey, pageContent, category) {
    let page = readFileSync("templates/class.tpl").toString()
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
        const props = GenerateClassProperties(pageContent, lang)
        tabsTrigger.push(`<TabsTrigger value="${lang}">${langs[lang]}</TabsTrigger>`)
        tabContents.push(`<TabsContent value="${lang}">
${GenerateClassConstructor(pageContent, lang, category)}${props}${props != "" ? "\n" : ""}${GenerateClassFunctions(pageContent, lang)}
${existsSync(`${path}/additional/${pageKey.split(".").join("/")}/${lang}.md`) ? readFileSync(`${path}/additional/${pageKey.split(".").join("/")}/${lang}.md`) : ""}${existsSync(`${path}/examples/${pageKey.split(".").join("/")}/example.${lang}`) ? `\n### Example\n\`\`\`${lang}\n${readFileSync(`${path}/examples/${pageKey.split(".").join("/")}/example.${lang}`)}\n\`\`\`` : ""}
</TabsContent>`)
    }

    return page.replace(
        "{code}",
        str.replace("{tabtriggers}", tabsTrigger.join("\n")).replace("{tabcontents}", tabContents.join("\n"))
    )
}