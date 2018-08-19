#pragma once

#ifdef  SWERenderer_EXPORT
#define SWERenderer_API __declspec(dllexport) 
#else 
#define  SWERenderer_API __declspec(dllimport) 
#endif