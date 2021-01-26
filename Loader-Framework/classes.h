#pragma once
#include "includes.h"

class Menu {
public:
	Menu(std::string title);

	void add_item_int(const int& input_int);
	void add_item_float(const float& input_float);
	void add_item_string(const std::string& input_str);

private:
	std::string window_title;
};