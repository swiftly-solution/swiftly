<br/>
<p align="center">
    <img src="https://sttci.b-cdn.net/status.swiftlycs2.net/2105/logo.png" alt="Swiftly Private Message Logo" width="600" height="131">
</p>

## New Version: SwiftlyS2

SwiftlyS2 is a powerful scripting framework for Source 2 games, built in C++ with C# plugin support. It provides developers with a comprehensive API to create plugins for Source 2-based games like Counter-Strike 2.

The new version of the framework is available at https://swiftlys2.net.

## Status

As originally announced, the project entered maintenance-only mode on **October 10, 2025**, with the intention of giving server owners and developers time to migrate to the next generation framework.

Swiftly Lua officially reaches **End-of-Life on April 10, 2026**.

No further development, features, or fixes will be provided.

This repository will remain public as a historical reference for the work that has been done.

## Personal Note

This project wasn't built overnight.

For **two years**, Swiftly was developed almost **every single day**.  
Days and nights were spent staring at the screen, rewriting systems, debugging crashes, and sometimes just sitting there wondering if the framework would ever become what it was supposed to be.

There were many moments where it felt impossible.

Many late nights where the only thing on my mind was **one more bug**, **one more feature**, **one more rewrite that might finally make everything click**.

And slowly, over time, it did.

Swiftly Lua started as a simple **experiment** to improve the ecosystem of Counter-Strike 2 server development using **Lua**, a dynamic scripting language. The goal was to give server developers something powerful but easy to extend.

What started as a small experiment slowly turned into a **full framework** used by developers building plugins and extensions for Source 2 servers.

And that was something I never expected when writing the first lines of code.

If you used Swiftly Lua, contributed to it, built plugins for it, reported bugs, suggested features, or even just tried it once — **thank you**.

Discontinuing this project was a very difficult decision. Not only because of the time invested in it, but because **other people invested their time in it too**. People built plugins, servers, ideas, and communities around it.

And that meant a lot.

## Why Swiftly Lua Is Ending

Over time, the limitations of the original design started to appear.

Lua, while flexible and easy to use, proved to be **not the best choice for a modern Source 2 server framework**. It lacks strong type safety and doesn't provide a native asynchronous environment that allows operations to run safely across threads.

These limitations became especially clear when trying to implement features like:

- HTTP requests  
- multi-threaded game hooks  
- more advanced server integrations  

The architecture started fighting the future instead of enabling it.

We explored alternatives.

At one point we experimented with **JavaScript**. It's a language many developers already know and use daily. Unfortunately the engine used to embed it (**QuickJS**) was too slow for the needs of the framework, and embedding **V8** turned out to be an extremely complex task for a project mostly maintained by a single developer.

Later, when a new developer joined the team, we began exploring **C#**.

And everything suddenly made sense.

C# provided:

- a modern type-safe environment  
- strong tooling  
- excellent performance through .NET  
- asynchronous programming built into the language  

Today, it works **beautifully** in SwiftlyS2.

## Thank You

To everyone who believed in the project.

To everyone who ran it on their servers.  
To everyone who wrote plugins for it.  
To everyone who opened issues, suggested improvements, or reported bugs.

Thank you.

Swiftly Lua may be ending, but what it helped create will continue to evolve.

And that's what open source is really about.

## Memorial Page

You can check the memorial of the Swiftly Lua version here: [https://swiftlys2.net/memorial](https://swiftlys2.net/memorial)