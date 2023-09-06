#include "..\Base\Wnd.h"

using namespace win;

HINSTANCE Wnd::hInstance{ nullptr };
HWND Wnd::this_window{ nullptr };
LRESULT Wnd::WndFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}

Wnd::Wnd(HINSTANCE _hInstance, LPCWSTR _wndCassName, BOOL IsExW) :
	msg(), wndclassW(), wndclassExW()
{
	std::locale::global(std::locale("zh_cn"));
	Wnd::hInstance = _hInstance;

	if (IsExW == FALSE)
	{
		wndclassW.style = static_cast<UINT>(WndClassStyle::HredRaw) | static_cast<UINT>(WndClassStyle::VredRaw);
		wndclassW.lpfnWndProc = WndFunc;
		wndclassW.cbClsExtra = 0;
		wndclassW.cbWndExtra = sizeof(LONG_PTR);
		wndclassW.hInstance = Wnd::hInstance;
		wndclassW.hbrBackground = nullptr;
		wndclassW.lpszMenuName = nullptr;
		wndclassW.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wndclassW.lpszClassName = _wndCassName;
	}

	else
	{
		wndclassExW.cbSize = sizeof(wndclassExW);
		wndclassExW.style = static_cast<UINT>(WndClassStyle::HredRaw) | static_cast<UINT>(WndClassStyle::VredRaw);
		wndclassExW.lpfnWndProc = WndFunc;
		wndclassExW.cbClsExtra = 0;
		wndclassExW.cbWndExtra = sizeof(LONG_PTR);
		wndclassExW.hInstance = Wnd::hInstance;
		wndclassExW.hbrBackground = nullptr;
		wndclassExW.lpszMenuName = nullptr;
		wndclassExW.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wndclassExW.lpszClassName = _wndCassName;
	}
}
Wnd::Wnd(HINSTANCE _hInstance, LPCWSTR _wndCassName, CONST WndClassStyle& style, BOOL IsExW) :
	msg(), wndclassW(), wndclassExW()
{
	std::locale::global(std::locale("zh_cn"));
	Wnd::hInstance = _hInstance;

	if (IsExW == FALSE)
	{
		wndclassW.style = static_cast<UINT>(style);
		wndclassW.lpfnWndProc = WndFunc;
		wndclassW.cbClsExtra = 0;
		wndclassW.cbWndExtra = sizeof(LONG_PTR);
		wndclassW.hInstance = Wnd::hInstance;
		wndclassW.hbrBackground = nullptr;
		wndclassW.lpszMenuName = nullptr;
		wndclassW.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wndclassW.lpszClassName = _wndCassName;
	}

	else
	{
		wndclassExW.cbSize = sizeof(wndclassExW);
		wndclassExW.style = static_cast<UINT>(style);
		wndclassExW.lpfnWndProc = WndFunc;
		wndclassExW.cbClsExtra = 0;
		wndclassExW.cbWndExtra = sizeof(LONG_PTR);
		wndclassExW.hInstance = Wnd::hInstance;
		wndclassExW.hbrBackground = nullptr;
		wndclassExW.lpszMenuName = nullptr;
		wndclassExW.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wndclassExW.lpszClassName = _wndCassName;
	}
}
Wnd::Wnd(HINSTANCE _hInstance, LPCWSTR _wndCassName, CONST CursorStyle& Cursor, BOOL IsExW) :
	msg(), wndclassW(), wndclassExW()
{
	std::locale::global(std::locale("zh_cn"));
	Wnd::hInstance = _hInstance;

	if (IsExW == FALSE)
	{
		wndclassW.style = static_cast<UINT>(WndClassStyle::HredRaw) | static_cast<UINT>(WndClassStyle::VredRaw);
		wndclassW.lpfnWndProc = WndFunc;
		wndclassW.cbClsExtra = 0;
		wndclassW.cbWndExtra = sizeof(LONG_PTR);
		wndclassW.hInstance = Wnd::hInstance;
		wndclassW.hbrBackground = nullptr;
		wndclassW.lpszMenuName = nullptr;
		wndclassW.hCursor = LoadCursor(nullptr, MAKEINTRESOURCEW(Cursor));
		wndclassW.lpszClassName = _wndCassName;
	}

	else
	{
		wndclassExW.cbSize = sizeof(wndclassExW);
		wndclassExW.style = static_cast<UINT>(WndClassStyle::HredRaw) | static_cast<UINT>(WndClassStyle::VredRaw);
		wndclassExW.lpfnWndProc = WndFunc;
		wndclassExW.cbClsExtra = 0;
		wndclassExW.cbWndExtra = sizeof(LONG_PTR);
		wndclassExW.hInstance = Wnd::hInstance;
		wndclassExW.hbrBackground = nullptr;
		wndclassExW.lpszMenuName = nullptr;
		wndclassExW.hCursor = LoadCursor(nullptr, MAKEINTRESOURCEW(Cursor));
		wndclassExW.lpszClassName = _wndCassName;
	}
}
Wnd::Wnd(HINSTANCE _hInstance, LPCWSTR _wndCassName, CONST WndClassStyle& style, CONST WndStyle& Cursor, BOOL IsExW) :
	msg(), wndclassW(), wndclassExW()
{
	std::locale::global(std::locale("zh_cn"));
	Wnd::hInstance = _hInstance;

	if (IsExW == FALSE)
	{
		wndclassW.style = static_cast<UINT>(style);
		wndclassW.lpfnWndProc = WndFunc;
		wndclassW.cbClsExtra = 0;
		wndclassW.cbWndExtra = sizeof(LONG_PTR);
		wndclassW.hInstance = Wnd::hInstance;
		wndclassW.hbrBackground = nullptr;
		wndclassW.lpszMenuName = nullptr;
		wndclassW.hCursor = LoadCursor(nullptr, MAKEINTRESOURCEW(Cursor));
		wndclassW.lpszClassName = _wndCassName;
	}

	else
	{
		wndclassExW.cbSize = sizeof(wndclassExW);
		wndclassExW.style = static_cast<UINT>(style);
		wndclassExW.lpfnWndProc = WndFunc;
		wndclassExW.cbClsExtra = 0;
		wndclassExW.cbWndExtra = sizeof(LONG_PTR);
		wndclassExW.hInstance = Wnd::hInstance;
		wndclassExW.hbrBackground = nullptr;
		wndclassExW.lpszMenuName = nullptr;
		wndclassExW.hCursor = LoadCursor(nullptr, MAKEINTRESOURCEW(Cursor));
		wndclassExW.lpszClassName = _wndCassName;
	}
}
Wnd::Wnd(CONST Wnd& _Wnd) :
	msg(),
	wndclassW(_Wnd.wndclassW),
	wndclassExW(_Wnd.wndclassExW) {}
