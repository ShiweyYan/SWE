#include "BaseApplication.h"
#include <iostream>

using namespace SWE;
using namespace std;

bool BaseApplication::m_bQuit = false;

BaseApplication::BaseApplication()
{
}

// Parse command line, read configuration, initialize all sub modules
int BaseApplication::Initialize()
{
	int ret = 0;

	return ret;
}

// Finalize all sub modules and clean up all runtime temporary files.
void BaseApplication::Finalize()
{

}


// One cycle of the main loop
void BaseApplication::Tick()
{

}

void BaseApplication::SetCommandLineParameters(int argc, char** argv)
{
	m_nArgC = argc;
	m_ppArgV = argv;
}

bool BaseApplication::IsQuit()
{
	return m_bQuit;
}