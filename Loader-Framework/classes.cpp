#include "classes.h"
#define AUTHOR "relisted"
#define VERSION "1.0"

Menu::Menu(std::string title) {
	window_title = title;
	SetConsoleTitleA(window_title.c_str());
};

void Menu::add_item_int(const int& input_int) {
	std::cout << "\n" << xorstr_("integer value: ") << input_int << "\n";
};
void Menu::add_item_float(const float& input_float) {
	std::cout << "\n" << xorstr_("float value: ") << input_float << "\n";
};
void Menu::add_item_string(const std::string& input_str) {
	std::cout << "\n" << xorstr_("string value: ") << input_str << "\n";
};
