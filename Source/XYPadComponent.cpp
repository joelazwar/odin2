/*
  ==============================================================================

    XYPadComponent.cpp
    Created: 27 Feb 2019 8:45:18pm
    Author:  frot

  ==============================================================================
*/

#include "XYPadComponent.h"
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
XYPadComponent::XYPadComponent(Knob &p_x, Knob &p_y, bool p_vector_pad) :
    m_knob_x(p_x), m_knob_y(p_y), m_vector_pad(p_vector_pad) {
	m_color = juce::Colour(30, 30, 30);
}

XYPadComponent::~XYPadComponent() {
}

void XYPadComponent::paint(Graphics &g) {
	SET_INTERPOLATION_QUALITY(g)

	g.setColour(m_color);
	juce::Point<int> top_left = getLocalBounds().getTopLeft();
	if (m_GUI_big) {
		top_left.addXY(m_inlay + 2, m_inlay);
	} else {
		top_left.addXY(m_inlay + 1, m_inlay);
	}
	juce::Point<int> bottom_right = getLocalBounds().getBottomRight();
	bottom_right.addXY(-m_inlay, -m_inlay);
	g.fillRect(juce::Rectangle<int>(top_left, bottom_right)); //

	if (m_draw_logo) {
		g.drawImageAt(m_logo, 0, -5);
	}

	if (m_vector_pad) {
		g.setColour(juce::Colours::lightgrey);
		if (m_GUI_big) {
			g.setFont(18.0f);
			g.drawText(
			    "A", OdinHelper::c150(VECTOR_LEFT)+1, OdinHelper::c150(VECTOR_DOWN), 12, 23, Justification::topLeft);
			g.drawText("B", OdinHelper::c150(VECTOR_LEFT)+1, OdinHelper::c150(VECTOR_UP), 12, 23, Justification::topLeft);
			g.drawText("C", OdinHelper::c150(VECTOR_RIGHT), OdinHelper::c150(VECTOR_UP), 12, 23, Justification::topLeft);
			g.drawText(
			    "D", OdinHelper::c150(VECTOR_RIGHT), OdinHelper::c150(VECTOR_DOWN), 12, 23, Justification::topLeft);
		} else {
			g.setFont(12.0f);
			g.drawText("A", VECTOR_LEFT, VECTOR_DOWN, 8, 15, Justification::topLeft);
			g.drawText("B", VECTOR_LEFT, VECTOR_UP, 8, 15, Justification::topLeft);
			g.drawText("C", VECTOR_RIGHT, VECTOR_UP, 8, 15, Justification::topLeft);
			g.drawText("D", VECTOR_RIGHT, VECTOR_DOWN, 8, 15, Justification::topLeft);
		}
	}

	int handle_inlay    = HANDLE_INLAY;
	int handle_diameter = HANDLE_DIAMETER;
	if (m_GUI_big) {
		//handle_inlay *= 1.5f;
		handle_diameter = 10;
	}

	float x_handle = handle_inlay + m_value_x * (getWidth() - handle_diameter - 2 * handle_inlay);
	if (m_GUI_big) {
		++x_handle;
	}
	float y_handle =
	    getHeight() - handle_diameter - (handle_inlay + m_value_y * (getHeight() - handle_diameter - 2 * handle_inlay));
	if (!m_vector_pad) {
		//g.setColour(Colour(0, 10, 30));
		g.setColour(Colour(60, 90, 120));
		if (!m_GUI_big) {
			g.drawLine(m_inlay, y_handle + handle_diameter / 2, getWidth() - m_inlay, y_handle + handle_diameter / 2);
		} else {
			g.drawLine(
			    m_inlay + 2, y_handle + handle_diameter / 2, getWidth() - m_inlay, y_handle + handle_diameter / 2);
		}
		g.drawLine(x_handle + handle_diameter / 2, m_inlay, x_handle + handle_diameter / 2, getHeight() - m_inlay);
		g.setColour(Colour(20, 105, 129));
		g.fillEllipse(x_handle - 1, y_handle - 1, handle_diameter + 2, handle_diameter + 2);
	}
	g.setColour(Colours::white);
	g.fillEllipse(x_handle, y_handle, handle_diameter, handle_diameter);

	g.drawImageAt(m_panel, 0, 0);
}

void XYPadComponent::mouseDrag(const MouseEvent &event) {
	mouseInteraction();
}

void XYPadComponent::mouseDown(const MouseEvent &event) {
	mouseInteraction();
	m_lock_set_XY_while_drawing = true;
}

void XYPadComponent::mouseInteraction() {
	juce::Point<int> mouse_pos = getMouseXYRelative();

	int handle_inlay    = HANDLE_INLAY;
	int handle_diameter = HANDLE_DIAMETER;
	if (m_GUI_big) {
		//handle_inlay *= 1.5f;
		handle_diameter *= 1.5f;
	}

	m_value_x = (float)(mouse_pos.getX() - handle_inlay - handle_diameter / 2) /
	            (float)(getWidth() - handle_diameter - 2 * handle_inlay);
	m_value_x = m_value_x < 0 ? 0 : m_value_x;
	m_value_x = m_value_x > 1 ? 1 : m_value_x;

	m_value_y = (float)(mouse_pos.getY() + handle_diameter / 2 - getHeight() + handle_inlay) /
	            ((float)(2 * handle_inlay + handle_diameter - getHeight()));
	m_value_y = m_value_y < 0 ? 0 : m_value_y;
	m_value_y = m_value_y > 1 ? 1 : m_value_y;

	m_knob_x.setValue(m_value_x);
	m_knob_y.setValue(m_value_y);

	repaint();
}

void XYPadComponent::mouseUp(const MouseEvent &event) {
	m_lock_set_XY_while_drawing = false;
	Component::mouseUp(event);
}
