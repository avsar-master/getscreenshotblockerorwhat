#include <Windows.h>
#include <iostream>

int main()
{
	HWND topWindow = GetTopWindow(GetDesktopWindow());

	do
	{
		DWORD pdwAffinity = -1;

		char szWindow[128];
		GetWindowTextA(topWindow, szWindow, 128);

		BOOL isDRMProtected = GetWindowDisplayAffinity(topWindow, &pdwAffinity);

		if (pdwAffinity == WDA_EXCLUDEFROMCAPTURE)
		{
			std::cout << "Found WDA_EXCLUDEFROMCAPTURE: " << szWindow << " ID: " << (int)topWindow << std::endl;
		}

		if (pdwAffinity == WDA_MONITOR)
		{
			std::cout << "Found WDA_MONITOR: " << szWindow << " ID: " << topWindow << std::endl;
		}
	} while (topWindow = GetWindow(topWindow, GW_HWNDNEXT));
}
