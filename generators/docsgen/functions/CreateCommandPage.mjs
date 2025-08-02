import { readFileSync } from "fs";
import GenerateCommandFlags from "./GenerateCommandFlags.mjs";

export default function CreateCommandPage(pageKey, pageContent, category) {
    let page = readFileSync("templates/command.tpl").toString()

    page = page.replace("{title}", pageContent.name)
    page = page.replace("{command}", pageContent.name)
    page = page.replace("{description}", pageContent.description)
    page = page.replace("{arguments}", pageContent.args)
    page = page.replace("{flags}", GenerateCommandFlags(pageContent))

    return page
}