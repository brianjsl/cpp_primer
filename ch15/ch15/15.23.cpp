class Base {
public:
	virtual int fcn();
};

class D1 : public Base {
public:
	using Base::fcn();
	int fcn(int);
	virtual void f2();
};

class D2 : public D1 {
public:
	int fcn(int);
	int fcn();
	void f2();
};

int main() {
	Base bobj; D1 d1obj; D2 d2obj;

	Base* bp1 = &bobj, * bp2 = &d1obj, * bp3 = &d2obj;
	bp1->fcn(); //virtual call, will call Base::fcn()
	bp2->fcn(); //virtual call, will call D1::fcn() which is equivalent to Base::fcn() at run time
	bp3->fcn(); //virtual call, will call D2::fcn() at run time

	D1* d1p = &d1obj; D2* d2p = &d2obj;
	bp2->f2(); //Base has no f2() member so will return error
	d1p->f2(); //virtual call, Calls D1::f2()
	d2p->f2(); //virtual call, Calls D2::f2() at runtime
}
