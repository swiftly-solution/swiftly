#ifndef _sdk_access_h
#define _sdk_access_h

#include <map>
#include <vector>
#include <string>
#include <set>

enum SDKFieldType_t : uint32_t
{
    Int8 = 0,
    Int16,
    Int32,
    Int64,
    UInt8,
    UInt16,
    UInt32,
    UInt64,
    Float,
    Double,
    Bool,
    Parent,
    StringToken,
    StringSymbolLarge,
    StringUtl,
    String,
    Class,
    SDKCHandle,
    EntityIndex,
    SColor,
    SQAngle,
    SVector,
    SVector2D,
    SVector4D,
    ClassPointer,
    RawListEntityIndex,

    StringSymbolLargeArray,
    StringTokenArray,
    StringUtlArray,
    Int8Array,
    Int16Array,
    Int32Array,
    Int64Array,
    UInt8Array,
    UInt16Array,
    UInt32Array,
    UInt64Array,
    FloatArray,
    DoubleArray,
    BoolArray,
    SColorArray,
    SQAngleArray,
    SVectorArray,
    SVector2DArray,
    SVector4DArray,
    ClassArray,
    CHandleArray,

    CHandleCUtlVector,
    StringSymbolLargeCUtlVector,
    StringTokenCUtlVector,
    StringUtlCUtlVector,
    Int8CUtlVector,
    Int16CUtlVector,
    Int32CUtlVector,
    Int64CUtlVector,
    UInt8CUtlVector,
    UInt16CUtlVector,
    UInt32CUtlVector,
    UInt64CUtlVector,
    FloatCUtlVector,
    DoubleCUtlVector,
    SColorCUtlVector,
    SQAngleCUtlVector,
    SVectorCUtlVector,
    SVector2DCUtlVector,
    SVector4DCUtlVector,
    BoolCUtlVector,
};

class SDKAccess {
private:
    std::map<uint64_t, std::string> fieldNames;
    std::map<uint64_t, SDKFieldType_t> fieldTypes;
    std::map<uint64_t, uint64_t> fieldSizes;
    std::map<uint64_t, std::string> fieldClass;
    std::map<std::string, std::map<std::string, int64_t>> sdktypes;
    std::set<std::string> classes;
    std::set<std::string> processedFieldNames;
    std::set<std::string> blockedFields;

public:
    void LoadSDKData();

    std::string& GetFieldName(uint64_t path);
    SDKFieldType_t GetFieldType(uint64_t path);
    std::string GetFieldClass(uint64_t path);
    uint32_t GetFieldSize(uint64_t path);
    std::set<std::string> GetProcessedFieldNames();
    std::set<std::string> GetClasses();
    std::map<std::string, std::map<std::string, int64_t>> GetSDKTypes();

    bool IsFieldBlocked(std::string field);
    bool ExistsField(uint64_t path);
};

extern SDKAccess g_sdk;

#endif