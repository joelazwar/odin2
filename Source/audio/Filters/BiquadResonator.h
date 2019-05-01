#pragma once

#include "BiquadFilter.h"
#include "../../GlobalIncludes.h"

#include <cmath>

class BiquadResonator : public BiquadFilter {
public:
  BiquadResonator() {
    m_b0 = 1;
    m_b1 = 0;
    m_b2 = 0;
    m_a2 = 1;    
  }
  ~BiquadResonator() {}

  void setRadius(float p_radius) {
    m_radius = p_radius;
    recalculateFilterCoefficients();
  }
  void setSampleRate(float p_sr) {
    m_samplerate = p_sr;
    recalculateFilterCoefficients();
  }
  void setFrequency(float p_freq) {
    m_freq = p_freq;
    recalculateFilterCoefficients();
  }

  void recalculateFilterCoefficients() {
    m_a1 = 2 * m_radius * cos(2 * M_PI * m_freq / m_samplerate);
    m_a2 = m_radius * m_radius;
  }

protected:
  float m_radius = 0.9;
  float m_freq = 2000;
  float m_samplerate = 48000.f;
};
