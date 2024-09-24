#include "Translations.h"

#include "../../common.h"
#include "../configuration/Configuration.h"

#include "../../filesystem/files/Files.h"
#include "../../player/playermanager/PlayerManager.h"

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

#define HAS_MEMBER(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                     \
    if (!DOCUMENT.HasMember(MEMBER_NAME))                                                  \
    {                                                                                      \
        TranslationsError(string_format("The field \"%s\" doesn't exists.", MEMBER_PATH)); \
        continue;                                                                          \
    }

#define IS_STRING(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                       \
    if (!DOCUMENT[MEMBER_NAME].IsString())                                                  \
    {                                                                                       \
        TranslationsError(string_format("The field \"%s\" is not a string.", MEMBER_PATH)); \
        continue;                                                                           \
    }

#define IS_OBJECT(DOCUMENT, MEMBER_NAME, MEMBER_PATH)                                        \
    if (!DOCUMENT[MEMBER_NAME].IsObject())                                                   \
    {                                                                                        \
        TranslationsError(string_format("The field \"%s\" is not an object.", MEMBER_PATH)); \
        continue;                                                                            \
    }

void TranslationsError(std::string text)
{
    if (!g_SMAPI)
        return;

    PLUGIN_PRINTF("Translations", "%s\n", text.c_str());
}

void Translations::LoadTranslations()
{
    for (auto it = this->m_translations.begin(); it != this->m_translations.end(); ++it)
        delete it->second;

    this->m_translations.clear();

    if (!Files::ExistsPath("addons/swiftly/translations"))
        Files::CreateDirectory("addons/swiftly/translations");

    std::vector<std::string> translationFiles = Files::FetchFileNames("addons/swiftly/translations");

    for (const std::string &translationFilePath : translationFiles)
    {
        if (!ends_with(translationFilePath, ".json"))
            continue;
        if (!starts_with(translationFilePath, string_format("addons/swiftly/translations%stranslation.", WIN_LINUX("\\", "/"))))
            continue;

        std::string translationFileName = explode(translationFilePath, string_format("addons/swiftly/translations%s", WIN_LINUX("\\", "/")))[1];
        std::string mainTranslationKey = explode(explode(translationFileName, ".json")[0], "translation.")[1];

        rapidjson::Document transFile;
        transFile.Parse(Files::Read(translationFilePath).c_str());
        if (transFile.HasParseError())
        {
            TranslationsError(string_format("A parsing error has been detected for translation file \"%s\".\nError (offset %u): %s\n", translationFileName.c_str(), (unsigned)transFile.GetErrorOffset(), GetParseError_En(transFile.GetParseError())));
            continue;
        }
        if (transFile.IsArray())
        {
            TranslationsError(string_format("Translation file \"%s\" cannot be an array.", translationFileName.c_str()));
            continue;
        }

        for (auto it = transFile.MemberBegin(); it != transFile.MemberEnd(); ++it)
        {
            std::string key = it->name.GetString();

            IS_OBJECT(transFile, key.c_str(), string_format("%s.%s", mainTranslationKey.c_str(), key.c_str()).c_str())
            HAS_MEMBER(it->value, "en", string_format("%s.%s.en", mainTranslationKey.c_str(), key.c_str()).c_str())

            Translation *translation = new Translation();
            for (auto it2 = it->value.MemberBegin(); it2 != it->value.MemberEnd(); ++it2)
            {
                std::string transKey = it2->name.GetString();

                IS_STRING(it->value, transKey.c_str(), string_format("%s.%s.%s", mainTranslationKey.c_str(), key.c_str(), transKey.c_str()).c_str())

                std::string transVal = it2->value.GetString();
                translation->RegisterLanguage(transKey, transVal);
            }
            this->m_translations.insert(std::make_pair(mainTranslationKey + "." + key, translation));
        }
    }
}

std::string Translations::FetchTranslation(std::string key, int playerid)
{
    Player* player = g_playerManager->GetPlayer(playerid);
    if(player && g_Config->FetchValue<bool>("core.use_player_language")) {
        std::string language = player->language;
        if (this->m_translations.find(key) == this->m_translations.end())
            return key + "." + language;

        std::string translation = this->m_translations[key]->FetchLanguage(language);
        if (translation == "NO_TRANSLATION") {
            translation = this->m_translations[key]->FetchLanguage(g_Config->FetchValue<std::string>("core.language"));
            if(translation == "NO_TRANSLATION")
                return key + "." + language;
            else
                return translation;
        }
        else
            return translation;
    } else {
        std::string language = g_Config->FetchValue<std::string>("core.language");    

        if (this->m_translations.find(key) == this->m_translations.end())
            return key + "." + language;

        std::string translation = this->m_translations[key]->FetchLanguage(language);
        if (translation == "NO_TRANSLATION")
            return key + "." + language;
        else
            return translation;
    }
}