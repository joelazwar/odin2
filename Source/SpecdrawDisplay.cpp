/*
  ==============================================================================

    SpecdrawDisplay.cpp
    Created: 2 Mar 2019 11:00:22am
    Author:  frot

  ==============================================================================
*/

#include "SpecdrawDisplay.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
SpecdrawDisplay::SpecdrawDisplay() {
  m_glaspanel = ImageCache::getFromMemory(BinaryData::drawpanel_png,
                                          BinaryData::drawpanel_pngSize);

  setSize(m_glaspanel.getWidth(), m_glaspanel.getHeight());

  setMouseCursor(MouseCursor::StandardCursorType::CrosshairCursor);
}

SpecdrawDisplay::~SpecdrawDisplay() {}

void SpecdrawDisplay::paint(Graphics &g) {

  g.setColour(m_color);
  juce::Point<int> top_left = getLocalBounds().getTopLeft();
  top_left.addXY(m_inlay + 1, m_inlay);
  juce::Point<int> bottom_right = getLocalBounds().getBottomRight();
  bottom_right.addXY(-m_inlay - 1, -m_inlay);
  g.fillRect(juce::Rectangle<int>(top_left, bottom_right)); //

  g.setColour(m_draw_color);

  float height =
      (float)(getHeight() - DRAW_INLAY_UP_SPEC - DRAW_INLAY_DOWN_SPEC);

  for (int i = 0; i < SPECDRAW_STEPS_X; ++i) {
    g.drawLine(DRAW_INLAY_LEFT_SPEC + i,
               getHeight() - DRAW_INLAY_DOWN_SPEC - m_draw_values[i] * height,
               DRAW_INLAY_LEFT_SPEC + i, getHeight() - DRAW_INLAY_DOWN_SPEC);
  }

  g.drawImageAt(m_glaspanel, 0, 0);
}

void SpecdrawDisplay::resized() {}

void SpecdrawDisplay::mouseDrag(const MouseEvent &event) { mouseInteraction(); }

void SpecdrawDisplay::mouseDown(const MouseEvent &event) { mouseInteraction(); }

int max_int(int a, int b) { return a < b ? b : a; }
int min_int(int a, int b) { return a > b ? b : a; }

void SpecdrawDisplay::mouseInteraction() {
  juce::Point<int> mouse_pos = getMouseXYRelative();
  int x = mouse_pos.getX();
  float y = mouse_pos.getY();

  // if (x > DRAW_INLAY_LEFT_SPEC && x < getWidth() - DRAW_INLAY_RIGHT_SPEC) {
  y = y < DRAW_INLAY_UP_SPEC ? DRAW_INLAY_UP_SPEC : y;
  y = y > getHeight() - DRAW_INLAY_DOWN_SPEC
          ? getHeight() - DRAW_INLAY_DOWN_SPEC
          : y;
  x = x > DRAW_INLAY_LEFT_SPEC ? x : DRAW_INLAY_LEFT_SPEC + 1;
  x = x < getWidth() - DRAW_INLAY_RIGHT_SPEC
          ? x
          : getWidth() - DRAW_INLAY_RIGHT_SPEC - 1;
  x -= DRAW_INLAY_LEFT_SPEC + 1;

  float float_y = (getHeight() - DRAW_INLAY_DOWN_SPEC - y) /
                  (getHeight() - DRAW_INLAY_UP_SPEC - DRAW_INLAY_DOWN_SPEC);
  // float_y = (round(float_y * SPECDRAW_STEPS_Y))/SPECDRAW_STEPS_Y;
  if (m_mouse_was_down) {

    int max_x = max_int(x, m_last_x_value);
    int min_x = min_int(x, m_last_x_value);
    int range_x = max_x - min_x;

    float min_y = x > m_last_x_value ? m_last_y_value : float_y;
    float max_y = x >= m_last_x_value ? float_y : m_last_y_value;
    float range_y = max_y - min_y;

    if (range_x > 0) {
      for (int i = min_x; i <= max_x; ++i) {
        // m_draw_values[i] = float_y;//left_y_value  + (right_y_value -
        // left_y_value)*(float)(i - min_int(x, m_last_x_value))/(max_int(x,
        // m_last_x_value)- min_int(x, m_last_x_value));
        m_draw_values[i] =
            min_y + (range_y) * (float)(i - min_x) / (float)range_x;
      }
    } else {
      m_draw_values[x] = float_y;
    }
  } else {
    m_draw_values[x] = float_y;
  }
  m_last_x_value = x;
  m_last_y_value = float_y;
  //}
  onDraw();
  repaint();
  // if (!m_mouse_was_down) {
  m_mouse_was_down = true;
  //  DBG("MOUSE DOWN!");
  //}
}

void SpecdrawDisplay::mouseUp(const MouseEvent &event) {
  // if(m_mouse_was_down){
  //  m_mouse_was_down = false;
  m_mouse_was_down = false;
  // DBG("UP!");
  //}
}

float *SpecdrawDisplay::getDrawnTable() { return m_draw_values; }
