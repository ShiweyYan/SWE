#pragma once

#ifdef SWECORE_EXPORT
#define SWECORE_API __declspec(dllexport) 
#else 
#define SWECORE_API __declspec(dllimport) 
#endif