#include "classes.h"
#include "downloader.h"
#include "utils.h"

int main()
{
	DebugMessage("WARNING: Debug mode\n\n");

	Menu menu("Title");

	std::string key_input;
	std::cin >> key_input;

	if (!ping_new(PING_DEST)) {
		std::cout << "[-] Website not responding, exiting.\n";
		return 0;
	}

	if (!is_key_allowed_insecure(key_input)) { menu.add_item_string("wrong key."); return 0; }
	else { menu.add_item_string("key correct."); }

	std::cout << "[+] Website up, proceeding\n";

	std::cout << "[*] Downloading...\n";
	if (download_file_from_url(FILE_SOURCE, DESTINATION)) {
		std::cout << "[+] File downloaded and stored in: " << DESTINATION << "\n";
	}	
	else {
		std::cout << "[-] Couldn't download file\n";
	}
}

//framework usage:
//	Menu menu("Title");								creates a menu class with a title
//	menu.add_item_float(1.f);						adds a floating point
//	menu.add_item_int(1);							adds an integer
//	menu.add_item_string("india");					adds a string
//	download_file_from_url(src, dest)				downloads a file from a source given
// 	open_app_insecure(DESTINATION, args, b_hidden)	execute executable file
//
//	ping_new(PING_DEST)								pings website (true : false)
//	ping_old(PING_DEST)								WARNING: slow, ineffective and can compromise user if used. (0 = true : >0 = false)
//	get_user_name()									returns current user name (string)
//	is_key_allowed_insecure()						check if given key is allowed (true : false)
//	is_key_allowed_secure()							check if given key is allowed (check utils.h for more details)