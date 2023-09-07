#include "..\Base\D2d.h"

using namespace d2d;

HWND D2dWnd::this_window{ nullptr };
LRESULT WINAPI D2dWnd::WndFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT hr{};

	if (message == WM_CREATE)
	{
		LPCREATESTRUCTW pcs{ reinterpret_cast<LPCREATESTRUCTW>(lParam) };
		D2dWnd* pD2dWnd{ reinterpret_cast<D2dWnd*>(pcs->lpCreateParams) };

		SetWindowLongPtrW(
			hwnd,
			GWLP_USERDATA,
			reinterpret_cast<LONG_PTR>(pD2dWnd));

		hr = 1;
	}

	else
	{
		D2dWnd* pD2dWnd{ reinterpret_cast<D2dWnd*>(static_cast<LONG_PTR>(GetWindowLongPtrW(
			hwnd,
			GWLP_USERDATA))) };

		DWORD x = GetLastError();

		bool wasHandled = false;

		if (pD2dWnd)
		{
			switch (message)
			{
			case WM_SIZE:
			{
				UINT width = LOWORD(lParam);
				UINT height = HIWORD(lParam);
				pD2dWnd->OnResize(width, height);
			}
			hr = 0;
			wasHandled = true;
			break;

			case WM_DISPLAYCHANGE:
			{
				InvalidateRect(hwnd, nullptr, FALSE);
			}
			hr = 0;
			wasHandled = true;
			break;

			case WM_PAINT:
			{
				pD2dWnd->OnRender();
				ValidateRect(hwnd, NULL);
			}
			hr = 0;
			wasHandled = true;
			break;

			case WM_DESTROY:
			{
				PostQuitMessage(0);
			}
			hr = 1;
			wasHandled = true;
			break;
			}
		}

		if (!wasHandled)
		{
			hr = DefWindowProcW(hwnd, message, wParam, lParam);
		}
	}

	return hr;
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
	SafeRelease(&m_pDirect2dFactory);
	SafeRelease(&m_pRenderTarget);
	SafeRelease(&m_pLightSlateGrayBrush);
	SafeRelease(&m_pCornflowerBlueBrush);
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

BOOL D2dWnd::Show()
{
	DOUBLE dpi{ static_cast<DOUBLE>(GetDpiForWindow(D2dWnd::this_window)) };

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

		return TRUE;
	}

	else
		return FALSE;
}
BOOL D2dWnd::Show(INT nCmdShow)
{
	DOUBLE dpi{ static_cast<DOUBLE>(GetDpiForWindow(D2dWnd::this_window)) };

	SetWindowPos(
		D2dWnd::this_window,
		nullptr,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		static_cast<int>(ceil(640.f * dpi / 96.f)),
		static_cast<int>(ceil(480.f * dpi / 96.f)),
		SWP_NOMOVE);

	ShowWindow(D2dWnd::this_window, nCmdShow);
	UpdateWindow(D2dWnd::this_window);

	HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption, nullptr, 0);

	if (SUCCEEDED(CoInitialize(nullptr)))
	{
		RunMessageLoop();
		CoUninitialize();

		return TRUE;
	}

	else
		return FALSE;
}

HRESULT D2dWnd::CreateDeviceIndependentResources()
{
	HRESULT hr{ S_OK };

	hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_pDirect2dFactory);

	return hr;
}
HRESULT D2dWnd::CreateDeviceResources()
{
	HRESULT hr{ S_OK };

	if (!m_pRenderTarget)
	{
		RECT rc{};
		GetClientRect(D2dWnd::this_window, &rc);

		D2D1_SIZE_U size{ D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top) };

		hr = m_pDirect2dFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(D2dWnd::this_window, size),
			&m_pRenderTarget
		);

		if (SUCCEEDED(hr))
		{
			hr = m_pRenderTarget->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::LightSlateGray),
				&m_pLightSlateGrayBrush
			);
		}

		if (SUCCEEDED(hr))
		{
			// Create a blue brush.
			hr = m_pRenderTarget->CreateSolidColorBrush(
				D2D1::ColorF(D2D1::ColorF::CornflowerBlue),
				&m_pCornflowerBlueBrush
			);
		}
	}

	return hr;
}
VOID D2dWnd::DiscardDeviceResources()
{
	SafeRelease(&m_pRenderTarget);
	SafeRelease(&m_pLightSlateGrayBrush);
	SafeRelease(&m_pCornflowerBlueBrush);
}
HRESULT D2dWnd::OnRender()
{
	HRESULT hr{ S_OK };

	hr = CreateDeviceResources();

	if (SUCCEEDED(hr))
	{
		m_pRenderTarget->BeginDraw();
		m_pRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
		m_pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

		D2D1_SIZE_F rtSize{ m_pRenderTarget->GetSize() };

		INT width{ static_cast<int>(rtSize.width) };
		INT height = static_cast<int>(rtSize.height);

		for (INT x{ 0 }; x < width; x += 10)
		{
			m_pRenderTarget->DrawLine(
				D2D1::Point2F(static_cast<FLOAT>(x), 0.0f),
				D2D1::Point2F(static_cast<FLOAT>(x), rtSize.height),
				m_pLightSlateGrayBrush,
				0.5f
			);
		}

		for (int y{ 0 }; y < height; y += 10)
		{
			m_pRenderTarget->DrawLine(
				D2D1::Point2F(0.0f, static_cast<FLOAT>(y)),
				D2D1::Point2F(rtSize.width, static_cast<FLOAT>(y)),
				m_pLightSlateGrayBrush,
				0.5f
			);
		}

		D2D1_RECT_F rectangle1{ D2D1::RectF(
			rtSize.width / 2 - 50.0f,
			rtSize.height / 2 - 50.0f,
			rtSize.width / 2 + 50.0f,
			rtSize.height / 2 + 50.0f
		) };

		D2D1_RECT_F rectangle2{ D2D1::RectF(
			rtSize.width / 2 - 100.0f,
			rtSize.height / 2 - 100.0f,
			rtSize.width / 2 + 100.0f,
			rtSize.height / 2 + 100.0f
		) };

		m_pRenderTarget->FillRectangle(&rectangle1, m_pLightSlateGrayBrush);
		m_pRenderTarget->FillRectangle(&rectangle1, m_pCornflowerBlueBrush);

		hr = m_pRenderTarget->EndDraw();
	}

	if (hr == D2DERR_RECREATE_TARGET)
	{
		hr = S_OK;
		DiscardDeviceResources();
	}

	return hr;
}
VOID D2dWnd::OnResize(UINT width, UINT height)
{
	if (m_pRenderTarget)
	{
		m_pRenderTarget->Resize(D2D1::SizeU(width, height));
	}
}