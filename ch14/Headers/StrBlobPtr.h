#pragma once

#include "StrBlob.h"
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
    friend StrBlobPtr operator+(const StrBlobPtr&, size_t n);
    friend StrBlobPtr operator-(const StrBlobPtr&, size_t n);

public:
    StrBlobPtr() : curr(0) {};
    StrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {};
    std::string& deref() const;
    StrBlobPtr& incr();

    std::string& operator[](size_t n) {
        auto p = check(n, "Valid range of StrBlobPtr");
        return (*p)[n];
    };
    
    const std::string& operator[](size_t n) const {
        auto p = check(n, "Valid range of StrBlobPtr");
        return (*p)[n];
    };

    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t,
        const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

