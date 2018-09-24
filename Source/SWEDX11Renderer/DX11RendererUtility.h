#pragma once
#include<string>
#include <memory>
#include <functional> 
#include <assert.h>
using std::wstring;

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
	if (pT != nullptr)
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