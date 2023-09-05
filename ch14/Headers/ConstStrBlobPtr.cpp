#include "ConstStrBlobPtr.h"
#include "StrBlob.h"

std::shared_ptr<const std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound ConstStrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

const std::string& ConstStrBlobPtr::operator*() const {
    auto p = check(curr, "Dereference past end of ConstStrBlobPtr");
    return (*p)[curr];
};

const std::string* ConstStrBlobPtr::operator->() const {
    return &this -> operator*();
};

ConstStrBlobPtr& ConstStrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr& ConstStrBlobPtr::operator--() {
    check(curr, "increment past end of StrBlobPtr");
    --curr;
    return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator++(int) {
    ConstStrBlobPtr ret = *this;
    ++*this;
    return ret;
}

ConstStrBlobPtr ConstStrBlobPtr::operator--(int) {
    ConstStrBlobPtr ret = *this;
    --*this;
    return ret;
}

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    lhs.check(lhs.curr, "incremenet past end of StrBlobPtr");
    rhs.check(rhs.curr, "incremenet past end of StrBlobPtr");
    return (lhs.wptr.lock() == rhs.wptr.lock());
};

bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    return !(lhs == rhs);
};

bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    lhs.check(lhs.curr, "incremenet past end of StrBlobPtr");
    rhs.check(rhs.curr, "incremenet past end of StrBlobPtr");
    return (lhs.wptr.lock() < rhs.wptr.lock());
};

bool operator<=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    return (lhs < rhs) || (lhs == rhs);
};

bool operator>(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    return !(lhs <= rhs);
};

bool operator>=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs) {
    return !(lhs < rhs);
};
