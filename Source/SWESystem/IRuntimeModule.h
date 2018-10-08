#pragma once
#include "SWESystem.h"
#include "Interface.h"
#include "Singleton.h"

namespace SWE
{

	Interface SWESYSTEM_API IRuntimeModule
	{
	public:
		virtual ~IRuntimeModule() {};

		virtual int Start() = 0;
		virtual void End() = 0;
		virtual void Update() = 0;
	};

}