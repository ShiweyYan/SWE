#pragma once

//RTTI Begin
#define DECLEAR_RTTI const static Rtti RTTI;

#define IMPLEMENT_RTTI_ORIGION(className) \
	const Rtti className::RTTI(#className);

#define IMPLEMENT_RTTI(className, baseClassesNum, ...) \
	const Rtti className::RTTI(#className, baseClassesNum, ##__VA_ARGS__);
//RTTI End