import { existsSync, mkdirSync, readdirSync, readFileSync, rmdirSync, statSync, writeFileSync } from "fs";
import GenerateCategoryAPI from "./functions/GenerateCategoryAPI.mjs";

let cats = [
    {
        key: "plugin-docs",
        value: "../documentation/docs",
        writePath: "build/cs/Scripting"
    },
    {
        key: "sdk/cs2",
        value: "../sdkdocumentation/docs",
        writePath: "build/cs/SDK/CS2"
    }
]
export let currentPath = ""

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

let apiCategories = {}
let metadata = {}
for (const ent of cats) {
    const categories = readdirSync(ent.value)
    metadata[ent.key] = []

    for (const category of categories) {
        const pages = GetFiles(`${ent.value}/${category}`)

        for (const page of pages) {
            let pageKey = page.replace(ent.value + "/", "")
            let isCategory = pageKey.endsWith("_index.json")

            if (pageKey.endsWith("_index.json")) {
                pageKey = pageKey.replace("/_index.json", "").replace(new RegExp("\/", "g"), ".")
            } else {
                pageKey = pageKey.replace(".json", "").replace(new RegExp("\/", "g"), ".")
            }

            if (!isCategory) {
                metadata[ent.key].push({ page, path: pageKey.split(".").join("/") })
            } else {
                apiCategories[pageKey] = JSON.parse(readFileSync(page))
            }
        }
    }
}

for (const ent of cats) {
    currentPath = ent.value

    let files = GenerateCategoryAPI(metadata, ent, apiCategories)
    if (!existsSync(ent.writePath)) mkdirSync(ent.writePath, { recursive: true })

    const skipFirstTwo = ent.writePath.split("/").slice(2).join(".")

    for (const [path, content] of Object.entries(files)) {
        if (content.length == 0) continue;
        if (path == "JSON" || path == "Hooks") continue;

        writeFileSync(
            ent.writePath + "/" + path + ".cs",
            `namespace SwiftlyS2.API.${skipFirstTwo}
{
${content.map(v => v.split("\n").map((x) => `    ${x}`).join("\n")).join("\n")}
}`
        )
    }
}