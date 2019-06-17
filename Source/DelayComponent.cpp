/*
  ==============================================================================

    DelayComponent.cpp
    Created: 27 Feb 2019 12:02:33am
    Author:  frot

  ==============================================================================
*/

#include "DelayComponent.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
DelayComponent::DelayComponent(AudioProcessorValueTreeState &vts,
                               bool p_is_standalone)
    : m_sync("sync", juce::DrawableButton::ButtonStyle::ImageRaw),
      m_value_tree(vts),
      m_delay_synctime_denominator_identifier("delay_synctime_denominator"),
      m_delay_synctime_numerator_identifier("delay_synctime_numerator"),
      m_is_standalone_plugin(p_is_standalone) {

  m_delay_time_attach.reset(
      new SliderAttachment(m_value_tree, "delay_time", m_time));
  m_delay_feedback_attach.reset(
      new SliderAttachment(m_value_tree, "delay_feedback", m_feedback));
  m_delay_hp_attach.reset(new SliderAttachment(m_value_tree, "delay_hp", m_HP));
  m_delay_ducking_attach.reset(
      new SliderAttachment(m_value_tree, "delay_ducking", m_ducking));
  m_delay_dry_attach.reset(
      new SliderAttachment(m_value_tree, "delay_dry", m_dry));
  m_delay_wet_attach.reset(
      new SliderAttachment(m_value_tree, "delay_wet", m_wet));

  //if (!m_is_standalone_plugin) {
    m_sync_attach.reset(new ButtonAttachment(m_value_tree, "", m_sync));

    juce::Image sync_1 = ImageCache::getFromMemory(
        BinaryData::buttonsync_1_png, BinaryData::buttonsync_1_pngSize);
    juce::Image sync_2 = ImageCache::getFromMemory(
        BinaryData::buttonsync_2_png, BinaryData::buttonsync_2_pngSize);
    juce::Image sync_3 = ImageCache::getFromMemory(
        BinaryData::buttonsync_3_png, BinaryData::buttonsync_3_pngSize);
    juce::Image sync_4 = ImageCache::getFromMemory(
        BinaryData::buttonsync_4_png, BinaryData::buttonsync_4_pngSize);

    juce::DrawableImage sync_draw1;
    juce::DrawableImage sync_draw2;
    juce::DrawableImage sync_draw3;
    juce::DrawableImage sync_draw4;

    sync_draw1.setImage(sync_1);
    sync_draw2.setImage(sync_2);
    sync_draw3.setImage(sync_3);
    sync_draw4.setImage(sync_4);

    m_sync.setImages(&sync_draw2, &sync_draw2, &sync_draw1, &sync_draw1,
                     &sync_draw4, &sync_draw4, &sync_draw3, &sync_draw3);
    m_sync.setClickingTogglesState(true);
    m_sync.setBounds(DELAY_SYNC_POS_X, DELAY_SYNC_POS_Y, sync_1.getWidth(),
                     sync_1.getHeight());
    m_sync.setTriggeredOnMouseDown(true);
    m_sync.setColour(juce::DrawableButton::ColourIds::backgroundOnColourId,
                     juce::Colour());
    m_sync.setTooltip("Syncs the delay time to your track");
    addAndMakeVisible(m_sync);
  //}
  m_sync.onStateChange = [&]() {
    //if (!m_is_standalone_plugin) {
      setSync(m_sync.getToggleState());
    //}
  };
  juce::Image metal_knob_big = ImageCache::getFromMemory(
      BinaryData::metal_knob_big_png, BinaryData::metal_knob_big_pngSize);
  juce::Image black_knob_mid = ImageCache::getFromMemory(
      BinaryData::black_knob_mid_png, BinaryData::black_knob_mid_pngSize);

  m_time.setStrip(metal_knob_big, N_KNOB_FRAMES);
  m_time.setSliderStyle(Slider::RotaryVerticalDrag);
  m_time.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
  m_time.setRange(TIME_MIN, TIME_MAX);
  //m_time.setSkewFactorFromMidPoint(TIME_MID);
  //skew value printed as 0.627099
  m_time.setTextValueSuffix(" s");
  m_time.setNumDecimalPlacesToDisplay(3);
  m_time.setDoubleClickReturnValue(true, TIME_DEFAULT,
                                   ModifierKeys::ctrlModifier);
  m_time.setKnobTooltip("The time for the \nsignal to echo back");
  addAndMakeVisible(m_time);

  m_feedback.setStrip(metal_knob_big, N_KNOB_FRAMES);
  m_feedback.setSliderStyle(Slider::RotaryVerticalDrag);
  m_feedback.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
  m_feedback.setSkewFactorFromMidPoint(FEEDBACK_MID);
  // m_feedback.setValue(0.6f);
  m_feedback.setKnobTooltip("How much to echo back");

  addAndMakeVisible(m_feedback);

  m_HP.setStrip(black_knob_mid, N_KNOB_FRAMES);
  m_HP.setSliderStyle(Slider::RotaryVerticalDrag);
  m_HP.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
  m_HP.setRange(HP_FREQ_MIN, HP_FREQ_MAX);
  m_HP.setSkewFactorFromMidPoint(HP_FREQ_MID);
  m_HP.setDoubleClickReturnValue(true, HP_FREQ_DEFAULT,
                                 ModifierKeys::ctrlModifier);
  // m_HP.setValue(HP_FREQ_DEFAULT);
  m_HP.setTextValueSuffix(" Hz");
  m_HP.setNumDecimalPlacesToDisplay(1);
  m_HP.setKnobTooltip("The cutoff frequency\n for a highpass filter\n which is "
                      "applied\nto the signals");
  addAndMakeVisible(m_HP);

  m_ducking.setStrip(black_knob_mid, N_KNOB_FRAMES);
  m_ducking.setSliderStyle(Slider::RotaryVerticalDrag);
  m_ducking.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
  m_ducking.setKnobTooltip(
      "Lowers the wet volume\nwhen a signal is at the\ninput of the delay\nUse "
      "this to declutter\nyour sounds");
  addAndMakeVisible(m_ducking);

  m_dry.setStrip(black_knob_mid, N_KNOB_FRAMES);
  m_dry.setSliderStyle(Slider::RotaryVerticalDrag);
  m_dry.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
  m_dry.setSkewFactorFromMidPoint(DRY_WET_MID);
  // m_dry.setValue(DRY_DEFAULT);
  m_dry.setDoubleClickReturnValue(true, DRY_DEFAULT,
                                  ModifierKeys::ctrlModifier);
  m_dry.setKnobTooltip("Volume of the input signal");
  addAndMakeVisible(m_dry);

  m_wet.setStrip(black_knob_mid, N_KNOB_FRAMES);
  m_wet.setSliderStyle(Slider::RotaryVerticalDrag);
  m_wet.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
  m_wet.setSkewFactorFromMidPoint(DRY_WET_MID);
  // m_wet.setValue(WET_DEFAULT);
  m_wet.setDoubleClickReturnValue(true, WET_DEFAULT,
                                  ModifierKeys::ctrlModifier);
  m_wet.setKnobTooltip("Volume of the delayed signal only");
  addAndMakeVisible(m_wet);

  m_sync_attach.reset(new ButtonAttachment(m_value_tree, "delay_sync", m_sync));

  m_sync_time.OnValueChange = [&](int p_left, int p_right) {
    m_value_tree.state.setProperty(m_delay_synctime_numerator_identifier,
                                   p_left, nullptr);
    m_value_tree.state.setProperty(m_delay_synctime_denominator_identifier,
                                   p_right, nullptr);
  };
  m_sync_time.setTopLeftPosition(SYNC_TIME_DELAY_POS_X, SYNC_TIME_DELAY_POS_Y);
  m_sync_time.setTooltip("Set the delay time in sync to your track");
  addChildComponent(m_sync_time);

  m_feedback.setNumDecimalPlacesToDisplay(3);
  m_ducking.setNumDecimalPlacesToDisplay(3);
  m_dry.setNumDecimalPlacesToDisplay(3);
  m_wet.setNumDecimalPlacesToDisplay(3);

  forceValueTreeOntoComponents(m_value_tree.state);
}

