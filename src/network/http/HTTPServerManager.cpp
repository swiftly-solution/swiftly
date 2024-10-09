#include "HTTPServerManager.h"
#include "../../common.h"

HTTPServerManager::~HTTPServerManager()
{
    for(auto it = httpServers.begin(); it != httpServers.end(); ++it) {
        it->second->stop();
        delete it->second;
    }
}

typedef void (*HTTPCallback)(const httplib::Request&, httplib::Response&, std::vector<std::any>);

void SetupServer(HTTPServerManager* _this, std::string ip_addr, uint16_t port)
{
    std::pair<std::string, uint16_t> key{ip_addr, port};
    
    _this->httpServers[key]->set_pre_routing_handler([&](const httplib::Request& req, httplib::Response& res) {
        auto listeners = _this->httpListeners[key];
        for(auto listener : listeners)
            reinterpret_cast<HTTPCallback>(listener.first)(req, res, listener.second);

        return listeners.size() > 0 ? httplib::Server::HandlerResponse::Handled : httplib::Server::HandlerResponse::Unhandled;
    });

    _this->httpServers[key]->listen(ip_addr, port);
}

void HTTPServerManager::SetupHTTPServer(std::string ip_addr, uint16_t port)
{
    std::pair<std::string, uint16_t> key{ip_addr, port};
    if(httpServers.find(key) != httpServers.end()) {
        httpServers[key]->stop();
        delete httpServers[key];
    }

    this->httpServers[key] = new httplib::Server();
    std::thread(SetupServer, this, ip_addr, port).detach();
}

void HTTPServerManager::RegisterHTTPServerListener(std::string ip_addr, uint16_t port, void* callback, std::vector<std::any> additional)
{
    std::pair<std::string, uint16_t> key{ip_addr, port};
    if(httpServers.find(key) == httpServers.end()) SetupHTTPServer(ip_addr, port);

    httpListeners[key].push_back({ callback, additional });
}

void HTTPServerManager::UnregisterHTTPServerListener(std::string ip_addr, uint16_t port, void* callback)
{
    std::pair<std::string, uint16_t> key{ip_addr, port};
    if(httpServers.find(key) == httpServers.end()) SetupHTTPServer(ip_addr, port);

    for(auto it = httpListeners[key].begin(); it != httpListeners[key].end(); ++it)
        if(std::any_cast<void*>(it->second[0]) == callback) {
            httpListeners[key].erase(it);
            break;
        }

    if(httpListeners[key].size() == 0) {
        httpServers[key]->stop();
        delete httpServers[key];
        httpServers.erase(key);
    }
}