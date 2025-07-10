#ifndef _server_configuration_configuration_h
#define _server_configuration_configuration_h

#include <string>
#include <map>
#include <any>

#include <rapidjson/json.hpp>

class Configuration
{
private:
    std::map<std::string, std::any> config;
    std::map<std::string, std::any> pluginConfig;
    std::map<std::string, unsigned int> configArraySizes;
    bool loaded = false;

public:
    bool LoadConfiguration();
    bool IsConfigurationLoaded();

    void LoadPluginConfigurations();

    std::map<std::string, std::any>& FetchPluginConfiguration();
    std::map<std::string, std::any>& FetchConfiguration();
    std::map<std::string, unsigned int>& FetchConfigArraySizes();

    void SetArraySize(std::string key, unsigned int size);

    template <typename T>
    T FetchValue(std::string key);

    template <typename T>
    void SetValue(std::string key, T value);

    template <typename T>
    void SetPluginValue(std::string key, T value);

    bool HasKey(std::string key);
    void LoadPluginConfig(std::string key);
    void ClearPluginConfig();
};

extern Configuration g_Config;

template <typename T>
T Configuration::FetchValue(std::string key)
{
    if (config.find(key) == config.end())
        return 0;

    try {
        return std::any_cast<T>(config[key]);
    }
    catch (std::bad_any_cast& e) {
        fprintf(stdout, "%s: %s\n", key.c_str(), e.what());
        return (T)0;
    }
}

#endif