DelayComponent::~DelayComponent() {}

void DelayComponent::paint(Graphics &g) { g.drawImageAt(m_background, 0, 0); }

void DelayComponent::resized() {
  m_time.setBounds(TIME_POS_X, TIME_POS_Y, METAL_KNOB_BIG_SIZE_X,
                   METAL_KNOB_BIG_SIZE_Y);
  m_feedback.setBounds(FEEDBACK_POS_X, FEEDBACK_POS_Y, METAL_KNOB_BIG_SIZE_X,
                       METAL_KNOB_BIG_SIZE_Y);
  m_HP.setBounds(DELAY_HP_POS_X, DELAY_HP_POS_Y, BLACK_KNOB_MID_SIZE_X,
                 BLACK_KNOB_MID_SIZE_Y);
  m_ducking.setBounds(DUCKING_POS_X, DUCKING_POS_Y, BLACK_KNOB_MID_SIZE_X,
                      BLACK_KNOB_MID_SIZE_Y);
  m_dry.setBounds(DRY_POS_X, DRY_POS_Y, BLACK_KNOB_MID_SIZE_X,
                  BLACK_KNOB_MID_SIZE_Y);
  m_wet.setBounds(WET_POS_X, WET_POS_Y, BLACK_KNOB_MID_SIZE_X,
                  BLACK_KNOB_MID_SIZE_Y);
}

void DelayComponent::forceValueTreeOntoComponents(ValueTree p_tree) {
  m_sync_time.setValues(
      m_value_tree.state[m_delay_synctime_numerator_identifier],
      m_value_tree.state[m_delay_synctime_denominator_identifier]);
}
