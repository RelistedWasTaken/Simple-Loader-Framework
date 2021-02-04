# Simple Loader Framework

> This is a Simple Loader Framework anyone can use for simple projetcs

---

### Information:
- [Description](#description)
- [How To Use](#how-to-use)
- [Directories and Links](#directories-and-links)
- [Example Program](#example-program)
- [Author](#author)

## Description

A simple project created by me to be used as a loader in smaller/personal projects

#### Features:

- Download/Execute application from URL
- Checking a specific key to allow download
- Hiding the application downloaded
- Pinging/Checking if given website is alive

## How To Use

- Simple Menu Class Usage
```c
Menu menu("Title") //creates a menu with a title given
menu.add_item(anything) //moved add_item to template
```
- Downloader Usage
```c
download_file_from_url(src, dest, hidden) //downloads a file from a url to a destination and can be hidden
open_app_insecure(DESTINATION, args, b_hidden) //opens a file from destination with specific arguments (put "" if none).
ping_new(PING_DEST) //ping a website with a given destination (url/ip?)
ping_old(PING_DEST) //not recommended to use. Does the same as above
is_key_allowed_insecure() //check if given key is allowed returns true or false
is_key_allowed_secure() //check if given key is allowed returns and int value (usage showcase lower)
```

#### Usage of is_key_allowed_secure/insecure:
lets say you need to check whether the user has access to your product or not
you would need some kind of a serial id from the user trying to download the product
you can upload the key in any format, on any website, in any extension.
I will use <b>1111-3</b> as an example, so i upload a file.txt to my web hosting
with 1111-3 written in it, and than call is_key_allowed_insecure() with key_input being a string entered by the user

- Example
```c
if (!is_key_allowed_insecure(key_input)) { menu.add_item(xorstr_("wrong key.")); return 0; }
else { menu.add_item(xorstr_("key correct.")); }
```

the real difference between insecure and secure version is the more complicated return
so its harder to backtrace normally.


## Directories and Links

All website links/urls can be changed in <b>includes.h</b>
</br>
Directories can be changed in <b>utils.h -> get_path()</b>

## Example Program:
```c
#include "downloader.h"
#include "utils.h"
#include "xor.h"
#include "simple_menu.h"

int main() {
	Menu menu(xorstr_("Title"));

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
```

## Author

relisted 2021.
