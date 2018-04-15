#pragma once
#include <iostream>
using std::ostream;

namespace SWE
{
	struct GfxConfig
	{
		GfxConfig() :redBits(8), greenBits(8), blueBits(8), alphaBits(8), depthBits(24), stencilBits(8), screenWidth(800), screenHeight(600), IsFullScreen(false), msaaSamples(8) {}

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

		friend ostream& operator << (ostream& out, GfxConfig& gfxConfig)
		{
			out << "GfxConfiguration:" <<
				" R:" << gfxConfig.redBits <<
				" G:" << gfxConfig.greenBits <<
				" B:" << gfxConfig.blueBits <<
				" A:" << gfxConfig.alphaBits <<
				" D:" << gfxConfig.depthBits <<
				" S:" << gfxConfig.stencilBits <<
				" M:" << gfxConfig.msaaSamples <<
				" W:" << gfxConfig.screenWidth <<
				" H:" << gfxConfig.screenHeight <<
				std::endl;
			return out;
		}
	};
}