#include <filesystem/files/files.h>

void HandleConfigExamples() {
    auto files = Files::FetchFileNames("addons/swiftly/configs");
    for(auto file : files) {
        const std::string config_name = replace(file, ".example", "");
        if(ends_with(file, ".example.json") && !Files::ExistsPath(config_name)) {
            Files::Write(config_name, Files::Read(file), false);
        }
    }
}