#ifndef _contenttypes_h
#define _contenttypes_h

#include <map>
#include <string>

enum ContentType
{
    APPLICATION_JSON = 1,
    APPLICATION_FORM_URLENCODE = 2,
    MULTIPART_FORMDATA = 3,
    TEXT_CSS = 4,
    TEXT_CSV = 5,
    TEXT_HTML = 6,
    TEXT_JAVASCRIPT = 7,
    TEXT_PLAIN = 8,
    TEXT_XML = 9,
};

static std::map<int, std::string> contentTypesMap = {
    {APPLICATION_JSON, "application/json"},
    {APPLICATION_FORM_URLENCODE, "application/x-www-form-urlencoded"},
    {MULTIPART_FORMDATA, "multipart/form-data"},
    {TEXT_CSS, "text/css"},
    {TEXT_CSV, "text/csv"},
    {TEXT_HTML, "text/html"},
    {TEXT_JAVASCRIPT, "text/javascript"},
    {TEXT_PLAIN, "text/plain"},
    {TEXT_XML, "text/xml"},
};

#endif