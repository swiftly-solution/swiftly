export default function GenerateFunctionVariable(pageContent, category, language) {
    if (pageContent.override_function && pageContent.override_function[language]) return pageContent.override_function[language]
    if (language == "cs") {
        let cls = ""
        if (pageContent.override_variable) cls = "Generic"
        else cls = category.data.title.split(" ").join("")

        return `${cls}.${pageContent.function}`
    } else if (language == "lua") {
        let v = category.data.variable
        if (pageContent.override_variable) v = ""
        return `${v}${v == "" ? "" : ":"}${pageContent.function}`
    } else throw new Error(`Unimplemented for language ${language}`)
}