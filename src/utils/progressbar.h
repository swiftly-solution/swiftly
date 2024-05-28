#ifndef _utils_progressbar_h
#define _utils_progressbar_h

#include "utils.h"
#include <stdint.h>
#include <string>

class ProgressBar
{
private:
    size_t progress;
    std::string barPrefix;

public:
    ProgressBar() {}

    void SetProgress(size_t prog) { this->progress = prog; }
    void SetBarPrefix(std::string prefix) { this->barPrefix = prefix; }

    std::string GetContent(std::string sufix)
    {
        std::string output = this->barPrefix;
        output += "[";
        for (size_t i = 0; i < 50; i++)
            output += (i < (progress / 2) ? "■" : "-");
        output += "]";
        return string_format("%s %s", output.c_str(), sufix.c_str());
    };
};

#endif