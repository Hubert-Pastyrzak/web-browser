#include <Windows.h>
#include "UI_Backend_Windows.h"
#include "WebBrowser.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	UI_Backend_Windows uiBackend(hInstance, nCmdShow);
	WebBrowser webBrowser(uiBackend);

	int exitCode = webBrowser.run();
	return exitCode;
}
