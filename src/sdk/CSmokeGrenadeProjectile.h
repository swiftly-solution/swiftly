#pragma once
#include "CBaseCSGrenadeProjectile.h"
#include "schemasystem.h"
#include "vector.h"

class CSmokeGrenadeProjectile : public CBaseCSGrenadeProjectile
{
public:
	SCHEMA_FIELD(Vector, CSmokeGrenadeProjectile, m_vSmokeColor);
};