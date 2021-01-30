#include "downloader.h"
#include "utils.h"
#include "xor.h"
#include "simple_menu.h"

int main() {
	DebugMessage(xorstr_("WARNING: Debug mode\n\n"));

	Menu menu(xorstr_("Title"));

	std::cout << xorstr_("user key: ");

	std::string key_input;
	std::cin >> key_input;

	if (!ping_new(PING_DEST)) {
		std::cout << xorstr_("[-] Website not responding, exiting.\n");
		pause_until_leave();
	}

	if (!is_key_allowed_insecure(key_input)) { menu.add_item(xorstr_("wrong key.")); pause_until_leave(); }
	else { menu.add_item(xorstr_("key correct.")); }

	std::cout << xorstr_("[+] Website up, proceeding\n");

	std::cout << xorstr_("[*] Downloading...\n");

	if (download_file_from_url(FILE_SOURCE, get_path(), false)) {
		std::cout << xorstr_("[+] File downloaded and stored in: ") << get_path() << "\n";
		pause_until_leave();
	} 
	else {
		std::cout << xorstr_("[-] Couldn't download file\n");
		pause_until_leave();
	}

	return 0;
}