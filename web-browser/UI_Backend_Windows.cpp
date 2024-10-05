#include "UI_Backend_Windows.h"
#include "Globals_Windows.h"
#include "UI_Window_Windows.h"
#include "UI_Edit_Windows.h"

LRESULT CALLBACK UI_Backend_Windows::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	auto window = (UI_Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	if (window) {
		switch (uMsg) {
		case WM_GETMINMAXINFO: {
			PMINMAXINFO minMaxInfo = (PMINMAXINFO)lParam;

			RECT rect = {};
			rect.right = window->minClientAreaSize.width;
			rect.bottom = 40;

			AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

			minMaxInfo->ptMinTrackSize.x = rect.right - rect.left;
			minMaxInfo->ptMinTrackSize.y = rect.bottom - rect.top;

			return 0;
		}

		case WM_SIZE: {
			if (window->onResize) {
				int width = LOWORD(lParam);
				int height = HIWORD(lParam);
				window->onResize(UI_Size(width, height));
			}

			return 0;
		}

		case WM_CLOSE:
			if (window->onClose) {
				window->onClose();
			}

			return 0;

		case WM_COMMAND: {
			if (HIWORD(wParam) == BN_CLICKED) {
				HWND hButton = (HWND)lParam;
				auto& button = *((UI_Button*)GetWindowLongPtr(hButton, GWLP_USERDATA));

				if (button.onClick) {
					button.onClick();
				}
			}

			break;
		}
		}
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

UI_Backend_Windows::UI_Backend_Windows(HINSTANCE hInstance, int nCmdShow) : hInstance(hInstance), nCmdShow(nCmdShow) {
	WNDCLASS wc = {};
	wc.lpszClassName = WINDOWS_CLASS_NAME;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.lpfnWndProc = UI_Backend_Windows::WndProc;

	RegisterClass(&wc);
}

UI_Backend_Windows::~UI_Backend_Windows() {
	UnregisterClass(WINDOWS_CLASS_NAME, this->hInstance);
}

UI_Window& UI_Backend_Windows::createWindow(const wchar_t* title) {
	auto window = new UI_Window_Windows(this->hInstance, this->nCmdShow, title);
	return *window;
}

int UI_Backend_Windows::runMessageLoop() {
	MSG msg = {};
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	int exitCode = msg.wParam;
	return exitCode;
}

void UI_Backend_Windows::requestMessageLoopQuit(int exitCode) {
	PostQuitMessage(exitCode);
}
