#pragma once

#ifdef SWEDX11_EXPORT
#define SWEDX11_API __declspec(dllexport) 
#else 
#define SWEDX11_API __declspec(dllimport) 
#endif