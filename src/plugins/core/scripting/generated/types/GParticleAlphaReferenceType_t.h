#ifndef _gparticlealphareferencetype_t_h
#define _gparticlealphareferencetype_t_h

enum class ParticleAlphaReferenceType_t : uint64_t
{
    PARTICLE_ALPHA_REFERENCE_ALPHA_ALPHA = 0x0,
    PARTICLE_ALPHA_REFERENCE_OPAQUE_ALPHA = 0x1,
    PARTICLE_ALPHA_REFERENCE_ALPHA_OPAQUE = 0x2,
    PARTICLE_ALPHA_REFERENCE_OPAQUE_OPAQUE = 0x3,
};

#endif