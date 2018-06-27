#pragma once
#include <windows.h>
#include <windowsx.h>
#include "BaseApplication.h"
#include "GfxConfig.h"

namespace SWE {
	class  WindowsApplication : public BaseApplication
	{
	public:
		WindowsApplication(GfxConfig gfxCfg):m_kGfxConfig(gfxCfg){};

		virtual int Initialize();
		virtual void Finalize();
		// One cycle of the main loop
		virtual void Tick();

		HWND GetMainWindow() { return m_hWnd; };

	protected:
		void CreateMainWindow();

	private:
		// the WindowProc function prototype
		static LRESULT CALLBACK WindowProc(HWND hWnd,
			UINT message,
			WPARAM wParam,
			LPARAM lParam);

	protected:
		HWND m_hWnd;
		GfxConfig m_kGfxConfig;
	};
}