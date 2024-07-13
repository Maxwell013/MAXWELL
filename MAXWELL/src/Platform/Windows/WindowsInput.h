#pragma once

#include "Maxwell/Input.h"

namespace Maxwell {

	class WindowsInput : public Input {

	protected:

		virtual bool isKeyPressedImpl(int p_keycode) override final;
		virtual bool isMouseButtonPressedImpl(int p_button) override final;
		virtual float getMouseXImpl() override final;
		virtual float getMouseYImpl() override final;
		virtual std::pair<float, float> getMousePositionImpl() override final;
	};
}