#ifndef _sdkaccess_h
#define _sdkaccess_h

#include <map>
#include <vector>
#include <string>

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
    std::map<std::string, std::string> fieldNames;
    std::map<std::string, SDKFieldType_t> fieldTypes;
    std::map<std::string, uint64_t> fieldSizes;
    std::map<std::string, std::string> fieldClass;
    std::map<std::string, bool> structStates;
    std::vector<std::string> classnames;

public:
    SDKAccess();
    ~SDKAccess();

    void LoadSDKData();

    std::vector<std::string> GetClassnames();
    std::string GetFieldName(std::string path);
    SDKFieldType_t GetFieldType(std::string path);
    std::string GetFieldClass(std::string path);
    uint32_t GetFieldSize(std::string path);
    bool GetClassStructState(std::string className);

    bool ExistsField(std::string path);
};

extern SDKAccess* g_sdk;

#endif