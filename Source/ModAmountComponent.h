/*
  ==============================================================================

    ModAmountComponent.h
    Created: 3 Mar 2019 2:02:02am
    Author:  frot

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#define INLAY_DEF_MODAMOUNT 1
#define DRAG_SCALAR 0.01f;

//==============================================================================
/*
 */
class ModAmountComponent : public Component, public SettableTooltipClient, public AudioProcessorValueTreeState::Listener
{
public:
  ModAmountComponent();
  ~ModAmountComponent();

  void paint(Graphics &) override;
  void setImage(juce::Image p_panel) { m_glas_panel = p_panel; }
  void setInlay(int p_inlay) { m_inlay = p_inlay; }
  void setColor(juce::Colour p_color) { m_color = p_color; }
  void setColorBars(juce::Colour p_color, juce::Colour p_color_negative)
  {
    m_color_bar = p_color;
    m_color_bar_negative = p_color_negative;
  }

  void setValue(float p_amount)
  {
		const MessageManagerLock mmLock;
    m_value = p_amount;
    repaint();
  }

  void reset()
  {
    m_value = 0;
    onValueChange(0);
    repaint();
  }

  void mouseDown(const MouseEvent &event) override
  {
    m_drag_start_y = getMouseXYRelative().getY();
    m_drag_start_value = m_value;
  }
  void mouseDrag(const MouseEvent &event) override;

  std::function<void()> onMouseDown = []() {}; // overwriteable with lambda
  std::function<void(float)> onValueChange = [](float) {};

  void parameterChanged (const String &parameterID, float newValue) override;

  void setParameterId(String p_id){m_parameter_id = p_id;}

private:
  String m_parameter_id = "";

  juce::Colour m_color_bar;
  juce::Colour m_color_bar_negative;
  juce::Colour m_color = juce::Colours::black;
  int m_inlay = INLAY_DEF_MODAMOUNT;
  juce::Image m_glas_panel;

  float m_value = 0.f;
  float m_drag_start_value = 0.f;
  int m_drag_start_y = 0;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModAmountComponent)
};
