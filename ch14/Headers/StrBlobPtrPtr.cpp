#include "StrBlobPtrPtr.h"

StrBlobPtr& StrBlobPtrPtr::operator*(){
	return (*ptr);
}

StrBlobPtr* StrBlobPtrPtr::operator->() {
	return &this->operator*();
}
