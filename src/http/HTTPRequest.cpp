#include "HTTPRequest.h"
#include "curl/base64.h"

HTTPRequest::HTTPRequest(std::string url)
{
    this->req = new CurlRequest();
    this->req->SetUserAgent("Swiftly/HTTPManager");
    this->req->SetTimeout(30);
    this->url = url;
}

HTTPRequest::~HTTPRequest()
{
    this->headers.clear();

    this->body.clear();
    delete this->req;
}

void HTTPRequest::Get(std::string path)
{
    this->req->SetUrl(this->url + path);
    this->req->SetHeaders(this->headers);
    this->req->Get();
    this->executed = true;
}

void HTTPRequest::Delete(std::string path)
{
    this->req->SetUrl(this->url + path);
    this->req->SetHeaders(this->headers);
    this->req->Delete();
    this->executed = true;
}

void HTTPRequest::Post(std::string path)
{
    std::string final_content_type = contentTypesMap.at(this->content_type);
    this->req->SetUrl(this->url + path);
    this->req->SetHeaders(this->headers);
    this->req->Post(this->body);
    this->executed = true;
}

void HTTPRequest::Put(std::string path)
{
    std::string final_content_type = contentTypesMap.at(this->content_type);
    this->req->SetUrl(this->url + path);
    this->req->SetHeaders(this->headers);
    this->req->Put(this->body);
    this->executed = true;
}

void HTTPRequest::Patch(std::string path)
{
    std::string final_content_type = contentTypesMap.at(this->content_type);
    this->req->SetUrl(this->url + path);
    this->req->SetHeaders(this->headers);
    this->req->Patch(this->body);
    this->executed = true;
}

void HTTPRequest::AddHeader(std::string key, std::string value)
{
    if (this->headers.find(key) == this->headers.end())
        this->headers.insert(std::make_pair(key, value));
}

void HTTPRequest::DeleteHeader(std::string key)
{
    if (this->headers.find(key) != this->headers.end())
        this->headers.erase(key);
}

void HTTPRequest::AddMultipartFile(std::string field, std::string content, std::string filename, std::string file_content_type)
{
    // TODO: AddMultipartFile
}

void HTTPRequest::SetContentType(ContentType content_type)
{
    this->content_type = content_type;
}

void HTTPRequest::SetBody(std::string body)
{
    this->body = body;
}

void HTTPRequest::SetBasicAuthentication(std::string username, std::string password)
{
    this->headers.insert({"Authorization", "Basic " + base64::to_base64(username + ":" + password)});
}

void HTTPRequest::SetBearerAuthenticationToken(std::string token)
{
    this->headers.insert({"Authorization", "Bearer " + token});
}

void HTTPRequest::SetFollowRedirect(bool follow)
{
    this->req->SetFollowLocation(follow);
}

std::string HTTPRequest::GetBody()
{
    if (!this->executed || !this->req)
        return "";

    return this->req->GetResponseBody();
}

int HTTPRequest::GetStatusCode()
{
    if (!this->executed || !this->req)
        return 0;

    return this->req->GetStatusCode();
}

std::string HTTPRequest::GetError()
{
    if (!this->req)
        return "";

    return this->req->GetError();
}