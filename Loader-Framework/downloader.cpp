#include "downloader.h"
#include <Urlmon.h>
#include <wininet.h>
#pragma comment(lib,"Wininet.lib")

bool download_file_from_url(const std::string& source, const std::string& destination) {
    if (SUCCEEDED(URLDownloadToFileA(NULL, source.c_str(), destination.c_str(), 0, NULL))) {
        return true;
    }
    return false;
}

int ping_old(const std::string& dest) {
	return (std::system(("ping -c1 " + dest).c_str()));
}

bool ping_new(const std::string& dest) {
	if (InternetCheckConnectionA(dest.c_str(), 0x00000001, 0)) {
		return true;
	}
	else {
		return false;
	}
}

//thanks to https://www.unknowncheats.me/forum/c-and-c-/337204-download-string-url.html and dupecc
std::string replaceAll(std::string subject, const std::string& search,
    const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
    return subject;
}

std::string DownloadString(std::string URL) {
    HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
    HINTERNET urlFile;
    std::string rtn;
    if (interwebs) {
        urlFile = InternetOpenUrlA(interwebs, URL.c_str(), NULL, NULL, NULL, NULL);
        if (urlFile) {
            char buffer[2000];
            DWORD bytesRead;
            do {
                InternetReadFile(urlFile, buffer, 2000, &bytesRead);
                rtn.append(buffer, bytesRead);
                memset(buffer, 0, 2000);
            } while (bytesRead);
            InternetCloseHandle(interwebs);
            InternetCloseHandle(urlFile);
            std::string p = replaceAll(rtn, "|n", "\r\n");
            return p;
        }
    }
    InternetCloseHandle(interwebs);
    std::string p = replaceAll(rtn, "|n", "\r\n");
    return p;
}