#pragma once
#include "includes.h"

class Menu {
public:
	Menu(std::string title) : window_title(title) {
		SetConsoleTitleA(window_title.c_str());
	};

	template <typename T> 
	void add_item(const T& input) {
		std::cout << input << std::endl;
	};

private:
	std::string window_title;
};