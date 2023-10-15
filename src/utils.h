#define PREFIX "[Swiftly]"

#define PRINT(CATEGORY, FORMAT_STR) g_SMAPI->ConPrint(std::string(PREFIX).append(" [").append(CATEGORY).append("] ").append(FORMAT_STR).c_str())
#define PRINTF(CATEGORY, FORMAT_STR, ...) g_SMAPI->ConPrintf(std::string(PREFIX).append(" [").append(CATEGORY).append("] ").append(FORMAT_STR).c_str(), __VA_ARGS__)
#define CLIENT_PRINT(SLOT, CATEGORY, FORMAT_STR) g_SMAPI->ClientConPrint(SLOT, std::string(PREFIX).append(" [").append(CATEGORY).append("] ").append(FORMAT_STR).c_str())
#define CLIENT_PRINTF(SLOT, CATEGORY, FORMAT_STR, ...) g_SMAPI->ClientConPrintf(SLOT, std::string(PREFIX).append(" [").append(CATEGORY).append("] ").append(FORMAT_STR).c_str(), __VA_ARGS__)
