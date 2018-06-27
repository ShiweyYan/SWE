#pragma once
#include "SWESystem.h"
#include "Interface.h"

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