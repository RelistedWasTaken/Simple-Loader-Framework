#pragma once
#include "includes.h"
#include <sstream>
#include <conio.h>
#include <Lmcons.h>
#include <vector>

int t_;
int f_;
int* result;

std::string get_user_name() {
	TCHAR username[UNLEN + 1];
	DWORD size = UNLEN + 1;
	GetUserName((TCHAR*)username, &size);
	std::wstring wStr = username;
	std::string str = std::string(wStr.begin(), wStr.end());
	return str;
}

std::vector<std::string> fetch_all_info_from_txt() {
	std::string s = DownloadString(KEY_LOCATION);
	std::stringstream ss(s);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	return vstrings;
}

bool is_key_allowed_insecure(const std::string& input_sent) {
	std::vector<std::string> keys_fetched = fetch_all_info_from_txt();
	for (auto& key : keys_fetched) {
		if (key == input_sent) {
			return true;
		}
	}
	return false;
}

int is_key_allowed_secure(const std::string& input_sent) {
	std::vector<std::string> keys_fetched = fetch_all_info_from_txt();
	for (auto& key : keys_fetched) {
		t_ = rand() % 1651541681 + 1;
		f_ = rand() % 2581517441 + 1;
		if (key == input_sent) {
			result = new int(t_ + f_);
			return t_;
		}
	}
	result = new int(t_ - f_);
	return f_;
}


/*
secure vs non-secure
	non-secure
	returns a boolean value which can easily be faked.
	usage:
	if (!is_key_allowed_insecure(key_input)) { menu.add_item_string("wrong key."); return 0; }
	else { menu.add_item_string("key correct."); }

	secure
	returns a random value and compares it after the end
	usage:
	is_key_allowed_secure(key_input)
	if (*result == t_ - f_) { menu.add_item_string("wrong key."); return 0; }
	else if (*result == t_ + f_) { menu.add_item_string("key correct."); }
*/


//thx dupecc
void open_app_insecure(std::string path, LPCSTR arguments, bool hidden) {
	if (hidden) {
		ShellExecuteA(NULL, NULL, path.c_str(), arguments, NULL, NULL);
	}
	else {
		ShellExecuteA(NULL, NULL, path.c_str(), arguments, NULL, SW_SHOWDEFAULT);
	}
}

void DebugMessage(const char* message) {
#ifdef _DEBUG
	std::cout << message;
#endif
}

void pause_until_leave() {
	_getch();
	exit(1);
}