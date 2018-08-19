#pragma once
#include "SWERenderer/Renderer/SWERenderer.h"
#include <iostream>

struct SWERenderer_API RendererDesc
{
	RendererDesc() :redBits(8), greenBits(8), blueBits(8), alphaBits(8), depthBits(24), stencilBits(8), screenWidth(800), screenHeight(600), IsFullScreen(false), msaaSamples(8) {}

	unsigned short redBits;
	unsigned short greenBits;
	unsigned short blueBits;
	unsigned short alphaBits;
	unsigned short depthBits;
	unsigned short stencilBits;
	int screenWidth;
	int screenHeight;
	bool IsFullScreen;
	unsigned short msaaSamples;

	friend std::ostream& operator << (std::ostream& out, RendererDesc& renderDesc)
	{
		out << "GfxConfiguration:" <<
			" R:" << renderDesc.redBits <<
			" G:" << renderDesc.greenBits <<
			" B:" << renderDesc.blueBits <<
			" A:" << renderDesc.alphaBits <<
			" D:" << renderDesc.depthBits <<
			" S:" << renderDesc.stencilBits <<
			" M:" << renderDesc.msaaSamples <<
			" W:" << renderDesc.screenWidth <<
			" H:" << renderDesc.screenHeight <<
			std::endl;
		return out;
	}
};