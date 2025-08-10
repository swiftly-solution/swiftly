import { readdirSync, readFileSync, statSync, writeFileSync } from "fs";
import GenerateCategoryPage from "./functions/GenerateCategoryPage.mjs";
import GeneratePage from "./functions/GeneratePage.mjs";

export let links = {}
export let currentPath = ""

let cats = [
    {
        key: "plugin-docs",
        value: "../documentation/docs"
    },
    {
        key: "sdk",
        value: "../sdkdocumentation/docs"
    },
    {
        key: "sdk.cs2",
        value: "../gamesdkdocumentation/cs2/docs",
        subcategory: true
    }
]

function GetFiles(dir, files_) {
    files_ = files_ || [];
    var files = readdirSync(dir);
    for (var i in files) {
        var name = dir + '/' + files[i];
        if (statSync(name).isDirectory()) {
            GetFiles(name, files_);
        } else {
            files_.push(name);
        }
    }
    return files_;
}

let metadata = {}
for (const ent of cats) {
    const categories = readdirSync(ent.value)

    for (const category of categories) {
        const pages = GetFiles(`${ent.value}/${category}`)

        for (const page of pages) {
            let pageKey = page.replace(ent.value + "/", "")
            let origKey = page.replace(ent.value + "/", "")
            let isCategory = pageKey.endsWith("/_index.json")

            if (pageKey.endsWith("/_index.json")) {
                pageKey = pageKey.replace("/_index.json", "").replace(new RegExp("\/", "g"), ".")
            } else {
                pageKey = pageKey.replace(".json", "").replace(new RegExp("\/", "g"), ".")
            }

            if (isCategory) {
                metadata[pageKey] = {
                    data: JSON.parse(readFileSync(page)),
                    category: ent.key,
                    pages: []
                }
                links[JSON.parse(readFileSync(page)).title.split(" ").join("")] = { pageKey, category: ent.key }
            } else {
                let cat = origKey.replace(".json", "").split("/").slice(0, -1).join(".")
                if (!metadata[cat]) {
                    metadata[cat] = {
                        data: JSON.parse(readFileSync(`${ent.value}/${cat}/_index.json`)),
                        category: ent.key,
                        pages: []
                    }
                } else {
                    metadata[cat].pages.push({ filePath: page, key: pageKey })
                }

                const pageData = JSON.parse(readFileSync(page))
                if (pageData.kind == 'function') links[pageData.function] = { pageKey, category: ent.key }
                else if (pageData.kind == 'static') links[pageData.title] = { pageKey, category: ent.key }
                else links[pageData.name] = { pageKey, category: ent.key }
            }
        }
    }
}

let pages = {}

for (const ent of cats) {
    currentPath = ent.value

    let currentCategory = ent.subcategory ? ent.key.split(".")[0] : ent.key
    let subcategory = ent.subcategory ? `${ent.key.split(".").pop()}.` : ""

    if (!pages[currentCategory]) pages[currentCategory] = {}
    for (const [category, data] of Object.entries(metadata)) {
        if (data.category != ent.key) continue;
        pages[currentCategory][`${subcategory}${category}`] = {
            page: GenerateCategoryPage(category, data),
            title: data.data.title,
            icon: data.data.icon
        }

        for (const pg of data.pages) {
            const pageContent = JSON.parse(readFileSync(pg.filePath));
            let page = GeneratePage(pg.key, pageContent, data)
            let foundRef = false
            for (const key of Object.keys(links)) {
                if (!page.page) continue;
                if (page.page.includes(key)) {
                    if (!foundRef) {
                        foundRef = true
                        page.page += `\n\n## References`
                    }
                    page.page += `\n- [${key}](/${links[key].category.split(".").join("/")}/${links[key].pageKey.split(".").join("/")})`
                }
            }
            pages[currentCategory][`${subcategory}${pg.key}`] = page
        }
    }

    writeFileSync(currentCategory + ".json", JSON.stringify(pages[currentCategory], null, 4))
}