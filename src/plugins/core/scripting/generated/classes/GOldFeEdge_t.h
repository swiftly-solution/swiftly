class GOldFeEdge_t;

#ifndef _gcoldfeedge_t_h
#define _gcoldfeedge_t_h

#include "../../../scripting.h"




class GOldFeEdge_t
{
private:
    void *m_ptr;

public:
    GOldFeEdge_t() {}
    GOldFeEdge_t(void *ptr) : m_ptr(ptr) {}

    std::vector<float> GetK() const { float* outValue = GetSchemaValue<float*>(m_ptr, "OldFeEdge_t", "m_flK"); std::vector<float> ret; for(int i = 0; i < 3; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetK(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "OldFeEdge_t", "m_flK"); for(int i = 0; i < 3; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "OldFeEdge_t", "m_flK", true, outValue); }
    float GetInvA() const { return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "invA"); }
    void SetInvA(float value) { SetSchemaValue(m_ptr, "OldFeEdge_t", "invA", true, value); }
    float GetT() const { return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "t"); }
    void SetT(float value) { SetSchemaValue(m_ptr, "OldFeEdge_t", "t", true, value); }
    float GetThetaRelaxed() const { return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "flThetaRelaxed"); }
    void SetThetaRelaxed(float value) { SetSchemaValue(m_ptr, "OldFeEdge_t", "flThetaRelaxed", true, value); }
    float GetThetaFactor() const { return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "flThetaFactor"); }
    void SetThetaFactor(float value) { SetSchemaValue(m_ptr, "OldFeEdge_t", "flThetaFactor", true, value); }
    float GetC01() const { return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "c01"); }
    void SetC01(float value) { SetSchemaValue(m_ptr, "OldFeEdge_t", "c01", true, value); }
    float GetC02() const { return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "c02"); }
    void SetC02(float value) { SetSchemaValue(m_ptr, "OldFeEdge_t", "c02", true, value); }
    float GetC03() const { return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "c03"); }
    void SetC03(float value) { SetSchemaValue(m_ptr, "OldFeEdge_t", "c03", true, value); }
    float GetC04() const { return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "c04"); }
    void SetC04(float value) { SetSchemaValue(m_ptr, "OldFeEdge_t", "c04", true, value); }
    float GetAxialModelDist() const { return GetSchemaValue<float>(m_ptr, "OldFeEdge_t", "flAxialModelDist"); }
    void SetAxialModelDist(float value) { SetSchemaValue(m_ptr, "OldFeEdge_t", "flAxialModelDist", true, value); }
    std::vector<float> GetAxialModelWeights() const { float* outValue = GetSchemaValue<float*>(m_ptr, "OldFeEdge_t", "flAxialModelWeights"); std::vector<float> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetAxialModelWeights(std::vector<float> value) { float* outValue = GetSchemaValue<float*>(m_ptr, "OldFeEdge_t", "flAxialModelWeights"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "OldFeEdge_t", "flAxialModelWeights", true, outValue); }
    std::vector<uint16_t> GetNode() const { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "OldFeEdge_t", "m_nNode"); std::vector<uint16_t> ret; for(int i = 0; i < 4; i++) { ret.push_back(outValue[i]); } return ret; }
    void SetNode(std::vector<uint16_t> value) { uint16_t* outValue = GetSchemaValue<uint16_t*>(m_ptr, "OldFeEdge_t", "m_nNode"); for(int i = 0; i < 4; i++) { outValue[i] = value[i]; } SetSchemaValue(m_ptr, "OldFeEdge_t", "m_nNode", true, outValue); }

    bool IsValid() { return (m_ptr != nullptr); }
};

#endif