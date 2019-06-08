#include "Chorus.h"
#include <cmath>

Chorus::Chorus() {}

Chorus::~Chorus() {}

float Chorus::doChorus(float p_input) {

  float LFO_sine;
  float LFO_cosine;
  incLFO();
  doLFO(LFO_sine, LFO_cosine);

  // make them unipolar
  LFO_sine = LFO_sine * 0.5f + 0.5f;
  LFO_cosine = LFO_cosine * 0.5f + 0.5f;

  float amount_modded = m_amount + *m_amount_mod;
  amount_modded = amount_modded < 0 ? 0 : amount_modded;
  // amount_modded = amount_modded < 0 ? 0 : amount_modded;

  // Delayline 1
  float read_index =
      (float)m_write_index - CHORUS_MIN_DISTANCE -
      (LFO_sine * CHORUS_AMOUNT_RANGE * amount_modded) * m_samplerate;
  int read_index_trunc = floor(read_index);
  int read_index_next = read_index_trunc + 1;
  float frac = read_index - (float)read_index_trunc;
  read_index_trunc = read_index_trunc < 0
                         ? read_index_trunc + CHORUS_BUFFER_LENGTH
                         : read_index_trunc;
  read_index_next = read_index_next < 0 ? read_index_next + CHORUS_BUFFER_LENGTH
                                        : read_index_next;
  read_index_next = read_index_next >= CHORUS_BUFFER_LENGTH
                        ? read_index_next - CHORUS_BUFFER_LENGTH
                        : read_index_next;
  float output = linearInterpolation(m_circular_buffer[read_index_trunc],
                                     m_circular_buffer[read_index_next], frac);

  // Delayline 2
  read_index =
      (float)m_write_index - CHORUS_MIN_DISTANCE -
      (LFO_cosine * CHORUS_AMOUNT_RANGE * amount_modded) * m_samplerate;
  read_index_trunc = floor(read_index);
  read_index_next = read_index_trunc + 1;
  frac = read_index - (float)read_index_trunc;
  read_index_trunc = read_index_trunc < 0
                         ? read_index_trunc + CHORUS_BUFFER_LENGTH
                         : read_index_trunc;
  read_index_next = read_index_next < 0 ? read_index_next + CHORUS_BUFFER_LENGTH
                                        : read_index_next;
  read_index_next = read_index_next >= CHORUS_BUFFER_LENGTH
                        ? read_index_next - CHORUS_BUFFER_LENGTH
                        : read_index_next;
  output += linearInterpolation(m_circular_buffer[read_index_trunc],
                                m_circular_buffer[read_index_next], frac);

  // Delayline 3
  read_index =
      (float)m_write_index - CHORUS_MIN_DISTANCE -
      ((1 - LFO_sine) * CHORUS_AMOUNT_RANGE * amount_modded) * m_samplerate;
  read_index_trunc = floor(read_index);
  read_index_next = read_index_trunc + 1;
  frac = read_index - (float)read_index_trunc;
  read_index_trunc = read_index_trunc < 0
                         ? read_index_trunc + CHORUS_BUFFER_LENGTH
                         : read_index_trunc;
  read_index_next = read_index_next < 0 ? read_index_next + CHORUS_BUFFER_LENGTH
                                        : read_index_next;
  read_index_next = read_index_next >= CHORUS_BUFFER_LENGTH
                        ? read_index_next - CHORUS_BUFFER_LENGTH
                        : read_index_next;
  output += linearInterpolation(m_circular_buffer[read_index_trunc],
                                m_circular_buffer[read_index_next], frac);
  
  // Delayline 4
  read_index =
      (float)m_write_index - CHORUS_MIN_DISTANCE -
      ((1 - LFO_cosine) * CHORUS_AMOUNT_RANGE * amount_modded) * m_samplerate;
  read_index_trunc = floor(read_index);
  read_index_next = read_index_trunc + 1;
  frac = read_index - (float)read_index_trunc;
  read_index_trunc = read_index_trunc < 0
                         ? read_index_trunc + CHORUS_BUFFER_LENGTH
                         : read_index_trunc;
  read_index_next = read_index_next < 0 ? read_index_next + CHORUS_BUFFER_LENGTH
                                        : read_index_next;
  read_index_next = read_index_next >= CHORUS_BUFFER_LENGTH
                        ? read_index_next - CHORUS_BUFFER_LENGTH
                        : read_index_next;
  output += linearInterpolation(m_circular_buffer[read_index_trunc],
                                m_circular_buffer[read_index_next], frac);

  output *= 0.25f;

  m_circular_buffer[m_write_index] = p_input + output * m_feedback;
  incWriteIndex();

  float drywet_modded = m_dry_wet + *m_drywet_mod;
  drywet_modded = drywet_modded > 1 ? 1 : drywet_modded;
  drywet_modded = drywet_modded < 0 ? 0 : drywet_modded;

  return output * drywet_modded + (1.f - drywet_modded) * p_input;
}
