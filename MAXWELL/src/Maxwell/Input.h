#pragma once

#include "Maxwell/Core.h"

namespace Maxwell {

	class MAXWELL_API Input {

	private:

		static Input* s_instance;

	protected:

		virtual bool isKeyPressedImpl(int p_keycode) = 0;

		virtual bool isMouseButtonPressedImpl(int p_keycode) = 0;
		virtual float getMouseXImpl() = 0;
		virtual float getMouseYImpl() = 0;
		virtual std::pair<float, float> getMousePositionImpl() = 0;

	public:

		inline static bool isKeyPressed(int p_keycode) { return s_instance->isKeyPressedImpl(p_keycode); }

		inline static bool isMouseButttonPressed(int p_button) { return s_instance->isMouseButtonPressedImpl(p_button); }
		inline static float getMouseX() { return s_instance->getMouseXImpl(); }
		inline static float getMouseY() { return s_instance->getMouseYImpl(); }
		inline static std::pair<float, float> getMousePosition() { return s_instance->getMousePositionImpl(); }
	};
}