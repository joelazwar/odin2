

{
  // Oscillator 1
  std::make_unique<AudioParameterInt>("osc1_oct", "Oscillator1 Octave", -3, 3,
                                      0),
      std::make_unique<AudioParameterInt>("osc1_semi", "Oscillator1 Semitones",
                                          -7, 7, 0),
      std::make_unique<AudioParameterFloat>(
          "osc1_fine", "Oscillator1 Finetune",
          NormalisableRange<float>(-50.0f, 50.0f), 0),
      std::make_unique<AudioParameterFloat>(
          "osc1_vol", "Oscillator1 Volume",
          NormalisableRange<float>(-20.0f, 12.0f), 0),
      std::make_unique<AudioParameterInt>("osc1_reset", "Oscillator1 Reset", 0,
                                          1, 0),
      std::make_unique<AudioParameterFloat>(
          "osc1_position", "Oscillator1 Position",
          NormalisableRange<float>(0.f, 1.f), 0),
      std::make_unique<AudioParameterFloat>("osc1_detune", "Oscillator1 Detune",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0),
      std::make_unique<AudioParameterFloat>(
          "osc1_multi_position", "Oscillator1 Multi Position",
          NormalisableRange<float>(0.f, 1.f), 0),
      std::make_unique<AudioParameterFloat>("osc1_spread", "Oscillator1 Spread",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0),
      std::make_unique<AudioParameterFloat>(
          "osc1_pulsewidth", "Oscillator1 PulseWidth",
          NormalisableRange<float>(0.f, 1.f), 0.5f),
      std::make_unique<AudioParameterFloat>("osc1_drift", "Oscillator1 Drift",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0.f),
      std::make_unique<AudioParameterFloat>(
          "osc1_vec_x", "Oscillator1 Vector X",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "osc1_vec_y", "Oscillator1 Vector Y",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "osc1_arp_speed", "Oscillator1 Arpeggiator Speed",
          NormalisableRange<float>(1.f, 60.f), 20.f),
      std::make_unique<AudioParameterInt>("osc1_step_1", "Oscillator1 Step1",
                                          -12, 12, 0),
      std::make_unique<AudioParameterInt>("osc1_step_2", "Oscillator1 Step2",
                                          -12, 12, 12),
      std::make_unique<AudioParameterInt>("osc1_step_3", "Oscillator1 Step3",
                                          -12, 12, 7),
      std::make_unique<AudioParameterInt>(
          "osc1_arp_on", "Oscillator1 Arpeggiator On", 0, 1, 0),
      std::make_unique<AudioParameterInt>("osc1_step_3_on",
                                          "Oscillator1 Step3 On", 0, 1, 0),
      std::make_unique<AudioParameterInt>("osc1_chipnoise",
                                          "Oscillator1 Chipnoise", 0, 1, 0),
      std::make_unique<AudioParameterInt>(
          "osc1_carrier_ratio", "Oscillator1 Carrier Ratio", 1, 12, 1),
      std::make_unique<AudioParameterInt>(
          "osc1_modulator_ratio", "Oscillator1 Modulator Ratio", 1, 12, 1),
      std::make_unique<AudioParameterInt>(
          "osc1_exp_fm", "Oscillator1 Exponential FM", 0, 1, 1),
      std::make_unique<AudioParameterFloat>("osc1_fm", "Oscillator1 FM amount",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0.f),
      std::make_unique<AudioParameterFloat>(
          "osc1_lp", "Oscillator1 Noise Lowpass",
          NormalisableRange<float>(80.f, 18000.f), 18000.f),
      std::make_unique<AudioParameterFloat>(
          "osc1_hp", "Oscillator1 Noise Highpass",
          NormalisableRange<float>(80.f, 18000.f), 80.f),
      // Oscillator 2
      std::make_unique<AudioParameterInt>("osc2_oct", "Oscillator2 Octave", -3,
                                          3, 0),
      std::make_unique<AudioParameterInt>("osc2_semi", "Oscillator2 Semitones",
                                          -7, 7, 0),
      std::make_unique<AudioParameterFloat>(
          "osc2_fine", "Oscillator2 Finetune",
          NormalisableRange<float>(-50.0f, 50.0f), 0),
      std::make_unique<AudioParameterFloat>(
          "osc2_vol", "Oscillator2 Volume",
          NormalisableRange<float>(-20.0f, 12.0f), 0),
      std::make_unique<AudioParameterInt>("osc2_reset", "Oscillator2 Reset", 0,
                                          1, 0),
      std::make_unique<AudioParameterFloat>(
          "osc2_position", "Oscillator2 Position",
          NormalisableRange<float>(0.f, 1.f), 0),
      std::make_unique<AudioParameterFloat>("osc2_detune", "Oscillator2 Detune",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0),
      std::make_unique<AudioParameterFloat>(
          "osc2_multi_position", "Oscillator2 Multi Position",
          NormalisableRange<float>(0.f, 1.f), 0),
      std::make_unique<AudioParameterFloat>("osc2_spread", "Oscillator2 Spread",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0),
      std::make_unique<AudioParameterFloat>(
          "osc2_pulsewidth", "Oscillator2 PulseWidth",
          NormalisableRange<float>(0.f, 1.f), 0.5f),
      std::make_unique<AudioParameterFloat>("osc2_drift", "Oscillator2 Drift",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0.f),
      std::make_unique<AudioParameterFloat>(
          "osc2_vec_x", "Oscillator2 Vector X",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "osc2_vec_y", "Oscillator2 Vector Y",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "osc2_arp_speed", "Oscillator2 Arpeggiator Speed",
          NormalisableRange<float>(1.f, 60.f), 20.f),
      std::make_unique<AudioParameterInt>("osc2_step_1", "Oscillator2 Step1",
                                          -12, 12, 0),
      std::make_unique<AudioParameterInt>("osc2_step_2", "Oscillator2 Step2",
                                          -12, 12, 12),
      std::make_unique<AudioParameterInt>("osc2_step_3", "Oscillator2 Step3",
                                          -12, 12, 7),
      std::make_unique<AudioParameterInt>(
          "osc2_arp_on", "Oscillator2 Arpeggiator On", 0, 1, 0),
      std::make_unique<AudioParameterInt>("osc2_step_3_on",
                                          "Oscillator2 Step3 On", 0, 1, 0),
      std::make_unique<AudioParameterInt>("osc2_chipnoise",
                                          "Oscillator2 Chipnoise", 0, 1, 0),
      std::make_unique<AudioParameterInt>(
          "osc2_carrier_ratio", "Oscillator2 Carrier Ratio", 1, 12, 1),
      std::make_unique<AudioParameterInt>(
          "osc2_modulator_ratio", "Oscillator2 Modulator Ratio", 1, 12, 1),
      std::make_unique<AudioParameterInt>(
          "osc2_exp_fm", "Oscillator2 Exponential FM", 0, 1, 1),
      std::make_unique<AudioParameterFloat>("osc2_fm", "Oscillator2 FM amount",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0.f),
      std::make_unique<AudioParameterFloat>(
          "osc2_lp", "Oscillator2 Noise Lowpass",
          NormalisableRange<float>(80.f, 18000.f), 18000.f),
      std::make_unique<AudioParameterFloat>(
          "osc2_hp", "Oscillator2 Noise Highpass",
          NormalisableRange<float>(80.f, 18000.f), 80.f),
      // Oscillator 3
      std::make_unique<AudioParameterInt>("osc3_oct", "Oscillator3 Octave", -3,
                                          3, 0),
      std::make_unique<AudioParameterInt>("osc3_semi", "Oscillator3 Semitones",
                                          -7, 7, 0),
      std::make_unique<AudioParameterFloat>(
          "osc3_fine", "Oscillator3 Finetune",
          NormalisableRange<float>(-50.0f, 50.0f), 0),
      std::make_unique<AudioParameterFloat>(
          "osc3_vol", "Oscillator3 Volume",
          NormalisableRange<float>(-20.0f, 12.0f), 0),
      std::make_unique<AudioParameterInt>("osc3_reset", "Oscillator3 Reset", 0,
                                          1, 0),
      std::make_unique<AudioParameterFloat>(
          "osc3_position", "Oscillator3 Position",
          NormalisableRange<float>(0.f, 1.f), 0),
      std::make_unique<AudioParameterFloat>("osc3_detune", "Oscillator3 Detune",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0),
      std::make_unique<AudioParameterFloat>(
          "osc3_multi_position", "Oscillator3 Multi Position",
          NormalisableRange<float>(0.f, 1.f), 0),
      std::make_unique<AudioParameterFloat>("osc3_spread", "Oscillator3 Spread",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0),
      std::make_unique<AudioParameterFloat>(
          "osc3_pulsewidth", "Oscillator3 PulseWidth",
          NormalisableRange<float>(0.f, 1.f), 0.5f),
      std::make_unique<AudioParameterFloat>("osc3_drift", "Oscillator3 Drift",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0.f),
      std::make_unique<AudioParameterFloat>(
          "osc3_vec_x", "Oscillator3 Vector X",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "osc3_vec_y", "Oscillator3 Vector Y",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "osc3_arp_speed", "Oscillator3 Arpeggiator Speed",
          NormalisableRange<float>(1.f, 60.f), 20.f),
      std::make_unique<AudioParameterInt>("osc3_step_1", "Oscillator3 Step1",
                                          -12, 12, 0),
      std::make_unique<AudioParameterInt>("osc3_step_2", "Oscillator3 Step2",
                                          -12, 12, 12),
      std::make_unique<AudioParameterInt>("osc3_step_3", "Oscillator3 Step3",
                                          -12, 12, 7),
      std::make_unique<AudioParameterInt>(
          "osc3_arp_on", "Oscillator3 Arpeggiator On", 0, 1, 0),
      std::make_unique<AudioParameterInt>("osc3_step_3_on",
                                          "Oscillator3 Step3 On", 0, 1, 0),
      std::make_unique<AudioParameterInt>("osc3_chipnoise",
                                          "Oscillator3 Chipnoise", 0, 1, 0),
      std::make_unique<AudioParameterInt>(
          "osc3_carrier_ratio", "Oscillator3 Carrier Ratio", 1, 12, 1),
      std::make_unique<AudioParameterInt>(
          "osc3_modulator_ratio", "Oscillator3 Modulator Ratio", 1, 12, 1),
      std::make_unique<AudioParameterInt>(
          "osc3_exp_fm", "Oscillator3 Exponential FM", 0, 1, 1),
      std::make_unique<AudioParameterFloat>("osc3_fm", "Oscillator3 FM amount",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0.f),
      std::make_unique<AudioParameterFloat>(
          "osc3_lp", "Oscillator3 Noise Lowpass",
          NormalisableRange<float>(80.f, 18000.f), 18000.f),
      std::make_unique<AudioParameterFloat>(
          "osc3_hp", "Oscillator3 Noise Highpass",
          NormalisableRange<float>(80.f, 18000.f), 80.f),
      // Filter1
      std::make_unique<AudioParameterInt>("fil1_osc1", "Filter1 Osc1 Input", 0,
                                          1, 1),
      std::make_unique<AudioParameterInt>("fil1_osc2", "Filter1 Osc2 Input", 0,
                                          1, 1),
      std::make_unique<AudioParameterInt>("fil1_osc3", "Filter1 Osc3 Input", 0,
                                          1, 1),
      std::make_unique<AudioParameterFloat>(
          "fil1_vel", "Filter1 Velocity Amount",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil1_env", "Filter1 Envelope Amount",
          NormalisableRange<float>(-1.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil1_kbd", "Filter1 Keyboard Follow",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil1_gain", "Filter1 Gain", NormalisableRange<float>(-12.f, 12.f),
          0.f),
      std::make_unique<AudioParameterFloat>(
          "fil1_freq", "Filter1 Frequency",
          NormalisableRange<float>(80.f, 18000.f), 2000.f),
      std::make_unique<AudioParameterFloat>("fil1_res", "Filter1 Resonance",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0.f),
      std::make_unique<AudioParameterFloat>(
          "fil1_saturation", "Filter1 Saturation",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil1_sem_transition", "Filter1 SEM Transition",
          NormalisableRange<float>(-1.f, 1.f), -1.f),
      std::make_unique<AudioParameterFloat>(
          "fil1_formant_transition", "Filter1 Formant Transition",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterInt>("fil1_vowel_left",
                                          "Filter1 Left Vowel", 0, 7, 0),
      std::make_unique<AudioParameterInt>("fil1_vowel_right",
                                          "Filter1 Right Vowel", 0, 7, 2),
      std::make_unique<AudioParameterInt>("fil1_comb_polarity",
                                          "Filter1 Comb Polarity", 0, 1, 0),
      // Filter2
      std::make_unique<AudioParameterInt>("fil2_osc1", "Filter2 Osc1 Input", 0,
                                          1, 0),
      std::make_unique<AudioParameterInt>("fil2_osc2", "Filter2 Osc2 Input", 0,
                                          1, 0),
      std::make_unique<AudioParameterInt>("fil2_osc3", "Filter2 Osc3 Input", 0,
                                          1, 0),
      std::make_unique<AudioParameterInt>("fil2_fil1", "Filter2 Filter1 Input",
                                          0, 1, 1),
      std::make_unique<AudioParameterFloat>(
          "fil2_vel", "Filter2 Velocity Amount",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil2_env", "Filter2 Envelope Amount",
          NormalisableRange<float>(-1.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil2_kbd", "Filter2 Keyboard Follow",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil2_gain", "Filter2 Gain", NormalisableRange<float>(-12.f, 12.f),
          0.f),
      std::make_unique<AudioParameterFloat>(
          "fil2_freq", "Filter2 Frequency",
          NormalisableRange<float>(80.f, 18000.f), 2000.f),
      std::make_unique<AudioParameterFloat>("fil2_res", "Filter2 Resonance",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0.f),
      std::make_unique<AudioParameterFloat>(
          "fil2_saturation", "Filter2 Saturation",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil2_sem_transition", "Filter2 SEM Transition",
          NormalisableRange<float>(-1.f, 1.f), -1.f),
      std::make_unique<AudioParameterFloat>(
          "fil2_formant_transition", "Filter2 Formant Transition",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterInt>("fil2_vowel_left",
                                          "Filter2 Left Vowel", 0, 7, 0),
      std::make_unique<AudioParameterInt>("fil2_vowel_right",
                                          "Filter2 Right Vowel", 0, 7, 2),
      std::make_unique<AudioParameterInt>("fil2_comb_polarity",
                                          "Filter2 Comb Polarity", 0, 1, 0),
      // Filter3
      std::make_unique<AudioParameterFloat>(
          "fil3_vel", "Filter3 Velocity Amount",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil3_env", "Filter3 Envelope Amount",
          NormalisableRange<float>(-1.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil3_kbd", "Filter3 Keyboard Follow",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil3_gain", "Filter3 Gain", NormalisableRange<float>(-12.f, 12.f),
          0.f),
      std::make_unique<AudioParameterFloat>(
          "fil3_freq", "Filter3 Frequency",
          NormalisableRange<float>(80.f, 18000.f), 2000.f),
      std::make_unique<AudioParameterFloat>("fil3_res", "Filter3 Resonance",
                                            NormalisableRange<float>(0.f, 1.f),
                                            0.f),
      std::make_unique<AudioParameterFloat>(
          "fil3_saturation", "Filter3 Saturation",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>(
          "fil3_sem_transition", "Filter3 SEM Transition",
          NormalisableRange<float>(-1.f, 1.f), -1.f),
      std::make_unique<AudioParameterFloat>(
          "fil3_formant_transition", "Filter3 Formant Transition",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterInt>("fil3_vowel_left",
                                          "Filter3 Left Vowel", 0, 7, 0),
      std::make_unique<AudioParameterInt>("fil3_vowel_right",
                                          "Filter3 Right Vowel", 0, 7, 2),
      std::make_unique<AudioParameterInt>("fil3_comb_polarity",
                                          "Filter3 Comb Polarity", 0, 1, 0),
      // Amp
      std::make_unique<AudioParameterFloat>(
          "amp_vel", "Amplifier Velocity Amount",
          NormalisableRange<float>(0.f, 1.f), 0.f),
      std::make_unique<AudioParameterFloat>("amp_pan", "Amplifier Panorama",
                                            NormalisableRange<float>(-1.f, 1.f),
                                            0.f),
      std::make_unique<AudioParameterFloat>(
          "amp_gain", "Amplifier Gain", NormalisableRange<float>(-20.f, 12.f),
          0.f),
      // Distortion
      std::make_unique<AudioParameterFloat>(
          "dist_threshold", "Distortion Threshold",
          NormalisableRange<float>(0.f, 1.f), 0.7f),
      std::make_unique<AudioParameterFloat>("dist_drywet", "Distortion DryWet",
                                            NormalisableRange<float>(0.f, 1.f),
                                            1.f),
      std::make_unique<AudioParameterInt>("dist_on", "Distortion Enable", 0, 1,
                                          0),
      // ADSR1
      std::make_unique<AudioParameterFloat>(
          "env1_attack", "AmpEnv Attack",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 0.01f),
      std::make_unique<AudioParameterFloat>(
          "env1_decay", "AmpEnv Decay",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 1.f),
      std::make_unique<AudioParameterFloat>(
          "env1_sustain", "AmpEnv Sustain",
          NormalisableRange<float>(0.f, 1.f, 0.f, 0.575717), 0.5f),
      std::make_unique<AudioParameterFloat>(
          "env1_release", "AmpEnv Release",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 0.01f),
      std::make_unique<AudioParameterInt>("env1_loop", "AmpEnv Loop", 0, 1, 0),
      // ADSR2
      std::make_unique<AudioParameterFloat>(
          "env2_attack", "FilterEnv Attack",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 0.01f),
      std::make_unique<AudioParameterFloat>(
          "env2_decay", "FilterEnv Decay",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 1.f),
      std::make_unique<AudioParameterFloat>(
          "env2_sustain", "FilterEnv Sustain",
          NormalisableRange<float>(0.f, 1.f, 0.f, 0.575717), 0.5f),
      std::make_unique<AudioParameterFloat>(
          "env2_release", "FilterEnv Release",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 0.01f),
      std::make_unique<AudioParameterInt>("env2_loop", "FilterEnv Loop", 0, 1,
                                          0),
      // ADSR3
      std::make_unique<AudioParameterFloat>(
          "env3_attack", "ModEnv Attack",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 0.01f),
      std::make_unique<AudioParameterFloat>(
          "env3_decay", "ModEnv Decay",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 1.f),
      std::make_unique<AudioParameterFloat>(
          "env3_sustain", "ModEnv Sustain",
          NormalisableRange<float>(0.f, 1.f, 0.f, 0.575717), 0.5f),
      std::make_unique<AudioParameterFloat>(
          "env3_release", "ModEnv Release",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 0.01f),
      std::make_unique<AudioParameterInt>("env3_loop", "ModEnv Loop", 0, 1, 0),
      // ADSR4
      std::make_unique<AudioParameterFloat>(
          "env4_attack", "GlobalEnv Attack",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 0.01f),
      std::make_unique<AudioParameterFloat>(
          "env4_decay", "GlobalEnv Decay",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 1.f),
      std::make_unique<AudioParameterFloat>(
          "env4_sustain", "GlobalEnv Sustain",
          NormalisableRange<float>(0.f, 1.f, 0.f, 0.575717), 0.5f),
      std::make_unique<AudioParameterFloat>(
          "env4_release", "GlobalEnv Release",
          NormalisableRange<float>(0.001f, 10.f, 0.f, 0.300912), 0.01f),
      std::make_unique<AudioParameterInt>("env4_loop", "GlobalEnv Loop", 0, 1,
                                          0),
      // LFO1
      std::make_unique<AudioParameterInt>("lfo1_reset", "LFO1 Reset", 0, 1, 0),
      std::make_unique<AudioParameterInt>("lfo1_sync", "LFO1 Sync", 0, 1, 0),
      std::make_unique<AudioParameterInt>("lfo1_wave", "LFO1 Waveform", 0, 20,
                                          0),
      std::make_unique<AudioParameterFloat>(
          "lfo1_freq", "LFO1 Frequency",
          NormalisableRange<float>(0.05f, 100.f, 0.f, 0.196757), 1),
      // LFO2
      std::make_unique<AudioParameterInt>("lfo2_reset", "LFO2 Reset", 0, 1, 0),
      std::make_unique<AudioParameterInt>("lfo2_sync", "LFO2 Sync", 0, 1, 0),
      std::make_unique<AudioParameterInt>("lfo2_wave", "LFO2 Waveform", 0, 20,
                                          0),
      std::make_unique<AudioParameterFloat>(
          "lfo2_freq", "LFO2 Frequency",
          NormalisableRange<float>(0.05f, 100.f, 0.f, 0.196757), 1),
      // LFO3
      std::make_unique<AudioParameterInt>("lfo3_reset", "LFO3 Reset", 0, 1, 0),
      std::make_unique<AudioParameterInt>("lfo3_sync", "LFO3 Sync", 0, 1, 0),
      std::make_unique<AudioParameterInt>("lfo3_wave", "LFO3 Waveform", 0, 20,
                                          0),
      std::make_unique<AudioParameterFloat>(
          "lfo3_freq", "LFO3 Frequency",
          NormalisableRange<float>(0.05f, 100.f, 0.f, 0.196757), 1),
      // LFO4
      std::make_unique<AudioParameterInt>("lfo4_reset", "LFO4 Reset", 0, 1, 0),
      std::make_unique<AudioParameterInt>("lfo4_sync", "LFO4 Sync", 0, 1, 0),
      std::make_unique<AudioParameterInt>("lfo4_wave", "LFO4 Waveform", 0, 20,
                                          0),
      std::make_unique<AudioParameterFloat>(
          "lfo4_freq", "LFO4 Frequency",
          NormalisableRange<float>(0.05f, 100.f, 0.f, 0.196757), 1),
      // Misc
      std::make_unique<AudioParameterInt>("fil1_to_amp", "Filter1 To Amplifier",
                                          0, 1, 0),
      std::make_unique<AudioParameterInt>("fil2_to_amp", "Filter2 To Amplifier",
                                          0, 1, 1),
      std::make_unique<AudioParameterFloat>("glide", "Glide", 0.f, 1.f, 0.f),
      std::make_unique<AudioParameterFloat>("master", "Master", -20.f, 12.f,
                                            0.f),
      std::make_unique<AudioParameterFloat>("modwheel", "Modwheel", 0.f, 1.f,
                                            0.f),
      std::make_unique<AudioParameterFloat>("pitchbend", "Pitchbend", -1.f, 1.f,
                                            0.f),
      std::make_unique<AudioParameterInt>("pitchbend_amount",
                                          "Pitchbend Semitones", 0, 24, 12),
      std::make_unique<AudioParameterFloat>("xy_x", "XY Pad X", 0.f, 1.f, 0.f),
      std::make_unique<AudioParameterFloat>("xy_y", "XY Pad Y", 0.f, 1.f, 0.f),
      std::make_unique<AudioParameterInt>("delay_sync", "Delay Sync", 0, 1, 0),
      std::make_unique<AudioParameterFloat>(
          "delay_time", "Delay Time",
          NormalisableRange<float>(0.01f, 3.f, 0.f, 0.627099), 1.f),
      std::make_unique<AudioParameterFloat>("delay_feedback", "Delay Feedback",
                                            0.f, 1.f, 0.6f),
      std::make_unique<AudioParameterFloat>(
          "delay_hp", "Delay Highpass Frequency", 80.f, 18000.f, 80.f),
      std::make_unique<AudioParameterFloat>("delay_ducking", "Delay Ducking",
                                            0.f, 1.f, 0.f),
      std::make_unique<AudioParameterFloat>("delay_dry", "Delay Dry", 0.f, 1.f,
                                            1.f),
      std::make_unique<AudioParameterFloat>("delay_wet", "Delay Wet", 0.f, 1.f,
                                            0.8f),
      std::make_unique<AudioParameterInt>("delay_on", "Delay On", 0, 1, 0),

      // Phaser
      std::make_unique<AudioParameterInt>("phaser_sync", "Phaser Sync", 0, 1,
                                          0),
      std::make_unique<AudioParameterInt>("phaser_reset", "Phaser Reset", 0, 1,
                                          0),
      std::make_unique<AudioParameterInt>("phaser_on", "Phaser On", 0, 1, 0),
      std::make_unique<AudioParameterFloat>("phaser_freq", "Phaser Frequency",
                                            400, 8000, 4000),
      std::make_unique<AudioParameterFloat>("phaser_feedback",
                                            "Phaser Feedback", 0, 1, 0.25f),
      std::make_unique<AudioParameterFloat>("phaser_rate", "Phaser Rate", 0.05f,
                                            20.f, 0.25f),
      std::make_unique<AudioParameterFloat>("phaser_mod", "Phaser Amount", 0.f,
                                            1.f, 0.3f),
      std::make_unique<AudioParameterFloat>("phaser_drywet", "Phaser DryWet",
                                            0.f, 1.f, 1.f),
      // Flanger
      std::make_unique<AudioParameterInt>("flanger_sync", "Flanger Sync", 0, 1,
                                          0),
      std::make_unique<AudioParameterInt>("flanger_reset", "Flanger Reset", 0,
                                          1, 0),
      std::make_unique<AudioParameterInt>("flanger_on", "Flanger On", 0, 1, 0),

      std::make_unique<AudioParameterFloat>("flanger_rate", "Flanger Rate",
                                            0.05f, 20.f, 0.2f),
      std::make_unique<AudioParameterFloat>(
          "flanger_feedback", "Flanger Feedback", -1.f, 1.f, 0.6f),
      std::make_unique<AudioParameterFloat>("flanger_amount", "Flanger Amount",
                                            0.f, 1.f, 0.3f),
      std::make_unique<AudioParameterFloat>("flanger_drywet", "Flanger DryWet",
                                            0.f, 1.f, 1.f),
      std::make_unique<AudioParameterInt>("chorus_sync", "Chorus Sync", 0, 1,
                                          0),
      std::make_unique<AudioParameterInt>("chorus_reset", "Chorus Reset", 0, 1,
                                          0),
      std::make_unique<AudioParameterInt>("chorus_on", "Chorus On", 0, 1, 0),

      std::make_unique<AudioParameterFloat>("chorus_rate", "Chorus Frequency",
                                            0.05f, 20.f, 0.2f),
      std::make_unique<AudioParameterFloat>("chorus_amount", "Chorus Amount",
                                            0.f, 1.f, 0.3f),
      std::make_unique<AudioParameterFloat>("chorus_feedback",
                                            "Chorus Feedback", -1.f, 1.f, 0.f),
      std::make_unique<AudioParameterFloat>("chorus_drywet", "Chorus DryWet",
                                            0.f, 1.f, 1.f),

      // ModMatrix
      std::make_unique<AudioParameterFloat>("amount_1_[0]", "row1_dest1_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_2_[0]", "row1_dest2_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_3_[0]", "row1_scale_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_1_[1]", "row2_dest1_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_2_[1]", "row2_dest2_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_3_[1]", "row2_scale_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_1_[2]", "row3_dest1_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_2_[2]", "row3_dest2_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_3_[2]", "row3_scale_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_1_[3]", "row4_dest1_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_2_[3]", "row4_dest2_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_3_[3]", "row4_scale_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_1_[4]", "row5_dest1_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_2_[4]", "row5_dest2_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_3_[4]", "row5_scale_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_1_[5]", "row6_dest1_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_2_[5]", "row6_dest2_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_3_[5]", "row6_scale_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_1_[6]", "row7_dest1_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_2_[6]", "row7_dest2_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_3_[6]", "row7_scale_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_1_[7]", "row8_dest1_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_2_[7]", "row8_dest2_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_3_[7]", "row8_scale_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_1_[8]", "row9_dest1_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_2_[8]", "row9_dest2_amount",
                                            -1, 1, 0),
      std::make_unique<AudioParameterFloat>("amount_3_[8]", "row9_scale_amount",
                                            -1, 1, 0),

  // include geneerated code for drawtables
  // #include "GeneratedAudioValueCode.h"
}
