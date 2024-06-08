#ifndef _grendermodelsubmodelfieldtype_t_h
#define _grendermodelsubmodelfieldtype_t_h

enum class RenderModelSubModelFieldType_t : uint64_t
{
    SUBMODEL_AS_BODYGROUP_SUBMODEL = 0x0,
    SUBMODEL_AS_MESHGROUP_INDEX = 0x1,
    SUBMODEL_AS_MESHGROUP_MASK = 0x2,
    SUBMODEL_IGNORED_USE_MODEL_DEFAULT_MESHGROUP_MASK = 0x3,
};

#endif