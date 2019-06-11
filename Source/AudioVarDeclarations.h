/*
  ==============================================================================

    AudioVarDeclarations.h
    Created: 5 Apr 2019 9:30:01pm
    Author:  frot

  ==============================================================================
*/

#pragma once
//osc1
    float* m_osc_type[3];
    float* m_osc_oct[3];
    float* m_osc_semi[3];
    float* m_osc_fine[3];
    float* m_osc_vol[3];
    float* m_osc_position[3];
    float* m_osc_detune[3];
    float* m_osc_multi_position[3];
    float* m_osc_spread[3];
    float* m_osc_pulsewidth[3];
    float* m_osc_drift[3];
    float* m_osc_arp_speed[3];
    float* m_osc_step_1[3];
    float* m_osc_step_2[3];
    float* m_osc_step_3[3];
    float* m_osc_fm[3];
    float* m_osc_carrier_ratio[3];
    float* m_osc_modulator_ratio[3];
    float* m_osc_carrier_wave[3];
    float* m_osc_modulator_wave[3];
    float* m_osc_lp[3];
    float* m_osc_hp[3];
    float* m_osc_reset[3];
    float* m_osc_arp_on[3];
    float* m_osc_step_3_on[3];
    float* m_osc_chipnoise[3];
    float* m_osc_chipwave[3];
    float* m_osc_exp_fm[3];
    float* m_osc_vec_a[3];
    float* m_osc_vec_b[3];
    float* m_osc_vec_c[3];
    float* m_osc_vec_d[3];
    float* m_osc_vec_x[3];
    float* m_osc_vec_y[3];
    float* m_osc_wavetable[3];
    
    //filters
    float* m_fil_type[3];
    float* m_fil_vel[3];
    float* m_fil_kbd[3];
    float* m_fil_env[3];
    float* m_fil_gain[3];
    float* m_fil_freq[3];
    float* m_fil_res[3];
    float* m_fil_saturation[3];
    float* m_fil_formant_transition[3];
    float* m_fil_sem_transition[3];
    float* m_fil_vowel_left[3];
    float* m_fil_vowel_right[3];
    float* m_fil_comb_polarity[3];

    //midsection
    float* m_amp_pan;
    float* m_amp_gain;
    float* m_amp_vel;
    float* m_dist_threshold;
    float* m_dist_drywet;
    float* m_dist_on;
    float* m_fil1_to_amp;
    float* m_fil2_to_amp;
    //env1
    float* m_env1_attack;
    float* m_env1_decay;
    float* m_env1_sustain;
    float* m_env1_release;
    float* m_env1_loop;
    //env2
    float* m_env2_attack;
    float* m_env2_decay;
    float* m_env2_sustain;
    float* m_env2_release;
    float* m_env2_loop;
    //env3
    float* m_env3_attack;
    float* m_env3_decay;
    float* m_env3_sustain;
    float* m_env3_release;
    float* m_env3_loop;
    //env4
    float* m_env4_attack;
    float* m_env4_decay;
    float* m_env4_sustain;
    float* m_env4_release;
    float* m_env4_loop;
    //lfo1
    float* m_lfo1_freq;
    float* m_lfo1_reset;
    float* m_lfo1_sync;
    float* m_lfo1_wave;
    //lfo2
    float* m_lfo2_freq;
    float* m_lfo2_reset;
    float* m_lfo2_sync;
    float* m_lfo2_wave;
    //lfo3
    float* m_lfo3_freq;
    float* m_lfo3_reset;
    float* m_lfo3_sync;
    float* m_lfo3_wave;
    //lfo4
    float* m_lfo4_freq;
    float* m_lfo4_reset;
    float* m_lfo4_sync;
    float* m_lfo4_wave;
    //main
    float* m_glide;
    float* m_master;
    float* m_modwheel;
    float* m_pitchbend;
    float* m_pitchbend_amount;
    float* m_xy_x;
    float* m_xy_y;
    float* m_delay_on;
    float* m_phaser_on;
    float* m_flanger_on;
    float* m_chorus_on;
    float* m_fil_osc1[2];
    float* m_fil_osc2[2];
    float* m_fil_osc3[2];
    float* m_fil2_fil1;
    //delay
    float* m_delay_time;
    float* m_delay_feedback;
    float* m_delay_hp;
    float* m_delay_ducking;
    float* m_delay_dry;
    float* m_delay_wet;
    float* m_delay_sync;
    //phaser
    float* m_phaser_reset;
    float* m_phaser_sync;
    float* m_phaser_rate;
    float* m_phaser_freq;
    float* m_phaser_feedback;
    float* m_phaser_mod;
    float* m_phaser_drywet;
    //flanger
    float* m_flanger_reset;
    float* m_flanger_sync;
    float* m_flanger_rate;
    float* m_flanger_amount;
    float* m_flanger_drywet;
    float* m_flanger_feedback;
    //chorus
    float* m_chorus_reset;
    float* m_chorus_sync;
    float* m_chorus_rate;
    float* m_chorus_amount;
    float* m_chorus_feedback;
    float* m_chorus_drywet;
    //modmatrix
    float* m_amount_1[9];
    float* m_amount_2[9];
    float* m_amount_3[9];

