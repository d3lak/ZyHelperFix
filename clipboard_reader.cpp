#include <winsock2.h>
#include <iostream>
#include <tchar.h>
#include "clipboard_reader.h"
#include "Debug.h"
#include <sstream> 



clipboard_reader::clipboard_reader()
{
}


int clipboard_reader::Read()
{
	StartupTime = GetTickCount();
	while (true) {
	
		Sleep(32);
		try {
			if (!OpenClipboard(nullptr)) {
				DEBUG_MSG("could not open bytestream" << std::endl);
				continue;
			}


			HANDLE hData = GetClipboardData(CF_TEXT);

			if (hData == nullptr) {
				DEBUG_MSG("hData == nullptr." << std::endl);
				DEBUG_MSG("Start THUD first." << std::endl);
				Sleep(5000);
				continue;
			}


			char * pszText = static_cast<char*>(GlobalLock(hData));
			if (pszText == nullptr) {
				DEBUG_MSG("text == nullptr" << std::endl);
				continue;
			}

			content = pszText;
			GlobalUnlock(hData);

			Running = true;

			CloseClipboard();
		}
		catch (...) {}
		
	}
}

bool clipboard_reader::ElementAt(unsigned  i, unsigned j)
{
	std::string copy;
	bool result;
	if (content.length() >= j)
	{
		copy = content;
	}
	else
	{
		return false;
	}

	result = (copy.at(j) & (1 << i)) != 0;

	return result;
}

bool clipboard_reader::IsReady()
{
	if (!Running) {
		return false;
	}

	DWORD currentTime = GetTickCount() - 5000;
	if (currentTime < StartupTime) {
		return false;
	}

	bool viable = content.length() >= 2;

	if (viable)
	{
		return true;
	}
	DEBUG_MSG("returning false" << std::endl);
	return false;
}

clipboard_reader::~clipboard_reader()
{
	MessageBox(NULL, _T("Error: reader terminated"),
		_T("ERROR"), MB_OK | MB_ICONEXCLAMATION);
}
