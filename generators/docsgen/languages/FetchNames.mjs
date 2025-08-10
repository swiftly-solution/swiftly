import { readFileSync } from "fs";

export default function FetchNames() {
    return JSON.parse(readFileSync("languages/names.json"))
}