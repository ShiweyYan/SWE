#pragma once

//RTTI Begin
#define DECLEAR_RTTI \
public:\
	const static Rtti RTTI;\
	virtual const Rtti& GetRTTI() const {return RTTI;}
	
//根据参数不同的的集中快捷宏,基类可以直接传类名
#define IMPLEMENT_RTTI_0(className) \
	const Rtti className::RTTI(#className);
#define IMPLEMENT_RTTI_1(className, baseClassName0) \
	const Rtti className::RTTI(#className, 1, &baseClassName0::RTTI);
#define IMPLEMENT_RTTI_2(className, baseClassName0, baseClassName1) \
	const Rtti className::RTTI(#className, 2, &baseClassName0::RTTI, &baseClassName1::RTTI);
#define IMPLEMENT_RTTI_3(className, baseClassName0, baseClassName1, baseClassName2) \
	const Rtti className::RTTI(#className, 3, &baseClassName0::RTTI,  &baseClassName1::RTTI,  &baseClassName2::RTTI);
#define IMPLEMENT_RTTI_4(className, baseClassName0, baseClassName1, baseClassName2, baseClassName3) \
	const Rtti className::RTTI(#className, 4,  &baseClassName0::RTTI,  &baseClassName1::RTTI,  &baseClassName2::RTTI, &baseClassName3::RTTI);
//完整宏,可以支持任意数量的基类,...需要传递RTTI的指针,such as &A::RTTI
#define IMPLEMENT_RTTI(className, baseClassesNum, ...) \
	const Rtti className::RTTI(#className, baseClassesNum, ##__VA_ARGS__);

#define IsKindOf(className, pObj)\
	pObj->GetRTTI().IsKindOf(className::RTTI)
#define DYNAMIC_CAST(className, pObj) \
	pObj->GetRTTI().DynamicCast<className>(className::RTTI, pObj)
//RTTI End

#define SMART_POINTER(ClassName) \
	typedef SmartPointer<ClassName> ClassName##Ptr;