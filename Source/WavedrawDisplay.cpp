/*
  ==============================================================================

    WavedrawDisplay.cpp
    Created: 2 Mar 2019 1:38:37am
    Author:  frot

  ==============================================================================
*/

#include "WavedrawDisplay.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
WavedrawDisplay::WavedrawDisplay() {
  m_glaspanel = ImageCache::getFromMemory(BinaryData::drawpanel_png,
                                          BinaryData::drawpanel_pngSize);

  setSize(m_glaspanel.getWidth(), m_glaspanel.getHeight());

  setMouseCursor(MouseCursor::StandardCursorType::CrosshairCursor);
}

WavedrawDisplay::~WavedrawDisplay() {}

void WavedrawDisplay::paint(Graphics &g) {

  g.setColour(m_color);
  juce::Point<int> top_left = getLocalBounds().getTopLeft();
  top_left.addXY(m_inlay + 1, m_inlay);
  juce::Point<int> bottom_right = getLocalBounds().getBottomRight();
  bottom_right.addXY(-m_inlay - 1, -m_inlay);
  g.fillRect(juce::Rectangle<int>(top_left, bottom_right)); //

  g.setColour(m_draw_color);

  float width = (float)(getWidth() - DRAW_INLAY_LEFT - DRAW_INLAY_RIGHT) /
                (float)WAVEDRAW_STEPS_X;
  float height = (float)(getHeight() - DRAW_INLAY_UP - DRAW_INLAY_DOWN) / 2.f;
  float mid = (float)getHeight() / 2.f;

  for (int i = 0; i < WAVEDRAW_STEPS_X; ++i) {
    // g.drawLine(DRAW_INLAY_LEFT + i * width, mid - m_draw_values[i] * height,
    // DRAW_INLAY_LEFT + (i + 1) * width, mid - m_draw_values[i] * height,
    // WAVEDRAW_THICCNESS);
    if (i != WAVEDRAW_STEPS_X - 1) {
      g.drawLine(DRAW_INLAY_LEFT + (i)*width, mid - m_draw_values[i] * height,
                 DRAW_INLAY_LEFT + (i + 1) * width,
                 mid - m_draw_values[i + 1] * height, WAVEDRAW_THICCNESS);
    } else {
      g.drawLine(DRAW_INLAY_LEFT + (i)*width, mid - m_draw_values[i] * height,
                 DRAW_INLAY_LEFT + (i + 1) * width,
                 mid - m_draw_values[0] * height, WAVEDRAW_THICCNESS);
    }
  }

  g.drawImageAt(m_glaspanel, 0, 0);
}

void WavedrawDisplay::resized() {}

void WavedrawDisplay::mouseDrag(const MouseEvent &event) { mouseInteraction(); }

void WavedrawDisplay::mouseDown(const MouseEvent &event) { mouseInteraction(); }

int max_int_wavedraw(int a, int b) { return a < b ? b : a; } // shouldnt be here
int min_int_wavedraw(int a, int b) { return a > b ? b : a; } // shouldnt be here

void WavedrawDisplay::mouseInteraction() {

  // get Mouse data
  juce::Point<int> mouse_pos = getMouseXYRelative();
  float x = mouse_pos.getX();
  float y = mouse_pos.getY();

  // clamp values
  y = y < DRAW_INLAY_UP ? DRAW_INLAY_UP : y;
  y = y > getHeight() - DRAW_INLAY_DOWN ? getHeight() - DRAW_INLAY_DOWN : y;
  x = x > DRAW_INLAY_LEFT ? x : DRAW_INLAY_LEFT + 1;
  x = x < getWidth() - DRAW_INLAY_RIGHT ? x : getWidth() - DRAW_INLAY_RIGHT - 1;

  float float_x =
      (x - DRAW_INLAY_LEFT) / (getWidth() - DRAW_INLAY_LEFT - DRAW_INLAY_RIGHT);
  int step_x = (int)(floor(float_x * WAVEDRAW_STEPS_X));

  float float_y =
      (y - DRAW_INLAY_UP) / (getHeight() - DRAW_INLAY_UP - DRAW_INLAY_DOWN);
  float_y = 2 * (0.5 - float_y);

  if (m_mouse_was_down) {
    int min_x = min_int_wavedraw(step_x, m_last_x_value);
    int max_x = max_int_wavedraw(step_x, m_last_x_value);
    float range_x = max_x - min_x;

    float min_y = step_x > m_last_x_value ? m_last_y_value : float_y;
    float max_y = step_x >= m_last_x_value ? float_y : m_last_y_value;
    float range_y = max_y - min_y;

    if (range_x > 0) {
      for (int i = min_x; i <= max_x; ++i) {
        // m_draw_values[i] = float_y;
        m_draw_values[i] =
            min_y + (range_y) * (float)(i - min_x) / (float)range_x;
      }
    } else {
      m_draw_values[step_x] = float_y;
    }
  } else {
    m_draw_values[step_x] = float_y;
  }
  m_last_x_value = step_x;
  m_last_y_value = float_y;

  onDraw();
  repaint();

  m_mouse_was_down = true;
}

void WavedrawDisplay::mouseUp(const MouseEvent &event) {
  m_mouse_was_down = false;
}

float *WavedrawDisplay::getDrawnTable() { return m_draw_values; }
