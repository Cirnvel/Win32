#pragma once

#include "Wnd.h"

#include <memory>
#include <cmath>

#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

namespace d2d
{
    using namespace win;

    template <typename Interface>
    inline void SafeRelease(
        Interface** ppInterfaceToRelease)
    {
        if (*ppInterfaceToRelease != nullptr)
        {
            (*ppInterfaceToRelease)->Release();
            (*ppInterfaceToRelease) = nullptr;
        }
    }

    class D2dWnd: protected win::Wnd
    {
    public:

        D2dWnd(HINSTANCE _hInstance, LPCWSTR _wndClassName, BOOL IsExW = FALSE);
        D2dWnd(HINSTANCE _hInstance, LPCWSTR _wndClassName, CONST WndClassStyle& style, BOOL IsExW = FALSE);
        D2dWnd(HINSTANCE _hInstance, LPCWSTR _wndClassName, CONST CursorStyle& cursor, BOOL IsExW = FALSE);
        D2dWnd(HINSTANCE _hInstance, LPCWSTR _wndClassName, CONST WndClassStyle& style, CONST WndStyle& Cursor, BOOL IsExW = FALSE);
        explicit D2dWnd(CONST D2dWnd& _Wnd) = delete;
        D2dWnd& operator=(CONST D2dWnd&) = delete;
        virtual ~D2dWnd();

        virtual BOOL InitiallizeWindowW(LPCWSTR title_name) override;
        virtual BOOL InitiallizeWindowW(LPCWSTR title_name, CONST WndStyle& style) override;
        virtual BOOL InitiallizeWindowExW(LPCWSTR title_name) override;
        virtual BOOL InitiallizeWindowExW(LPCWSTR title_name, CONST WndStyle& style) override;
        BOOL Show();
        BOOL Show(INT nCmdShow);

    protected:

        virtual HRESULT CreateDeviceIndependentResources();
        virtual HRESULT CreateDeviceResources();
        VOID DiscardDeviceResources();
        HRESULT OnRender();
        VOID OnResize(UINT width, UINT height);

    private:

        ID2D1Factory* m_pDirect2dFactory;
        ID2D1HwndRenderTarget* m_pRenderTarget;
        ID2D1SolidColorBrush* m_pLightSlateGrayBrush;
        ID2D1SolidColorBrush* m_pCornflowerBlueBrush;

        static HWND this_window;
        static LRESULT WINAPI WndFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
    };
}