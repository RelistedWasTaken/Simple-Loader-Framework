# Simple Loader Framework

> This is a Simple Loader Framework anyone can use for simple projetcs

---

### Information:
- [Description](#description)
- [How To Use](#how-to-use)
- [Author](#author-info)

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
menu.add_item_float(1.f) //adds a floating point
menu.add_item_int(1) //adds an integer
menu.add_item_string("dummy") //adds a string
```
- Downloader Usage
```c
download_file_from_url(src, dest) //downloads a file from a url to a destination
open_app_insecure(DESTINATION, args, b_hidden) //opens a file from destination with specific arguments (put "" if none).
ping_new(PING_DEST) //ping a website with a given destination (url/ip?)
ping_old(PING_DEST) //not recommended to use. Does the same as above
is_key_allowed_insecure() //check if given key is allowed returns true or false
is_key_allowed_secure() //check if given key is allowed returns and int value ([How To Use - is_key_allowed_secure/insecure](#is_key_allowed))
```

#### Usage of is_key_allowed_secure/insecure:
lets say you need to check whether the user has access to your product or not
you would need some kind of a serial id from the user trying to download the product
you can upload the key in any format, on any website, in any extension.
I will use <b>1111-3</b> as an example, so i upload a file.txt to my web hosting
1111-3 written on it, and than call is_key_allowed_insecure() with key_input being a string entered by the user

- Example
```c
if (!is_key_allowed_insecure(key_input)) { menu.add_item_string("wrong key."); return 0; }
else { menu.add_item_string("key correct."); }
```

- Example: 2
```c
if (*result == t_ - f_) { menu.add_item_string("wrong key."); return 0; } //you can change the variables in utils.h
else if (*result == t_ + f_) { menu.add_item_string("key correct."); }
```

the real difference between insecure and secure version is the more complicated return
so its harder to backtrace normally.

## Author

relisted 2021.
