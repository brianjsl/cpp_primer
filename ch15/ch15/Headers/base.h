#pragma once
#include <string>
#include <iostream>
using namespace std;

class base {
public:
	string name() { return basename; }
	virtual void print(ostream& os = std::cout) const { os << basename; } //prints the basename member of the class 

private:
	string basename;
};

class derived : public base {
public:
	void print(ostream& os = std::cout) const override{
		base::print(os);
		os << " " << i;
	};  
private:
	int i;
};

class Base
{
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv : public Base {
	int f() { return prot_mem; }
	int g() { return priv_mem; }

	void memfcn(Base& b) { b = *this; }
};

struct Priv_Derv : private Base {
	int f1() const { return prot_mem; }
	void memfcn(Base& b) { b = *this; }
};

struct Prot_Derv : protected Base {
	void memfcn(Base& b) { b = *this; }
};

struct Derived_from_Public : public Pub_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base& b) { b = *this; }
};

struct Derived_from_Private : public Priv_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base& b) { b = *this; }
};

struct Derived_from_Protected : public Prot_Derv {
	int use_base() { return prot_mem; }
	void memfcn(Base& b) { b = *this; }
};
