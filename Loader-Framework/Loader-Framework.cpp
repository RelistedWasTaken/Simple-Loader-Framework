#include "classes.h"
#include "downloader.h"
#include "utils.h"
#include "xor.h"

int main() {
	DebugMessage(xorstr_("WARNING: Debug mode\n\n"));

	Menu menu(xorstr_("Title"));

	std::string key_input;
	std::cin >> key_input;

	if (!ping_new(PING_DEST)) {
		std::cout << xorstr_("[-] Website not responding, exiting.\n");
		pause_until_leave();
	}

	if (!is_key_allowed_insecure(key_input)) { menu.add_item_string(xorstr_("wrong key.")); pause_until_leave(); }
	else { menu.add_item_string(xorstr_("key correct.")); }

	std::cout << xorstr_("[+] Website up, proceeding\n");

	std::cout << xorstr_("[*] Downloading...\n");

	if (download_file_from_url(FILE_SOURCE, get_path())) {
		std::cout << xorstr_("[+] File downloaded and stored in: ") << get_path() << "\n";
		pause_until_leave();
	} 
	else {
		std::cout << xorstr_("[-] Couldn't download file\n");
		pause_until_leave();
	}

	return 0;
}