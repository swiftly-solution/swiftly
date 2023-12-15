#include "HTTPRequest.h"

HTTPRequest::HTTPRequest(std::string url)
{
    this->client = new httplib::Client(url);
    this->client->set_default_headers({{"Accept-Encoding", "gzip, deflate"}});
}

HTTPRequest::~HTTPRequest()
{
    this->multipartItems.clear();
    this->params.clear();
    this->headers.clear();

    this->body.clear();
    delete this->client;
}

void HTTPRequest::Get(std::string path)
{
    this->executed = true;
    this->result = this->client->Get(path, this->params, this->headers);
}

void HTTPRequest::Delete(std::string path)
{
    this->executed = true;
    this->result = this->client->Delete(path, this->headers);
}

void HTTPRequest::Post(std::string path)
{
    this->executed = true;
    std::string final_content_type = contentTypesMap.at(this->content_type);
    if (this->content_type == ContentType::MULTIPART_FORMDATA)
        this->result = this->client->Post(path, this->headers, this->multipartItems);
    else
        this->result = this->client->Post(path, this->headers, this->body, final_content_type);
}

void HTTPRequest::Put(std::string path)
{
    this->executed = true;
    std::string final_content_type = contentTypesMap.at(this->content_type);
    if (this->content_type == ContentType::MULTIPART_FORMDATA)
        this->result = this->client->Put(path, this->headers, this->multipartItems);
    else
        this->result = this->client->Put(path, this->headers, this->body, final_content_type);
}

void HTTPRequest::Patch(std::string path)
{
    this->executed = true;
    std::string final_content_type = contentTypesMap.at(this->content_type);
    this->result = this->client->Patch(path, this->headers, this->body, final_content_type);
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
    httplib::MultipartFormData data{field, content, filename, file_content_type};

    this->multipartItems.push_back(data);
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
    this->client->set_basic_auth(username, password);
}

void HTTPRequest::SetBearerAuthenticationToken(std::string token)
{
    this->client->set_bearer_token_auth(token);
}

void HTTPRequest::SetFollowRedirect(bool follow)
{
    this->client->set_follow_location(follow);
}

std::string HTTPRequest::GetBody()
{
    if (!this->executed)
        return "";

    return this->result->body;
}

int HTTPRequest::GetStatusCode()
{
    if (!this->executed)
        return 0;

    return this->result->status;
}

std::string HTTPRequest::GetError()
{
    if (!this->result)
        return "";

    return httplib::to_string(this->result.error());
}