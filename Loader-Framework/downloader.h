#pragma once
#include "includes.h"
#include <urlmon.h>
#include <tchar.h>
#pragma comment(lib, "urlmon.lib")

bool download_file_from_url(const std::string& source, const std::string& destination);

int ping_old(const std::string& dest);

bool ping_new(const std::string& dest);

std::string DownloadString(std::string URL);

std::string replaceAll(std::string subject, const std::string& search, const std::string& replace);