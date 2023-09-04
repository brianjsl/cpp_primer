#include "StrBlobPtr.h"
#include "StrBlob.h"

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const {
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret;
}

std::string& StrBlobPtr::deref() const {
    auto p = check(curr, "derefence past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    lhs.check(lhs.curr, "incremenet past end of StrBlobPtr");
    rhs.check(rhs.curr, "incremenet past end of StrBlobPtr");
    return (lhs.wptr.lock() == rhs.wptr.lock());
};

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return !(lhs == rhs);
};

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    lhs.check(lhs.curr, "incremenet past end of StrBlobPtr");
    rhs.check(rhs.curr, "incremenet past end of StrBlobPtr");
    return (lhs.wptr.lock() < rhs.wptr.lock());
};

bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return (lhs < rhs) || (lhs == rhs);
};

bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return !(lhs <= rhs);
};

bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
    return !(lhs < rhs);
};


StrBlobPtr& StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--() {
    check(curr, "increment past end of StrBlobPtr");
    --curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++* this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --* this;
    return ret;
}

StrBlobPtr operator+(const StrBlobPtr& p, size_t n) {
    StrBlobPtr ret = p;
    p.check(p.curr + n - 1, "increment past end of StrBlobPtr");
    ret.curr += n;
    return ret;
}

StrBlobPtr operator-(const StrBlobPtr& p, size_t n) {
    return p + (-n);
}
