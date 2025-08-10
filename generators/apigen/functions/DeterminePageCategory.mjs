import { readFileSync } from "fs";

export default function DeterminePageCategory(page, categories) {
    const pageKey = page.path.split("/").join(".")
    const categoryLocation = pageKey.split(".").slice(0, -1).join(".")
    const pageContent = JSON.parse(readFileSync(page.page))

    if (!categories[categoryLocation]) return "Generic";
    else if (pageContent.override_variable) return "Generic"
    else return categories[categoryLocation].title.split(" ").join("")
}