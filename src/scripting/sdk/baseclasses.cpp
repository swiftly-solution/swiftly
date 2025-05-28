#include <scripting/core.h>

#include <utils/utils.h>

LoadScriptingComponent(baseclasses, [](PluginObject plugin, EContext* ctx) -> void {
    ADD_CLASS("Vector");
    ADD_CLASS("Vector2D");
    ADD_CLASS("Vector4D");
    ADD_CLASS("QAngle");
    ADD_CLASS("Color");

    bool isLua = ctx->GetKind() == ContextKinds::Lua;

    ADD_CLASS_FUNCTION("Vector", "Vector", [](FunctionContext* context, ClassData* data) -> void {
        float x = context->GetArgumentOr<float>(0, 0.0f);
        float y = context->GetArgumentOr<float>(1, 0.0f);
        float z = context->GetArgumentOr<float>(2, 0.0f);
        data->SetData("vector_ptr", Vector(x, y, z));
    });

    ADD_CLASS_MEMBER("Vector", "x", [](FunctionContext* context, ClassData* data) -> void {
        Vector* vec = data->GetDataPtr<Vector>("vector_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->x);
    }, [](FunctionContext* context, ClassData* data) -> void {
        Vector* vec = data->GetDataPtr<Vector>("vector_ptr");
        if (!vec) return;
        vec->x = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_MEMBER("Vector", "y", [](FunctionContext* context, ClassData* data) -> void {
        Vector* vec = data->GetDataPtr<Vector>("vector_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->y);
    }, [](FunctionContext* context, ClassData* data) -> void {
        Vector* vec = data->GetDataPtr<Vector>("vector_ptr");
        if (!vec) return;
        vec->y = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_MEMBER("Vector", "z", [](FunctionContext* context, ClassData* data) -> void {
        Vector* vec = data->GetDataPtr<Vector>("vector_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->z);
    }, [](FunctionContext* context, ClassData* data) -> void {
        Vector* vec = data->GetDataPtr<Vector>("vector_ptr");
        if (!vec) return;
        vec->z = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_FUNCTION("Vector", "GetPtr", [](FunctionContext* context, ClassData* data) -> void {
        Vector* vec = data->GetDataPtr<Vector>("vector_ptr");
        context->SetReturn(string_format("%p", vec));
    });

    ADD_CLASS_FUNCTION("Vector", isLua ? "__len" : "length", [](FunctionContext* context, ClassData* data) -> void {
        Vector* vec = data->GetDataPtr<Vector>("vector_ptr");
        context->SetReturn(FastSqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
    });

    ADD_CLASS_FUNCTION("Vector", isLua ? "__eq" : "equal", [](FunctionContext* context, ClassData* data) -> void {
        Vector vec = data->GetData<Vector>("vector_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(false);
        if (!otherVecData->HasData("vector_ptr")) return context->SetReturn(false);

        Vector otherVec = otherVecData->GetData<Vector>("vector_ptr");

        context->SetReturn(vec == otherVec);
    });

    ADD_CLASS_FUNCTION("Vector", isLua ? "__tostring" : "toString", [](FunctionContext* context, ClassData* data) -> void {
        Vector* vec = data->GetDataPtr<Vector>("vector_ptr");
        context->SetReturn(string_format("Vector(%f,%f,%f)", vec->x, vec->y, vec->z));
    });

    ADD_CLASS_FUNCTION("Vector", isLua ? "__add" : "add", [](FunctionContext* context, ClassData* data) -> void {
        Vector vec = data->GetData<Vector>("vector_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("vector_ptr")) return context->SetReturn(data);

        Vector otherVec = otherVecData->GetData<Vector>("vector_ptr");

        data->SetData("vector_ptr", vec + otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector", isLua ? "__unm" : "unm", [](FunctionContext* context, ClassData* data) -> void {
        Vector vec = data->GetData<Vector>("vector_ptr");

        data->SetData("vector_ptr", -vec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector", isLua ? "__sub" : "sub", [](FunctionContext* context, ClassData* data) -> void {
        Vector vec = data->GetData<Vector>("vector_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("vector_ptr")) return context->SetReturn(data);

        Vector otherVec = otherVecData->GetData<Vector>("vector_ptr");

        data->SetData("vector_ptr", vec - otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector", isLua ? "__mul" : "mul", [](FunctionContext* context, ClassData* data) -> void {
        Vector vec = data->GetData<Vector>("vector_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("vector_ptr")) return context->SetReturn(data);

        Vector otherVec = otherVecData->GetData<Vector>("vector_ptr");

        data->SetData("vector_ptr", vec * otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector", isLua ? "__div" : "div", [](FunctionContext* context, ClassData* data) -> void {
        Vector vec = data->GetData<Vector>("vector_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("vector_ptr")) return context->SetReturn(data);

        Vector otherVec = otherVecData->GetData<Vector>("vector_ptr");

        data->SetData("vector_ptr", vec / otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector2D", "Vector2D", [](FunctionContext* context, ClassData* data) -> void {
        float x = context->GetArgumentOr<float>(0, 0.0f);
        float y = context->GetArgumentOr<float>(1, 0.0f);
        data->SetData("Vector2D_ptr", Vector2D(x, y));
    });

    ADD_CLASS_MEMBER("Vector2D", "x", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D* vec = data->GetDataPtr<Vector2D>("Vector2D_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->x);
    }, [](FunctionContext* context, ClassData* data) -> void {
        Vector2D* vec = data->GetDataPtr<Vector2D>("Vector2D_ptr");
        if (!vec) return;
        vec->x = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_MEMBER("Vector2D", "y", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D* vec = data->GetDataPtr<Vector2D>("Vector2D_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->y);
    }, [](FunctionContext* context, ClassData* data) -> void {
        Vector2D* vec = data->GetDataPtr<Vector2D>("Vector2D_ptr");
        if (!vec) return;
        vec->y = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_FUNCTION("Vector2D", "GetPtr", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D* vec = data->GetDataPtr<Vector2D>("Vector2D_ptr");
        context->SetReturn(string_format("%p", vec));
    });

    ADD_CLASS_FUNCTION("Vector2D", isLua ? "__len" : "length", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D* vec = data->GetDataPtr<Vector2D>("Vector2D_ptr");
        context->SetReturn(FastSqrt(vec->x * vec->x + vec->y * vec->y));
    });

    ADD_CLASS_FUNCTION("Vector2D", isLua ? "__eq" : "equal", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D vec = data->GetData<Vector2D>("Vector2D_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(false);
        if (!otherVecData->HasData("Vector2D_ptr")) return context->SetReturn(false);

        Vector2D otherVec = otherVecData->GetData<Vector2D>("Vector2D_ptr");

        context->SetReturn(vec == otherVec);
    });

    ADD_CLASS_FUNCTION("Vector2D", isLua ? "__tostring" : "toString", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D* vec = data->GetDataPtr<Vector2D>("Vector2D_ptr");
        context->SetReturn(string_format("Vector2D(%f,%f)", vec->x, vec->y));
    });

    ADD_CLASS_FUNCTION("Vector2D", isLua ? "__add" : "add", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D vec = data->GetData<Vector2D>("Vector2D_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("Vector2D_ptr")) return context->SetReturn(data);

        Vector2D otherVec = otherVecData->GetData<Vector2D>("Vector2D_ptr");

        data->SetData("Vector2D_ptr", vec + otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector2D", isLua ? "__unm" : "unm", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D vec = data->GetData<Vector2D>("Vector2D_ptr");

        data->SetData("Vector2D_ptr", -vec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector2D", isLua ? "__sub" : "sub", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D vec = data->GetData<Vector2D>("Vector2D_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("Vector2D_ptr")) return context->SetReturn(data);

        Vector2D otherVec = otherVecData->GetData<Vector2D>("Vector2D_ptr");

        data->SetData("Vector2D_ptr", vec - otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector2D", isLua ? "__mul" : "mul", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D vec = data->GetData<Vector2D>("Vector2D_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("Vector2D_ptr")) return context->SetReturn(data);

        Vector2D otherVec = otherVecData->GetData<Vector2D>("Vector2D_ptr");

        data->SetData("Vector2D_ptr", vec * otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector2D", isLua ? "__div" : "div", [](FunctionContext* context, ClassData* data) -> void {
        Vector2D vec = data->GetData<Vector2D>("Vector2D_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("Vector2D_ptr")) return context->SetReturn(data);

        Vector2D otherVec = otherVecData->GetData<Vector2D>("Vector2D_ptr");

        data->SetData("Vector2D_ptr", vec / otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector4D", "Vector4D", [](FunctionContext* context, ClassData* data) -> void {
        float x = context->GetArgumentOr<float>(0, 0.0f);
        float y = context->GetArgumentOr<float>(1, 0.0f);
        float z = context->GetArgumentOr<float>(2, 0.0f);
        float w = context->GetArgumentOr<float>(3, 0.0f);
        data->SetData("Vector4D_ptr", Vector4D(x, y, z, w));
    });

    ADD_CLASS_MEMBER("Vector4D", "x", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->x);
    }, [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        if (!vec) return;
        vec->x = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_MEMBER("Vector4D", "y", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->y);
    }, [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        if (!vec) return;
        vec->y = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_MEMBER("Vector4D", "z", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->z);
    }, [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        if (!vec) return;
        vec->z = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_MEMBER("Vector4D", "w", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->w);
    }, [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        if (!vec) return;
        vec->w = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_FUNCTION("Vector4D", "GetPtr", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        context->SetReturn(string_format("%p", vec));
    });

    ADD_CLASS_FUNCTION("Vector4D", isLua ? "__len" : "length", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        context->SetReturn(FastSqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z + vec->w * vec->w));
    });

    ADD_CLASS_FUNCTION("Vector4D", isLua ? "__eq" : "equal", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D vec = data->GetData<Vector4D>("Vector4D_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(false);
        if (!otherVecData->HasData("Vector4D_ptr")) return context->SetReturn(false);

        Vector4D otherVec = otherVecData->GetData<Vector4D>("Vector4D_ptr");

        context->SetReturn(vec == otherVec);
    });

    ADD_CLASS_FUNCTION("Vector4D", isLua ? "__tostring" : "toString", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D* vec = data->GetDataPtr<Vector4D>("Vector4D_ptr");
        context->SetReturn(string_format("Vector4D(%f,%f,%f,%f)", vec->x, vec->y, vec->z, vec->w));
    });

    ADD_CLASS_FUNCTION("Vector4D", isLua ? "__add" : "add", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D vec = data->GetData<Vector4D>("Vector4D_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("Vector4D_ptr")) return context->SetReturn(data);

        Vector4D otherVec = otherVecData->GetData<Vector4D>("Vector4D_ptr");

        data->SetData("Vector4D_ptr", vec + otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector4D", isLua ? "__unm" : "unm", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D vec = data->GetData<Vector4D>("Vector4D_ptr");

        data->SetData("Vector4D_ptr", -vec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector4D", isLua ? "__sub" : "sub", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D vec = data->GetData<Vector4D>("Vector4D_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("Vector4D_ptr")) return context->SetReturn(data);

        Vector4D otherVec = otherVecData->GetData<Vector4D>("Vector4D_ptr");

        data->SetData("Vector4D_ptr", vec - otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector4D", isLua ? "__mul" : "mul", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D vec = data->GetData<Vector4D>("Vector4D_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("Vector4D_ptr")) return context->SetReturn(data);

        Vector4D otherVec = otherVecData->GetData<Vector4D>("Vector4D_ptr");

        data->SetData("Vector4D_ptr", vec * otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Vector4D", isLua ? "__div" : "div", [](FunctionContext* context, ClassData* data) -> void {
        Vector4D vec = data->GetData<Vector4D>("Vector4D_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("Vector4D_ptr")) return context->SetReturn(data);

        Vector4D otherVec = otherVecData->GetData<Vector4D>("Vector4D_ptr");

        vec.x /= otherVec.x;
        vec.y /= otherVec.y;
        vec.z /= otherVec.z;
        vec.w /= otherVec.w;

        data->SetData("Vector4D_ptr", vec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("QAngle", "QAngle", [](FunctionContext* context, ClassData* data) -> void {
        float x = context->GetArgumentOr<float>(0, 0.0f);
        float y = context->GetArgumentOr<float>(1, 0.0f);
        float z = context->GetArgumentOr<float>(2, 0.0f);
        data->SetData("QAngle_ptr", QAngle(x, y, z));
    });

    ADD_CLASS_MEMBER("QAngle", "x", [](FunctionContext* context, ClassData* data) -> void {
        QAngle* vec = data->GetDataPtr<QAngle>("QAngle_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->x);
    }, [](FunctionContext* context, ClassData* data) -> void {
        QAngle* vec = data->GetDataPtr<QAngle>("QAngle_ptr");
        if (!vec) return;
        vec->x = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_MEMBER("QAngle", "y", [](FunctionContext* context, ClassData* data) -> void {
        QAngle* vec = data->GetDataPtr<QAngle>("QAngle_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->y);
    }, [](FunctionContext* context, ClassData* data) -> void {
        QAngle* vec = data->GetDataPtr<QAngle>("QAngle_ptr");
        if (!vec) return;
        vec->y = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_MEMBER("QAngle", "z", [](FunctionContext* context, ClassData* data) -> void {
        QAngle* vec = data->GetDataPtr<QAngle>("QAngle_ptr");
        if (!vec) return context->SetReturn(0.0f);
        context->SetReturn(vec->z);
    }, [](FunctionContext* context, ClassData* data) -> void {
        QAngle* vec = data->GetDataPtr<QAngle>("QAngle_ptr");
        if (!vec) return;
        vec->z = context->GetArgumentOr<float>(0, 0.0f);
        });

    ADD_CLASS_FUNCTION("QAngle", "GetPtr", [](FunctionContext* context, ClassData* data) -> void {
        QAngle* vec = data->GetDataPtr<QAngle>("QAngle_ptr");
        context->SetReturn(string_format("%p", vec));
    });

    ADD_CLASS_FUNCTION("QAngle", isLua ? "__len" : "length", [](FunctionContext* context, ClassData* data) -> void {
        QAngle* vec = data->GetDataPtr<QAngle>("QAngle_ptr");
        context->SetReturn(FastSqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z));
    });

    ADD_CLASS_FUNCTION("QAngle", isLua ? "__eq" : "equal", [](FunctionContext* context, ClassData* data) -> void {
        QAngle vec = data->GetData<QAngle>("QAngle_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(false);
        if (!otherVecData->HasData("QAngle_ptr")) return context->SetReturn(false);

        QAngle otherVec = otherVecData->GetData<QAngle>("QAngle_ptr");

        context->SetReturn(vec == otherVec);
    });

    ADD_CLASS_FUNCTION("QAngle", isLua ? "__tostring" : "toString", [](FunctionContext* context, ClassData* data) -> void {
        QAngle* vec = data->GetDataPtr<QAngle>("QAngle_ptr");
        context->SetReturn(string_format("QAngle(%f,%f,%f)", vec->x, vec->y, vec->z));
    });

    ADD_CLASS_FUNCTION("QAngle", isLua ? "__add" : "add", [](FunctionContext* context, ClassData* data) -> void {
        QAngle vec = data->GetData<QAngle>("QAngle_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("QAngle_ptr")) return context->SetReturn(data);

        QAngle otherVec = otherVecData->GetData<QAngle>("QAngle_ptr");

        data->SetData("QAngle_ptr", vec + otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("QAngle", isLua ? "__unm" : "unm", [](FunctionContext* context, ClassData* data) -> void {
        QAngle vec = data->GetData<QAngle>("QAngle_ptr");

        data->SetData("QAngle_ptr", -vec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("QAngle", isLua ? "__sub" : "sub", [](FunctionContext* context, ClassData* data) -> void {
        QAngle vec = data->GetData<QAngle>("QAngle_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("QAngle_ptr")) return context->SetReturn(data);

        QAngle otherVec = otherVecData->GetData<QAngle>("QAngle_ptr");

        data->SetData("QAngle_ptr", vec - otherVec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("QAngle", isLua ? "__mul" : "mul", [](FunctionContext* context, ClassData* data) -> void {
        QAngle vec = data->GetData<QAngle>("QAngle_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("QAngle_ptr")) return context->SetReturn(data);

        QAngle otherVec = otherVecData->GetData<QAngle>("QAngle_ptr");

        vec.x /= otherVec.x;
        vec.y /= otherVec.y;
        vec.z /= otherVec.z;

        data->SetData("QAngle_ptr", vec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("QAngle", isLua ? "__div" : "div", [](FunctionContext* context, ClassData* data) -> void {
        QAngle vec = data->GetData<QAngle>("QAngle_ptr");

        auto otherVecData = context->GetArgumentOr<ClassData*>(0, nullptr);
        if (!otherVecData) return context->SetReturn(data);
        if (!otherVecData->HasData("QAngle_ptr")) return context->SetReturn(data);

        QAngle otherVec = otherVecData->GetData<QAngle>("QAngle_ptr");

        vec.x /= otherVec.x;
        vec.y /= otherVec.y;
        vec.z /= otherVec.z;

        data->SetData("QAngle_ptr", vec);
        context->SetReturn(data);
    });

    ADD_CLASS_FUNCTION("Color", "Color", [](FunctionContext* context, ClassData* data) -> void {
        int r = context->GetArgumentOr<int>(0, 0);
        int g = context->GetArgumentOr<int>(1, 0);
        int b = context->GetArgumentOr<int>(2, 0);
        int a = context->GetArgumentOr<int>(3, 0);
        data->SetData("Color_ptr", Color(r, g, b, a));
    });

    ADD_CLASS_MEMBER("Color", "r", [](FunctionContext* context, ClassData* data) -> void {
        Color* vec = data->GetDataPtr<Color>("Color_ptr");
        if (!vec) return context->SetReturn(0);
        context->SetReturn(vec->r());
    }, [](FunctionContext* context, ClassData* data) -> void {
        Color* vec = data->GetDataPtr<Color>("Color_ptr");
        if (!vec) return;
        vec->SetColor(context->GetArgumentOr<int>(0, 0), vec->g(), vec->b(), vec->a());
        });

    ADD_CLASS_MEMBER("Color", "g", [](FunctionContext* context, ClassData* data) -> void {
        Color* vec = data->GetDataPtr<Color>("Color_ptr");
        if (!vec) return context->SetReturn(0);
        context->SetReturn(vec->g());
    }, [](FunctionContext* context, ClassData* data) -> void {
        Color* vec = data->GetDataPtr<Color>("Color_ptr");
        if (!vec) return;
        vec->SetColor(vec->r(), context->GetArgumentOr<int>(0, 0), vec->b(), vec->a());
        });

    ADD_CLASS_MEMBER("Color", "b", [](FunctionContext* context, ClassData* data) -> void {
        Color* vec = data->GetDataPtr<Color>("Color_ptr");
        if (!vec) return context->SetReturn(0);
        context->SetReturn(vec->b());
    }, [](FunctionContext* context, ClassData* data) -> void {
        Color* vec = data->GetDataPtr<Color>("Color_ptr");
        if (!vec) return;
        vec->SetColor(vec->r(), vec->g(), context->GetArgumentOr<int>(0, 0), vec->a());
        });

    ADD_CLASS_MEMBER("Color", "a", [](FunctionContext* context, ClassData* data) -> void {
        Color* vec = data->GetDataPtr<Color>("Color_ptr");
        if (!vec) return context->SetReturn(0);
        context->SetReturn(vec->a());
    }, [](FunctionContext* context, ClassData* data) -> void {
        Color* vec = data->GetDataPtr<Color>("Color_ptr");
        if (!vec) return;
        vec->SetColor(vec->r(), vec->g(), vec->b(), context->GetArgumentOr<int>(0, 0));
        });

    ADD_CLASS_FUNCTION("Color", isLua ? "__tostring" : "toString", [](FunctionContext* context, ClassData* data) -> void {
        Color* vec = data->GetDataPtr<Color>("Color_ptr");
        context->SetReturn(string_format("Color(%d,%d,%d,%d)", vec->r(), vec->g(), vec->b(), vec->a()));
    });

    ADD_CLASS_FUNCTION("Color", "GetPtr", [](FunctionContext* context, ClassData* data) -> void {
        Color* vec = data->GetDataPtr<Color>("Color_ptr");
        context->SetReturn(string_format("%p", vec));
    });
})