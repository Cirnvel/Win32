#include "..\Base\D2d.h"

using namespace d2d;

HWND D2dWnd::this_window{ nullptr };
LRESULT WINAPI D2dWnd::WndFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return NULL;
}

D2dWnd::D2dWnd(HINSTANCE _hInstance, LPCWSTR _wndClassName, BOOL IsExW) :
	Wnd::Wnd(_hInstance, _wndClassName, IsExW),
	m_pDirect2dFactory(),
	m_pRenderTarget(),
	m_pLightSlateGrayBrush(),
	m_pCornflowerBlueBrush()
{
	if (IsExW == FALSE)
		wndclassW.lpfnWndProc = D2dWnd::WndFunc;

	else
		wndclassExW.lpfnWndProc = D2dWnd::WndFunc;
}

D2dWnd::D2dWnd(HINSTANCE _hInstance, LPCWSTR _wndClassName, CONST WndClassStyle& style, BOOL IsExW) :
	Wnd::Wnd(_hInstance, _wndClassName, style, IsExW),
	m_pDirect2dFactory(),
	m_pRenderTarget(),
	m_pLightSlateGrayBrush(),
	m_pCornflowerBlueBrush()
{
	if (IsExW == FALSE)
		wndclassW.lpfnWndProc = D2dWnd::WndFunc;

	else
		wndclassExW.lpfnWndProc = D2dWnd::WndFunc;
}

D2dWnd::D2dWnd(HINSTANCE _hInstance, LPCWSTR _wndClassName, CONST CursorStyle& cursor, BOOL IsExW) :
	Wnd::Wnd(_hInstance, _wndClassName, cursor, IsExW),
	m_pDirect2dFactory(),
	m_pRenderTarget(),
	m_pLightSlateGrayBrush(),
	m_pCornflowerBlueBrush()
{
	if (IsExW == FALSE)
		wndclassW.lpfnWndProc = D2dWnd::WndFunc;

	else
		wndclassExW.lpfnWndProc = D2dWnd::WndFunc;
}

D2dWnd::D2dWnd(HINSTANCE _hInstance, LPCWSTR _wndClassName, CONST WndClassStyle& style, CONST WndStyle& Cursor, BOOL IsExW) :
	Wnd::Wnd(_hInstance, _wndClassName, style, Cursor, IsExW),
	m_pDirect2dFactory(),
	m_pRenderTarget(),
	m_pLightSlateGrayBrush(),
	m_pCornflowerBlueBrush()
{
	if (IsExW == FALSE)
		wndclassW.lpfnWndProc = D2dWnd::WndFunc;

	else
		wndclassExW.lpfnWndProc = D2dWnd::WndFunc;
}

D2dWnd::~D2dWnd()
{
	SafeRelease(m_pDirect2dFactory.release());
	m_pDirect2dFactory.reset();

	SafeRelease(m_pRenderTarget.release());
	m_pRenderTarget.reset();

	SafeRelease(m_pLightSlateGrayBrush.release());
	m_pLightSlateGrayBrush.reset();

	SafeRelease(m_pCornflowerBlueBrush.release());
	m_pCornflowerBlueBrush.reset();
}

BOOL D2dWnd::InitiallizeWindowW(LPCWSTR title_name)
{
	HRESULT hr{};

	hr = CreateDeviceIndependentResources();

	if (FAILED(hr))
	{
		MessageBoxW(nullptr, L"设备无关资源创建失败 ！", L"Error", MB_ICONERROR | MB_OK);

		return FALSE;
	}

	else
	{
		RegisterClassW(&wndclassW);

		D2dWnd::this_window = CreateWindowW(
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

		if (!D2dWnd::this_window)
		{
			MessageBoxW(nullptr, TEXT("该窗口程序创建失败 ！"), TEXT("Error"), MB_ICONERROR | MB_OK);

			return FALSE;
		}

		else
			return TRUE;
	}
}
BOOL D2dWnd::InitiallizeWindowW(LPCWSTR title_name, CONST WndStyle& style)
{
	HRESULT hr{};

	hr = CreateDeviceIndependentResources();

	if (FAILED(hr))
	{
		MessageBoxW(nullptr, L"设备无关资源创建失败 ！", L"Error", MB_ICONERROR | MB_OK);

		return FALSE;
	}

	else
	{
		RegisterClassW(&wndclassW);

		D2dWnd::this_window = CreateWindowW(
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

		if (!D2dWnd::this_window)
		{
			MessageBoxW(nullptr, TEXT("该窗口程序创建失败 ！"), TEXT("Error"), MB_ICONERROR | MB_OK);

			return FALSE;
		}

		else
			return TRUE;
	}
}
BOOL D2dWnd::InitiallizeWindowExW(LPCWSTR title_name)
{
	HRESULT hr{};

	hr = CreateDeviceIndependentResources();

	if (FAILED(hr))
	{
		MessageBoxW(nullptr, L"设备无关资源创建失败 ！", L"Error", MB_ICONERROR | MB_OK);

		return FALSE;
	}

	else
	{
		RegisterClassExW(&wndclassExW);

		D2dWnd::this_window = CreateWindowW(
			wndclassExW.lpszClassName,
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

		if (!D2dWnd::this_window)
		{
			MessageBoxW(nullptr, TEXT("该窗口程序创建失败 ！"), TEXT("Error"), MB_ICONERROR | MB_OK);

			return FALSE;
		}

		else
			return TRUE;
	}
}
BOOL D2dWnd::InitiallizeWindowExW(LPCWSTR title_name, CONST WndStyle& style)
{
	HRESULT hr{};

	hr = CreateDeviceIndependentResources();

	if (FAILED(hr))
	{
		MessageBoxW(nullptr, L"设备无关资源创建失败 ！", L"Error", MB_ICONERROR | MB_OK);

		return FALSE;
	}

	else
	{
		RegisterClassExW(&wndclassExW);

		D2dWnd::this_window = CreateWindowW(
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

		if (!D2dWnd::this_window)
		{
			MessageBoxW(nullptr, TEXT("该窗口程序创建失败 ！"), TEXT("Error"), MB_ICONERROR | MB_OK);

			return FALSE;
		}

		else
			return TRUE;
	}
}

VOID D2dWnd::Show()
{
	double dpi{ GetDpiForWindow(D2dWnd::this_window) };

	SetWindowPos(
		D2dWnd::this_window,
		nullptr,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		static_cast<int>(ceil(640.f * dpi / 96.f)),
		static_cast<int>(ceil(480.f * dpi / 96.f)),
		SWP_NOMOVE);

	ShowWindow(D2dWnd::this_window, static_cast<UINT>(ShowStyle::ShowNormal));
	UpdateWindow(D2dWnd::this_window);

	HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption, nullptr, 0);

	if (SUCCEEDED(CoInitialize(nullptr)))
	{
		RunMessageLoop();
		CoUninitialize();
	}
}
VOID D2dWnd::Show(INT nCmdShow)
{
	double dpi{ GetDpiForWindow(D2dWnd::this_window) };

	SetWindowPos(
		D2dWnd::this_window,
		nullptr,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		static_cast<int>(ceil(640.f * dpi / 96.f)),
		static_cast<int>(ceil(480.f * dpi / 96.f)),
		SWP_NOMOVE);

	ShowWindow(D2dWnd::this_window, static_cast<UINT>(ShowStyle::ShowNormal));
	UpdateWindow(D2dWnd::this_window);

	HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption, nullptr, 0);

	if (SUCCEEDED(CoInitialize(nullptr)))
	{
		RunMessageLoop(nCmdShow);
		CoUninitialize();
	}
}