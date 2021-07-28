#include "Windows.h"
#include <tchar.h>
#include <stdio.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Shell32.lib")

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hPrI, PSTR szCmdLine, int iCmdShow) {
	//0x42 is 'b'
	if(RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, 0x42)) {
		int isHiding = 0;

		MSG msg = {0};
		while(GetMessage(&msg, NULL, 0, 0) != 0) {
			if(msg.message == WM_HOTKEY) {
				isHiding = isHiding == 0 ? 1 : 0;

				APPBARDATA data;
				data.cbSize = sizeof(data);
				data.hWnd = FindWindow("System_TrayWnd", NULL);

				// 1 = autohide, 2 = alwaysontop
				data.lParam = isHiding ? 1 : 2;

				SHAppBarMessage(ABM_SETSTATE, &data);
			}
			Sleep(100);
		}
	}

	return 0;
}
