#pragma once

#ifdef SWESYSTEM_EXPORT
#define SWESYSTEM_API __declspec(dllexport) 
#else 
#define SWESYSTEM_API __declspec(dllimport) 
#endif