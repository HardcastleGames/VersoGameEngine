#pragma once
#include <map>
#include "MouseEnum.h"

namespace Verso {
	class Input {
	public:

		Input() = default;
		~Input() = default;



		std::map<bool, char> KeyStates;
		std::map<MouseButton, char> MouseStates;

		void KeyDown(char Key);
		void KeyUp(char Key);
		bool IsKeyDown(char Key);

		void MouseDown(MouseButton button);
		void MouseUp(MouseButton button);
		bool IsMouseDown(MouseButton button);
	};



}
