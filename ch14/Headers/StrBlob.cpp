#include "StrBlobPtr.h"
#include "StrBlob.h"

void StrBlob::check(size_type i, const std::string& msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
    check(0, "pop_back on emptyStrBlob");
    this->pop_back();
}

std::string& StrBlob::front() {
    check(0, "front on emptyStrBlob");
    return this->front();
}

std::string& StrBlob::back() {
    check(0, "back on emptyStrBlob");
    return this->back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); };

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, this->size()); }

StrBlobPtr StrBlob::cbegin() const { return  StrBlobPtr(*this); };
StrBlobPtr StrBlob::cend() const { return StrBlobPtr(*this, this->size()); };

bool operator==(const StrBlob& lhs, const StrBlob& rhs) {
    if (lhs.size() != rhs.size()) return false;
    for (auto i = 0; i != lhs.size(); ++i) {
        if (*(lhs.data->begin() + i) != *(rhs.data->begin() + i))
            return false;
    }
    return true;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs) {
    return !(lhs == rhs);
};

void StrBlob::print() {
    for (auto idx = data->begin(); idx != data->end(); ++idx) {
        std::cout << *idx << " ";
    }
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs) {
    auto len = (lhs.size() <= rhs.size()) ? lhs.size() : rhs.size();
    bool first_n_equal = true;
    for (size_t i = 0; i < len; ++i) {
        if (*(lhs.data -> begin() + i) > *(rhs.data -> begin() + i))
            return false;
        else if (*(lhs.data -> begin() + i) < *(rhs.data -> begin() + i))
            first_n_equal = false;
    }
    if (first_n_equal && lhs.size() >= rhs.size())
        return false;

    return true;
}

bool operator<=(const StrBlob& lhs, const StrBlob& rhs) {
    return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const StrBlob& lhs, const StrBlob& rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const StrBlob& lhs, const StrBlob& rhs) {
    return !(lhs < rhs);
}

