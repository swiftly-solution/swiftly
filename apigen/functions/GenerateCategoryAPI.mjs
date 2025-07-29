import { readFileSync } from "fs"
import DeterminePageCategory from "./DeterminePageCategory.mjs"
import GenerateTypeContent from "./GenerateTypeContent.mjs"
import GenerateFunctionContent from "./GenerateFunctionContent.mjs"
import GenerateClassContent from "./GenerateClassContent.mjs"

let createdClasses = {}
let oldCategory = ""

export default function GenerateCategoryAPI(metadata, category, apiCategories) {
    const currentPages = metadata[category.key]
    if (oldCategory == "") oldCategory = category.key
    else if (oldCategory != category.key) {
        oldCategory = category.key
        createdClasses = {}
    }

    for (const page of currentPages) {
        const pageContent = JSON.parse(readFileSync(page.page))

        const determinePageCategory = DeterminePageCategory(page, apiCategories)
        if (!createdClasses.hasOwnProperty(determinePageCategory)) createdClasses[determinePageCategory] = []

        if (pageContent.kind == 'function') {
            createdClasses[determinePageCategory].push(GenerateFunctionContent(pageContent, determinePageCategory));
        }
        else if (pageContent.kind == "class") {
            createdClasses[determinePageCategory].push(GenerateClassContent(pageContent, determinePageCategory));
        }
        else if (pageContent.kind == "event") {
            // Not Required for C# implementation
        }
        else if (pageContent.kind == "type") {
            createdClasses[determinePageCategory].push(GenerateTypeContent(pageContent));
        }
    }

    for (const key of Object.keys(createdClasses)) {
        if (key == "Types") continue;
        if (!createdClasses[key].length) continue;

        createdClasses[key] = createdClasses[key].filter((v) => v.length > 0).map(v => v.split("\n").map(k => `    ${k}`).join("\n"))
        createdClasses[key].push("}")
        if (!category.writePath.includes("SDK")) {
            createdClasses[key].unshift('    }')
            createdClasses[key].unshift(`        _ctx = Invoker.CallNative<IntPtr>("${key}", "${key}", CallKind.ClassFunction);`)
            createdClasses[key].unshift('        if (_ctx != IntPtr.Zero) return;')
            createdClasses[key].unshift('    {')
            createdClasses[key].unshift('    private static void InitializeContext()')
            createdClasses[key].unshift(`    private static IntPtr _ctx = IntPtr.Zero;\n`);
        }
        createdClasses[key].unshift(`public class ${key}\n{`)
    }

    return createdClasses
}