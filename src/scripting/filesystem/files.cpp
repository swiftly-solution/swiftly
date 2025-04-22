#include <scripting/core.h>
#include <filesystem/files/files.h>

LoadScriptingComponent(files, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Files");

    ADD_CLASS_FUNCTION("Files", "Files", [](FunctionContext* context, ClassData* data) -> void {});

    ADD_CLASS_FUNCTION("Files", "Append", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;
        std::string content = context->GetArgumentOr<std::string>(1, "");
        bool hasdate = context->GetArgumentOr<bool>(2, false);

        Files::Append(path, content, hasdate);
    });

    ADD_CLASS_FUNCTION("Files", "Write", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;
        std::string content = context->GetArgumentOr<std::string>(1, "");
        bool hasdate = context->GetArgumentOr<bool>(2, false);
        
        Files::Write(path, content, hasdate);
    });

    ADD_CLASS_FUNCTION("Files", "Read", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;

        context->SetReturn(Files::Read(path));
    });

    ADD_CLASS_FUNCTION("Files", "Delete", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;

        Files::Delete(path);
    });

    ADD_CLASS_FUNCTION("Files", "GetBase", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;

        context->SetReturn(Files::getBase(path));
    });

    ADD_CLASS_FUNCTION("Files", "ExistsPath", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;

        context->SetReturn(Files::ExistsPath(path));
    });

    ADD_CLASS_FUNCTION("Files", "IsDirectory", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;

        context->SetReturn(Files::IsDirectory(path));
    });

    ADD_CLASS_FUNCTION("Files", "FetchFileNames", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;

        context->SetReturn(Files::FetchFileNames(path));
    });

    ADD_CLASS_FUNCTION("Files", "FetchDirectories", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;

        context->SetReturn(Files::FetchDirectories(path));
    });

    ADD_CLASS_FUNCTION("Files", "CreateDirectory", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;

        context->SetReturn(Files::CreateDirectory(path));
    });

    ADD_CLASS_FUNCTION("Files", "Compress", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;

        std::string output = context->GetArgumentOr<std::string>(1, "");
        if(output == "") return;

        context->SetReturn(Files::Compress(path, output));
    });

    ADD_CLASS_FUNCTION("Files", "Decompress", [](FunctionContext* context, ClassData* data) -> void {
        std::string path = context->GetArgumentOr<std::string>(0, "");
        if(path == "") return;

        std::string output = context->GetArgumentOr<std::string>(1, "");
        if(output == "") return;

        context->SetReturn(Files::Decompress(path, output));
    });
})