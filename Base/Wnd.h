#pragma once

#include <Windows.h>
#include <tchar.h>

#include <string>
#include <locale>

namespace win
{
	enum class WndClassStyle : UINT
	{
		ByteAlignClient = CS_BYTEALIGNCLIENT,
		Byte_AlignWindow = CS_BYTEALIGNWINDOW,
		ClassDc = CS_CLASSDC,
		DblCliks = CS_DBLCLKS,
		DropShadow = CS_DROPSHADOW,
		GlobalClass = CS_GLOBALCLASS,
		HredRaw = CS_HREDRAW,
		NoClose = CS_NOCLOSE,
		OwnDc = CS_OWNDC,
		ParentDc = CS_PARENTDC,
		SaveBits = CS_SAVEBITS,
		VredRaw = CS_VREDRAW
	};
	enum class CursorStyle : UINT
	{
		Arrow = 32512,
		Ibeam = 32513,
		Wait = 32514,
		Cross = 32515,
		Uparrow = 32516,
		Size = 32640,
		Icon = 32641,
		SizeNwse = 32642,
		SizeNesW = 32643,
		SizeWe = 32644,
		SizeNs = 32645,
		SizeAll = 32646,
		No = 32648,
		Hand = 32649,
		AppStarting = 32650,
		Help = 32651
	};
	enum class WndStyle : ULONG64
	{
		Border = WS_BORDER,
		Caption = WS_CAPTION,
		Child = WS_CHILD,
		ChildWindow = WS_CHILDWINDOW,
		ClipChildren = WS_CLIPCHILDREN,
		ClipSiBlings = WS_CLIPSIBLINGS,
		Disabled = WS_DISABLED,
		DlgFrame = WS_DLGFRAME,
		Group = WS_GROUP,
		Hscroll = WS_HSCROLL,
		Iconic = WS_ICONIC,
		MaxiMize = WS_MAXIMIZE,
		MaximizeBox = WS_MAXIMIZEBOX,
		Minimize = WS_MINIMIZE,
		MinimizeBox = WS_MINIMIZEBOX,
		OverLapped = WS_OVERLAPPED,
		OverLappedWindow = WS_OVERLAPPEDWINDOW,
		PopUp = WS_POPUP,
		SizeBox = WS_SIZEBOX,
		SysMenu = WS_SYSMENU,
		TabStop = WS_TABSTOP,
		ThickFrame = WS_THICKFRAME,
		Titled = WS_TILED,
		TitledWindow = WS_TILEDWINDOW,
		Visible = WS_VISIBLE,
		Vscroll = WS_VSCROLL
	};
	enum class WndExStyle : UINT
	{
		AcceptFiles = WS_EX_ACCEPTFILES,
		AppWindow = WS_EX_APPWINDOW,
		ClientEdge = WS_EX_CLIENTEDGE,
		Composited = WS_EX_COMPOSITED,
		ContextHelp = WS_EX_CONTEXTHELP,
		ControlParent = WS_EX_CONTROLPARENT,
		DlgmodalFrame = WS_EX_DLGMODALFRAME,
		Layered = WS_EX_LAYERED,
		Layoutrtl = WS_EX_LAYOUTRTL,
		Left = WS_EX_LEFT,
		LeftScrollBar = WS_EX_LEFTSCROLLBAR,
		LtrReading = WS_EX_LTRREADING,
		MdiChild = WS_EX_MDICHILD,
		NoActivate = WS_EX_NOACTIVATE,
		NoInheritLayout = WS_EX_NOINHERITLAYOUT,
		NoParentNotify = WS_EX_NOPARENTNOTIFY,
		NoRedirectionBitmap = WS_EX_NOREDIRECTIONBITMAP,
		OverLappedWindow = WS_EX_OVERLAPPEDWINDOW,
		PaletteWindow =  WS_EX_PALETTEWINDOW,
		Right = WS_EX_RIGHT,
		RightScrollBar = WS_EX_RIGHTSCROLLBAR,
		RtlReading = WS_EX_RTLREADING,
		StaticeDge = WS_EX_STATICEDGE,
		ToolWindow = WS_EX_TOOLWINDOW,
		TopMost = WS_EX_TOPMOST,
		TransParent = WS_EX_TRANSPARENT,
		WindowEdge = WS_EX_WINDOWEDGE
	};
	enum class ShowStyle : UINT
	{
		Hide = SW_HIDE,
		ShowNormal = SW_SHOWNORMAL,
		ShowMinimized =  SW_SHOWMINIMIZED,
		ShowMaxMize = SW_MAXIMIZE,
		ShowNoActivate = SW_SHOWNOACTIVATE,
		Show = SW_SHOW,
		Minimize = SW_MINIMIZE,
		ShowMinNoActive = SW_SHOWMINNOACTIVE,
		ShowNa = SW_SHOWNA,
		Restore = SW_RESTORE,
		ShowDefault = SW_SHOWDEFAULT,
		ForceMinimize = SW_FORCEMINIMIZE
	};

	class Wnd
	{
	public:

		Wnd(HINSTANCE _hInstance, LPCWSTR _wndclassName, BOOL IsExW = FALSE);
		Wnd(HINSTANCE _hInstance, LPCWSTR _wndclassName, CONST WndClassStyle& style, BOOL IsExW = FALSE);
		Wnd(HINSTANCE _hInstance, LPCWSTR _wndclassName, CONST CursorStyle& cursor, BOOL IsExW = FALSE);
		Wnd(HINSTANCE _hInstance, LPCWSTR _wndclassName, CONST WndClassStyle& style, CONST WndStyle& Cursor, BOOL IsExW = FALSE);
		explicit WINAPI Wnd(CONST Wnd& _Wnd);
		Wnd& operator=(CONST Wnd& _wnd);
		virtual ~Wnd() = default;

		Wnd(CONST WNDCLASSW& _wndclassW);
		Wnd(CONST WNDCLASSEXW& _wndclassExW);

		virtual BOOL InitiallizeWindowW(LPCWSTR title_name);
		virtual BOOL InitiallizeWindowW(LPCWSTR title_name, CONST WndStyle& style);
		virtual BOOL InitiallizeWindowExW(LPCWSTR title_name);
		virtual BOOL InitiallizeWindowExW(LPCWSTR title_name, CONST WndStyle& style);
		virtual WPARAM Show();
		virtual WPARAM Show(INT nCmdShow);

	private:

		MSG msg;
		WNDCLASSW wndclassW;
		WNDCLASSEXW wndclassExW;

		static HINSTANCE hInstance;
		static HWND this_window;

		static LRESULT WINAPI WndFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}