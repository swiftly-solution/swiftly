# Getting Started - Plugin Manifest

The `manifest.json` file defines essential metadata and configuration for SwiftlyS2 plugins. It resides in the plugin's root directory and is executed in a separate runtime from the plugin's Lua/JS/CS scripts.

---

## File Location

```
/plugins/your-plugin-name/manifest.json
```

---

## Example `manifest.json`

```json
{
  "name": "Tags",
  "description": "Tags plugin",
  "version": "v1.0.0",
  "website": "",
  "author": "Swiftly Solution",
  "kind": "lua",
  "files": [
    "**/*.lua"
  ],
  "dependencies": {
    "plugins": ["cookies"],
    "extensions": [],
    "runtime": ["/version:1.4.0"]
  },
  "games": [],
  "$schema": "https://cdn.swiftlys2.net/plugins/manifest.json"
}
```

---

## Field Reference

| Field         | Type     | Required | Description |
|---------------|----------|----------|-------------|
| `name`        | string   | ✅       | Plugin name. |
| `description` | string   | ✅       | Short description of the plugin. |
| `version`     | string   | ✅       | Plugin version (e.g., `v1.0.0`). |
| `website`     | string   | ✅       | URL for documentation or homepage (can be empty). |
| `author`      | string   | ✅       | Plugin author or organization. |
| `kind`        | string   | ✅       | Language of the plugin. Supported values: `lua`, `js`, `cs`. |
| `files`       | array    | ✅       | List of file globs to include (e.g., `**/*.lua`). |
| `dependencies`| object   | ✅       | Plugin, extension, and runtime dependencies. |
| `games`       | array    | ✅       | List of supported games (e.g., `["cs2"]`). |
| `$schema`     | string   | ❌       | JSON schema URL for validation (optional). |

---

### `dependencies` Object

| Field         | Type     | Required | Description |
|---------------|----------|----------|-------------|
| `plugins`     | array    | ✅       | Names of other plugins this one depends on. |
| `extensions`  | array    | ✅       | Required extensions (can be empty). |
| `runtime`     | array    | ✅       | Runtime requirements (e.g., specific versions). |



#### `runtime` Array
| Field         | Type     | Format     | Description |
|---------------|----------|------------|-------------|
| `/version`    | string   | x.x.x      |Specifies the minimum required version of the SwiftlyCS2 runtime that must be present for the plugin to function correctly. |

> [!note]
> 💡 **Tip:** Use `/version:x.x.x` to avoid loading plugins on outdated SwiftlyS2 runtime versions, which could lead to compatibility issues.
---

### `games` Field

Only required if the plugin targets specific games.

> [!note]
> 💡 **Tip:** You can set `"games": []` to indicate that the plugin is compatible with all games, rather than targeting specific ones.

| Value | Description          |
|-------|----------------------|
| `cs2` | Counter-Strike 2     |

---

## Schema Reference

The manifest follows a [JSON Schema](http://json-schema.org/draft-04/schema#), and you can include it via:

```json
"$schema": "https://cdn.swiftlys2.net/plugins/manifest.json"
```

---

## Required Fields Summary

| Field        | Required |
|--------------|----------|
| name         | ✅        |
| description  | ✅        |
| version      | ✅        |
| author       | ✅        |
| website      | ✅        |
| kind         | ✅        |
| files        | ✅        |
| dependencies | ✅        |
| games        | ✅        |

---
> [!note]
> 💡 **Tip:** Always validate your `manifest.json` against the schema to avoid runtime issues.
