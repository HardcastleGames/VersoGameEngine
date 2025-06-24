#pragma once
#include <map>

namespace Verso {
	class Input {
	public:

		Input() = default;
		~Input() = default;

		std::map<bool, char> KeyStates;

		void KeyDown(char Key);
		void KeyUp(char Key);
		bool IsKeyDown(char Key);
	};



}
