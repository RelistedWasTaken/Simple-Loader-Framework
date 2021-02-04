#pragma once
#include <sstream>
#include <conio.h>
#include <Lmcons.h>
#include <shlobj.h>
#include <filesystem>
#include <vector>

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

std::string get_path() {
	char* pValue;
	std::string str("/my_file.exe");
	size_t len;
	errno_t err = _dupenv_s(&pValue, &len, "TEMP");
	return (pValue + str);
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
