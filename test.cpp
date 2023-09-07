#include "Base\Wnd.h"
#include "Base\D2d.h"

using namespace d2d;

INT WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdline, INT nCmdShow)
{
	D2dWnd d2dwnd(hInstance, L"D2dProGram", TRUE);
	d2dwnd.InitiallizeWindowExW(L"FirstProGram");
	d2dwnd.Show();

	return 0;
}