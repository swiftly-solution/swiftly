import { readFileSync } from "fs";

let pageCategories = {
    function: "Functions",
    class: "Classes",
    static: "Informations",
    event: "Events",
    type: "Types"
}

export default function GenerateCategoryPage(category_key, data) {
    let page = readFileSync("templates/category.tpl").toString()

    page = page.replace("{title}", data.data.title)
    page = page.replace("{description}", `This is the list of items available for ${data.data.title} API.`)

    let currentCategories = []
    let perCategoryPages = {}
    for (const pg of data.pages) {
        const pageContent = JSON.parse(readFileSync(pg.filePath));
        if (!currentCategories.includes(pageContent.kind)) {
            currentCategories.push(pageContent.kind)
            perCategoryPages[pageContent.kind] = []
        }
        perCategoryPages[pageContent.kind].push(pg.key)
    }

    let subcategory = (data.category != category_key ? data.category.split(".").slice(1).join(".") : "")

    let categoryText = ""
    for (const [kind, entries] of Object.entries(perCategoryPages)) {
        categoryText += `${categoryText == "" ? "" : "\n"}## ${pageCategories[kind] || "Informations"}\n\n`
        categoryText += `<Catalog filter="${subcategory != "" ? entries.map((v) => `${subcategory}.${v}`).join(",") : entries.join(",")}"></Catalog>`
    }
    if (categoryText == "") categoryText = "<Catalog />"

    page = page.replace("{catalog}", categoryText)

    return page
}