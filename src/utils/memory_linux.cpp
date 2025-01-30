#ifndef _WIN32
#include "memory.h"

using namespace DynLibUtils;

CMemory FindVirtTable(DynLibUtils::CModule *_this, const std::string_view svTableName, int32_t offset, bool bDecorated)
{
    if (svTableName.empty())
		return CMemory();

	CModule::ModuleSections_t readOnlyData = _this->GetSectionByName(".rodata"), readOnlyRelocations = _this->GetSectionByName(".data.rel.ro");
	if (!readOnlyData.IsSectionValid() || !readOnlyRelocations.IsSectionValid())
		return CMemory();

	std::string sDecoratedTableName(bDecorated ? svTableName : std::to_string(svTableName.length()) + std::string(svTableName));
	std::string sMask(sDecoratedTableName.length() + 1, 'x');

	CMemory typeInfoName = _this->FindPattern(sDecoratedTableName.data(), sMask, nullptr, &readOnlyData);
	if (!typeInfoName)
		return CMemory();

	CMemory referenceTypeName = _this->FindPattern(&typeInfoName, "xxxxxxxx", nullptr, &readOnlyRelocations); // Get reference to type name.
	if (!referenceTypeName)
		return CMemory();

	CMemory typeInfo = referenceTypeName.Offset(-0x8); // Offset -0x8 to typeinfo.

	for (const auto& sectionName : { std::string_view(".data.rel.ro"), std::string_view(".data.rel.ro.local") })
	{
		CModule::ModuleSections_t section = _this->GetSectionByName(sectionName);
		if (!section.IsSectionValid())
			continue;

		CMemory reference;
		while ((reference = _this->FindPattern(&typeInfo, "xxxxxxxx", reference, &section))) // Get reference typeinfo in vtable
		{
			if (reference.Offset(-0x8).GetValue<int64_t>() == offset) // Offset to this.
			{
				return reference.Offset(0x8);
			}

			reference.OffsetSelf(0x8);
		}
	}

	return CMemory();
}

#endif