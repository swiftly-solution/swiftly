import { existsSync, readFileSync } from "fs"
import GenerateFunctionParameters from "./GenerateFunctionParameters.mjs"
import GenerateType from "./GenerateType.mjs"
import GenerateFunctionReturn from "./GenerateFunctionReturn.mjs"
import { currentPath } from "../index.mjs"
import FetchNames from "../languages/FetchNames.mjs"
import ProcessFunctionParameters from "./ProcessFunctionParameters.mjs"
import { markdownTable } from "../utils/markdownTable.mjs"

export default function GenerateEventPage(pageKey, pageContent, category) {
    let page = readFileSync("templates/types.tpl").toString()
    let path = currentPath.split("/").slice(0, -1).join("/")

    page = page.replace("{title}", pageContent.event_name)
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
        tabContents.push(`<TabsContent value="${lang}">
\`\`\`${lang}${GenerateFunctionParameters(pageContent.mode == "core" ? { [lang == "cs" ? "@event" : "event"]: "Event", ...pageContent.arguments } : { [lang == "cs" ? "@event" : "event"]: "Event" }, lang)}${lang == "cs" ? `\n// Event returns ${GenerateType(pageContent.return, lang)} via event.SetReturn\n// The function returns an EventResult` : ""}
${lang != "cs" ? GenerateFunctionReturn("EventResult", lang) : ""}${lang == "lua" ? `--- @event returns ${GenerateType(pageContent.return, lang)} via event:SetReturn\n` : ""}${lang == "cs" ? "Events." : ""}AddEventHandler("${pageContent.event_name}", ${lang == "lua" ? "function" : ""}(${ProcessFunctionParameters(pageContent.mode == "core" ? { [lang == "cs" ? "@event" : "event"]: "Event", ...pageContent.arguments } : { [lang == "cs" ? "@event" : "event"]: "Event" }, lang)})${lang == "lua" ? "" : " => {"}
    ${lang == "lua" ? "-- [[...]]" : "// ..."}
    return EventResult.Continue;
${lang == "lua" ? "end" : "}"})
\`\`\`${existsSync(`${path}/additional/${pageKey.split(".").join("/")}/${lang}.md`) ? "\n" + readFileSync(`${path}/additional/${pageKey.split(".").join("/")}/${lang}.md`) : ""}
</TabsContent>`)
    }

    if (pageContent.mode != "core") {
        const gameEventData = [
            ["Key", "Data Type"]
        ]

        for (const key of Object.keys(pageContent.arguments)) {
            gameEventData.push([
                `\`${key}\``,
                `\`${pageContent.arguments[key]}\``
            ])
        }

        page += `\n\n## Arguments\n${markdownTable(gameEventData, {
            align: ['c', 'c']
        })}`
    }

    return page.replace(
        "{code}",
        str.replace("{tabtriggers}", tabsTrigger.join("\n")).replace("{tabcontents}", tabContents.join("\n"))
    )
}