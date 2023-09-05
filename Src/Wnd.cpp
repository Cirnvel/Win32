#include "..\Base\Wnd.h"

HINSTANCE win::Wnd::hInstance{ nullptr };
HWND win::Wnd::this_window{ nullptr };
LRESULT win::Wnd::WndFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
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

win::Wnd::Wnd(HINSTANCE _hInstance, LPCWSTR _wndclassName, BOOL IsExW) :
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
		wndclassW.lpszClassName = _wndclassName;
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
		wndclassExW.lpszClassName = _wndclassName;
	}
}
win::Wnd::Wnd(HINSTANCE _hInstance, LPCWSTR _wndclassName, CONST WndClassStyle& style, BOOL IsExW) :
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
		wndclassW.lpszClassName = _wndclassName;
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
		wndclassExW.lpszClassName = _wndclassName;
	}
}
win::Wnd::Wnd(HINSTANCE _hInstance, LPCWSTR _wndclassName, CONST CursorStyle& Cursor, BOOL IsExW) :
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
		wndclassW.lpszClassName = _wndclassName;
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
		wndclassExW.lpszClassName = _wndclassName;
	}
}
win::Wnd::Wnd(HINSTANCE _hInstance, LPCWSTR _wndclassName, CONST WndClassStyle& style, CONST WndStyle& Cursor, BOOL IsExW) :
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
		wndclassW.lpszClassName = _wndclassName;
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
		wndclassExW.lpszClassName = _wndclassName;
	}
}
win::Wnd::Wnd(CONST Wnd& _Wnd) :
	msg(),
	wndclassW(_Wnd.wndclassW),
	wndclassExW(_Wnd.wndclassExW) {}
win::Wnd& win::Wnd::operator=(CONST Wnd& _wnd)
{
	wndclassW = _wnd.wndclassW;
	wndclassExW = _wnd.wndclassExW;

	return *this;
}

win::Wnd::Wnd(CONST WNDCLASSW& _wndclassW) : msg(), wndclassW(_wndclassW), wndclassExW()
{
	Wnd::hInstance = _wndclassW.hInstance;
}
win::Wnd::Wnd(CONST WNDCLASSEXW& _wndclassExW) : msg(), wndclassW(), wndclassExW(_wndclassExW)
{
	Wnd::hInstance = _wndclassExW.hInstance;
}

BOOL win::Wnd::InitiallizeWindowW(LPCWSTR title_name)
{

	if (!RegisterClassW(&wndclassW))
	{
		MessageBoxW(nullptr, TEXT("¸Ã´°¿Ú³ÌÐò×¢²áÊ§°Ü £¡"), TEXT("Error"), MB_ICONERROR);

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
			nullptr
		);

		return TRUE;
	}
}
BOOL win::Wnd::InitiallizeWindowW(LPCWSTR title_name, CONST WndStyle& style)
{
	if (!RegisterClassW(&wndclassW))
	{
		MessageBoxW(nullptr, TEXT("¸Ã´°¿Ú³ÌÐò×¢²áÊ§°Ü £¡"), TEXT("Error"), MB_ICONERROR);

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

		return TRUE;
	}
}
BOOL win::Wnd::InitiallizeWindowExW(LPCWSTR title_name)
{
	if (!RegisterClassExW(&wndclassExW))
	{
		MessageBoxW(nullptr, TEXT("¸Ã´°¿Ú³ÌÐò×¢²áÊ§°Ü £¡"), TEXT("Error"), MB_ICONERROR);

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

		return TRUE;
	}

}
BOOL win::Wnd::InitiallizeWindowExW(LPCWSTR title_name, CONST WndStyle& style)
{
	if (!RegisterClassExW(&wndclassExW))
	{
		MessageBoxW(nullptr, TEXT("¸Ã´°¿Ú³ÌÐò×¢²áÊ§°Ü £¡"), TEXT("Error"), MB_ICONERROR);

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

		return TRUE;
	}

}

WPARAM win::Wnd::Show()
{
	ShowWindow(this_window, static_cast<UINT>(ShowStyle::ShowNormal));
	UpdateWindow(this_window);

	while (GetMessageW(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return msg.wParam;
}
WPARAM win::Wnd::Show(INT nCmdShow)
{
	ShowWindow(this_window, nCmdShow);
	UpdateWindow(this_window);

	while (GetMessageW(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return msg.wParam;
}