import { readFileSync } from "fs";
import { currentPath } from "../index.mjs";

export default function GenerateStaticPage(pageKey, pageContent, category) {
    return readFileSync(currentPath.split("/").slice(0, -1).join("/") + "/static/" + pageKey.split(".").join("/") + ".md").toString()
}