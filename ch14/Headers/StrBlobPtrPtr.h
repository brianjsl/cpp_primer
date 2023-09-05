#pragma once
#include "StrBlobPtr.h"

class StrBlobPtrPtr {
public:
	StrBlobPtr& operator*();
	StrBlobPtr* operator->();

private:
	StrBlobPtr* ptr;
};