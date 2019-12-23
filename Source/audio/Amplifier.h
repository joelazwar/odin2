#pragma once

#include "../JuceLibraryCode/JuceHeader.h" //for db to gain
#include "../GlobalIncludes.h"


#define MIDI_VEL_MAX 127.f
#define WIDTH_DELAY_SAMPLES 1000
#define WIDTH_MAX_DELAY_SECONDS 0.002

class Amplifier {

public:

  void doAmplifier(float p_in, float &po_left_out, float &po_right_out);
  void incWriteIndex();


  void setWidth(float p_width){
    m_width_seconds = p_width * WIDTH_MAX_DELAY_SECONDS;
  }

  void setSampleRate(float p_samplerate){
    m_samplerate = p_samplerate;
  }

  inline void setGainDecibels(float p_dB) {
    // convert dB to multiplicator
    m_gain = Decibels::decibelsToGain(p_dB);
  }

  inline void setPan(float p_pan) { m_pan = p_pan; }

  // this is for the knob
  inline void setVelocityAmount(float p_vel) { 
    //m_vel_amount = p_vel; 
    m_width_seconds = p_vel * WIDTH_MAX_DELAY_SECONDS;
  }

  // this is for the keypress value
  inline void setMIDIVelocity(int p_MIDI_vel) {
    m_MIDI_vel = (float)p_MIDI_vel / MIDI_VEL_MAX;
  }

  void setGainModPointer(float *p_pointer) { m_gain_mod = p_pointer; }
  void setPanModPointer(float *p_pointer) { m_pan_mod = p_pointer; }
  void setVelModPointer(float *p_pointer) { m_vel_mod = p_pointer; }

protected:
  inline float linearInterpolation(float p_low, float p_high,
                                   float p_distance) {
    return (1.f - p_distance) * p_low + p_distance * p_high;
  }

  float *m_gain_mod;
  float *m_pan_mod;
  float *m_vel_mod;

  float m_width_seconds = 0;
  float m_width_delay_buffer[WIDTH_DELAY_SAMPLES] = {0};
  float m_samplerate;
  int m_write_index = 0;

  float m_MIDI_vel = 0.f;
  float m_vel_amount = 0.f;
  float m_gain = 1.f; // this is a multiplicator, not a dB value
  float m_gain_smooth = 1.f;
  float m_pan = 0.f;
  float m_pan_smooth = 0.f;
};