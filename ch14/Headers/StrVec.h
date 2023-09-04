#pragma once
#include <initializer_list>
#include <memory>
#include <string>
#include <iostream>

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {};
    StrVec(std::initializer_list<std::string> il)
        : elements(nullptr), first_free(nullptr), cap(nullptr) {
        auto newdata = alloc_n_copy(il.begin(), il.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    };

    // copy constructors
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    // move semantics
    StrVec(StrVec&&) noexcept;
    StrVec& operator=(StrVec&&) noexcept;

    //other overloaded operators
    StrVec& operator=(std::initializer_list<std::string>);
    std::string& operator[](size_t n);
    const std::string& operator[](size_t n) const;

    // member functions
    void push_back(const std::string&);
    size_t size() const { return first_free - elements; }
    void reserve(size_t n);
    void resize(size_t n);
    size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }

    void print() {
        for (auto idx = begin(); idx != end(); ++idx) {
            std::cout << *idx << " ";
        }
    }

private:
    static std::allocator<std::string> alloc;

    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }
    void free();
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*,
        const std::string*);
    void reallocate();
    std::string* elements; // Pointer to the start of the vector
    std::string* first_free;
    std::string* cap;
};

