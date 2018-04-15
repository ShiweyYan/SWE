#pragma once

namespace SWE {
#define Interface class

	Interface IApplication
	{
	public:
		virtual int Initialize() = 0;
		virtual void Finalize() = 0;
		// One cycle of the main loop
		virtual void Tick() = 0;

		virtual void SetCommandLineParameters(int argc, char** argv) = 0;

		virtual bool IsQuit() = 0;

		virtual void OnDraw() = 0;
	};
}

extern SWE::IApplication*    g_pApp;