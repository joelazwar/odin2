#define DEBUG_VARIABLES


//todo split this into a few functions to reduce overhead

void OdinAudioProcessor::treeValueChanged(const String &p_ID,
                                          float p_new_value) {

  // create identifier once, then compare it against everything
  Identifier id(p_ID);

#ifdef DEBUG_VARIABLES
  DBG(p_ID + ": " + std::to_string(p_new_value));
#endif

  if (id == m_osc1_analog_wave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].analog_osc[0].selectWavetable((int)p_new_value - 1);
    }
  } else if (id == m_osc2_analog_wave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].analog_osc[1].selectWavetable((int)p_new_value - 1);
    }
  } else if (id == m_osc3_analog_wave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].analog_osc[2].selectWavetable((int)p_new_value - 1);
    }
  } else if (id == m_osc1_oct_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setOctave(p_new_value, 0);
    }
  } else if (id == m_osc2_oct_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setOctave(p_new_value, 1);
    }
  } else if (id == m_osc3_oct_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setOctave(p_new_value, 2);
    }
  } else if (id == m_osc1_semi_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setSemitones(p_new_value, 0);
    }
  } else if (id == m_osc2_semi_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setSemitones(p_new_value, 1);
    }
  } else if (id == m_osc3_semi_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setSemitones(p_new_value, 2);
    }
  } else if (id == m_osc1_fine_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setFinetune(p_new_value, 0);
    }
  } else if (id == m_osc2_fine_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setFinetune(p_new_value, 1);
    }
  } else if (id == m_osc3_fine_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setFinetune(p_new_value, 2);
    }
  } else if (id == m_osc1_reset_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setReset(p_new_value, 0);
    }
  } else if (id == m_osc2_reset_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setReset(p_new_value, 1);
    }
  } else if (id == m_osc3_reset_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setReset(p_new_value, 2);
    }
  } else if (id == m_osc1_pulsewidth_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].analog_osc[0].setPWMDuty(p_new_value);
    }
  } else if (id == m_osc2_pulsewidth_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].analog_osc[1].setPWMDuty(p_new_value);
    }
  } else if (id == m_osc3_pulsewidth_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].analog_osc[2].setPWMDuty(p_new_value);
    }
  } else if (id == m_osc1_drift_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].analog_osc[0].setDrift(p_new_value);
    }
  } else if (id == m_osc2_drift_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].analog_osc[1].setDrift(p_new_value);
    }
  } else if (id == m_osc3_drift_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].analog_osc[2].setDrift(p_new_value);
    }
  } else if (id == m_osc1_position_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].wavetable_osc[0].setPosition(p_new_value);
    }
  } else if (id == m_osc2_position_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].wavetable_osc[1].setPosition(p_new_value);
    }
  } else if (id == m_osc3_position_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].wavetable_osc[2].setPosition(p_new_value);
    }
  } else if (id == m_osc1_wavetable_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].wavetable_osc[0].selectWavetable(p_new_value);
    }
  } else if (id == m_osc2_wavetable_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].wavetable_osc[1].selectWavetable(p_new_value);
    }
  } else if (id == m_osc3_wavetable_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].wavetable_osc[2].selectWavetable(p_new_value);
    }
  } else if (id == m_osc1_detune_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].multi_osc[0].setDetune(p_new_value);
    }
  } else if (id == m_osc2_detune_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].multi_osc[1].setDetune(p_new_value);
    }
  } else if (id == m_osc3_detune_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].multi_osc[2].setDetune(p_new_value);
    }
  } else if (id == m_osc1_multi_position_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].multi_osc[0].setPosition(p_new_value);
    }
  } else if (id == m_osc2_multi_position_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].multi_osc[1].setPosition(p_new_value);
    }
  } else if (id == m_osc3_multi_position_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].multi_osc[2].setPosition(p_new_value);
    }
  } else if (id == m_osc1_spread_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].multi_osc[0].setWavetableMultiSpread(p_new_value);
    }
  } else if (id == m_osc2_spread_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].multi_osc[1].setWavetableMultiSpread(p_new_value);
    }
  } else if (id == m_osc3_spread_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].multi_osc[2].setWavetableMultiSpread(p_new_value);
    }
  }
  else if (id == m_osc1_vec_a_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[0].selectWavetable(p_new_value, 0);
    }
  } else if (id == m_osc2_vec_a_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[1].selectWavetable(p_new_value, 0);
    }
  } else if (id == m_osc3_vec_a_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[2].selectWavetable(p_new_value, 0);
    }
  } else if (id == m_osc1_vec_b_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[0].selectWavetable(p_new_value, 1);
    }
  } else if (id == m_osc2_vec_b_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[1].selectWavetable(p_new_value, 1);
    }
  } else if (id == m_osc3_vec_b_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[2].selectWavetable(p_new_value, 1);
    }
  } else if (id == m_osc1_vec_c_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[0].selectWavetable(p_new_value, 2);
    }
  } else if (id == m_osc2_vec_c_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[1].selectWavetable(p_new_value, 2);
    }
  } else if (id == m_osc3_vec_c_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[2].selectWavetable(p_new_value, 2);
    }
  } else if (id == m_osc1_vec_d_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[0].selectWavetable(p_new_value, 3);
    }
  } else if (id == m_osc2_vec_d_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[1].selectWavetable(p_new_value, 3);
    }
  } else if (id == m_osc3_vec_d_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[2].selectWavetable(p_new_value, 3);
    }
  } else if (id == m_osc1_vec_x_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[0].setX(p_new_value);
    }
  } else if (id == m_osc2_vec_x_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[1].setX(p_new_value);
    }
  } else if (id == m_osc3_vec_x_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[2].setX(p_new_value);
    }
  } else if (id == m_osc1_vec_y_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[0].setY(p_new_value);
    }
  } else if (id == m_osc2_vec_y_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[1].setY(p_new_value);
    }
  } else if (id == m_osc3_vec_y_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].vector_osc[2].setY(p_new_value);
    }
  } else if (id == m_osc1_chipwave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[0].selectWavetable(p_new_value);
    }
  } else if (id == m_osc2_chipwave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[1].selectWavetable(p_new_value);
    }
  } else if (id == m_osc3_chipwave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[2].selectWavetable(p_new_value);
    }
  } else if (id == m_osc1_chipnoise_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[0].setNoiseEnabled(p_new_value);
    }
  } else if (id == m_osc2_chipnoise_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[1].setNoiseEnabled(p_new_value);
    }
  } else if (id == m_osc3_chipnoise_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[2].setNoiseEnabled(p_new_value);
    }
  } else if (id == m_osc1_step_1_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[0].setArpSemitone(0, p_new_value);
    }
  } else if (id == m_osc2_step_1_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[1].setArpSemitone(0, p_new_value);
    }
  } else if (id == m_osc3_step_1_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[2].setArpSemitone(0, p_new_value);
    }
  } else if (id == m_osc1_step_2_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[0].setArpSemitone(1, p_new_value);
    }
  } else if (id == m_osc2_step_2_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[1].setArpSemitone(1, p_new_value);
    }
  } else if (id == m_osc3_step_2_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[2].setArpSemitone(1, p_new_value);
    }
  } else if (id == m_osc1_step_3_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[0].setArpSemitone(2, p_new_value);
    }
  } else if (id == m_osc2_step_3_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[1].setArpSemitone(2, p_new_value);
    }
  } else if (id == m_osc3_step_3_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[2].setArpSemitone(2, p_new_value);
    }
  } else if (id == m_osc1_step_3_on_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[0].setArpStepThreeOn(p_new_value);
    }
  } else if (id == m_osc2_step_3_on_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[1].setArpStepThreeOn(p_new_value);
    }
  } else if (id == m_osc3_step_3_on_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[2].setArpStepThreeOn(p_new_value);
    }
  } else if (id == m_osc1_arp_on_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[0].setArpEnabled(p_new_value);
    }
  } else if (id == m_osc2_arp_on_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[1].setArpEnabled(p_new_value);
    }
  } else if (id == m_osc3_arp_on_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[2].setArpEnabled(p_new_value);
    }
  } else if (id == m_osc1_arp_speed_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[0].setArpSpeed(p_new_value);
    }
  } else if (id == m_osc2_arp_speed_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[1].setArpSpeed(p_new_value);
    }
  } else if (id == m_osc3_arp_speed_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].chiptune_osc[2].setArpSpeed(p_new_value);
    }
  } else if (id == m_osc1_fm_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[0].setFMAmount(p_new_value);
    }
  } else if (id == m_osc2_fm_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[1].setFMAmount(p_new_value);
    }
  } else if (id == m_osc3_fm_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[2].setFMAmount(p_new_value);
    }
  } else if (id == m_osc1_carrier_ratio_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[0].setCarrierRatio(p_new_value);
    }
  } else if (id == m_osc2_carrier_ratio_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[1].setCarrierRatio(p_new_value);
    }
  } else if (id == m_osc3_carrier_ratio_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[2].setCarrierRatio(p_new_value);
    }
  } else if (id == m_osc1_modulator_ratio_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[0].setModulatorRatio(p_new_value);
    }
  } else if (id == m_osc2_modulator_ratio_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[1].setModulatorRatio(p_new_value);
    }
  } else if (id == m_osc3_modulator_ratio_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[2].setModulatorRatio(p_new_value);
    }
  } else if (id == m_osc1_carrier_wave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[0].selectCarrierWavetable(p_new_value);
    }
  } else if (id == m_osc2_carrier_wave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[1].selectCarrierWavetable(p_new_value);
    }
  } else if (id == m_osc3_carrier_wave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[2].selectCarrierWavetable(p_new_value);
    }
  } else if (id == m_osc1_modulator_wave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[0].selectModulatorWavetable(p_new_value);
    }
  } else if (id == m_osc2_modulator_wave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[1].selectModulatorWavetable(p_new_value);
    }
  } else if (id == m_osc3_modulator_wave_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[2].selectModulatorWavetable(p_new_value);
    }
  } else if (id == m_osc1_exp_fm_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[0].setFMExponential(p_new_value);
    }
  } else if (id == m_osc2_exp_fm_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[1].setFMExponential(p_new_value);
    }
  } else if (id == m_osc3_exp_fm_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].fm_osc[2].setFMExponential(p_new_value);
    }
  } else if (id == m_osc1_hp_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].noise_osc[0].setHPFreq(p_new_value);
    }
  } else if (id == m_osc2_hp_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].noise_osc[1].setHPFreq(p_new_value);
    }
  } else if (id == m_osc3_hp_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].noise_osc[2].setHPFreq(p_new_value);
    }
  } else if (id == m_osc1_lp_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].noise_osc[0].setLPFreq(p_new_value);
    }
  } else if (id == m_osc2_lp_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].noise_osc[1].setLPFreq(p_new_value);
    }
  } else if (id == m_osc3_lp_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].noise_osc[2].setLPFreq(p_new_value);
    }
  } else if (id == m_fil1_freq_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setFilterFreq(p_new_value, 0);
    }
  } else if (id == m_fil2_freq_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setFilterFreq(p_new_value, 1);
    }
  } else if (id == m_fil1_res_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setFilterRes(p_new_value, 0);
    }
  } else if (id == m_fil2_res_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setFilterRes(p_new_value, 1);
    }
  } else if (id == m_fil1_type_identifier) {
    if (p_new_value < 7.5f && p_new_value > 1.5f) {
      for (int voice = 0; voice < VOICES; ++voice) {
        m_voice[voice].ladder_filter[0].setFilterType((int)p_new_value - 2);
      }
    }
  } else if (id == m_fil2_type_identifier) {
    if (p_new_value < 7.5f && p_new_value > 1.5f) {
      for (int voice = 0; voice < VOICES; ++voice) {
        m_voice[voice].ladder_filter[1].setFilterType((int)p_new_value - 2);
      }
    }
  } else if (id == m_fil1_kbd_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setKbd(p_new_value, 0);
    }
  } else if (id == m_fil2_kbd_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setKbd(p_new_value, 1);
    }
  } else if (id == m_fil1_vel_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setVelModAmount(p_new_value, 0);
    }
  } else if (id == m_fil2_vel_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setVelModAmount(p_new_value, 1);
    }
  } else if (id == m_fil1_env_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setEnvModAmount(p_new_value, 0);
    }
  } else if (id == m_fil2_env_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setEnvModAmount(p_new_value, 1);
    }
  } else if (id == m_fil1_saturation_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setSaturation(p_new_value, 0);
    }
  } else if (id == m_fil2_saturation_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].setSaturation(p_new_value, 1);
    }
  } else if (id == m_fil1_vowel_left_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].formant_filter[0].setVowelLeft((int)p_new_value - 1);
    }
  } else if (id == m_fil2_vowel_left_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].formant_filter[1].setVowelLeft((int)p_new_value - 1);
    }
  } else if (id == m_fil1_vowel_right_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].formant_filter[0].setVowelRight((int)p_new_value - 1);
    }
  } else if (id == m_fil2_vowel_right_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].formant_filter[1].setVowelRight((int)p_new_value - 1);
    }
  } else if (id == m_fil1_formant_transition_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].formant_filter[0].setTransition(p_new_value);
    }
  } else if (id == m_fil2_formant_transition_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].formant_filter[1].setTransition(p_new_value);
    }
  } else if (id == m_fil1_comb_polarity_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].comb_filter[0].setPositive(p_new_value);
    }
  } else if (id == m_fil2_comb_polarity_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].comb_filter[1].setPositive(p_new_value);
    }
  } else if (id == m_amp_pan_identifier) {
    m_amp.setPan(p_new_value);
  } else if (id == m_amp_gain_identifier) {
    m_amp.setGainDecibels(p_new_value);
  } else if (id == m_amp_vel_identifier) {
    m_amp.setVelocityAmount(p_new_value);
  } else if (id == m_dist_drywet_identifier) {
    m_distortion[0].setDryWet(p_new_value);
    m_distortion[1].setDryWet(p_new_value);
  } else if (id == m_dist_threshold_identifier) {
    m_distortion[0].setThreshold(p_new_value);
    m_distortion[1].setThreshold(p_new_value);
  } else if (id == m_dist_algo_identifier) {
    m_distortion[0].setOverdrive(p_new_value < 1.5f);
    m_distortion[1].setOverdrive(p_new_value < 1.5f);
  } else if (id == m_fil3_freq_identifier) {
    m_ladder_filter[0].m_freq_base = p_new_value;
    m_SEM_filter_12[0].m_freq_base = p_new_value;
    m_SEM_filter_24[0].m_freq_base = p_new_value;
    m_korg_filter[0].m_freq_base = p_new_value;
    m_diode_filter[0].m_freq_base = p_new_value;
    m_comb_filter[0].setCombFreq(p_new_value);
    m_ladder_filter[1].m_freq_base = p_new_value;
    m_SEM_filter_12[1].m_freq_base = p_new_value;
    m_SEM_filter_24[1].m_freq_base = p_new_value;
    m_korg_filter[1].m_freq_base = p_new_value;
    m_diode_filter[1].m_freq_base = p_new_value;
    m_comb_filter[1].setCombFreq(p_new_value);
  } else if (id == m_fil3_res_identifier) {
    m_ladder_filter[0].setResControl(p_new_value);
    m_SEM_filter_12[0].setResControl(p_new_value);
    m_SEM_filter_24[0].setResControl(p_new_value);
    m_korg_filter[0].setResControl(p_new_value);
    m_diode_filter[0].setResControl(p_new_value);
    m_comb_filter[0].setResonance(p_new_value);
    m_ladder_filter[1].setResControl(p_new_value);
    m_SEM_filter_12[1].setResControl(p_new_value);
    m_SEM_filter_24[1].setResControl(p_new_value);
    m_korg_filter[1].setResControl(p_new_value);
    m_diode_filter[1].setResControl(p_new_value);
    m_comb_filter[1].setResonance(p_new_value);
  } else if (id == m_fil3_type_identifier) {
    if (p_new_value < 7.5f && p_new_value > 1.5f) {
      m_ladder_filter[0].setFilterType((int)p_new_value - 2);
      m_ladder_filter[1].setFilterType((int)p_new_value - 2);
    }
  } else if (id == m_fil3_kbd_identifier) {
    m_ladder_filter[0].m_kbd_mod_amount = p_new_value;
    m_SEM_filter_12[0].m_kbd_mod_amount = p_new_value;
    m_SEM_filter_24[0].m_kbd_mod_amount = p_new_value;
    m_korg_filter[0].m_kbd_mod_amount = p_new_value;
    m_diode_filter[0].m_kbd_mod_amount = p_new_value;
    m_comb_filter[0].m_kbd_mod_amount = p_new_value;
    m_ladder_filter[1].m_kbd_mod_amount = p_new_value;
    m_SEM_filter_12[1].m_kbd_mod_amount = p_new_value;
    m_SEM_filter_24[1].m_kbd_mod_amount = p_new_value;
    m_korg_filter[1].m_kbd_mod_amount = p_new_value;
    m_diode_filter[1].m_kbd_mod_amount = p_new_value;
    m_comb_filter[1].m_kbd_mod_amount = p_new_value;
  } else if (id == m_fil3_vel_identifier) {
    m_ladder_filter[0].m_vel_mod_amount = p_new_value;
    m_SEM_filter_12[0].m_vel_mod_amount = p_new_value;
    m_SEM_filter_24[0].m_vel_mod_amount = p_new_value;
    m_korg_filter[0].m_vel_mod_amount = p_new_value;
    m_diode_filter[0].m_vel_mod_amount = p_new_value;
    m_comb_filter[0].m_vel_mod_amount = p_new_value;
    m_formant_filter[0].m_vel_mod_amount = p_new_value;
    m_ladder_filter[1].m_vel_mod_amount = p_new_value;
    m_SEM_filter_12[1].m_vel_mod_amount = p_new_value;
    m_SEM_filter_24[1].m_vel_mod_amount = p_new_value;
    m_korg_filter[1].m_vel_mod_amount = p_new_value;
    m_diode_filter[1].m_vel_mod_amount = p_new_value;
    m_comb_filter[1].m_vel_mod_amount = p_new_value;
    m_formant_filter[1].m_vel_mod_amount = p_new_value;
  } else if (id == m_fil3_env_identifier) {
    m_ladder_filter[0].m_env_mod_amount = p_new_value;
    m_SEM_filter_12[0].m_env_mod_amount = p_new_value;
    m_SEM_filter_24[0].m_env_mod_amount = p_new_value;
    m_korg_filter[0].m_env_mod_amount = p_new_value;
    m_diode_filter[0].m_env_mod_amount = p_new_value;
    m_comb_filter[0].m_env_mod_amount = p_new_value;
    m_formant_filter[0].m_env_mod_amount = p_new_value;
    m_ladder_filter[1].m_env_mod_amount = p_new_value;
    m_SEM_filter_12[1].m_env_mod_amount = p_new_value;
    m_SEM_filter_24[1].m_env_mod_amount = p_new_value;
    m_korg_filter[1].m_env_mod_amount = p_new_value;
    m_diode_filter[1].m_env_mod_amount = p_new_value;
    m_comb_filter[1].m_env_mod_amount = p_new_value;
    m_formant_filter[1].m_env_mod_amount = p_new_value;
  } else if (id == m_fil3_saturation_identifier) {
    m_ladder_filter[0].m_overdrive = p_new_value;
    m_SEM_filter_12[0].m_overdrive = p_new_value;
    m_SEM_filter_24[0].m_overdrive = p_new_value;
    m_korg_filter[0].m_overdrive = p_new_value;
    m_diode_filter[0].m_overdrive = p_new_value;
    m_ladder_filter[1].m_overdrive = p_new_value;
    m_SEM_filter_12[1].m_overdrive = p_new_value;
    m_SEM_filter_24[1].m_overdrive = p_new_value;
    m_korg_filter[1].m_overdrive = p_new_value;
    m_diode_filter[1].m_overdrive = p_new_value;
  } else if (id == m_fil3_vowel_left_identifier) {
    m_formant_filter[0].setVowelLeft((int)p_new_value - 1);
    m_formant_filter[1].setVowelLeft((int)p_new_value - 1);
  } else if (id == m_fil3_vowel_right_identifier) {
    m_formant_filter[0].setVowelRight((int)p_new_value - 1);
    m_formant_filter[1].setVowelRight((int)p_new_value - 1);
  } else if (id == m_fil3_formant_transition_identifier) {
    m_formant_filter[0].setTransition(p_new_value);
    m_formant_filter[1].setTransition(p_new_value);
  } else if (id == m_fil3_comb_polarity_identifier) {
    m_comb_filter[0].setPositive(p_new_value);
    m_comb_filter[1].setPositive(p_new_value);
  } else if (id == m_delay_time_identifier) {
    m_delay[0].setDelayTime(p_new_value);
    m_delay[1].setDelayTime(p_new_value);
  } else if (id == m_delay_feedback_identifier) {
    m_delay[0].setFeedback(p_new_value);
    m_delay[1].setFeedback(p_new_value);
  } else if (id == m_delay_hp_identifier) {
    m_delay[0].setHPFreq(p_new_value);
    m_delay[1].setHPFreq(p_new_value);
  } else if (id == m_delay_ducking_identifier) {
    m_delay[0].setDucking(p_new_value);
    m_delay[1].setDucking(p_new_value);
  } else if (id == m_delay_dry_identifier) {
    m_delay[0].setDry(p_new_value);
    m_delay[1].setDry(p_new_value);
  } else if (id == m_delay_wet_identifier) {
    m_delay[0].setWet(p_new_value);
    m_delay[1].setWet(p_new_value);
  } else if (id == m_phaser_amount_identifier) {
    m_phaser[0].setLFOAmplitude(p_new_value);
    m_phaser[1].setLFOAmplitude(p_new_value);
  } else if (id == m_phaser_frequency_identifier) {
    m_phaser[0].setLFOFreq(p_new_value);
    m_phaser[1].setLFOFreq(p_new_value);
  } else if (id == m_phaser_drywet_identifier) {
    m_phaser[0].setAmount(p_new_value);
    m_phaser[1].setAmount(p_new_value);
  } else if (id == m_flanger_amount_identifier) {
    m_flanger[0].setLFOAmount(p_new_value);
    m_flanger[1].setLFOAmount(p_new_value);
  } else if (id == m_flanger_frequency_identifier) {
    m_flanger[0].setLFOFreq(p_new_value);
    m_flanger[1].setLFOFreq(p_new_value);
  } else if (id == m_flanger_drywet_identifier) {
    m_flanger[0].setDryWet(p_new_value);
    m_flanger[1].setDryWet(p_new_value);
  } else if (id == m_chorus_amount_identifier) {
    m_chorus[0].setAmount(p_new_value);
    m_chorus[1].setAmount(p_new_value);
  } else if (id == m_chorus_frequency_identifier) {
    m_chorus[0].setLFOFreq(p_new_value);
    m_chorus[1].setLFOFreq(p_new_value);
  } else if (id == m_chorus_drywet_identifier) {
    m_chorus[0].setDryWet(p_new_value);
    m_chorus[1].setDryWet(p_new_value);
  } else if (id == m_env1_attack_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[0].setAttack(p_new_value);
    }
  } else if (id == m_env2_attack_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[1].setAttack(p_new_value);
    }
  } else if (id == m_env3_attack_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[2].setAttack(p_new_value);
    }
  } else if (id == m_env4_attack_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[3].setAttack(p_new_value);
    }
  }
  else if (id == m_env1_decay_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[0].setDecay(p_new_value);
    }
  } else if (id == m_env2_decay_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[1].setDecay(p_new_value);
    }
  } else if (id == m_env3_decay_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[2].setDecay(p_new_value);
    }
  } else if (id == m_env4_decay_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[3].setDecay(p_new_value);
    }
  } else if (id == m_env1_sustain_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[0].setSustain(p_new_value);
    }
  } else if (id == m_env2_sustain_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[1].setSustain(p_new_value);
    }
  } else if (id == m_env3_sustain_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[2].setSustain(p_new_value);
    }
  } else if (id == m_env4_sustain_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[3].setSustain(p_new_value);
    }
  } else if (id == m_env1_release_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[0].setRelease(p_new_value);
    }
  } else if (id == m_env2_release_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[1].setRelease(p_new_value);
    }
  } else if (id == m_env3_release_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[2].setRelease(p_new_value);
    }
  } else if (id == m_env4_release_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[3].setRelease(p_new_value);
    }
  } else if (id == m_env1_loop_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[0].setLoop(p_new_value);
    }
  } else if (id == m_env2_loop_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[1].setLoop(p_new_value);
    }
  } else if (id == m_env3_loop_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[2].setLoop(p_new_value);
    }
  } else if (id == m_env4_loop_identifier) {
    for (int voice = 0; voice < VOICES; ++voice) {
      m_voice[voice].env[3].setLoop(p_new_value);
    }
  }
  else if (id == m_osc1_vol_identifier) {
    m_osc_vol_control[0] = Decibels::decibelsToGain(p_new_value);
  }
  else if (id == m_osc2_vol_identifier) {
    m_osc_vol_control[1] = Decibels::decibelsToGain(p_new_value);
  }
  else if (id == m_osc3_vol_identifier) {
    m_osc_vol_control[2] = Decibels::decibelsToGain(p_new_value);
  }
  else if (id == m_fil1_gain_identifier) {
    m_fil_gain_control[0] = Decibels::decibelsToGain(p_new_value);
  }
  else if (id == m_fil2_gain_identifier) {
    m_fil_gain_control[1] = Decibels::decibelsToGain(p_new_value);
  }
  else if (id == m_fil3_gain_identifier) {
    m_fil_gain_control[2] = Decibels::decibelsToGain(p_new_value);
  }

  //modmatrix
  else if(id == m_amount_1_row_1_identifier){
    m_mod_matrix.setModAmount(0, p_new_value);
  }
  else if(id == m_source_row_1_identifier){
    m_mod_matrix.setModSource(0, p_new_value);
  }
  else if(id == m_dest_1_row_1_identifier){
    m_mod_matrix.setModDestination(0, p_new_value);
  }

}