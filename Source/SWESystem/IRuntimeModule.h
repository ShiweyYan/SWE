#pragma once
#include "Interface.h"

namespace SWE
{

	Interface IRuntimeModule
	{
	public:
		virtual ~IRuntimeModule() {};

		virtual int Start() = 0;
		virtual void End() = 0;
		virtual void Update() = 0;
	};

}