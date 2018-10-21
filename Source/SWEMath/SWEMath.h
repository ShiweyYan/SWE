#pragma once

#ifdef SWEMATH_EXPORT
#define SWEMATH_API __declspec(dllexport) 
#else 
#define SWEMATH_API __declspec(dllimport) 
#endif

#define EPSILON_E3 (float)(1E-3) 
#define EPSILON_E4 (float)(1E-4) 
#define EPSILON_E5 (float)(1E-5)
#define EPSILON_E6 (float)(1E-6)