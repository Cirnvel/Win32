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
    template <typename Interface>
    inline void SafeRelease(
        Interface** ppInterfaceToRelease)
    {
        if (*ppInterfaceToRelease != nullptr)
        {
            (*ppInterfaceToRelease)->Release();
            (*ppInterfaceToRelease) = nullptr;
        }

        D2D1
    }

    class D2dWnd: private win::Wnd
    {
    public:

    private:
    };
}