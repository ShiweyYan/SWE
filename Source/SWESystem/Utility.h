#pragma once
#include<string>
#include <memory>
#include <functional> 
#include <assert.h>
using std::wstring;

#define UNUSED(x) (void)(x);

#define HRESULT_ASSERT(x) FAILED(x)?assert(false):assert(true) 
#define HRESULT_RETURN(x) if(FAILED(x)){return false;} else{return true;}

//-------------------------------------------------
//make a shared_ptr for COM
//-------------------------------------------------
template<typename T>
inline std::shared_ptr<T> MakeCOMPtr(T* rawPtr)
{
	return rawPtr ? std::shared_ptr<T>(rawPtr, std::mem_fn(&T::Release)) : std::shared_ptr<T>();
}

//-------------------------------------------------
//安全的释放COM接口
//-------------------------------------------------
template <class T>
inline void SafeRelease(T& iface)
{
	if (iface)
	{
		iface->Release();
		iface = NULL;
	}
}

template<class T>
inline void SafeDelete(T*& pT)
{
	if (pT!=nullptr)
	{
		delete pT;
		pT = nullptr;
	}
}

template<class T>
inline void SafeDeleteArray(T*& pT)
{
	if (pT != nullptr)
	{
		delete[] pT;
		pT = nullptr;
	}
}

//-------------------------------------------------
//判断x是不是2次幂
//-------------------------------------------------
inline bool IsPowerOf2(const int x)
{
	return x&(x - 1) ? false : true;
}

//---------------------------------------------------------------------
//用来截断一个变量，将变量限制在一个范围内
//---------------------------------------------------------------------
template <class T>
inline void  Snap(T &a, T min, T max)
{
	if (a < min)
		a = min;
	if (a > max)
		a = max;
}

//----------------------------------------------------------------------
//用来获取一个给定范围内的随机数，默认范围是0到1
//----------------------------------------------------------------------
inline float RandFloat(float min = 0.f, float max = 1.f)
{
	return min + (max - min)*((float)rand() / RAND_MAX);
}

//----------------------------------------------------------------------
//string to wstring  
//----------------------------------------------------------------------
inline std::wstring s2ws(const std::string& s)
{
	const char* str = s.c_str();
	size_t len = s.size() + 1;
	wchar_t *wstr = new wchar_t[len];
	size_t converted = 0;
	mbsrtowcs_s(&converted, wstr, len, &str, len, nullptr);
	std::wstring ret(wstr);
	delete[] wstr;
	return ret;
}

//----------------------------------------------------------------------
//wstring to string
//----------------------------------------------------------------------
inline std::string ws2s(const std::wstring& ws)
{
	const wchar_t* wstr = ws.c_str();
	size_t len = 2 * ws.size() + 1;
	char *str = new char[len];
	size_t converted = 0;
	wcsrtombs_s(&converted, str, len, &wstr, len, nullptr);
	std::string ret(str);
	delete[] str;
	return ret;
}

const float eclipse = 0.0001f;
//----------------------------------------------------------------------
//浮点数equal
//----------------------------------------------------------------------
inline bool IsEqualFloat(float a, float b)
{
	float d_value = a - b;
	if (d_value<eclipse && d_value>-eclipse)
	{
		return true;
	}
	return false;
}
