#pragma once
#include "IApplication.h"
//#include "GraphicsManager.hpp"
//#include "MemoryManager.hpp"
//#include "AssetLoader.hpp"
//#include "SceneManager.hpp"
//#include "InputManager.hpp"
//#include "PhysicsManager.hpp"
//#include "GameLogic.hpp"

namespace SWE {
	class  BaseApplication: public IApplication
	{
	public:
		BaseApplication();
		virtual int Initialize();
		virtual void Finalize();
		// One cycle of the main loop
		virtual void Tick();

		virtual void SetCommandLineParameters(int argc, char** argv);

		virtual bool IsQuit();

		//inline GfxConfiguration& GetConfiguration() { return m_Config; };

		virtual void OnDraw() {};

	protected:
		// Flag if need quit the main loop of the application
		static bool         m_bQuit;
		int                 m_nArgC;
		char**              m_ppArgV;

	private:
		// hide the default construct to enforce a configuration
		//BaseApplication() {};
	};
}