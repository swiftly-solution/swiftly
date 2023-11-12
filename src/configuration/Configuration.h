#ifndef _configuration_h
#define _configuration_h

#include <string>
#include <map>
#include <any>

class Configuration
{
private:
    std::map<std::string, std::any> config;
    bool loaded = false;

public:
    bool LoadConfiguration();
    inline bool IsConfigurationLoaded() { return this->loaded; };

    void LoadPluginConfigurations();

    std::map<std::string, std::any> FetchConfiguration() { return this->config; }

    template <typename T>
    T FetchValue(std::string key);

    template <typename T>
    void SetValue(std::string key, T value);
};

extern Configuration *g_Config;

template <typename T>
T Configuration::FetchValue(std::string key)
{
    if (this->config.find(key) == this->config.end())
        return nullptr;

    return std::any_cast<T>(this->config.at(key));
}

#endif