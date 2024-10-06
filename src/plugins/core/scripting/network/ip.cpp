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
    try {
        auto m = maxminddbCity->get_all_fields(ip);
        return m["country_iso_code"];
    } catch(std::exception& e) {
        return "";
    }
}

std::string PluginIPAPI::GetContinent(std::string ip)
{
    try {
        auto m = maxminddbCity->get_all_fields(ip);
        return m["continent"];
    } catch(std::exception& e) {
        return "";
    }
}

std::string PluginIPAPI::GetCountry(std::string ip)
{
    try {
        auto m = maxminddbCity->get_all_fields(ip);
        return m["country"];
    } catch(std::exception& e) {
        return "";
    }
}

std::string PluginIPAPI::GetRegion(std::string ip)
{
    try {
        auto m = maxminddbCity->get_all_fields(ip);
        return m["subdivision"];
    } catch(std::exception& e) {
        return "";
    }
}

std::string PluginIPAPI::GetCity(std::string ip)
{
    try {
        auto m = maxminddbCity->get_all_fields(ip);
        return m["city"];
    } catch(std::exception& e) {
        return "";
    }
}

std::string PluginIPAPI::GetTimezone(std::string ip)
{
    try {
        auto m = maxminddbCity->get_all_fields(ip);
        return m["time_zone"];
    } catch(std::exception& e) {
        return "";
    }
}

double PluginIPAPI::GetLatitude(std::string ip)
{
    try {
        auto m = maxminddbCity->get_all_fields(ip);
        return V_StringToFloat32(m["latitude"].c_str(), 0.0f);
    } catch(std::exception& e) {
        return 0.0f;
    }
}

double PluginIPAPI::GetLongitude(std::string ip)
{
    try {
        auto m = maxminddbCity->get_all_fields(ip);
        return V_StringToFloat32(m["longitude"].c_str(), 0.0f);
    } catch(std::exception& e) {
        return 0.0f;
    }
}

std::string PluginIPAPI::GetASN(std::string ip)
{
    try {
        auto lookupRes = maxminddbASN->get_field(ip, "en", GeoLite2PP::VCStr{"autonomous_system_number", nullptr});
        return lookupRes;
    } catch(std::exception& e) {
        return "";
    }
}