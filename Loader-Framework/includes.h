#pragma once
#include "windows.h"
#include "xor.h"
#include <iostream>

#define FILE_SOURCE xorstr_("http://insert_website_name_here.com/file_name.exe")
#define KEY_LOCATION xorstr_("http://insert_website_name_here.com/key.txt")
#define PING_DEST xorstr_("http://insert_website_name_here.com")

//FILE_SOURCE http://insert_website_name_here.com/file_name.exe
//KEY_LOCATION http://insert_website_name_here.com/key.txt (doesnt have to be .txt, you can just upload it to your github as a .txt LOL)
//PING_DEST http://insert_website_name_here.com