#include "json.h"
#include <utils/common.h>
#include <utils/utils.h>

std::map<rapidjson::ParseErrorCode, const char*> errorCodes = {
    { rapidjson::ParseErrorCode::kParseErrorNone                           , "No error."},
    { rapidjson::ParseErrorCode::kParseErrorDocumentEmpty                  , "The document is empty."},
    { rapidjson::ParseErrorCode::kParseErrorDocumentRootNotSingular        , "The document root must not be followed by other values."},
    { rapidjson::ParseErrorCode::kParseErrorValueInvalid                   , "Invalid value."},
    { rapidjson::ParseErrorCode::kParseErrorObjectMissName                 , "Missing a name for object member."},
    { rapidjson::ParseErrorCode::kParseErrorObjectMissColon                , "Missing a colon after a name of object member."},
    { rapidjson::ParseErrorCode::kParseErrorObjectMissCommaOrCurlyBracket  , "Missing a comma or '}' after an object member."},
    { rapidjson::ParseErrorCode::kParseErrorArrayMissCommaOrSquareBracket  , "Missing a comma or ']' after an array element."},
    { rapidjson::ParseErrorCode::kParseErrorStringUnicodeEscapeInvalidHex  , "Incorrect hex digit after \\u escape in string."},
    { rapidjson::ParseErrorCode::kParseErrorStringUnicodeSurrogateInvalid  , "The surrogate pair in string is invalid."},
    { rapidjson::ParseErrorCode::kParseErrorStringEscapeInvalid            , "Invalid escape character in string."},
    { rapidjson::ParseErrorCode::kParseErrorStringMissQuotationMark        , "Missing a closing quotation mark in string."},
    { rapidjson::ParseErrorCode::kParseErrorStringInvalidEncoding          , "Invalid encoding in string."},
    { rapidjson::ParseErrorCode::kParseErrorNumberTooBig                   , "Number too big to be stored in double."},
    { rapidjson::ParseErrorCode::kParseErrorNumberMissFraction             , "Miss fraction part in number."},
    { rapidjson::ParseErrorCode::kParseErrorNumberMissExponent             , "Miss exponent in number."},
    { rapidjson::ParseErrorCode::kParseErrorTermination                    , "Terminate parsing due to Handler error."},
    { rapidjson::ParseErrorCode::kParseErrorUnspecificSyntaxError          , "Unspecific syntax error."}
};

const char* GetParseError_En(rapidjson::ParseErrorCode parseErrorCode) {
    if (errorCodes.find(parseErrorCode) != errorCodes.end()) return errorCodes[parseErrorCode];
    else return "Unknown error.";
}

std::string encoders::json::ToString(rapidjson::Value& j)
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    j.Accept(writer);
    return buffer.GetString();
}

rapidjson::Document encoders::json::FromString(std::string str, std::string path)
{
    rapidjson::Document doc;
    rapidjson::ParseResult parseResult = doc.Parse(str.c_str());
    if (!parseResult) {
        PLUGIN_PRINTF("json::FromString", string_format("An error has occured while trying to parse %s:\nError: %s.", path == "" ? "json string" : path.c_str(), GetParseError_En(parseResult.Code())));
        doc.SetObject();
    }
    return doc;
}