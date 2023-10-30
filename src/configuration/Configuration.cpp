#include "Configuration.h"
#include "../files/Files.h"

template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    int size_s = snprintf(nullptr, 0, format.c_str(), args...) + 1; // Extra space for '\0'
    if (size_s <= 0)
        throw std::runtime_error("Error during formatting.");

    size_t size = static_cast<size_t>(size_s);
    std::unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args...);
    return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

bool ConfigurationError(std::string configuration_file, std::string error)
{
    if (!g_SMAPI)
        return false;

    PRINTF("Configurations", "Error: %s: %s\n", configuration_file, error.c_str());
    return false;
}

bool Configuration::LoadConfiguration()
{
    return true;
}

bool Configuration::SaveConfiguration()
{
    return true;
}