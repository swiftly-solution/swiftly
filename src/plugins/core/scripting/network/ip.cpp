#include "../../scripting.h"
#include "../../../../server/configuration/Configuration.h"
#include <GeoLite2PP.hpp>

GeoLite2PP::DB *maxminddbCity = nullptr;
GeoLite2PP::DB *maxminddbASN = nullptr;

PluginIPAPI::PluginIPAPI(std::string m_plugin_name)
{
    this->plugin_name = m_plugin_name;
    if(!maxminddbCity) maxminddbCity = new GeoLite2PP::DB("addons/swiftly/data/GeoLite2-City.mmdb");
    if(!maxminddbASN) maxminddbASN = new GeoLite2PP::DB("addons/swiftly/data/GeoLite2-ASN.mmdb");
}

std::string PluginIPAPI::GetIsoCode(std::string ip)
{
    auto m = maxminddbCity->get_all_fields(ip);
    return m["country_iso_code"];
}

std::string PluginIPAPI::GetContinent(std::string ip)
{
    auto m = maxminddbCity->get_all_fields(ip);
    return m["continent"];
}

std::string PluginIPAPI::GetCountry(std::string ip)
{
    auto m = maxminddbCity->get_all_fields(ip);
    return m["country"];
}

std::string PluginIPAPI::GetRegion(std::string ip)
{
    auto m = maxminddbCity->get_all_fields(ip);
    return m["subdivision"];
}

std::string PluginIPAPI::GetCity(std::string ip)
{
    auto m = maxminddbCity->get_all_fields(ip);
    return m["city"];
}

std::string PluginIPAPI::GetTimezone(std::string ip)
{
    auto m = maxminddbCity->get_all_fields(ip);
    return m["time_zone"];
}

double PluginIPAPI::GetLatitude(std::string ip)
{
    auto m = maxminddbCity->get_all_fields(ip);
    return V_StringToFloat32(m["latitude"].c_str(), 0.0f);
}

double PluginIPAPI::GetLongitude(std::string ip)
{
    auto m = maxminddbCity->get_all_fields(ip);
    return V_StringToFloat32(m["longitude"].c_str(), 0.0f);
}

std::string PluginIPAPI::GetASN(std::string ip)
{
    auto lookupRes = maxminddbASN->get_field(ip, "en", GeoLite2PP::VCStr{"autonomous_system_number", nullptr});
    return lookupRes;
}