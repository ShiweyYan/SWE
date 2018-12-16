#pragma once
#include "SWESystem.h"
#include "Singleton.h"

namespace SWE
{

	class SWESYSTEM_API IRuntimeModule
	{
	public:
		virtual ~IRuntimeModule() {};

		virtual int Start() = 0;
		virtual void End() = 0;
		virtual void Update() = 0;
	};

}