Wnd& win::Wnd::operator=(CONST Wnd& _wnd)
{
	wndclassW = _wnd.wndclassW;
	wndclassExW = _wnd.wndclassExW;

	return *this;
}
Wnd::~Wnd()
{
	CloseHandle(Wnd::this_window);
	Wnd::this_window = nullptr;
}

Wnd::Wnd(CONST WNDCLASSW& _wndclassW) : msg(), wndclassW(_wndclassW), wndclassExW()
{
	Wnd::hInstance = _wndclassW.hInstance;
}
Wnd::Wnd(CONST WNDCLASSEXW& _wndclassExW) : msg(), wndclassW(), wndclassExW(_wndclassExW)
{
	Wnd::hInstance = _wndclassExW.hInstance;
}

BOOL Wnd::InitiallizeWindowW(LPCWSTR title_name)
{

	if (!RegisterClassW(&wndclassW))
	{
		MessageBoxW(nullptr, L"该窗口程序注册失败 ！", L"Error", MB_ICONERROR | MB_OK);

		return FALSE;
	}

	else
	{
		Wnd::this_window = CreateWindowW(
			wndclassW.lpszClassName,
			title_name,
			static_cast<UINT>(WndStyle::OverLappedWindow),
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			nullptr,
			nullptr,
			Wnd::hInstance,
			this
		);

		if(!Wnd::this_window)
		{
			MessageBoxW(nullptr, L"该窗口程序创建失败 ！", L"Error", MB_ICONERROR | MB_OK);

			return FALSE;
		}

		else
			return TRUE;
	}
}
BOOL Wnd::InitiallizeWindowW(LPCWSTR title_name, CONST WndStyle& style)
{
	if (!RegisterClassW(&wndclassW))
	{
		MessageBoxW(nullptr, L"该窗口程序注册失败 ！", L"Error", MB_ICONERROR | MB_OK);

		return FALSE;
	}

	else
	{
		Wnd::this_window = CreateWindowW(
			wndclassW.lpszClassName,
			title_name,
			static_cast<UINT>(style),
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			nullptr,
			nullptr,
			Wnd::hInstance,
			this
		);

		if (!Wnd::this_window)
		{
			MessageBoxW(nullptr, L"该窗口程序创建失败 ！", L"Error", MB_ICONERROR | MB_OK);

			return FALSE;
		}

		else
			return TRUE;
	}
}
BOOL Wnd::InitiallizeWindowExW(LPCWSTR title_name)
{
	if (!RegisterClassExW(&wndclassExW))
	{
		MessageBoxW(nullptr, L"该窗口程序注册失败 ！", L"Error", MB_ICONERROR | MB_OK);

		return FALSE;
	}

	else
	{
		Wnd::this_window = CreateWindowExW(
			static_cast<UINT>(WndExStyle::LtrReading),
			wndclassExW.lpszClassName,
			title_name,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			nullptr,
			nullptr,
			Wnd::hInstance,
			this
		);

		if (!Wnd::this_window)
		{
			MessageBoxW(nullptr, L"该窗口程序创建失败 ！", L"Error", MB_ICONERROR | MB_OK);

			return FALSE;
		}

		else
			return TRUE;
	}

}
BOOL Wnd::InitiallizeWindowExW(LPCWSTR title_name, CONST WndStyle& style)
{
	if (!RegisterClassExW(&wndclassExW))
	{
		MessageBoxW(nullptr, L"该窗口程序注册失败 ！", L"Error", MB_ICONERROR | MB_OK);

		return FALSE;
	}

	else
	{
		Wnd::this_window = CreateWindowExW(
			static_cast<UINT>(WndExStyle::LtrReading),
			wndclassExW.lpszClassName,
			title_name,
			static_cast<UINT>(style),
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			nullptr,
			nullptr,
			Wnd::hInstance,
			this
		);

		if (!Wnd::this_window)
		{
			MessageBoxW(nullptr, L"该窗口程序创建失败 ！", L"Error", MB_ICONERROR | MB_OK);

			return FALSE;
		}

		else
			return TRUE;
	}

}

WPARAM Wnd::Show()
{
	ShowWindow(Wnd::this_window, static_cast<UINT>(ShowStyle::ShowNormal));
	UpdateWindow(Wnd::this_window);

	RunMessageLoop();

	return msg.wParam;
}
WPARAM Wnd::Show(INT nCmdShow)
{
	ShowWindow(Wnd::this_window, static_cast<UINT>(ShowStyle::ShowNormal));
	UpdateWindow(Wnd::this_window);

	RunMessageLoop(nCmdShow);

	return msg.wParam;
}

VOID Wnd::RunMessageLoop()
{
	while (GetMessageW(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
}
VOID Wnd::RunMessageLoop(INT nCmdShow)
{
	while (GetMessageW(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
}