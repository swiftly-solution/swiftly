import GenerateClassPage from "./GenerateClassPage.mjs"
import GenerateEventPage from "./GenerateEventPage.mjs"
import GenerateFunctionPage from "./GenerateFunctionPage.mjs"
import GenerateStaticPage from "./GenerateStaticPage.mjs"
import GenerateTypePage from "./GenerateTypePage.mjs"

export default function GeneratePage(pageKey, pageContent, category) {
    if (pageContent.kind == 'function') return { page: GenerateFunctionPage(pageKey, pageContent, category), title: pageContent.function }
    else if (pageContent.kind == "class") return { page: GenerateClassPage(pageKey, pageContent, category), title: pageContent.name }
    else if (pageContent.kind == "event") return { page: GenerateEventPage(pageKey, pageContent, category), title: pageContent.event_name }
    else if (pageContent.kind == "type") return { page: GenerateTypePage(pageKey, pageContent, category), title: pageContent.name }
    else if (pageContent.kind == "static") return { page: GenerateStaticPage(pageKey, pageContent, category), title: pageContent.title }
    else throw Error(`${pageContent.kind} not implemented`)
    // else return { page: "", title: "" }
}