#ifndef _sdk_entity_checktransmit_h
#define _sdk_entity_checktransmit_h

#include <core/entrypoint.h>

class EntityCheckTransmit
{
public:
	CBitVec<MAX_EDICTS>* m_pTransmitEntity;	// 0
	CBitVec<MAX_EDICTS>* m_pUnkBitVec;		// 8
	CBitVec<MAX_EDICTS>* m_pUnkBitVec2;		// 16
	CBitVec<MAX_EDICTS>* m_pUnkBitVec3;		// 24
	CBitVec<MAX_EDICTS>* m_pTransmitAlways; // 32
	CUtlVector<int> m_unk40;				// 40
	vis_info_t* m_VisInfo;					// 64
	[[maybe_unused]] byte m_unk72[0x200];	// 72
	CEntityIndex m_nClientEntityIndex;		// 584
	bool m_bFullUpdate;						// 588
};

#endif