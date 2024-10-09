#ifndef _http_servermanager_h
#define _http_servermanager_h

#include <map>
#include <vector>
#include <string>
#include <any>
#include <httplib.h>

class HTTPServerManager
{
private:
    void SetupHTTPServer(std::string ip_addr, uint16_t port);
public:
    std::map<std::pair<std::string, uint16_t>, std::vector<std::pair<void*, std::vector<std::any>>>> httpListeners;
    std::map<std::pair<std::string, uint16_t>, httplib::Server*> httpServers;
    
    ~HTTPServerManager();

    void RegisterHTTPServerListener(std::string ip_addr, uint16_t port, void* callback, std::vector<std::any> additional);
    void UnregisterHTTPServerListener(std::string ip_addr, uint16_t port, void* callback);
};
extern HTTPServerManager* g_httpServerManager;

#endif