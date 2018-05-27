#include "Reference.h"

using namespace SWE;

SWE::Reference::Reference() :
	m_uiRefCount(0)
{

}

SWE::Reference::~Reference()
{
	m_uiRefCount = 0;
}
