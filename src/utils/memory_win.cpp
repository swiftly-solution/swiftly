#ifdef _WIN32
#include "memory.h"

using namespace DynLibUtils;

CMemory FindVirtTable(DynLibUtils::CModule *_this, const std::string_view svTableName, int32_t offset, bool bDecorated)
{
    if(svTableName.empty())
		return CMemory();
	
	CModule::ModuleSections_t runTimeData = GetSectionByName(".data"), readOnlyData = GetSectionByName(".rdata");
	if(!runTimeData.IsSectionValid() || !readOnlyData.IsSectionValid())
		return CMemory();

	std::string sDecoratedTableName(bDecorated ? svTableName : ".?AV" + std::string(svTableName) + "@@");
	std::string sMask(sDecoratedTableName.length() + 1, 'x');

	CMemory typeDescriptorName = _this->FindPattern(sDecoratedTableName.data(), sMask, nullptr, &runTimeData);
	if (!typeDescriptorName)
		return CMemory();

	CMemory rttiTypeDescriptor = typeDescriptorName.Offset(-0x10);
	const uintptr_t rttiTDRva = rttiTypeDescriptor - _this->GetModuleBase(); // The RTTI gets referenced by a 4-Byte RVA address. We need to scan for that address.

	CMemory reference;
	while ((reference = _this->FindPattern(&rttiTDRva, "xxxx", reference, &readOnlyData))) // Get reference typeinfo in vtable
	{
		// Check if we got a RTTI Object Locator for this reference by checking if -0xC is 1, which is the 'signature' field which is always 1 on x64.
		// Check that offset of this vtable is 0
		if (reference.Offset(-0xC).GetValue<int32_t>() == 1 && reference.Offset(-0x8).GetValue<int32_t>() == offset)
		{
			CMemory referenceOffset = reference.Offset(-0xC);
			CMemory rttiCompleteObjectLocator = _this->FindPattern(&referenceOffset, "xxxxxxxx", nullptr, &readOnlyData);
			if (rttiCompleteObjectLocator)
				return rttiCompleteObjectLocator.Offset(0x8);
		}

		reference.OffsetSelf(0x4);
	}

	return CMemory();
}
#endif