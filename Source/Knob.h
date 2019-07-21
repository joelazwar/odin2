/*
  ==============================================================================

    Knob.h
    Created: 23 Feb 2019 2:34:46pm
    Author:  frot

  ==============================================================================
*/
#include "GlobalIncludes.h"
#include "InputField.h"

#define N_KNOB_FRAMES 256 // todo

#define BLACK_KNOB_VERY_SMALL_SIZE_X 21
#define BLACK_KNOB_VERY_SMALL_SIZE_Y 24
#define BLACK_KNOB_VERY_SMALL_OFFSET_X 11
#define BLACK_KNOB_VERY_SMALL_OFFSET_Y 11

#define BLACK_KNOB_SMALL_SIZE_X 27
#define BLACK_KNOB_SMALL_SIZE_Y 30
#define BLACK_KNOB_SMALL_OFFSET_X 14
#define BLACK_KNOB_SMALL_OFFSET_Y 13

#define BLACK_KNOB_MID_SIZE_X 29
#define BLACK_KNOB_MID_SIZE_Y 32
#define BLACK_KNOB_MID_OFFSET_X 15
#define BLACK_KNOB_MID_OFFSET_Y 14

#define BLACK_KNOB_BIG_SIZE_X 32
#define BLACK_KNOB_BIG_SIZE_Y 35
#define BLACK_KNOB_BIG_OFFSET_X 17
#define BLACK_KNOB_BIG_OFFSET_Y 15

#define METAL_KNOB_SMALL_SIZE_X 33
#define METAL_KNOB_SMALL_SIZE_Y 35
#define METAL_KNOB_SMALL_OFFSET_X 18
#define METAL_KNOB_SMALL_OFFSET_Y 16

#define METAL_KNOB_BIG_SIZE_X 45
#define METAL_KNOB_BIG_SIZE_Y 48
#define METAL_KNOB_BIG_OFFSET_X 25
#define METAL_KNOB_BIG_OFFSET_Y 20

#define ROUND_KNOB_SIZE_X 36
#define ROUND_KNOB_SIZE_Y 39
#define ROUND_KNOB_OFFSET_X 19
#define ROUND_KNOB_OFFSET_Y 17

#define LABEL_OFFSET_Y -8
#define LABEL_SIZE_X 90
#define LABEL_SIZE_Y 40

#pragma once

class OdinAudioProcessor;

class KnobFeels : public juce::LookAndFeel_V4 {
public:
  KnobFeels() {
    // setColour(Slider::ColourIds::textBoxTextColourId, MENU_FONT_COLOR);
    // //todo no effect...
  }
  void drawBubble(Graphics &g, BubbleComponent &b,
                  const Point<float> &positionOfTip,
                  const Rectangle<float> &body) override {
    g.setColour(MENU_BACKGROUND_COLOR);
    g.fillRect(body); // pmai
    g.setColour(Colour(50, 50, 50));
    g.drawRect(body); // pmai
  }
  int getSliderPopupPlacement(Slider &slider) { return 2; }
};

class Knob : public juce::Slider {
public:
  Knob() : m_label("henlo", "texttt") {
    setLookAndFeel(&m_knob_feels);
    setRange(0, 1);

    setPopupDisplayEnabled(true, false, nullptr);
    setNumDecimalPlacesToDisplay(3);
    setVelocityModeParameters(1.0, 1, 0.0, true, ModifierKeys::shiftModifier);
    // RsetDoubleClicketurnValue(true, 0, ModifierKeys::ctrlModifier);

    setTooltip("henlo");
  }

  ~Knob() { setLookAndFeel(nullptr); }
  void setTextValueSuffix(const String &suffix) {
    setNumDecimalPlacesToDisplay(3);
    Slider::setTextValueSuffix(suffix);
  }

  String getTextFromValue(double value) override;

  void setStrip(juce::Image p_strip, size_t p_frames,
                bool p_is_vertical = true) {
    m_is_vertical = p_is_vertical;
    m_filmstrip = p_strip;
    if (m_is_vertical) {
      m_width = p_strip.getWidth();
      m_height = p_strip.getHeight() / p_frames;
    } else {
      m_width = p_strip.getWidth() / p_frames;
      m_height = p_strip.getHeight();
    }
    m_frames = p_frames;

    // m_drag_label.setVisible(false);
  }

  void paint(juce::Graphics &g) override {
    std::size_t image_number = static_cast<std::size_t>(
        // 0.5 + (getValue() - getMinimum()) / (getMaximum() - getMinimum()) *
        valueToProportionOfLength(getValue()) * (m_frames - 1));
    if (m_is_vertical) {
      g.drawImage(m_filmstrip, 0, 0, m_width, m_height, 0,
                  image_number * m_height, m_width, m_height);
    } else {
      g.drawImage(m_filmstrip, 0, 0, m_width, m_height, image_number * m_width,
                  0, m_width, m_height);
    }

    if (m_midi_learn) {
      g.setColour(Colours::red);
      g.drawRoundedRectangle(getLocalBounds().getX() + m_midi_learn_left_offset,
                             getLocalBounds().getY(),
                             getLocalBounds().getWidth() -
                                 m_midi_learn_left_offset,
                             getLocalBounds().getHeight(), 5,
                             2); // draw an outline around the component
    } else if (m_midi_control) {
      g.setColour(Colours::green);
      g.drawRoundedRectangle(getLocalBounds().getX() + m_midi_learn_left_offset,
                             getLocalBounds().getY(),
                             getLocalBounds().getWidth() -
                                 m_midi_learn_left_offset,
                             getLocalBounds().getHeight(), 5,
                             2); // draw an outline around the component
    }
  }

  //this does not override, but hide
  void setBounds(int x, int y, int width, int height) {
    Slider::setBounds(x,y,width,height);
  }

  void mouseDown(const MouseEvent &event) override;

  void setKnobTooltip(const std::string p_tooltip) { setTooltip(p_tooltip); }

  static void setOdinPointer(OdinAudioProcessor *p_pointer) {
    m_processor = p_pointer;
  }

  void stopMidiLearn() {
    m_midi_learn = false;
    repaint();
  }

  void setMidiControlActive() {
    m_midi_learn = false;
    m_midi_control = true;
    repaint();
  }

  void mouseDoubleClick(const MouseEvent &e) override {
    if (auto editor =
            findParentComponentOfClass<juce::AudioProcessorEditor>()) {
      if (auto value_field = dynamic_cast<InputField *>(
              editor->findChildWithID("value_input"))) {

        value_field->setVisible(true);
        Point<int> point_in_parent(
            getX() + getWidth() / 2 - INPUT_LABEL_SIZE_X / 2, getBottom() + 10);
        Point<int> point_in_editor =
            editor->getLocalPoint(getParentComponent(), point_in_parent);
        if (point_in_editor.getY() > 580) {
          point_in_editor -= Point<int>(0, 30);
        }

        value_field->setTopLeftPosition(point_in_editor);
        value_field->clear();
        value_field->grabKeyboardFocus();
        value_field->setAttachedSlider(this);
      }
    }
    Component::mouseDoubleClick(e);
  }

private:
  bool m_midi_learn = false;
  bool m_midi_control = false;

  int m_midi_learn_left_offset = 0;

  static OdinAudioProcessor *m_processor;
  bool m_is_vertical = true;
  std::size_t m_frames, m_width, m_height;
  juce::Image m_filmstrip;

  KnobFeels m_knob_feels;

  Label m_label;
};