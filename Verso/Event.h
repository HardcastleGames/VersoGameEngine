#pragma once
#include <functional>
#include <vector>
#include <iostream>
#include "MouseEnum.h"
#include "Log.h"


namespace Verso {
	class Event {
	public:

		using keyobserver = std::function<void(char)>;
		using mouseobserver = std::function<void(Verso::MouseButton)>;

		Event();
		~Event();

		void KeyPressed(const char Key);

		void MousePressed(const MouseButton Mouse);

		void KeyBind(const keyobserver& function)
		{
			KeyObservers.push_back(function);
		};

		void MouseBind(const mouseobserver& function)
		{
			MouseObservers.push_back(function);
		};


		

		std::vector<keyobserver>KeyObservers;
		std::vector<mouseobserver>MouseObservers;



	};
}
