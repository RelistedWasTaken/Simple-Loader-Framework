#include "classes.h"
#include "downloader.h"
#include "utils.h"

int main() {
	DebugMessage("WARNING: Debug mode\n\n");

	Menu menu("Title");

	std::string key_input;
	std::cin >> key_input;

	if (!ping_new(PING_DEST)) {
		std::cout << "[-] Website not responding, exiting.\n";
		pause_until_leave();
	}

	if (!is_key_allowed_insecure(key_input)) { menu.add_item_string("wrong key."); pause_until_leave(); }
	else { menu.add_item_string("key correct."); }

	std::cout << "[+] Website up, proceeding\n";

	std::cout << "[*] Downloading...\n";

	if (download_file_from_url(FILE_SOURCE, get_path())) {
		std::cout << "[+] File downloaded and stored in: " << get_path() << "\n";
		pause_until_leave();
	} 
	else {
		std::cout << "[-] Couldn't download file\n";
		pause_until_leave();
	}

	return 0;
}