#pragma once
#include "windows.h"
#include "xor.h"
#include <iostream>

#define FILE_SOURCE xorstr_("https://download.ccleaner.com/cctrialsetup.exe")
#define KEY_LOCATION xorstr_("http://somecoolwebsiteiuse.tk/file.txt")
#define PING_DEST xorstr_("http://somecoolwebsiteiuse.tk/")

//FILE_SOURCE http://insert_website_name_here.com/file_name.exe
//KEY_LOCATION http://insert_website_name_here.com/key.txt (doesnt have to be .txt, you can just upload it to your github as a .txt LOL)
//PING_DEST http://insert_website_name_here.com
//http://somecoolwebsiteiuse.tk/file.txt
//DESTINATION "C:/Users/" + get_user_name() + "/Desktop/some_file_name.exe"