//============================================================================
//============================================================================
//============================================================================
//============================================================================
//=============================      IDENTIFIER        =======================
//============================================================================
//============================================================================
//============================================================================
//============================================================================


    Identifier m_osc1_type_identifier;
    Identifier m_osc2_type_identifier;
    Identifier m_osc3_type_identifier;
    Identifier m_osc1_oct_identifier;
    Identifier m_osc2_oct_identifier;
    Identifier m_osc3_oct_identifier;
    Identifier m_osc1_semi_identifier;
    Identifier m_osc2_semi_identifier;
    Identifier m_osc3_semi_identifier;
    Identifier m_osc1_fine_identifier;
    Identifier m_osc2_fine_identifier;
    Identifier m_osc3_fine_identifier;
    Identifier m_osc1_analog_wave_identifier;
    Identifier m_osc2_analog_wave_identifier;
    Identifier m_osc3_analog_wave_identifier;
    Identifier m_osc1_vol_identifier;
    Identifier m_osc2_vol_identifier;
    Identifier m_osc3_vol_identifier;
    Identifier m_osc1_position_identifier;
    Identifier m_osc2_position_identifier;
    Identifier m_osc3_position_identifier;
    Identifier m_osc1_detune_identifier;
    Identifier m_osc2_detune_identifier;
    Identifier m_osc3_detune_identifier;
    Identifier m_osc1_multi_position_identifier;
    Identifier m_osc2_multi_position_identifier;
    Identifier m_osc3_multi_position_identifier;
    Identifier m_osc1_spread_identifier;
    Identifier m_osc2_spread_identifier;
    Identifier m_osc3_spread_identifier;
    Identifier m_osc1_pulsewidth_identifier;
    Identifier m_osc2_pulsewidth_identifier;
    Identifier m_osc3_pulsewidth_identifier;
    Identifier m_osc1_drift_identifier;
    Identifier m_osc2_drift_identifier;
    Identifier m_osc3_drift_identifier;
    Identifier m_osc1_arp_speed_identifier;
    Identifier m_osc2_arp_speed_identifier;
    Identifier m_osc3_arp_speed_identifier;
    Identifier m_osc1_step_1_identifier;
    Identifier m_osc2_step_1_identifier;
    Identifier m_osc3_step_1_identifier;
    Identifier m_osc1_step_2_identifier;
    Identifier m_osc2_step_2_identifier;
    Identifier m_osc3_step_2_identifier;
    Identifier m_osc1_step_3_identifier;
    Identifier m_osc2_step_3_identifier;
    Identifier m_osc3_step_3_identifier;
    Identifier m_osc1_fm_identifier;
    Identifier m_osc2_fm_identifier;
    Identifier m_osc3_fm_identifier;
    Identifier m_osc1_carrier_ratio_identifier;
    Identifier m_osc2_carrier_ratio_identifier;
    Identifier m_osc3_carrier_ratio_identifier;
    Identifier m_osc1_modulator_ratio_identifier;
    Identifier m_osc2_modulator_ratio_identifier;
    Identifier m_osc3_modulator_ratio_identifier;
    Identifier m_osc1_carrier_wave_identifier;
    Identifier m_osc2_carrier_wave_identifier;
    Identifier m_osc3_carrier_wave_identifier;
    Identifier m_osc1_modulator_wave_identifier;
    Identifier m_osc2_modulator_wave_identifier;
    Identifier m_osc3_modulator_wave_identifier;
    Identifier m_osc1_lp_identifier;
    Identifier m_osc2_lp_identifier;
    Identifier m_osc3_lp_identifier;
    Identifier m_osc1_hp_identifier;
    Identifier m_osc2_hp_identifier;
    Identifier m_osc3_hp_identifier;
    Identifier m_osc1_reset_identifier;
    Identifier m_osc2_reset_identifier;
    Identifier m_osc3_reset_identifier;
    Identifier m_osc1_arp_on_identifier;
    Identifier m_osc2_arp_on_identifier;
    Identifier m_osc3_arp_on_identifier;
    Identifier m_osc1_step_3_on_identifier;
    Identifier m_osc2_step_3_on_identifier;
    Identifier m_osc3_step_3_on_identifier;
    Identifier m_osc1_chipnoise_identifier;
    Identifier m_osc2_chipnoise_identifier;
    Identifier m_osc3_chipnoise_identifier;
    Identifier m_osc1_chipwave_identifier;
    Identifier m_osc2_chipwave_identifier;
    Identifier m_osc3_chipwave_identifier;
    Identifier m_osc1_exp_fm_identifier;
    Identifier m_osc2_exp_fm_identifier;
    Identifier m_osc3_exp_fm_identifier;
    Identifier m_osc1_vec_a_identifier;
    Identifier m_osc2_vec_a_identifier;
    Identifier m_osc3_vec_a_identifier;
    Identifier m_osc1_vec_b_identifier;
    Identifier m_osc2_vec_b_identifier;
    Identifier m_osc3_vec_b_identifier;
    Identifier m_osc1_vec_c_identifier;
    Identifier m_osc2_vec_c_identifier;
    Identifier m_osc3_vec_c_identifier;
    Identifier m_osc1_vec_d_identifier;
    Identifier m_osc2_vec_d_identifier;
    Identifier m_osc3_vec_d_identifier;
    Identifier m_osc1_vec_x_identifier;
    Identifier m_osc2_vec_x_identifier;
    Identifier m_osc3_vec_x_identifier;
    Identifier m_osc1_vec_y_identifier;
    Identifier m_osc2_vec_y_identifier;
    Identifier m_osc3_vec_y_identifier;
    Identifier m_osc1_wavetable_identifier;
    Identifier m_osc2_wavetable_identifier;
    Identifier m_osc3_wavetable_identifier;
    Identifier m_fil1_type_identifier;
    Identifier m_fil2_type_identifier;
    Identifier m_fil3_type_identifier;
    Identifier m_fil1_vel_identifier;
    Identifier m_fil2_vel_identifier;
    Identifier m_fil3_vel_identifier;
    Identifier m_fil1_env_identifier;
    Identifier m_fil2_env_identifier;
    Identifier m_fil3_env_identifier;
    Identifier m_fil1_kbd_identifier;
    Identifier m_fil2_kbd_identifier;
    Identifier m_fil3_kbd_identifier;
    Identifier m_fil1_gain_identifier;
    Identifier m_fil2_gain_identifier;
    Identifier m_fil3_gain_identifier;
    Identifier m_fil1_freq_identifier;
    Identifier m_fil2_freq_identifier;
    Identifier m_fil3_freq_identifier;
    Identifier m_fil1_res_identifier;
    Identifier m_fil2_res_identifier;
    Identifier m_fil3_res_identifier;
    Identifier m_fil1_saturation_identifier;
    Identifier m_fil2_saturation_identifier;
    Identifier m_fil3_saturation_identifier;
    Identifier m_fil1_formant_transition_identifier;
    Identifier m_fil2_formant_transition_identifier;
    Identifier m_fil3_formant_transition_identifier;
    Identifier m_fil1_sem_transition_identifier;
    Identifier m_fil2_sem_transition_identifier;
    Identifier m_fil3_sem_transition_identifier;
    Identifier m_fil1_vowel_left_identifier;
    Identifier m_fil2_vowel_left_identifier;
    Identifier m_fil3_vowel_left_identifier;
    Identifier m_fil1_vowel_right_identifier;
    Identifier m_fil2_vowel_right_identifier;
    Identifier m_fil3_vowel_right_identifier;
    Identifier m_fil1_comb_polarity_identifier;
    Identifier m_fil2_comb_polarity_identifier;
    Identifier m_fil3_comb_polarity_identifier;
    Identifier m_amp_pan_identifier;
    Identifier m_amp_gain_identifier;
    Identifier m_amp_vel_identifier;
    Identifier m_dist_threshold_identifier;
    Identifier m_dist_drywet_identifier;
    Identifier m_dist_on_identifier;
    Identifier m_dist_algo_identifier;
    Identifier m_fil1_to_amp_identifier;
    Identifier m_fil2_to_amp_identifier;
    Identifier m_env1_attack_identifier;
    Identifier m_env1_decay_identifier;
    Identifier m_env1_sustain_identifier;
    Identifier m_env1_release_identifier;
    Identifier m_env1_loop_identifier;
    Identifier m_env2_attack_identifier;
    Identifier m_env2_decay_identifier;
    Identifier m_env2_sustain_identifier;
    Identifier m_env2_release_identifier;
    Identifier m_env2_loop_identifier;
    Identifier m_env3_attack_identifier;
    Identifier m_env3_decay_identifier;
    Identifier m_env3_sustain_identifier;
    Identifier m_env3_release_identifier;
    Identifier m_env3_loop_identifier;
    Identifier m_env4_attack_identifier;
    Identifier m_env4_decay_identifier;
    Identifier m_env4_sustain_identifier;
    Identifier m_env4_release_identifier;
    Identifier m_env4_loop_identifier;
    Identifier m_lfo1_freq_identifier;
    Identifier m_lfo1_reset_identifier;
    Identifier m_lfo1_sync_identifier;
    Identifier m_lfo1_wave_identifier;
    Identifier m_lfo1_synctime_numerator_identifier;
    Identifier m_lfo1_synctime_denominator_identifier;
    Identifier m_lfo2_freq_identifier;
    Identifier m_lfo2_reset_identifier;
    Identifier m_lfo2_sync_identifier;
    Identifier m_lfo2_wave_identifier;
    Identifier m_lfo2_synctime_numerator_identifier;
    Identifier m_lfo2_synctime_denominator_identifier;
    Identifier m_lfo3_freq_identifier;
    Identifier m_lfo3_reset_identifier;
    Identifier m_lfo3_sync_identifier;
    Identifier m_lfo3_wave_identifier;
    Identifier m_lfo3_synctime_numerator_identifier;
    Identifier m_lfo3_synctime_denominator_identifier;
    Identifier m_lfo4_freq_identifier;
    Identifier m_lfo4_reset_identifier;
    Identifier m_lfo4_sync_identifier;
    Identifier m_lfo4_wave_identifier;
    Identifier m_lfo4_synctime_numerator_identifier;
    Identifier m_lfo4_synctime_denominator_identifier;
    Identifier m_glide_identifier;
    Identifier m_master_identifier;
    Identifier m_modwheel_identifier;
    Identifier m_pitchbend_identifier;
    Identifier m_pitchbend_amount_identifier;
    Identifier m_xy_x_identifier;
    Identifier m_xy_y_identifier;
    Identifier m_legato_identifier;
    Identifier m_delay_on_identifier;
    Identifier m_phaser_on_identifier;
    Identifier m_flanger_on_identifier;
    Identifier m_chorus_on_identifier;
    Identifier m_delay_selected_identifier;
    Identifier m_phaser_selected_identifier;
    Identifier m_flanger_selected_identifier;
    Identifier m_chorus_selected_identifier;
    Identifier m_fil1_osc1_identifier;
    Identifier m_fil1_osc2_identifier;
    Identifier m_fil1_osc3_identifier;
    Identifier m_fil2_osc1_identifier;
    Identifier m_fil2_osc2_identifier;
    Identifier m_fil2_osc3_identifier;
    Identifier m_fil2_fil1_identifier;
    Identifier m_delay_position_identifier;
    Identifier m_flanger_position_identifier;
    Identifier m_phaser_position_identifier;
    Identifier m_chorus_position_identifier;
    Identifier m_delay_time_identifier;
    Identifier m_delay_feedback_identifier;
    Identifier m_delay_hp_identifier;
    Identifier m_delay_ducking_identifier;
    Identifier m_delay_dry_identifier;
    Identifier m_delay_wet_identifier;
    Identifier m_delay_sync_identifier;
    Identifier m_delay_synctime_numerator_identifier;
    Identifier m_delay_synctime_denominator_identifier;
    Identifier m_phaser_reset_identifier;
    Identifier m_phaser_sync_identifier;
    Identifier m_phaser_rate_identifier;
    Identifier m_phaser_freq_identifier;
    Identifier m_phaser_feedback_identifier;
    Identifier m_phaser_mod_identifier;
    Identifier m_phaser_drywet_identifier;
    Identifier m_phaser_synctime_numerator_identifier;
    Identifier m_phaser_synctime_denominator_identifier;
    Identifier m_flanger_reset_identifier;
    Identifier m_flanger_sync_identifier;
    Identifier m_flanger_rate_identifier;
    Identifier m_flanger_amount_identifier;
    Identifier m_flanger_feedback_identifier;
    Identifier m_flanger_drywet_identifier;
    Identifier m_flanger_synctime_numerator_identifier;
    Identifier m_flanger_synctime_denominator_identifier;
    Identifier m_chorus_reset_identifier;
    Identifier m_chorus_sync_identifier;
    Identifier m_chorus_rate_identifier;
    Identifier m_chorus_amount_identifier;
    Identifier m_chorus_drywet_identifier;
    Identifier m_chorus_feedback_identifier;
    Identifier m_chorus_synctime_numerator_identifier;
    Identifier m_chorus_synctime_denominator_identifier;
    Identifier m_amount_1_row_1_identifier;
    Identifier m_amount_1_row_2_identifier;
    Identifier m_amount_1_row_3_identifier;
    Identifier m_amount_1_row_4_identifier;
    Identifier m_amount_1_row_5_identifier;
    Identifier m_amount_1_row_6_identifier;
    Identifier m_amount_1_row_7_identifier;
    Identifier m_amount_1_row_8_identifier;
    Identifier m_amount_1_row_9_identifier;
    Identifier m_amount_2_row_1_identifier;
    Identifier m_amount_2_row_2_identifier;
    Identifier m_amount_2_row_3_identifier;
    Identifier m_amount_2_row_4_identifier;
    Identifier m_amount_2_row_5_identifier;
    Identifier m_amount_2_row_6_identifier;
    Identifier m_amount_2_row_7_identifier;
    Identifier m_amount_2_row_8_identifier;
    Identifier m_amount_2_row_9_identifier;
    Identifier m_amount_3_row_1_identifier;
    Identifier m_amount_3_row_2_identifier;
    Identifier m_amount_3_row_3_identifier;
    Identifier m_amount_3_row_4_identifier;
    Identifier m_amount_3_row_5_identifier;
    Identifier m_amount_3_row_6_identifier;
    Identifier m_amount_3_row_7_identifier;
    Identifier m_amount_3_row_8_identifier;
    Identifier m_amount_3_row_9_identifier;
    Identifier m_source_row_1_identifier;
    Identifier m_source_row_2_identifier;
    Identifier m_source_row_3_identifier;
    Identifier m_source_row_4_identifier;
    Identifier m_source_row_5_identifier;
    Identifier m_source_row_6_identifier;
    Identifier m_source_row_7_identifier;
    Identifier m_source_row_8_identifier;
    Identifier m_source_row_9_identifier;
    Identifier m_dest_1_row_1_identifier;
    Identifier m_dest_1_row_2_identifier;
    Identifier m_dest_1_row_3_identifier;
    Identifier m_dest_1_row_4_identifier;
    Identifier m_dest_1_row_5_identifier;
    Identifier m_dest_1_row_6_identifier;
    Identifier m_dest_1_row_7_identifier;
    Identifier m_dest_1_row_8_identifier;
    Identifier m_dest_1_row_9_identifier;
    Identifier m_dest_2_row_1_identifier;
    Identifier m_dest_2_row_2_identifier;
    Identifier m_dest_2_row_3_identifier;
    Identifier m_dest_2_row_4_identifier;
    Identifier m_dest_2_row_5_identifier;
    Identifier m_dest_2_row_6_identifier;
    Identifier m_dest_2_row_7_identifier;
    Identifier m_dest_2_row_8_identifier;
    Identifier m_dest_2_row_9_identifier;
    Identifier m_scale_row_1_identifier;
    Identifier m_scale_row_2_identifier;
    Identifier m_scale_row_3_identifier;
    Identifier m_scale_row_4_identifier;
    Identifier m_scale_row_5_identifier;
    Identifier m_scale_row_6_identifier;
    Identifier m_scale_row_7_identifier;
    Identifier m_scale_row_8_identifier;
    Identifier m_scale_row_9_identifier;